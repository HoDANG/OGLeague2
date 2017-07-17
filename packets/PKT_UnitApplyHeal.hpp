#ifndef HPP_068_PKT_UnitApplyHeal_HPP
#define HPP_068_PKT_UnitApplyHeal_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_UnitApplyHeal_s : DefaultPacket<PKT_UnitApplyHeal>
{
    float maxHP;
    float heal;
};
#pragma pack(pop)

#endif
