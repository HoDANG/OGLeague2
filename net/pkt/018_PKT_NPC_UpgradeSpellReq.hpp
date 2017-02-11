#ifndef HPP_018_PKT_NPC_UpgradeSpellReq_HPP
#define HPP_018_PKT_NPC_UpgradeSpellReq_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_NPC_UpgradeSpellReq_s : DefaultPacket<PKT_NPC_UpgradeSpellReq>
{
    int8_t slot;
};
#pragma pack(pop)

#endif
