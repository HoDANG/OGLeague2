#ifndef HPP_133_PKT_WaypointGroupWithSpeed_HPP
#define HPP_133_PKT_WaypointGroupWithSpeed_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_WaypointGroupWithSpeed_s : DefaultPacket<PKT_WaypointGroupWithSpeed>
{
    int syncID;
    int16_t numbPaths;
};
#pragma pack(pop)

#endif
