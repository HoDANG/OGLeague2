#ifndef OBJBARRACKS_H
#define OBJBARRACKS_H

#include "objbuilding.h"

namespace Game
{
class ObjBarracks : public ObjBuilding
{
protected:
    ReplicationManager mReplicationManager;
public:
    ObjBarracks(World *world);
    void SetupReplicationInfo();

};
}

#endif // OBJBARRACKS_H
