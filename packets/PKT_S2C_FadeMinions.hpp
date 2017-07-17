#ifndef HPP_183_PKT_S2C_FadeMinions_HPP
#define HPP_183_PKT_S2C_FadeMinions_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_FadeMinions_s : DefaultPacket<PKT_S2C_FadeMinions>
{
    char team;
    float fadeAmount;
    float fadeTime;
};
#pragma pack(pop)

#endif
