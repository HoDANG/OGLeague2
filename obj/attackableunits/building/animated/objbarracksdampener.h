#ifndef OBJBARRACKSDAMPENER_H
#define OBJBARRACKSDAMPENER_H

#include "obj/attackableunits/building/animated/objanimatedbuilding.h"
#include "objanimatedbuilding.h"
#include "stats/replicationhelper.hpp"

class ObjBarracksDampener : public ObjAnimatedBuilding
{
protected:
    ReplicationManager mReplicationManager;
public:
    ObjBarracksDampener(World *world);
     void SetupReplicationInfo();
};

#endif // OBJBARRACKSDAMPENER_H
