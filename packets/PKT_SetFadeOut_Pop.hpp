#ifndef HPP_149_PKT_SetFadeOut_Pop_HPP
#define HPP_149_PKT_SetFadeOut_Pop_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SetFadeOut_Pop_s : DefaultPacket<PKT_SetFadeOut_Pop>
{
    int16_t id;
};
#pragma pack(pop)

#endif
