#ifndef PKT_BASE_H
#define PKT_BASE_H

#include <string>
#include <stdint.h>
#include <vector>
#include <sstream>
#include "../dep/buffer.hpp"
#include "../dep/enet.hpp"
#include "common/connectioninfo.h"
#include "common/playerliteinfo.h"
#include "common/pkt_enums.h"
#include "netbasepacket.h"
#include "netpacketstream.hpp"

//CHANNEL_MIDDLE_TIER_ROSTER
template<uint8_t ID,
         uint8_t CHANNEL = CHANNEL_MIDDLE_TIER_ROSTER,
         uint32_t FLAGS = ENET_PACKET_FLAG_RELIABLE>
struct DefaultPayload : public NetBasePacket<ID, CHANNEL, FLAGS>
{
    uint8_t type = ID;
};

//CHANNEL_GENERIC_APP_BROADCAST
#pragma pack(push, 1)
template<uint8_t ID,
         uint8_t CHANNEL = CHANNEL_DEFAULT,
         uint32_t FLAGS = ENET_PACKET_FLAG_RELIABLE>
struct DefaultPacket : public  NetBasePacket<ID, CHANNEL, FLAGS>
{
    uint8_t eventID = ID;
    uint32_t fromID;
};
#pragma pack(pop)

#endif // PKT_BASE_H
