#ifndef HPP_045_PKT_SetItem_HPP
#define HPP_045_PKT_SetItem_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SetItem_s : DefaultPacket<PKT_SetItem>
{
    char slot;
    unsigned int itemID;
    char itemsInSlot;
    char spellCharges;
};
#pragma pack(pop)

#endif
