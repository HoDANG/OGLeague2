#ifndef HPP_185_PKT_S2C_HeroStats_HPP
#define HPP_185_PKT_S2C_HeroStats_HPP
#include "base.hpp"
#include "shared/herostats.h"

#pragma pack(push, 1)
struct PKT_S2C_HeroStats_s : DefaultPacket<PKT_S2C_HeroStats>
{
    HeroStats stats;
};
#pragma pack(pop)

#endif
