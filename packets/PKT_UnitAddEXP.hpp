#ifndef HPP_028_PKT_UnitAddEXP_HPP
#define HPP_028_PKT_UnitAddEXP_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_UnitAddEXP_s : DefaultPacket<PKT_UnitAddEXP>
{
    unsigned int targetNetID;
    float exp;
};
#pragma pack(pop)

#endif
