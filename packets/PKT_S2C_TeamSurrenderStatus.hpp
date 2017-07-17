#ifndef HPP_169_PKT_S2C_TeamSurrenderStatus_HPP
#define HPP_169_PKT_S2C_TeamSurrenderStatus_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_TeamSurrenderStatus_s : DefaultPacket<PKT_S2C_TeamSurrenderStatus>
{
    enum Reason
    {
        VOTE_WAS_NO_SURRENDER = 0x0,
        NOT_ALLOWED_YET = 0x1,
        DONT_SPAM_SURRENDER = 0x2,
        ALREADY_VOTED = 0x3,
        SURRENDER_AGREED = 0x4,
    };
    Reason reason;
    char forVote;
    char againstVote;
    int team;
};
#pragma pack(pop)

#endif
