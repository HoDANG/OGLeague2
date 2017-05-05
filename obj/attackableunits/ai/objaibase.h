#ifndef OBJAIBASE_H
#define OBJAIBASE_H

#include "../attackableunit.h"

namespace Game
{
class ObjAiBase : public AttackableUnit
{
public:
    ObjAiBase(World *world);
};
}

#endif // OBJAIBASE_H
