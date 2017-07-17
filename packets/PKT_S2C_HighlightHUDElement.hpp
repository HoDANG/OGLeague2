#ifndef HPP_164_PKT_S2C_HighlightHUDElement_HPP
#define HPP_164_PKT_S2C_HighlightHUDElement_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_HighlightHUDElement_s : DefaultPacket<PKT_S2C_HighlightHUDElement>
{
    char elementType;
    char elementNumber;
};
#pragma pack(pop)

#endif
