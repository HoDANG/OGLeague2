#ifndef ATTACKABLEUNIT_H
#define ATTACKABLEUNIT_H

#include "../gameobject.h"
#include "../../common/health.h"
#include "../../common/mana.h"

namespace Game
{
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
}

#endif // ATTACKABLEUNIT_H
