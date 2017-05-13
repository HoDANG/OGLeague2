#ifndef OBJAIHERO_H
#define OBJAIHERO_H

#include "objaibase.h"
#include "../../properties/experience.hpp"
#include "../../properties/gold.hpp"

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
