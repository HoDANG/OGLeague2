#ifndef HPP_150_PKT_S2C_CreateUnitHighlight_HPP
#define HPP_150_PKT_S2C_CreateUnitHighlight_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_CreateUnitHighlight_s : DefaultPacket<PKT_S2C_CreateUnitHighlight>
{
    unsigned int unitNetworkID;
};
#pragma pack(pop)

#endif
