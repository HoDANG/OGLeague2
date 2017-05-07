#ifndef EGP_CHAT_H
#define EGP_CHAT_H

#include<inttypes.h>

struct EGP_Chat_s
{
    uint32_t cid;
    uint8_t chatType;
    uint32_t bufferLen;
    char buffer[512];
};

#endif // EGP_CHAT_H
