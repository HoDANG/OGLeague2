#ifndef HPP_005_PKT_S2C_StartSpawn_HPP
#define HPP_005_PKT_S2C_StartSpawn_HPP
#include "../base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_StartSpawn_s : DefaultPacket<PKT_S2C_StartSpawn>
{
    int8_t numbBotsOrder;
    int8_t numbBotsChaos;
};
#pragma pack(pop)

#endif
