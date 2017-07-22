#include "objbuilding.h"
#include "world.h"
#include "objectmanager.h"

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
