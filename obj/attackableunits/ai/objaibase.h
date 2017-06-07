#ifndef OBJAIBASE_H
#define OBJAIBASE_H

#include "obj/attackableunits/attackableunit.h"
#include "stats/characterintermediaterep.hpp"
#include "stats/characterstate.hpp"

class ObjAiBase : public AttackableUnit
{
protected:
    CharacterIntermediateRep charInterRep;
    CharacterState charState;
    Replicate<float> mDebugDrawRadius;
public:
    ReplicationManager mReplicationManager;
    ObjAiBase(World *world);
};

#endif // OBJAIBASE_H
