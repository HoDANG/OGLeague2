#ifndef HPP_009_PKT_S2C_PlayAnimation_HPP
#define HPP_009_PKT_S2C_PlayAnimation_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_PlayAnimation_s : DefaultPacket<PKT_S2C_PlayAnimation>
{
    unsigned int flags;
    float scaleTime;
    char animationName[64];
};
#pragma pack(pop)

#endif
