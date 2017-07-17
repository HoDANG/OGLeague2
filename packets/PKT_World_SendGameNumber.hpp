#ifndef HPP_122_PKT_World_SendGameNumber_HPP
#define HPP_122_PKT_World_SendGameNumber_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_World_SendGameNumber_s : DefaultPacket<PKT_World_SendGameNumber>
{
    uint64_t gameID;
};
#pragma pack(pop)

#endif
