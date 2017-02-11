#ifndef HPP_67_EGP_TEAMROSTERUPDATE_H
#define HPP_67_EGP_TEAMROSTERUPDATE_H

#include "../base.h"

struct EGP_TeamRosterUpdate_s : DefaultPayload<EGP_TeamRosterUpdate>
{
    unsigned int teamsize_order;
    unsigned int teamsize_chaos;
    int64_t orderMembers[24];
    int64_t chaosMembers[24];
    unsigned int current_teamsize_order;
    unsigned int current_teamsize_chaos;
};

#endif // 67_EGP_TEAMROSTERUPDATE_H
