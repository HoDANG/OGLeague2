#ifndef HPP_151_PKT_S2C_RemoveUnitHighlight_HPP
#define HPP_151_PKT_S2C_RemoveUnitHighlight_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_RemoveUnitHighlight_s : DefaultPacket<PKT_S2C_RemoveUnitHighlight>
{
    unsigned int unitNetworkID;
};
#pragma pack(pop)

#endif
