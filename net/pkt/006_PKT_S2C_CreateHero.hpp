#ifndef HPP_006_PKT_S2C_CreateHero_HPP
#define HPP_006_PKT_S2C_CreateHero_HPP
#include "../base.h"
//1
#pragma pack(push, 1)
struct PKT_S2C_CreateHero_s : DefaultPacket<PKT_S2C_CreateHero>
{
    uint32_t netObjID;
    uint32_t playerUID;
    int8_t netNodeID;
    int8_t skillLevel;
    int8_t teamIsOrder;
    int8_t isBot;
    int8_t botRank;
    int8_t spawnPosIndex;
    int skinID;
    char Name[40];
    char Skin[40];
};
#pragma pack(pop)

#endif
