#ifndef HPP_181_PKT_ChangeSlotSpellName_HPP
#define HPP_181_PKT_ChangeSlotSpellName_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_ChangeSlotSpellName_s : DefaultPacket<PKT_ChangeSlotSpellName>
{
    int8_t slot : 7;
    int8_t isAvatarSpell : 1;
    char spellName[64];
};
#pragma pack(pop)

#endif
