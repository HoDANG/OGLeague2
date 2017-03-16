#ifndef MAP_H
#define MAP_H

#include "../nav/navgrid.h"

namespace Game
{
class World;
class Map
{
private:
    NavGrid mGrid;
    World *pWorld;
    int mapNum = 0;
public:
    Map(World *world);
    int getMapNum() const;
    void setMapNum(int value);
    void preLoad();
};
}

#endif // MAP_H
