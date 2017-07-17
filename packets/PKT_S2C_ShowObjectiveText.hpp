#ifndef HPP_158_PKT_S2C_ShowObjectiveText_HPP
#define HPP_158_PKT_S2C_ShowObjectiveText_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_ShowObjectiveText_s : DefaultPacket<PKT_S2C_ShowObjectiveText>
{
    char textStringID[128];
};
#pragma pack(pop)

#endif
