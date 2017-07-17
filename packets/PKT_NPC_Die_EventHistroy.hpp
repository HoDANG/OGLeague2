#ifndef HPP_123_PKT_NPC_Die_EventHistroy_HPP
#define HPP_123_PKT_NPC_Die_EventHistroy_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_Die_EventHistroy_s : DefaultPacket<PKT_NPC_Die_EventHistroy>
{
    unsigned int killerNetID;
    float timeWindow;
    int32_t killerEventSourceType : 4;
};
#pragma pack(pop)

#endif
