#ifndef OBJHQ_H
#define OBJHQ_H

#include "objanimatedbuilding.h"
#include "stats/replicationhelper.hpp"

class ObjHQ : public ObjAnimatedBuilding
{
protected:
    ReplicationManager mReplicationManager;
public:
    ObjHQ(World *world);
    void SetupReplicationInfo();
};

#endif // OBJHQ_H
