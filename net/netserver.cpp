#include <iostream>
#include <type_traits>
#include "base.h"
#include "netserver.h"

bool NetServer::handleAuth(ENetPeer *peer, ENetPacket *packet)
{
    PKT_KeyCheck_s *pkt = (PKT_KeyCheck_s *) (packet->data);
    if(mCount > mMax )
        return false;
    if(packet->dataLength != sizeof(PKT_KeyCheck_s))
        return false;
    if(mBlowFish->Decrypt(pkt->checkId) != pkt->playerID)
        return false;
    if(mBlowFish->Encrypt(pkt->playerID) != pkt->checkId)
        return false;
    if(pkt->playerID > mPeers.size())
        return false;
    if(pkt->playerID > mMax)
        return false;
    if(mPeers[pkt->playerID] != nullptr)
        return false;

    mCount++;
    mPeers[pkt->playerID] = peer;
    peer->data = (void*)(pkt->playerID);

    PKT_KeyCheck_s rpkt;
    rpkt.cmd = 0;
    rpkt.clientID = pkt->playerID;
    rpkt.playerID = pkt->playerID;
    rpkt.checkId = pkt->checkId;
    sendPacket(pkt->playerID, rpkt, CHANNEL_DEFAULT);
    OnConnected(pkt->playerID);
    return true;
}

void NetServer::OnNetworkPacket(uint32_t cid, uint8_t channel, uint8_t *data, size_t size)
{
    switch(channel)
    {
    case CHANNEL_GENERIC_APP_TO_SERVER:
        OnPacket[data[0]](cid, data, size);
        break;
    case CHANNEL_MIDDLE_TIER_CHAT:
    case CHANNEL_MIDDLE_TIER_ROSTER:
        OnPayload[data[0]](cid, data, size);
        break;
    default:
        std::cout<<"Unkown channel: "<<(uint32_t)channel<<std::endl;
        break;
    }
}

NetServer::NetServer(uint32_t address, uint16_t port,
                     std::string key, uint32_t maxclients) :
    mBlowFish(std::make_unique<BlowFish>((uint8_t*)(key.c_str()), 16)),
    mMax(maxclients+1), mHost(nullptr), mCount(1)
{
    mAddress.host = address;
    mAddress.port = port;
    for(int i=0;i<13;i++)
        mPeers[i] = nullptr;
}

NetServer::~NetServer()
{
    if(mHost != nullptr)
        enet_host_destroy(mHost);
}

bool NetServer::start()
{
    if(mHost != nullptr)
        return false;
    mHost = enet_host_create(&mAddress,32,0,0);
    if(mHost == nullptr)
        return false;
    return true;
}

bool NetServer::host(uint32_t timeout)
{
    ENetEvent event;
    if(mHost == nullptr)
        return false;
    while(enet_host_service(mHost, &event, timeout) != 0)
    {
        switch(event.type)
        {
            case ENET_EVENT_TYPE_CONNECT:
                event.peer->data = 0;
                event.peer->mtu = 996;
            break;
            case ENET_EVENT_TYPE_DISCONNECT:
                if((uint32_t)(event.peer->data) > 0)
                {
                    mCount--;
                    mPeers[(uint32_t)(event.peer->data)] = 0;
                    OnDisconnected((uint32_t)(event.peer->data));
                }
            break;
            case ENET_EVENT_TYPE_RECEIVE:
                if((uint32_t)(event.peer->data) > 0)
                {
                    if(event.channelID >= CHANNEL_NUM_TOTAL)
                        break;
                    if(event.packet->dataLength >= 8)
                        mBlowFish->Decrypt(event.packet->data,
                                           event.packet->dataLength-(event.packet->dataLength%8));
                        OnNetworkPacket((uint32_t)(event.peer->data),
                                          event.channelID,
                                          (uint8_t*)(event.packet->data),
                                          event.packet->dataLength);
                }
                else
                {
                    handleAuth(event.peer, event.packet);
                }
                enet_packet_destroy(event.packet);
            break;
        }
    }
    return true;
}

void NetServer::sendPacket(uint32_t cid, uint8_t *pkt, size_t size, uint8_t channel, uint32_t flags)
{
    if(cid>mMax || cid>12)
        return;
    ENetPeer *peer = mPeers[cid];
    if(peer == nullptr)
        return;
    uint8_t *data = new uint8_t[size];
    memcpy(data, pkt, size);
    if(size >= 8)
        mBlowFish->Encrypt(data, size-(size%8));
    ENetPacket *packet = enet_packet_create(data, size, flags);
    enet_peer_send(peer, channel, packet);
    delete[] data;
}

template<class PKT>
void NetServer::sendPacket(uint32_t cid, PKT &pkt, uint8_t channel, uint32_t flags)
{
    sendPacket(cid, (uint8_t*)&pkt, sizeof(PKT), channel, flags);
}
