#ifndef OBJAIHERO_H
#define OBJAIHERO_H

#include "object/attackableunits/ai/objaibase.h"
#include "stats/experience.hpp"
#include "stats/gold.hpp"

class ObjAiHero : public ObjAiBase
{
public:
    Experience mExp;
    Gold mGold;
    Replicate<unsigned long> mCanCastBits1;
    Replicate<unsigned long> mCanCastBits2;
    ObjAiHero(World *world);
    void SetupReplicationInfo();
};

#endif // OBJAIHERO_H
