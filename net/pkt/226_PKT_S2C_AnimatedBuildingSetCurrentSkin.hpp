#ifndef HPP_226_PKT_S2C_AnimatedBuildingSetCurrentSkin_HPP
#define HPP_226_PKT_S2C_AnimatedBuildingSetCurrentSkin_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_S2C_AnimatedBuildingSetCurrentSkin_s : DefaultPacket<PKT_S2C_AnimatedBuildingSetCurrentSkin>
{
    uint8_t team;
    uint32_t skinID;
};
#pragma pack(pop)

#endif
