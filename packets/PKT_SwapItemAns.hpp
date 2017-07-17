#ifndef HPP_051_PKT_SwapItemAns_HPP
#define HPP_051_PKT_SwapItemAns_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SwapItemAns_s : DefaultPacket<PKT_SwapItemAns>
{
    char source;
    char dest;
};
#pragma pack(pop)

#endif
