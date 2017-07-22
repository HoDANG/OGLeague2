#ifndef NAVIGATIONMANAGER_H
#define NAVIGATIONMANAGER_H

#include "r3d.hpp"

class World;
class NavigationManager
{
private:
    r3dNavGrid mGrid;
    World* pWorld;
public:
    NavigationManager(World *world);
    void init();
};

#endif // NAVIGATIONMANAGER_H
