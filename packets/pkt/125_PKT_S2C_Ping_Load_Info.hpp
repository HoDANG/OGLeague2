#ifndef HPP_125_PKT_S2C_Ping_Load_Info_HPP
#define HPP_125_PKT_S2C_Ping_Load_Info_HPP
#include "../base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_Ping_Load_Info_s
        : DefaultPacket<PKT_S2C_Ping_Load_Info, CHANNEL_GENERIC_APP_BROADCAST>
{
    ConnectionInfo info;
};
#pragma pack(pop)

#endif
