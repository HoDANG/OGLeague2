#ifndef OBJAIBASE_H
#define OBJAIBASE_H

#include "../attackableunit.h"
#include "../../../rep/characterintermediaterep.h"
#include "../../../rep/characterstate.h"

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
