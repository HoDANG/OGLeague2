#ifndef HPP_147_PKT_SetFrequency_HPP
#define HPP_147_PKT_SetFrequency_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SetFrequency_s : DefaultPacket<PKT_SetFrequency>
{
    float newFrequency;
};
#pragma pack(pop)

#endif
