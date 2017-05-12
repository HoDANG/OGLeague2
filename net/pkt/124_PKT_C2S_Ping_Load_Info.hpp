#ifndef HPP_124_PKT_C2S_Ping_Load_Info_HPP
#define HPP_124_PKT_C2S_Ping_Load_Info_HPP
#include "../base.hpp"

#pragma pack(push, 1)
struct PKT_C2S_Ping_Load_Info_s
        : DefaultPacket<PKT_C2S_Ping_Load_Info,CHANNEL_GENERIC_APP_TO_SERVER>
{
    ConnectionInfo info;
};
#pragma pack(pop)

#endif
