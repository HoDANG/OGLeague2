#ifndef HPP_131_PKT_Waypoint_Acc_HPP
#define HPP_131_PKT_Waypoint_Acc_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_Waypoint_Acc_s : DefaultPacket<PKT_Waypoint_Acc>
{
    int syncID;
    char teleportCount;
};
#pragma pack(pop)

#endif
