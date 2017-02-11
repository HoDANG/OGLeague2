#ifndef HPP_176_PKT_Connected_HPP
#define HPP_176_PKT_Connected_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_Connected_s : DefaultPacket<PKT_Connected>
{
    uint32_t clientID;
};
#pragma pack(pop)

#endif
