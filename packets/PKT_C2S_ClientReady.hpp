#ifndef HPP_016_PKT_C2S_ClientReady_HPP
#define HPP_016_PKT_C2S_ClientReady_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_C2S_ClientReady_s
        : DefaultPacket<PKT_C2S_ClientReady,CHANNEL_GENERIC_APP_TO_SERVER>
{
};
#pragma pack(pop)

#endif
