#ifndef HEALTH_H
#define HEALTH_H

#include "replicationmanager.hpp"

struct Health
{
    Replicate<float> mCurrent;
    Replicate<float> mMax;
    Replicate<float> mNonHealValue;
};

#endif // HEALTH_H
