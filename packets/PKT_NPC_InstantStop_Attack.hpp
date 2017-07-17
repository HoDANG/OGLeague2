#ifndef HPP_054_PKT_NPC_InstantStop_Attack_HPP
#define HPP_054_PKT_NPC_InstantStop_Attack_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_InstantStop_Attack_s : DefaultPacket<PKT_NPC_InstantStop_Attack>
{
    int8_t mKeepAnimating : 1;
    int8_t mForceSpellCast : 1;
    int8_t mForceStop : 1;
    int8_t mAvatarSpell : 1;
    int8_t mDestroyMissile : 1;
    int8_t PAD0 : 1;
    int8_t PAD1 : 1;
    int8_t PAD2 : 1;
};
#pragma pack(pop)

#endif
