#ifndef HPP_142_PKT_S2C_MoveCameraToPoint_HPP
#define HPP_142_PKT_S2C_MoveCameraToPoint_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_MoveCameraToPoint_s : DefaultPacket<PKT_S2C_MoveCameraToPoint>
{
    int8_t bStartAtCurrentCameraPosition : 1;
    r3dPoint3D startPosition;
    r3dPoint3D targetPosition;
    float travelTime;
};
#pragma pack(pop)

#endif
