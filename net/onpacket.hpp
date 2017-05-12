#ifndef ONPACKET_H
#define ONPACKET_H

#include "netserver.hpp"
#include "netbasepacket.hpp"

template<class PKT>
class OnPacket
{
protected:
    NetServer *pServer;
public:
    OnPacket(NetServer &server)
        : OnPacket(&server)
    {

    }

    OnPacket(NetServer *server)
    {
        pServer = server;
        pServer->OnPacket[PKT::CHANNEL][PKT::ID].connect(wink::slot<void(uint32_t, uint8_t*, size_t)>(this,
                                              (void(OnPacket<PKT>::*)(uint32_t, uint8_t*, size_t))(&OnPacket<PKT>::Handle)));
    }

    virtual ~OnPacket()
    {
        pServer->OnPacket[PKT::CHANNEL][PKT::ID].disconnect(wink::slot<void(uint32_t, uint8_t*, size_t)>(this,
                                               (void(OnPacket<PKT>::*)(uint32_t, uint8_t*, size_t))(&OnPacket<PKT>::Handle)));
    }

    virtual void Handle(uint32_t cid, PKT *pkt, size_t size)
    {
    }
};

#endif // ONPACKET_H
