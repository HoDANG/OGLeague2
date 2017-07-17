#ifndef HPP_118_PKT_S2C_AI_State_HPP
#define HPP_118_PKT_S2C_AI_State_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_AI_State_s : DefaultPacket<PKT_S2C_AI_State>
{
    int mStateID;
};
#pragma pack(pop)

#endif
