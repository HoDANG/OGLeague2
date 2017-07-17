#ifndef HPP_121_PKT_World_SendCamera_Server_Acknologment_HPP
#define HPP_121_PKT_World_SendCamera_Server_Acknologment_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_World_SendCamera_Server_Acknologment_s : DefaultPacket<PKT_World_SendCamera_Server_Acknologment>
{
    char syncID;
};
#pragma pack(pop)

#endif
