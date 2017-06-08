#ifndef HPP_061_PKT_OnEnterVisiblityClient_HPP
#define HPP_061_PKT_OnEnterVisiblityClient_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_OnEnterVisiblityClient_s
        : DefaultPacket<PKT_OnEnterVisiblityClient, CHANNEL_GENERIC_APP_BROADCAST>
{
};
#pragma pack(pop)

#endif
