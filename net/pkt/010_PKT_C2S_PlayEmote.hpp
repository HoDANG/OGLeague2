#ifndef HPP_010_PKT_C2S_PlayEmote_HPP
#define HPP_010_PKT_C2S_PlayEmote_HPP
#include "../base.h"
//1
#pragma pack(push, 1)
struct PKT_C2S_PlayEmote_s : DefaultPacket<PKT_C2S_PlayEmote>
{
    uint32_t mEmotId;
};
#pragma pack(pop)

#endif
