#ifndef HPP_053_PKT_NPC_LevelUp_HPP
#define HPP_053_PKT_NPC_LevelUp_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_LevelUp_s : DefaultPacket<PKT_NPC_LevelUp>
{
    char mLevel;
    char mAPoints;
};
#pragma pack(pop)

#endif
