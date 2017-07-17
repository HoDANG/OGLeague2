#ifndef HPP_044_PKT_NPC_SetAutocast_HPP
#define HPP_044_PKT_NPC_SetAutocast_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_SetAutocast_s : DefaultPacket<PKT_NPC_SetAutocast>
{
    char slot;
};
#pragma pack(pop)

#endif
