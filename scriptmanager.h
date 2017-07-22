#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H

class World;
class ScriptManager
{
private:
    World *pWorld;
public:
    ScriptManager(World *world);
};

#endif // SCRIPTMANAGER_H
