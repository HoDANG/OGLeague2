#ifndef HPP_004_PKT_S2C_QueryStatusAns_HPP
#define HPP_004_PKT_S2C_QueryStatusAns_HPP
#include "../base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_QueryStatusAns_s
        : DefaultPacket<PKT_S2C_QueryStatusAns, CHANNEL_DEFAULT>
{
    int8_t res;
};
#pragma pack(pop)

#endif
