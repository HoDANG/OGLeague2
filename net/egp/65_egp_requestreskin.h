#ifndef HPP_65_EGP_REQUESTRESKIN_H
#define HPP_65_EGP_REQUESTRESKIN_H

#include "../base.h"

struct EGP_RequestReskin_s : DefaultPayload<EGP_RequestReskin>
{
    int64_t Id_Player;
    int skinID;
    uint32_t bufferLen;
    char buffer[128];
};

#endif // 65_EGP_REQUESTRESKIN_H
