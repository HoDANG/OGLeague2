#ifndef NetServer_H
#define NetServer_H

#include <vector>
#include <map>
#include <array>
#include <memory>
#include <functional>
#include <iostream>
#include <type_traits>
#include "../dep/enet.hpp"
#include "base.hpp"
#include "serveri.hpp"

class NetServer : public ServerI
{
protected:
    struct PKT_KeyCheck_s : NetBasePacket<0, CHANNEL_DEFAULT, ENET_PACKET_FLAG_RELIABLE>
    {
        uint8_t cmd;
        uint32_t clientID;
        uint64_t playerID;
        uint64_t checkId;
    };
private:
    uint32_t mMax = 0;
    uint32_t mCount = 1;
    ENetAddress mAddress;
    std::map<int, ENetPeer*> mPeers;
    ENetHost* mHost = nullptr;

    void OnNetworkPacket(uint32_t cid, uint8_t channel, uint8_t *data, size_t size)
    {
        switch(channel)
        {
        case CHANNEL_DEFAULT:
        case CHANNEL_GENERIC_APP_BROADCAST:
        case CHANNEL_GENERIC_APP_BROADCAST_UNRELIABLE:
            std::cout<<"unhandled channel: "<<channel<<std::endl;
            break;
        case CHANNEL_GENERIC_APP_TO_SERVER:
            OnPacket[CHANNEL_GENERIC_APP_TO_SERVER][data[0]](cid, data, size);
            break;
        case CHANNEL_MIDDLE_TIER_CHAT:
            OnPacket[CHANNEL_MIDDLE_TIER_CHAT][EGP_Chat](cid, data, size);
            break;
        case CHANNEL_MIDDLE_TIER_ROSTER:
            OnPacket[CHANNEL_MIDDLE_TIER_ROSTER][data[0]](cid, data, size);
            break;
        default:
            std::cout<<"Unkown channel: "<<(uint32_t)channel<<std::endl;
            break;
        }
    }
public:
    NetServer()
    {
    }
    ~NetServer()
    {
        if(mHost != nullptr)
            enet_host_destroy(mHost);
    }
    bool start(GameInfo *gameinfo)
    {
        pGameInfo = gameinfo;
        mMax = gameinfo->getHumans();
        mAddress.host = gameinfo->address;
        mAddress.port = gameinfo->port;
        mHost = enet_host_create(&mAddress, 32, 0, 0);
        return mHost == nullptr;
    }
    bool host(uint32_t timeout = 0)
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
                if((uint64_t)(event.peer->data) > 0)
                {
                    mCount--;
                    mPeers[(uint64_t)(event.peer->data)] = 0;
                    OnDisconnected((uint64_t)(event.peer->data));
                }
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                if((uint64_t)(event.peer->data) > 0)
                {
                    if(event.channelID >= CHANNEL_NUM_TOTAL)
                        break;
                    if(event.packet->dataLength >= 8)
                        pGameInfo->blowfish.Decrypt(event.packet->data,
                                           event.packet->dataLength-(event.packet->dataLength%8));
                    OnNetworkPacket((uint64_t)(event.peer->data),
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

    bool sendPacketRaw(uint32_t cid, uint8_t *pkt, size_t size, uint8_t channel,
                       uint32_t flags = ENET_PACKET_FLAG_RELIABLE)
    {
        if(cid > mMax)
            return false;
        ENetPeer *peer = mPeers[cid];
        if(peer == nullptr)
            return false;
        std::cout<<"Sent packet with id:"<<(uint32_t)pkt[0]<<" on channel"<<(uint32_t)channel<<std::endl;
        ENetPacket *packet = enet_packet_create(pkt, size, flags);
        if(size >= 8)
            pGameInfo->blowfish.Encrypt(packet->data, size-(size%8));
        enet_peer_send(peer, channel, packet);
        return true;
    }

    void eachClient(std::function<void(uint32_t, ServerI*)> each)
    {
        for(auto p: mPeers)
            if(p.second != nullptr)
                each(p.first, this);
    }
private:
    bool handleAuth(ENetPeer *peer, ENetPacket *packet)
    {
        PKT_KeyCheck_s *pkt = (PKT_KeyCheck_s *) (packet->data);
        if(mCount > mMax )
            return false;
        if(packet->dataLength != sizeof(PKT_KeyCheck_s))
            return false;
        if(pGameInfo->blowfish.Decrypt(pkt->checkId) != pkt->playerID)
            return false;
        if(pGameInfo->blowfish.Encrypt(pkt->playerID) != pkt->checkId)
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
        //sendPacket(pkt->playerID, rpkt);
        sendPacketRaw(pkt->playerID, (uint8_t*) &rpkt, sizeof(rpkt), CHANNEL_DEFAULT, ENET_PACKET_FLAG_RELIABLE);
        OnConnected(pkt->playerID);
        return true;
    }
};

#endif // NetServer_H
