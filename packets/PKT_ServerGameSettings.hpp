#ifndef HPP_091_PKT_ServerGameSettings_HPP
#define HPP_091_PKT_ServerGameSettings_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_ServerGameSettings_s : DefaultPacket<PKT_ServerGameSettings>
{
    bool FoW_LocalCulling;
    bool FoW_BroadcastEverything;
};
#pragma pack(pop)

#endif
