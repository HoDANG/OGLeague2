#ifndef EGP_CHAT_H
#define EGP_CHAT_H

#include "../../dep/enet.hpp"
#include "../common/pkt_enums.h"
#include "../netbasepacket.h"
#include <inttypes.h>


struct EGP_Chat_s : public NetBasePacket<EGP_Chat,
        CHANNEL_MIDDLE_TIER_CHAT,
        ENET_PACKET_FLAG_RELIABLE>
{
    uint32_t cid;
    uint8_t chatType;
    uint32_t bufferLen;
    char buffer[512];
};

#endif // EGP_CHAT_H
