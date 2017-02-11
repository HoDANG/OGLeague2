#ifndef NetServer_H
#define NetServer_H

#include <vector>
#include <map>
#include <array>
#include <memory>
#include "../dep/enet.hpp"
#include "../dep/blowfish.hpp"
#include "base.h"
#include "netclient.h"

class NetServer
{
private:
    uint32_t mMax;
    uint32_t mCount;
    ENetAddress mAddress;
    std::array<ENetPeer*, 13> mPeers;
    std::unique_ptr<BlowFish> mBlowFish;
    ENetHost* mHost;
    NetClient *pClient;

    bool handleAuth(ENetPeer *peer, ENetPacket *packet);
public:
    NetServer(NetClient *client, uint32_t address, uint16_t port, std::string key, uint32_t maxclients);
    ~NetServer();
    bool start();
    bool host(uint32_t timeout = 0);

    template<class PKT>
    void sendPacket(uint32_t cid, PKT &pkt,
                    uint8_t channel = CHANNEL_GENERIC_APP_BROADCAST,
                    uint32_t flags = ENET_PACKET_FLAG_RELIABLE);
    void sendPacket(uint32_t cid, uint8_t *pkt, size_t size,
                    uint8_t channel = CHANNEL_GENERIC_APP_BROADCAST,
                    uint32_t flags = ENET_PACKET_FLAG_RELIABLE);

};

#endif // NetServer_H
