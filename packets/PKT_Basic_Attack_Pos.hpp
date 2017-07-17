#ifndef HPP_060_PKT_Basic_Attack_Pos_HPP
#define HPP_060_PKT_Basic_Attack_Pos_HPP
#include "base.hpp"
#include "shared/commonbasicattack.h"

#pragma pack(push, 1)
struct PKT_Basic_Attack_Pos_s : DefaultPacket<PKT_Basic_Attack_Pos>
{
    CommonBasicAttack data;
    float pos[2];
};
#pragma pack(pop)

#endif
