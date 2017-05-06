#ifndef MANA_H
#define MANA_H

#include "../rep/replicationmanager.h"


struct Mana
{
    Replicate<float> mCurrent;
    Replicate<float> mMax;
};

#endif // MANA_H
