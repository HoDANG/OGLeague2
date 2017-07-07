#ifndef OBJBARRACKS_H
#define OBJBARRACKS_H

#include "objbuilding.h"

class ObjBarracks : public ObjBuilding
{
protected:
    ReplicationManager mReplicationManager;
public:
    ObjBarracks(World *world);
    void SetupReplicationInfo();

};

#endif // OBJBARRACKS_H
