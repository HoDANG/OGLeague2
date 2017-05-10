#include "objbuilding.h"

ObjBuilding::ObjBuilding(World *world)
    : AttackableUnit(world)
{

}

bool ObjBuilding::Load(std::string name)
{
    if(GameObject::Load(name))
    {
        return true;
    }
    return false;
}
