#ifndef HPP_075_PKT_AI_TargetS2C_HPP
#define HPP_075_PKT_AI_TargetS2C_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_AI_TargetS2C_s : DefaultPacket<PKT_AI_TargetS2C>
{
    uint32_t mTargetID;
};
#pragma pack(pop)

#endif
