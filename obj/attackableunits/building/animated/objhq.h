#ifndef OBJHQ_H
#define OBJHQ_H

#include "objanimatedbuilding.h"
#include "../../../../rep/replicationhelper.h"

namespace Game
{
class ObjHQ : public ObjAnimatedBuilding
{
protected:
    ReplicationManager mReplicationManager;
public:
    ObjHQ(World *world);
    void SetupReplicationInfo();
};
}

#endif // OBJHQ_H
