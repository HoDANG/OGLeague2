#ifndef HPP_148_PKT_SetFadeOut_Push_HPP
#define HPP_148_PKT_SetFadeOut_Push_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SetFadeOut_Push_s : DefaultPacket<PKT_SetFadeOut_Push>
{
    int16_t id;
    float fadeTime;
    float fadeTargetValue;
};
#pragma pack(pop)

#endif
