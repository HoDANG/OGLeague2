#ifndef HPP_188_PKT_S2C_AddDebugCircle_HPP
#define HPP_188_PKT_S2C_AddDebugCircle_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_AddDebugCircle_s : DefaultPacket<PKT_S2C_AddDebugCircle>
{
    int id;
    unsigned int unitNetworkID;
    r3dPoint3D center;
    float radius;
    r3dColor color;
};
#pragma pack(pop)

#endif
