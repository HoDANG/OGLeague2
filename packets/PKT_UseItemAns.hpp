#ifndef HPP_052_PKT_UseItemAns_HPP
#define HPP_052_PKT_UseItemAns_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_UseItemAns_s : DefaultPacket<PKT_UseItemAns>
{
    char slot;
    char itemsInSlot;
    char spellCharges;
};
#pragma pack(pop)

#endif
