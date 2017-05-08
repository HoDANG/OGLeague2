#ifndef HPP_140_PKT_OnReplication_HPP
#define HPP_140_PKT_OnReplication_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_OnReplication_s : DefaultPacket<PKT_OnReplication>
{
    unsigned int syncID;
    char count;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct RepHeader
{
  uint8_t setMaps;
  unsigned int networkID;
};
#pragma pack(pop)

#endif
