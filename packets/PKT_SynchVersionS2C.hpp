#ifndef HPP_074_PKT_SynchVersionS2C_HPP
#define HPP_074_PKT_SynchVersionS2C_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SynchVersionS2C_s
        : DefaultPacket<PKT_SynchVersionS2C, CHANNEL_GENERIC_APP_BROADCAST>
{
    int8_t mIsVersionOk;
    int mMapToLoad;
    PlayerLiteInfo playerInfo[12];
    char mVersionString[256];
    char mMapMode[128];
};
#pragma pack(pop)

#endif
