#ifndef HPP_030_PKT_NPC_MessageToClient_HPP
#define HPP_030_PKT_NPC_MessageToClient_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_NPC_MessageToClient_s : DefaultPacket<PKT_NPC_MessageToClient>
{
    unsigned int targetNetID;
    float bubbleDelay;
    int slotNum;
    char isError;
    char colorIndex;
    char message[1024];
};
#pragma pack(pop)

#endif
