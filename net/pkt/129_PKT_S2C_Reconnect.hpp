#ifndef HPP_129_PKT_S2C_Reconnect_HPP
#define HPP_129_PKT_S2C_Reconnect_HPP
#include "../base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_Reconnect_s
        : DefaultPacket<PKT_S2C_Reconnect, CHANNEL_GENERIC_APP_BROADCAST>
{
    uint32_t cid;
};
#pragma pack(pop)

#endif
