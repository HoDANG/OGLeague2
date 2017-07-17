#ifndef HPP_141_PKT_OnReplication_Acc_HPP
#define HPP_141_PKT_OnReplication_Acc_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_OnReplication_Acc_s : DefaultPacket<PKT_OnReplication_Acc>
{
    unsigned int syncID;
};
#pragma pack(pop)

#endif
