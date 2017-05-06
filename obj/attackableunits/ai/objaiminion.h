#ifndef OBJAIMINION_H
#define OBJAIMINION_H

#include "objaibase.h"

namespace Game
{
class ObjAiMinion : public ObjAiBase
{
public:
    ObjAiMinion(World *world);
    void SetupReplicationInfo();
};
}

#endif // OBJAIMINION_H
