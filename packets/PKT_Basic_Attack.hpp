#ifndef HPP_059_PKT_Basic_Attack_HPP
#define HPP_059_PKT_Basic_Attack_HPP
#include "base.hpp"
#include "shared/commonbasicattack.h"

#pragma pack(push, 1)
struct PKT_Basic_Attack_s : DefaultPacket<PKT_Basic_Attack>
{
    CommonBasicAttack data;
};
#pragma pack(pop)

#endif
