#ifndef HPP_135_PKT_S2C_ToggleInputLockingFlag_HPP
#define HPP_135_PKT_S2C_ToggleInputLockingFlag_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_ToggleInputLockingFlag_s : DefaultPacket<PKT_S2C_ToggleInputLockingFlag>
{
    unsigned int inputLockingFlags;
};
#pragma pack(pop)

#endif
