#ifndef HPP_116_PKT_S2C_BotAI_HPP
#define HPP_116_PKT_S2C_BotAI_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_BotAI_s : DefaultPacket<PKT_S2C_BotAI>
{
    char mBotAIName[64];
    char mBotAIStrategy[64];
    char mBotAIBehavior[64];
    char mBotAITask[64];
    char mBotAIState[3][64];
};
#pragma pack(pop)

#endif
