#ifndef VISIBILITYMANAGER_H
#define VISIBILITYMANAGER_H

class World;
class VisibilityManager
{
private:
    World *pWorld;
public:
    VisibilityManager(World *world);
};

#endif // VISIBILITYMANAGER_H
