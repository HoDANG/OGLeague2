#ifndef HPP_098_PKT_AddUnitPerceptionBubble_HPP
#define HPP_098_PKT_AddUnitPerceptionBubble_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_AddUnitPerceptionBubble_s : DefaultPacket<PKT_AddUnitPerceptionBubble>
{
    int perceptionBubbleType;
    uint32_t clientNetID;
    float radius;
    uint32_t unitNetID;
    float timeToLive;
    uint32_t bubbleID;
    uint32_t flags;
};
#pragma pack(pop)

#endif
