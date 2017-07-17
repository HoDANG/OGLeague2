#ifndef HPP_024_PKT_Pause_HPP
#define HPP_024_PKT_Pause_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_Pause_s : DefaultPacket<PKT_Pause>
{
    r3dPoint3D pos;
    r3dPoint3D forward;
    int syncID;
};
#pragma pack(pop)

#endif
