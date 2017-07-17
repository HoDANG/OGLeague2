#ifndef HPP_144_PKT_ChangeSlotSpellType_HPP
#define HPP_144_PKT_ChangeSlotSpellType_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_ChangeSlotSpellType_s : DefaultPacket<PKT_ChangeSlotSpellType>
{
    int8_t slot : 7;
    int8_t isAvatarSpell : 1;
    int8_t targeting;
};
#pragma pack(pop)

#endif
