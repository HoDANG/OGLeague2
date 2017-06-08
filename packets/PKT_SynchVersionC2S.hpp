#ifndef HPP_073_PKT_SynchVersionC2S_HPP
#define HPP_073_PKT_SynchVersionC2S_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SynchVersionC2S_s
        : DefaultPacket<PKT_SynchVersionC2S,CHANNEL_GENERIC_APP_TO_SERVER>
{
    float mTime_LastClient;
    uint32_t mClientNetID;
    char mVersionString[256];
};
#pragma pack(pop)

#endif
