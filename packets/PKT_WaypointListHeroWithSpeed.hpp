#ifndef HPP_090_PKT_WaypointListHeroWithSpeed_HPP
#define HPP_090_PKT_WaypointListHeroWithSpeed_HPP
#include "base.hpp"
#include "shared/speedparams.h"

#pragma pack(push, 1)
struct PKT_WaypointListHeroWithSpeed_s : DefaultPacket<PKT_WaypointListHeroWithSpeed>
{
    int syncID;
    SpeedParms speedParams;
};
#pragma pack(pop)

#endif
