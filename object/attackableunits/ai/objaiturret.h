#ifndef OBJAITURRET_H
#define OBJAITURRET_H

#include "objaibase.h"

class ObjAiTurret : public ObjAiBase
{
public:
    ObjAiTurret(World *world);
    void SetupReplicationInfo();
};

#endif // OBJAITURRET_H
