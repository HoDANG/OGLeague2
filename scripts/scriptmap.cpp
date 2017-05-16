#include "scriptmap.h"
#include "scripthelper.h"
#include "../world.h"

ScriptMap::ScriptMap(World *world)
    : pWorld(world)
{
}

void ScriptMap::Init(std::string name)
{
    ScriptHelper::InitState(mState);
    ScriptHelper::LoadLuaFile("LEVELS/"+name+"/Scripts/LevelScript.lua", mState);
    mState["OnLevelInit"]();
}
