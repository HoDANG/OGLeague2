#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <map>
#include <vector>
#include "r3d.hpp"

class World;
class GameObject;
class ObjectManager
{
private:
    World *pWorld;
    std::map<uint32_t, GameObject*> mObjects;
    std::vector<GameObject*> mObjectsVect;
public:
    ObjectManager(World *world);
    void add(GameObject *obj);
    void removeById(uint32_t id);
    void RegisterNetworkObjects();
    uint32_t getNextID();
    GameObject* getByName(std::string name);
    GameObject* CreateGameObject(std::string className, std::string loadName, r3dPoint3D pos,
                                 int flags, void* data);
    GameObject* CreateWorldObject(std::string loadName);
    void update();
};

#endif // OBJECTMANAGER_H
