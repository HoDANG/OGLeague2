#ifndef HPP_069_PKT_MissileReplication_HPP
#define HPP_069_PKT_MissileReplication_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_MissileReplication_s : DefaultPacket<PKT_MissileReplication>
{
    r3dPoint3D position;
    r3dPoint3D casterPos;
    r3dPoint3D direction;
    r3dPoint3D velocity;
    r3dPoint3D endPoint;
    r3dPoint3D unitPos;
    float speed;
    bool bounced;
    char castInfoBuf[512];
};
#pragma pack(pop)

#endif
