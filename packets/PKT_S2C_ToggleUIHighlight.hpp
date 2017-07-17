#ifndef HPP_173_PKT_S2C_ToggleUIHighlight_HPP
#define HPP_173_PKT_S2C_ToggleUIHighlight_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_ToggleUIHighlight_s : DefaultPacket<PKT_S2C_ToggleUIHighlight>
{
    char elementID;
    char elementType;
    char elementNumber;
    char elementSubCategory;
    int8_t flag : 1;
};
#pragma pack(pop)

#endif
