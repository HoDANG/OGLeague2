#ifndef HPP_007_PKT_S2C_CreateNeutral_HPP
#define HPP_007_PKT_S2C_CreateNeutral_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_CreateNeutral_s : DefaultPacket<PKT_S2C_CreateNeutral>
{
    unsigned int netObjID;
    char netNodeID;
    r3dPoint3D pos;
    r3dPoint3D groupPos;
    r3dPoint3D facePos;
    char Name[64];
    char SkinName[64];
    char UniqueName[64];
    int Team;
    int DamageBonus;
    int HealthBonus;
    int RoamState;
    int GroupNumber;
    int16_t CampLevel;
};
#pragma pack(pop)

#endif
