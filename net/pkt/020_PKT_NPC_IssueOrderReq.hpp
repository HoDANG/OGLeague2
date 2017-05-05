#ifndef HPP_020_PKT_NPC_IssueOrderReq_HPP
#define HPP_020_PKT_NPC_IssueOrderReq_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_NPC_IssueOrderReq_s : DefaultPacket<PKT_NPC_IssueOrderReq>
{
    char order;
    float posX;
    float posY;
    float posZ;
    unsigned int targetNetID;
    uint8_t data[];
};
#pragma pack(pop)

#endif
