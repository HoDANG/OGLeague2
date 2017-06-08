#ifndef HPP_66_EGP_REQUESTRENAME_H
#define HPP_66_EGP_REQUESTRENAME_H

#include "base.hpp"

struct EGP_RequestRename_s : DefaultPayload<EGP_RequestRename>
{
    int64_t Id_Player;
    int skinID;
    uint32_t bufferLen;
    char buffer[128];
};

#endif // 66_EGP_REQUESTRENAME_H
