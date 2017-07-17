#ifndef HPP_097_PKT_RemovePerceptionBubble_HPP
#define HPP_097_PKT_RemovePerceptionBubble_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_RemovePerceptionBubble_s : DefaultPacket<PKT_RemovePerceptionBubble>
{
    unsigned int bubbleID;
};
#pragma pack(pop)

#endif
