#ifndef HPP_093_PKT_NPC_BuffUpdateCountGroup_HPP
#define HPP_093_PKT_NPC_BuffUpdateCountGroup_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_BuffUpdateCountGroup_s : DefaultPacket<PKT_NPC_BuffUpdateCountGroup>
{
    float duration;
    float runningTime;
    char numInGroup;
};
#pragma pack(pop)

#endif
