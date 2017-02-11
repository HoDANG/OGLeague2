#ifndef HPP_009_PKT_S2C_PlayAnimation_HPP
#define HPP_009_PKT_S2C_PlayAnimation_HPP
#include "../base.h"
//1
#pragma pack(push, 1)
struct PKT_S2C_PlayAnimation_s : DefaultPacket<PKT_S2C_PlayAnimation>
{
    uint32_t flags;
    float scaleTime;
    int8_t animationName[64];
};
#pragma pack(pop)

#endif
