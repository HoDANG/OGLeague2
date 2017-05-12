#ifndef HPP_013_PKT_S2C_StartGame_HPP
#define HPP_013_PKT_S2C_StartGame_HPP
#include "../base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_StartGame_s
        : DefaultPacket<PKT_S2C_StartGame, CHANNEL_GENERIC_APP_BROADCAST>
{
};
#pragma pack(pop)

#endif
