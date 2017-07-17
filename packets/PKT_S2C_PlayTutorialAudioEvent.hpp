#ifndef HPP_143_PKT_S2C_PlayTutorialAudioEvent_HPP
#define HPP_143_PKT_S2C_PlayTutorialAudioEvent_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_S2C_PlayTutorialAudioEvent_s : DefaultPacket<PKT_S2C_PlayTutorialAudioEvent>
{
    char eventID[64];
    int8_t bShouldRegisterCallback : 1;
};
#pragma pack(pop)

#endif
