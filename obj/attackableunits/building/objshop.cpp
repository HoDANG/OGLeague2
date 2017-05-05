#include "objshop.h"
#include <string.h>

using namespace Game;

ObjShop::ObjShop(World *world)
    : ObjBuilding(world)
{

}

bool ObjShop::Load(std::string name)
{
    if(!ObjBuilding::Load(name))
        return false;
    if(_stricmp(name.c_str(), "chaos") >= 0)
        this->Team = TEAM_CHAOS;
    else
        this->Team = _stricmp(name.c_str(), "order") !=0 ? TEAM_ORDER : TEAM_NEUTRAL;
    return true;
}
