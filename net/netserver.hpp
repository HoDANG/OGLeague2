#ifndef NetServer_H
#define NetServer_H

#include <vector>
#include <map>
#include <array>
#include <memory>
#include <functional>
#include <iostream>
#include <type_traits>
#include "base.hpp"
#include "../dep/enet.hpp"
#include "../dep/blowfish.hpp"
#include "../dep/wink.hpp"
#include "netserveri.h"
#include "netpacketstream.hpp"

class NetServer
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
    uint32_t mMax;
    uint32_t mCount;
    ENetAddress mAddress;
    std::array<ENetPeer*, 13> mPeers;
    std::unique_ptr<BlowFish> mBlowFish;
    ENetHost* mHost;

    void OnNetworkPacket(uint32_t cid, uint8_t channel, uint8_t *data, size_t size)
    {
        std::vector<uint8_t> paket(data, data+size);
        switch(channel)
        {
        case CHANNEL_DEFAULT:
        case CHANNEL_GENERIC_APP_BROADCAST_UNRELIABLE:
        case CHANNEL_GENERIC_APP_BROADCAST:
        case CHANNEL_GENERIC_APP_TO_SERVER:
            OnPacket[CHANNEL_DEFAULT][data[0]](cid, paket);
            break;
        case CHANNEL_MIDDLE_TIER_CHAT:
            OnPacket[CHANNEL_MIDDLE_TIER_CHAT][EGP_Chat](cid, paket);
            break;
        case CHANNEL_MIDDLE_TIER_ROSTER:
            OnPacket[CHANNEL_MIDDLE_TIER_ROSTER][data[0]](cid, paket);
            break;
        default:
            std::cout<<"Unkown channel: "<<(uint32_t)channel<<std::endl;
            break;
        }
    }
public:
    NetServer(uint32_t address, uint16_t port, std::string key, uint32_t maxclients) :
        mBlowFish(std::make_unique<BlowFish>((uint8_t*)(key.c_str()), 16)),
        mMax(maxclients+1), mHost(nullptr), mCount(1),
        mAddress()
    {
        mAddress.host = address;
        mAddress.port = port;
        for(int i=0;i<13;i++)
            mPeers[i] = nullptr;
    }
    ~NetServer()
    {
        if(mHost != nullptr)
            enet_host_destroy(mHost);
    }
    bool start()
    {
        if(mHost != nullptr)
            return false;
        mHost = enet_host_create(&mAddress,32,0,0);
        if(mHost == nullptr)
            return false;
        return true;
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

    bool sendPacketRaw(uint32_t cid,
                       uint8_t *pkt, size_t size,
                       uint8_t channel = CHANNEL_GENERIC_APP_BROADCAST,
                       uint32_t flags = ENET_PACKET_FLAG_RELIABLE)
    {
        if(cid>mMax || cid>12)
            return false;
        ENetPeer *peer = mPeers[cid];
        if(peer == nullptr)
            return false;
        uint8_t *data = new uint8_t[size];
        memcpy(data, pkt, size);
        if(size >= 8)
            mBlowFish->Encrypt(data, size-(size%8));
        ENetPacket *packet = enet_packet_create(data, size, flags);
        enet_peer_send(peer, channel, packet);
        delete[] data;
        return true;
    }

    template<typename PKT>
    bool sendPacketStream(uint32_t cid, NetPacketStream<PKT> stream)
    {
        std::vector<uint8_t> data((uint8_t*)&stream, (uint8_t*)&stream + sizeof(PKT));
        stream > data;
        sendPacketRaw(cid, &data[0], data.size(), PKT::CHANNEL, PKT::FLAGS);
    }

    template<typename PKT>
    bool sendPacket(uint32_t cid, PKT pkt)
    {
        std::vector<uint8_t> data((uint8_t*)&pkt, (uint8_t*)&pkt + sizeof(PKT));
        sendPacketRaw(cid, &data[0], data.size(), PKT::CHANNEL, PKT::FLAGS);
    }



    wink::signal<wink::slot<void(uint32_t, std::vector<uint8_t>)>> OnPacket[7][256];
    wink::signal<std::function<void(uint32_t cid)>> OnConnected;
    wink::signal<std::function<void(uint32_t cid)>> OnDisconnected;
private:
    bool handleAuth(ENetPeer *peer, ENetPacket *packet)
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
        //sendPacket(pkt->playerID, rpkt);
        sendPacketRaw(pkt->playerID, (uint8_t*) &rpkt, sizeof(rpkt), CHANNEL_DEFAULT, ENET_PACKET_FLAG_RELIABLE);
        OnConnected(pkt->playerID);
        return true;
    }
};

#endif // NetServer_H
