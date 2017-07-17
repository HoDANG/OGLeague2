#ifndef HPP_156_PKT_S2C_SetInputLockingFlag_HPP
#define HPP_156_PKT_S2C_SetInputLockingFlag_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_SetInputLockingFlag_s : DefaultPacket<PKT_S2C_SetInputLockingFlag>
{
    unsigned int inputLockingFlags;
    bool flagValue;
};
#pragma pack(pop)

#endif
