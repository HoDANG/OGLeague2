#ifndef NETBASEPACKET_H
#define NETBASEPACKET_H

#include <vector>
#include <stdint.h>
#include <sstream>
#include "netserveri.hpp"

template <uint8_t TID, uint8_t TCHAN, uint32_t TFLAGS>
struct NetBasePacket
{
    static constexpr   uint8_t ID = TID;
    static constexpr   uint8_t CHANNEL = TCHAN;
    static constexpr   uint32_t FLAGS = TFLAGS;
};


#endif // NETBASEPACKET_H
