#ifndef HPP_047_PKT_BuyItemAns_HPP
#define HPP_047_PKT_BuyItemAns_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_BuyItemAns_s : DefaultPacket<PKT_BuyItemAns>
{
    char slot;
    unsigned int itemID;
    char itemsInSlot;
    char useOnBought;
};
#pragma pack(pop)

#endif
