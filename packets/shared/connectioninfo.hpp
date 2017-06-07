#ifndef CONNECTIONINFO_H
#define CONNECTIONINFO_H

#include <inttypes.h>

#pragma pack(push, 1)
struct ConnectionInfo
{
    uint32_t mClientID = 0;
    uint64_t mPlayerID = 0;
    float mPercentage = 0;
    float mETA = 0;
    int32_t mCount : 16;
    uint32_t mPing : 15;
    uint8_t mReady : 1;
    char mState[64];
};
#pragma pack(pop)

#endif // CONNECTIONINFO_H
