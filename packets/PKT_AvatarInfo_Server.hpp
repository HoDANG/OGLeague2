#ifndef HPP_096_PKT_AvatarInfo_Server_HPP
#define HPP_096_PKT_AvatarInfo_Server_HPP
#include "base.hpp"
#include "shared/avatarinfo.h"

#pragma pack(push, 1)
struct PKT_AvatarInfo_Server_s : DefaultPacket<PKT_AvatarInfo_Server>
{
    AvatarInfo info;
};
#pragma pack(pop)

#endif
