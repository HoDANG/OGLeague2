#ifndef HPP_171_PKT_S2C_Reconnect_HPP
#define HPP_171_PKT_S2C_Reconnect_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_S2C_Reconnect_s : DefaultPacket<PKT_S2C_Reconnect>
{
    uint32_t cid;
};
#pragma pack(pop)

#endif
