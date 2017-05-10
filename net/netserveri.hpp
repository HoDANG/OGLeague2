#ifndef NETSERVERI_H
#define NETSERVERI_H

#include <vector>
#include <inttypes.h>

struct NetServerI
{
    virtual bool sendPacketRaw(uint32_t cid,
                               uint8_t *pkt, size_t size,
                               uint8_t channel, uint32_t flags)
    {
        return true;
    }
};

#endif // NETSERVERI_H
