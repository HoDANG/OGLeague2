#ifndef HPP_167_PKT_S2C_Ping_Load_Info_HPP
#define HPP_167_PKT_S2C_Ping_Load_Info_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_S2C_Ping_Load_Info_s : DefaultPacket<PKT_S2C_Ping_Load_Info>
{
    ConnectionInfo info;
};
#pragma pack(pop)

#endif
