#ifndef HPP_036_PKT_NPC_CastSpellReq_HPP
#define HPP_036_PKT_NPC_CastSpellReq_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_CastSpellReq_s : DefaultPacket<PKT_NPC_CastSpellReq>
{
    int8_t isAvatarSlot : 1;
    int8_t slot : 7;
    r3dPoint3D pos;
    r3dPoint3D endPos;
    unsigned int targetNetID;
};
#pragma pack(pop)

#endif
