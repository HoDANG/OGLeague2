#ifndef HPP_067_PKT_SendSelectedObjID_HPP
#define HPP_067_PKT_SendSelectedObjID_HPP
#include "../base.h"

#pragma pack(push, 1)
struct PKT_SendSelectedObjID_s : DefaultPacket<PKT_SendSelectedObjID>
{
    uint32_t cliendID;
    uint32_t selectedNetID;
};
#pragma pack(pop)

#endif
