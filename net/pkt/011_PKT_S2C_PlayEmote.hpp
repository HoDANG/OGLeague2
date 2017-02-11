#ifndef HPP_011_PKT_S2C_PlayEmote_HPP
#define HPP_011_PKT_S2C_PlayEmote_HPP
#include "../base.h"
//1
#pragma pack(push, 1)
struct PKT_S2C_PlayEmote_s : DefaultPacket<PKT_S2C_PlayEmote>
{
    uint32_t mEmotId;
};
#pragma pack(pop)

#endif
