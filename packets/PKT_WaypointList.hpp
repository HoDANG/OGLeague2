#ifndef HPP_089_PKT_WaypointList_HPP
#define HPP_089_PKT_WaypointList_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_WaypointList_s : DefaultPacket<PKT_WaypointList>
{
    int syncID;
};
#pragma pack(pop)

#endif
