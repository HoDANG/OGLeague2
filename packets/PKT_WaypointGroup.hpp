#ifndef HPP_132_PKT_WaypointGroup_HPP
#define HPP_132_PKT_WaypointGroup_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_WaypointGroup_s : DefaultPacket<PKT_WaypointGroup>
{
    int syncID;
    int16_t numbPaths;
};
#pragma pack(pop)

#endif
