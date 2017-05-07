#ifndef OBJAIHERO_H
#define OBJAIHERO_H

#include "objaibase.h"
#include "../../../common/experience.h"
#include "../../../common/gold.h"


namespace Game
{
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
}

#endif // OBJAIHERO_H
