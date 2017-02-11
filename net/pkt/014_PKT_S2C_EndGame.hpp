#ifndef HPP_014_PKT_S2C_EndGame_HPP
#define HPP_014_PKT_S2C_EndGame_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_S2C_EndGame_s : DefaultPacket<PKT_S2C_EndGame>
{
    int8_t teamIsOrder;
    bool surrender;
};
#pragma pack(pop)

#endif
