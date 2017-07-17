#ifndef HPP_102_PKT_S2C_ShowHealthBar_HPP
#define HPP_102_PKT_S2C_ShowHealthBar_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_ShowHealthBar_s : DefaultPacket<PKT_S2C_ShowHealthBar>
{
    bool show;
};
#pragma pack(pop)

#endif
