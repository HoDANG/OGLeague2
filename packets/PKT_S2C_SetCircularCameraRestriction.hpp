#ifndef HPP_138_PKT_S2C_SetCircularCameraRestriction_HPP
#define HPP_138_PKT_S2C_SetCircularCameraRestriction_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_SetCircularCameraRestriction_s : DefaultPacket<PKT_S2C_SetCircularCameraRestriction>
{
    r3dPoint3D center;
    float radius;
};
#pragma pack(pop)

#endif
