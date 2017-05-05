#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <map>
#include <vector>

namespace Game
{
class World;
class GameObject;
class ObjectManager
{
private:
    World* pWorld;
    std::map<uint32_t, GameObject*> mObjects;
    std::vector<GameObject*> mObjectsVect;
public:
    ObjectManager(World* world);
    void add(GameObject *obj);
    void removeById(uint32_t id);
    void RegisterNetworkObjects();
    uint32_t getNextID();
    GameObject* getByName(std::string name);
};
}

#endif // OBJECTMANAGER_H
