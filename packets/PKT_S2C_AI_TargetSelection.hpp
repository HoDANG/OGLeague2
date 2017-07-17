#ifndef HPP_117_PKT_S2C_AI_TargetSelection_HPP
#define HPP_117_PKT_S2C_AI_TargetSelection_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_AI_TargetSelection_s : DefaultPacket<PKT_S2C_AI_TargetSelection>
{
    unsigned int mTargetIDs[5];
};
#pragma pack(pop)

#endif
