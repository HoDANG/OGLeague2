#ifndef SCRIPTMAP_H
#define SCRIPTMAP_H

#include "sol.hpp"

class World;
class ScriptMap
{
public:
    ScriptMap(World *world);
    void Init(std::string name);
    void PostInit();
    float barracksSpawnTime = 0;
    float neutralSpawnTime = 0;
    int m_SpawnInterations = 0;
    bool bPreviousNeutralSpawnEnabled = false;
    sol::state mState;
    World *pWorld;
};

#endif // SCRIPTMAP_H
