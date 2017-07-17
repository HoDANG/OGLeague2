#ifndef HPP_037_PKT_NPC_CastSpellAns_HPP
#define HPP_037_PKT_NPC_CastSpellAns_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_CastSpellAns_s : DefaultPacket<PKT_NPC_CastSpellAns>
{
    int casterPosSyncID;
};
#pragma pack(pop)

#endif
