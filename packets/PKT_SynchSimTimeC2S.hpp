#ifndef HPP_087_PKT_SynchSimTimeC2S_HPP
#define HPP_087_PKT_SynchSimTimeC2S_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SynchSimTimeC2S_s : DefaultPacket<PKT_SynchSimTimeC2S>
{
    unsigned int clientNetID;
    float time_LastServer;
    float time_LastClient;
};
#pragma pack(pop)

#endif
