#ifndef HPP_119_PKT_OnEvent_HPP
#define HPP_119_PKT_OnEvent_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_OnEvent_s : DefaultPacket<PKT_OnEvent>
{
    char eventNameID;
    uint32_t mOtherNetworkID;
};
#pragma pack(pop)

#endif
