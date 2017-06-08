#ifndef HPP_015_PKT_C2S_CharSelected_HPP
#define HPP_015_PKT_C2S_CharSelected_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_C2S_CharSelected_s
        : DefaultPacket<PKT_C2S_CharSelected,CHANNEL_GENERIC_APP_TO_SERVER>
{
};
#pragma pack(pop)

#endif
