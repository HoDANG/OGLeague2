#ifndef ATTACKABLEUNIT_H
#define ATTACKABLEUNIT_H

#include "../gameobject.h"
#include "../../common/health.h"

namespace Game
{
class AttackableUnit : public GameObject
{
public:
    Health mHealth;
    Replicate<int> mIsInvulnerable;
    Replicate<int> mIsTargetable;
    Replicate<int> mIsTargetableToTeam;
    AttackableUnit(World *world);
};
}

#endif // ATTACKABLEUNIT_H
