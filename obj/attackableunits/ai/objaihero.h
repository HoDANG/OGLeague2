#ifndef OBJAIHERO_H
#define OBJAIHERO_H

#include "objaibase.h"

namespace Game
{
class ObjAiHero : public ObjAiBase
{
public:
    ObjAiHero(World *world);
    void SetupReplicationInfo();
};
}

#endif // OBJAIHERO_H
