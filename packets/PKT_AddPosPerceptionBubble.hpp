#ifndef HPP_099_PKT_AddPosPerceptionBubble_HPP
#define HPP_099_PKT_AddPosPerceptionBubble_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_AddPosPerceptionBubble_s : DefaultPacket<PKT_AddPosPerceptionBubble>
{
    int32_t perceptionBubbleType;
    uint32_t clientNetID;
    float radius;
    r3dPoint3D pos;
    float timeToLive;
    uint32_t bubbleID;
    uint32_t flags;
};
#pragma pack(pop)

#endif
