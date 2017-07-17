#ifndef HPP_134_PKT_Connected_HPP
#define HPP_134_PKT_Connected_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_Connected_s : DefaultPacket<PKT_Connected>
{
    unsigned int clientID;
};
#pragma pack(pop)

#endif
