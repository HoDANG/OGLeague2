#ifndef ATTACKABLEUNIT_H
#define ATTACKABLEUNIT_H

#include "obj/gameobject.h"
#include "stats/health.hpp"
#include "stats/mana.hpp"

class AttackableUnit : public GameObject
{
public:
    Health mHealth;
    Mana mPAR;
    Replicate<int> mIsInvulnerable;
    Replicate<int> mIsTargetable;
    Replicate<int> mIsTargetableToTeam;
    Replicate<int> mIsPhysicalImmune;
    Replicate<int> mIsMagicImmune;
    AttackableUnit(World *world);
};

#endif // ATTACKABLEUNIT_H
