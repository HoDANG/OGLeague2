#ifndef HPP_023_PKT_UnitApplyDamage_HPP
#define HPP_023_PKT_UnitApplyDamage_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_UnitApplyDamage_s : DefaultPacket<PKT_UnitApplyDamage>
{
    int8_t type : 7;
    int8_t hasAttackSound : 1;
    unsigned int targetNetID;
    unsigned int sourceNetID;
    float damage;
};
#pragma pack(pop)

#endif
