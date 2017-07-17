#ifndef HPP_038_PKT_NPC_BuffAdd2_HPP
#define HPP_038_PKT_NPC_BuffAdd2_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_BuffAdd2_s : DefaultPacket<PKT_NPC_BuffAdd2>
{
    char buffSlot;
    char buffType;
    char count;
    unsigned int buffNameHash;
    float runningTime;
    float duration;
    unsigned int casterNetID;
};
#pragma pack(pop)

#endif
