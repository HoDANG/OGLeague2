#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include "../content/manager.h"
#include "../dep/wink.hpp"
#include "objectmanager.h"
#include "../obj/gameobject.h"
#include "../nav/navgrid.h"

namespace Game
{
class World
{
private:
    Content::Manager mContent;
    ObjectManager mObjectManager = ObjectManager(this);
    NavGrid mGrid;
    std::string mLevelName;
public:
    Content::Manager *content();
    ObjectManager *objectmanager();
    void init();
    GameObject* CreateGameObject(std::string className, std::string loadName, r3dPoint3D pos,
                                 int flags, void* data);
    GameObject* CreateWorldObject(std::string loadName);
    void LoadWorld();
    std::string levelName() const;
    void setLevelName(const std::string &levelName);
};
}

#endif // WORLD_H
