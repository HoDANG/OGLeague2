#ifndef HPP_055_PKT_Barrack_SpawnUnit_HPP
#define HPP_055_PKT_Barrack_SpawnUnit_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_Barrack_SpawnUnit_s : DefaultPacket<PKT_Barrack_SpawnUnit>
{
    uint32_t netObjID;
    int8_t netNodeID;
    int8_t waveCount;
    int8_t minionType;
    int16_t DamageBonus;
    int16_t HealthBonus;
};
#pragma pack(pop)

#endif
