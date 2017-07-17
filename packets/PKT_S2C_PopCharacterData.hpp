#ifndef HPP_105_PKT_S2C_PopCharacterData_HPP
#define HPP_105_PKT_S2C_PopCharacterData_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_PopCharacterData_s : DefaultPacket<PKT_S2C_PopCharacterData>
{
    unsigned int id;
};
#pragma pack(pop)

#endif
