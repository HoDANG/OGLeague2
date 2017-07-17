#ifndef HPP_139_PKT_S2C_LockCamera_HPP
#define HPP_139_PKT_S2C_LockCamera_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_LockCamera_s : DefaultPacket<PKT_S2C_LockCamera>
{
    bool lock;
};
#pragma pack(pop)

#endif
