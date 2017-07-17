#ifndef HPP_114_PKT_S2C_ChainMissileSync_HPP
#define HPP_114_PKT_S2C_ChainMissileSync_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_ChainMissileSync_s : DefaultPacket<PKT_S2C_ChainMissileSync>
{
    int size;
    unsigned int ownerNetworkID;
    unsigned int targets[32];
};
#pragma pack(pop)

#endif
