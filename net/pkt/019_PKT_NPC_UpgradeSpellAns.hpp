#ifndef HPP_019_PKT_NPC_UpgradeSpellAns_HPP
#define HPP_019_PKT_NPC_UpgradeSpellAns_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_NPC_UpgradeSpellAns_s : DefaultPacket<PKT_NPC_UpgradeSpellAns>
{
    int8_t slot;
    int8_t spellLevel;
    int8_t spellTrainingPoints;
};
#pragma pack(pop)

#endif
