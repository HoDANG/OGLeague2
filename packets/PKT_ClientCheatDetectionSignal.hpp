#ifndef HPP_187_PKT_ClientCheatDetectionSignal_HPP
#define HPP_187_PKT_ClientCheatDetectionSignal_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_ClientCheatDetectionSignal_s : DefaultPacket<PKT_ClientCheatDetectionSignal>
{
    unsigned int m_Signal;
    unsigned int m_Flags;
};
#pragma pack(pop)

#endif
