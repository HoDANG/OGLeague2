#include "objbuilding.h"

using namespace Game;

ObjBuilding::ObjBuilding()
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
