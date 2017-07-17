#ifndef HPP_152_PKT_S2C_OpenTutorialPopup_HPP
#define HPP_152_PKT_S2C_OpenTutorialPopup_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_OpenTutorialPopup_s : DefaultPacket<PKT_S2C_OpenTutorialPopup>
{
    char messageboxTextStringID[128];
};
#pragma pack(pop)

#endif
