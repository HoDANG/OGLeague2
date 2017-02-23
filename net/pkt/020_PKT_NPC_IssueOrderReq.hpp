#ifndef HPP_020_PKT_NPC_IssueOrderReq_HPP
#define HPP_020_PKT_NPC_IssueOrderReq_HPP

#include "../base.h"
#pragma pack(push, 1)
struct PKT_NPC_IssueOrderReq_s : DefaultPacket<PKT_NPC_IssueOrderReq>
{
/*
14
01 00 00 40
02          order
0c b2 3d 44 posX
d8 63 3a 43 posY
f2 23 8a 43 posZ
00 00 00 00 targetNetID
b0 ef 03 00
01 00 00 40
0b 76 f2 f7
f1 64 32 bb
f3 32
*/
    char order;
    float posX;
    float posY;
    float posZ;
    unsigned int targetNetID;
    uint8_t data[];
};
#pragma pack(pop)

#endif
