#ifndef HPP_171_PKT_C2S_TutorialAudioEventFinished_HPP
#define HPP_171_PKT_C2S_TutorialAudioEventFinished_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_C2S_TutorialAudioEventFinished_s : DefaultPacket<PKT_C2S_TutorialAudioEventFinished>
{
    unsigned int audioEventNetworkID;
};
#pragma pack(pop)

#endif
