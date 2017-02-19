#ifndef HPP_074_PKT_SynchVersionS2C_HPP
#define HPP_074_PKT_SynchVersionS2C_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_SynchVersionS2C_s : DefaultPacket<PKT_SynchVersionS2C>
{
    int8_t mIsVersionOk;
    int mMapToLoad;
    PlayerLiteInfo playerInfo[12];
    char mVersionString[256];
};
#pragma pack(pop)

#endif
