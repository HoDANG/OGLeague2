#ifndef HPP_004_PKT_S2C_QueryStatusAns_HPP
#define HPP_004_PKT_S2C_QueryStatusAns_HPP
#include "../base.h"
//1
#pragma pack(push, 1)
struct PKT_S2C_QueryStatusAns_s : DefaultPacket<PKT_S2C_QueryStatusAns>
{
    int8_t res;
};
#pragma pack(pop)

#endif
