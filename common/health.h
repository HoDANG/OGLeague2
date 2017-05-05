#ifndef HEALTH_H
#define HEALTH_H

#include "../rep/replicationmanager.h"

struct Health
{
    Replicate<float> mCurrent;
    Replicate<float> mMax;
    Replicate<float> mNonHealValue;
};

#endif // HEALTH_H
