#ifndef HPP_034_PKT_NPC_Die_HPP
#define HPP_034_PKT_NPC_Die_HPP
#include "base.hpp"
#include "common/damageinfo.h"

#pragma pack(push, 1)
struct PKT_NPC_Die_s : DefaultPacket<PKT_NPC_Die>
{
    unsigned int killerNetID;
    DamageInfo info;
    float DeathDuration;
    bool becomeZombie;
};
#pragma pack(pop)

#endif
