#ifndef HPP_124_PKT_C2S_Ping_Load_Info_HPP
#define HPP_124_PKT_C2S_Ping_Load_Info_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_C2S_Ping_Load_Info_s : DefaultPacket<PKT_C2S_Ping_Load_Info>
{
    ConnectionInfo info;
};
#pragma pack(pop)

#endif
