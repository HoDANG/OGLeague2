#ifndef HPP_176_PKT_S2C_MuteVolumeCategory_HPP
#define HPP_176_PKT_S2C_MuteVolumeCategory_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_MuteVolumeCategory_s : DefaultPacket<PKT_S2C_MuteVolumeCategory>
{
    char volumeCategory;
    int8_t muteFlag : 1;
};
#pragma pack(pop)

#endif
