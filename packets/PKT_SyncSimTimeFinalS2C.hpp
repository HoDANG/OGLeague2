#ifndef HPP_088_PKT_SyncSimTimeFinalS2C_HPP
#define HPP_088_PKT_SyncSimTimeFinalS2C_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SyncSimTimeFinalS2C_s : DefaultPacket<PKT_SyncSimTimeFinalS2C>
{
    float time_LastClient;
    float time_RTTlastoverhead;
    float time_convergence;
};
#pragma pack(pop)

#endif
