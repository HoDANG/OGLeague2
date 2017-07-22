#include "navigationmanager.h"
#include "world.h"
#include "common/gameinfo.hpp"

NavigationManager::NavigationManager(World *world)
    :pWorld(world)
{

}

void NavigationManager::init()
{
    mGrid.load("LEVELS/"+pWorld->gameinfo->getMapName()+"/AIPath.aimesh_ngrid");
}
