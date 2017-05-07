#ifndef OBJAIBASE_H
#define OBJAIBASE_H

#include "../attackableunit.h"
#include "../../../rep/characterintermediaterep.h"
#include "../../../rep/characterstate.h"

namespace Game
{
class ObjAiBase : public AttackableUnit
{
protected:
    CharacterIntermediateRep charInterRep;
    CharacterState charState;
public:
    ReplicationManager mReplicationManager;
    ObjAiBase(World *world);
};
}

#endif // OBJAIBASE_H
