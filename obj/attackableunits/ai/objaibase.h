#ifndef OBJAIBASE_H
#define OBJAIBASE_H

#include "../attackableunit.h"
#include "../../properties/characterintermediaterep.hpp"
#include "../../properties/characterstate.hpp"

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
