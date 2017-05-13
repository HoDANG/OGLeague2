#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include "../dep/wink.hpp"
#include "../obj/gameobject.h"
#include "objectmanager.h"

class World
{
private:
    ObjectManager mObjectManager = ObjectManager(this);
    r3dNavGrid mGrid;
    std::string mLevelName;
public:
    ObjectManager *objectmanager();
    void init();
    GameObject* CreateGameObject(std::string className, std::string loadName, r3dPoint3D pos,
                                 int flags, void* data);
    GameObject* CreateWorldObject(std::string loadName);
    void LoadWorld();
    std::string levelName() const;
    void setLevelName(const std::string &levelName);
};

#endif // WORLD_H
