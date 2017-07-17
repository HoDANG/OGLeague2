#ifndef HPP_092_PKT_NPC_BuffUpdateCount_HPP
#define HPP_092_PKT_NPC_BuffUpdateCount_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_BuffUpdateCount_s : DefaultPacket<PKT_NPC_BuffUpdateCount>
{
    char buffSlot;
    char count;
    float duration;
    float runningTime;
    unsigned int casterNetID;
};
#pragma pack(pop)

#endif
