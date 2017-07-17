#ifndef HPP_170_PKT_S2C_LineMissileHitList_HPP
#define HPP_170_PKT_S2C_LineMissileHitList_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_LineMissileHitList_s : DefaultPacket<PKT_S2C_LineMissileHitList>
{
    int16_t size;
};
#pragma pack(pop)

#endif
