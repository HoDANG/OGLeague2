#ifndef HPP_64_EGP_REQUESTJOINTEAM_H
#define HPP_64_EGP_REQUESTJOINTEAM_H

#include "../base.hpp"

struct EGP_RequestJoinTeam_s : DefaultPayload<EGP_RequestJoinTeam>
{
    uint32_t Id_Player;
    uint32_t team;
};

#endif // 64_EGP_REQUESTJOINTEAM_H
