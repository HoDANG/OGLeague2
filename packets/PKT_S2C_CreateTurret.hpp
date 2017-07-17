#ifndef HPP_008_PKT_S2C_CreateTurret_HPP
#define HPP_008_PKT_S2C_CreateTurret_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_CreateTurret_s : DefaultPacket<PKT_S2C_CreateTurret>
{
    unsigned int netObjID;
    char netNodeID;
    char Name[64];
};
#pragma pack(pop)

#endif
