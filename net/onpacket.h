#ifndef ONPACKET_H
#define ONPACKET_H

#include "netpacketstream.hpp"
#include "netserver.hpp"
#include "netbasepacket.h"

template<class PKT>
struct OnPacket
{
    NetServer *pServer;
    OnPacket(NetServer &server) : OnPacket(&server) {

    }

    OnPacket(NetServer *server)
    {
        pServer = server;
        pServer->OnPacket[PKT::CHANNEL][PKT::ID].connect(wink::slot<void(uint32_t, std::vector<uint8_t>)>(this, &OnPacket<PKT>::HandlePacket));
    }

    virtual ~OnPacket()
    {
        pServer->OnPacket[PKT::CHANNEL][PKT::ID].disconnect(wink::slot<void(uint32_t, std::vector<uint8_t>)>(this, &OnPacket<PKT>::HandlePacket));
    }

    virtual void Handle(uint32_t cid, const NetPacketStream<PKT> &req)
    {

    }
    virtual void HandlePacket(uint32_t cid, std::vector<uint8_t> vec)
    {
        Handle(cid, NetPacketStream<PKT>(vec));
    }
};

#endif // ONPACKET_H
