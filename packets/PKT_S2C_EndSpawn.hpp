#ifndef HPP_012_PKT_S2C_EndSpawn_HPP
#define HPP_012_PKT_S2C_EndSpawn_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_EndSpawn_s
        : DefaultPacket<PKT_S2C_EndSpawn, CHANNEL_GENERIC_APP_BROADCAST>
{
};
#pragma pack(pop)

#endif
