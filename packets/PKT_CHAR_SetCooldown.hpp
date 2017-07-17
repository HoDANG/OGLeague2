#ifndef HPP_033_PKT_CHAR_SetCooldown_HPP
#define HPP_033_PKT_CHAR_SetCooldown_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_CHAR_SetCooldown_s : DefaultPacket<PKT_CHAR_SetCooldown>
{
    int8_t slot : 7;
    int8_t isAvatarSpell : 1;
    float cooldown;
};
#pragma pack(pop)

#endif
