#include "map.h"
#include "world.h"

using namespace std;
using namespace Game;

Map::Map(World *world)
    : pWorld(world)
{

}

int Map::getMapNum() const
{
    return mapNum;
}

void Map::setMapNum(int value)
{
    mapNum = value;
}

void Map::preLoad()
{
    mGrid.load(pWorld->content()->getFile("LEVELS/Map"+to_string(mapNum)+"/AIPath.aimesh_ngrid"));
}

