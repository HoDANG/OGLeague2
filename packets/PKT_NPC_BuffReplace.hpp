#ifndef HPP_040_PKT_NPC_BuffReplace_HPP
#define HPP_040_PKT_NPC_BuffReplace_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_BuffReplace_s : DefaultPacket<PKT_NPC_BuffReplace>
{
    char buffSlot;
    float runningTime;
    float duration;
    unsigned int casterNetID;
};
#pragma pack(pop)

#endif
