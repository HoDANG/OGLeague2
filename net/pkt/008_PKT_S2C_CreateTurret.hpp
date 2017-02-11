#ifndef HPP_008_PKT_S2C_CreateTurret_HPP
#define HPP_008_PKT_S2C_CreateTurret_HPP
#include "../base.h"
//1
#pragma pack(push, 1)
struct PKT_S2C_CreateTurret_s : DefaultPacket<PKT_S2C_CreateTurret>
{
    uint32_t netObjID;
    int8_t netNodeID;
    int8_t Name[64];
};
#pragma pack(pop)

#endif
