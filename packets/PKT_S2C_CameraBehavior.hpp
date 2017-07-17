#ifndef HPP_108_PKT_S2C_CameraBehavior_HPP
#define HPP_108_PKT_S2C_CameraBehavior_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_CameraBehavior_s : DefaultPacket<PKT_S2C_CameraBehavior>
{
    r3dPoint3D position;
};
#pragma pack(pop)

#endif
