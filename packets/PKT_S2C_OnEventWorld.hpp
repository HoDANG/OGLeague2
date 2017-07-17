#ifndef HPP_177_PKT_S2C_OnEventWorld_HPP
#define HPP_177_PKT_S2C_OnEventWorld_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_OnEventWorld_s : DefaultPacket<PKT_S2C_OnEventWorld>
{
    char eventNameID;
    unsigned int sourceNetworkID;
    unsigned int mOtherNetworkID;
};
#pragma pack(pop)

#endif
