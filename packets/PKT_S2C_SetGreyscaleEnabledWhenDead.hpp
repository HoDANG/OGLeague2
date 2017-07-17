#ifndef HPP_179_PKT_S2C_SetGreyscaleEnabledWhenDead_HPP
#define HPP_179_PKT_S2C_SetGreyscaleEnabledWhenDead_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_SetGreyscaleEnabledWhenDead_s : DefaultPacket<PKT_S2C_SetGreyscaleEnabledWhenDead>
{
    int8_t flag : 1;
};
#pragma pack(pop)

#endif
