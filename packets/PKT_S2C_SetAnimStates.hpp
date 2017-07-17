#ifndef HPP_186_PKT_S2C_SetAnimStates_HPP
#define HPP_186_PKT_S2C_SetAnimStates_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_SetAnimStates_s : DefaultPacket<PKT_S2C_SetAnimStates>
{
    char numb;
};
#pragma pack(pop)

#endif
