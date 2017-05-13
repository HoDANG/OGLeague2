#include "world.h"
#include <string.h>
#include <iostream>

using namespace std;

World::World()
    : mObjectManager(this)
{
}

ObjectManager &World::objectmanager()
{
    return mObjectManager;
}

void World::init()
{

}

string World::levelName() const
{
    return mLevelName;
}

void World::setLevelName(const string &levelName)
{
    mLevelName = levelName;
}

void World::LoadWorld()
{
    mGrid.load("LEVELS/"+mLevelName+"/AIPath.aimesh_ngrid");
    r3dFile dsc("LEVELS/"+mLevelName+"/Scene/room.dsc");
    std::string name, quality;
    while(dsc >> name >> quality)
    {
        if(name.size()<6)
            continue;
        name = name.substr(0, name.size() - 4);
        mObjectManager.CreateWorldObject(name);
    }
}
