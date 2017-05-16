#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include "dep/wink.hpp"
#include "dep/r3d.hpp"
#include "scripts/scriptmap.h"
#include "objectmanager.h"

class World
{
private:
    ObjectManager mObjectManager;
    r3dNavGrid mGrid;
    std::string mLevelName;
    ScriptMap mScriptMap;
public:
    World();
    ObjectManager &objectmanager();
    void init();
    std::string levelName() const;
    void setLevelName(const std::string &levelName);
    void LoadWorld();
};

#endif // WORLD_H
