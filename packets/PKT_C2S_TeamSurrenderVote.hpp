#ifndef HPP_166_PKT_C2S_TeamSurrenderVote_HPP
#define HPP_166_PKT_C2S_TeamSurrenderVote_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_C2S_TeamSurrenderVote_s : DefaultPacket<PKT_C2S_TeamSurrenderVote>
{
    int8_t vote : 1;
};
#pragma pack(pop)

#endif
