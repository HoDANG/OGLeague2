#ifndef NetServer_H
#define NetServer_H

#include <vector>
#include <map>
#include <array>
#include <memory>
#include <functional>
#include <iostream>
#include <type_traits>
#include "dep/enet.hpp"
#include "net/base.hpp"
#include "net/serveri.hpp"

class NetServer : public ServerI
{
protected:
private:
    uint32_t mMax = 0;
    uint32_t mCount = 1;
    ENetAddress mAddress;
    std::map<int, ENetPeer*> mPeers;
    ENetHost* mHost = nullptr;

    void OnNetworkPacket(uint32_t cid, uint8_t channel, uint8_t *data, size_t size);
public:
    NetServer();
    ~NetServer();
    bool start(GameInfo *gameinfo);
    bool host(uint32_t timeout = 0);

    bool sendPacketRaw(uint32_t cid, uint8_t *pkt, size_t size, uint8_t channel,
                       uint32_t flags = ENET_PACKET_FLAG_RELIABLE);

    void eachClient(std::function<void(uint32_t, ServerI*)> each);
private:
    bool handleAuth(ENetPeer *peer, ENetPacket *packet);
};

#endif // NetServer_H
