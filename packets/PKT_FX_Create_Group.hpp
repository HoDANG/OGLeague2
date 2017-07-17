#ifndef HPP_021_PKT_FX_Create_Group_HPP
#define HPP_021_PKT_FX_Create_Group_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_FX_Create_Group_s : DefaultPacket<PKT_FX_Create_Group>
{
    char numbFXGroups;
    char data[];
};
#pragma pack(pop)

#endif
