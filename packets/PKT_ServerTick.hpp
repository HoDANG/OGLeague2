#ifndef HPP_070_PKT_ServerTick_HPP
#define HPP_070_PKT_ServerTick_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_ServerTick_s : DefaultPacket<PKT_ServerTick>
{
    float delta;
};
#pragma pack(pop)

#endif
