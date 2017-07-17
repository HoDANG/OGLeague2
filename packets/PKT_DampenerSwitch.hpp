#ifndef HPP_071_PKT_DampenerSwitch_HPP
#define HPP_071_PKT_DampenerSwitch_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_DampenerSwitch_s : DefaultPacket<PKT_DampenerSwitch>
{
    uint32_t newState;
    unsigned int duration;
};
#pragma pack(pop)

#endif
