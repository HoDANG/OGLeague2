#ifndef HPP_160_PKT_S2C_RefreshObjectiveText_HPP
#define HPP_160_PKT_S2C_RefreshObjectiveText_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_RefreshObjectiveText_s : DefaultPacket<PKT_S2C_RefreshObjectiveText>
{
    char textStringID[128];
};
#pragma pack(pop)

#endif
