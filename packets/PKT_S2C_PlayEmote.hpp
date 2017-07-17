#ifndef HPP_011_PKT_S2C_PlayEmote_HPP
#define HPP_011_PKT_S2C_PlayEmote_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_PlayEmote_s : DefaultPacket<PKT_S2C_PlayEmote>
{
    unsigned int mEmotId;
};
#pragma pack(pop)

#endif
