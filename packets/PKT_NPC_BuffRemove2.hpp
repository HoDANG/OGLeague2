#ifndef HPP_042_PKT_NPC_BuffRemove2_HPP
#define HPP_042_PKT_NPC_BuffRemove2_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_BuffRemove2_s : DefaultPacket<PKT_NPC_BuffRemove2>
{
    char buffSlot;
    unsigned int buffNameHash;
};
#pragma pack(pop)

#endif
