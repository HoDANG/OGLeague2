#ifndef HPP_050_PKT_SwapItemReq_HPP
#define HPP_050_PKT_SwapItemReq_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_SwapItemReq_s : DefaultPacket<PKT_SwapItemReq>
{
    char source;
    char dest;
};
#pragma pack(pop)

#endif
