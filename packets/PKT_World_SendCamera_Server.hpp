#ifndef HPP_065_PKT_World_SendCamera_Server_HPP
#define HPP_065_PKT_World_SendCamera_Server_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_World_SendCamera_Server_s : DefaultPacket<PKT_World_SendCamera_Server>
{
    r3dPoint3D cameraPosOnGround;
    unsigned int clientID;
    char syncID;
};
#pragma pack(pop)

#endif
