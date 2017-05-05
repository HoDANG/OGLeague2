#ifndef OBJBUILDING_H
#define OBJBUILDING_H

#include "../attackableunit.h"

namespace Game
{
class ObjBuilding : public AttackableUnit
{
public:
    ObjBuilding();
    bool Load(std::string name);
};
}

#endif // OBJBUILDING_H
