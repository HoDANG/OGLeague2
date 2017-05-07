#ifndef ONPACKET_H
#define ONPACKET_H

#include "netserver.h"

template<uint32_t ID, class PKT>
struct OnPacket
{
    NetServer *pServer;
    OnPacket(NetServer &server) : OnPacket(&server){

    }

    OnPacket(NetServer *server)
    {
        pServer = server;
        pServer->OnPacket[ID].connect(wink::slot<void(uint32_t, uint8_t*, size_t)>(this,
        (void(OnPacket<ID,PKT>::*)(uint32_t, uint8_t*, size_t))(&OnPacket<ID, PKT>::Handle)));
    }

    virtual ~OnPacket()
    {
        pServer->OnPacket[ID].disconnect(wink::slot<void(uint32_t, uint8_t*, size_t)>(this,
        (void(OnPacket<ID,PKT>::*)(uint32_t, uint8_t*, size_t))(&OnPacket<ID, PKT>::Handle)));
    }

    virtual void Handle(uint32_t cid, PKT *pkt, size_t size)
    {

    }
};

template<uint32_t ID, class PKT>
struct OnPayload
{
    NetServer *pServer;
    OnPayload(NetServer &server) : OnPayload(&server) {

    }

    OnPayload(NetServer *server)
    {
        pServer = server;
        pServer->OnPayload[ID].connect(wink::slot<void(uint32_t, uint8_t*, size_t)>(this,
        (void(OnPayload<ID,PKT>::*)(uint32_t, uint8_t*, size_t))(&OnPayload<ID, PKT>::Handle)));
    }

    virtual ~OnPayload()
    {
        pServer->OnPayload[ID].disconnect(wink::slot<void(uint32_t, uint8_t*, size_t)>(this,
        (void(OnPayload<ID,PKT>::*)(uint32_t, uint8_t*, size_t))(&OnPayload<ID, PKT>::Handle)));
    }

    virtual void Handle(uint32_t cid, PKT *pkt, size_t size)
    {

    }
};


#endif // ONPACKET_H
