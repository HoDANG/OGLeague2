#ifndef PKT_BASE_H
#define PKT_BASE_H

#include <string>
#include <stdint.h>
#include <vector>
#include <sstream>
#include "r3d.hpp"
#include "enet.hpp"
#include "packets/shared/connectioninfo.hpp"
#include "packets/shared/playerliteinfo.hpp"
#include "packets/packetenums.hpp"
#include "net/basepacket.hpp"

//CHANNEL_MIDDLE_TIER_ROSTER
template<uint8_t TID,
         uint8_t TCHANNEL = CHANNEL_MIDDLE_TIER_ROSTER,
         uint32_t TFLAGS = ENET_PACKET_FLAG_RELIABLE>
struct DefaultPayload : public NetBasePacket<TID, TCHANNEL, TFLAGS>
{
    uint8_t type = TID;
};

//CHANNEL_GENERIC_APP_BROADCAST
#pragma pack(push, 1)
template<uint8_t TID,
         uint8_t TCHANNEL = CHANNEL_GENERIC_APP_TO_SERVER,
         uint32_t TFLAGS = ENET_PACKET_FLAG_RELIABLE>
struct DefaultPacket : public  NetBasePacket<TID, TCHANNEL, TFLAGS>
{
    uint8_t eventID = TID;
    uint32_t fromID;
};
#pragma pack(pop)

#endif // PKT_BASE_H
