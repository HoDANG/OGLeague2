#include "objshop.h"
#include <string.h>
#include "stringutils.hpp"

ObjShop::ObjShop(World *world)
    : ObjBuilding(world)
{

}

bool ObjShop::Load(std::string name)
{
    if(!ObjBuilding::Load(name))
        return false;
    if(StringUtils::stringicmp(name, "chaos") >= 0)
        this->Team = TEAM_CHAOS;
    else
        this->Team = StringUtils::stringicmp(name, "order") !=0 ? TEAM_ORDER : TEAM_NEUTRAL;
    return true;
}
