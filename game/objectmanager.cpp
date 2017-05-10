#include "objectmanager.h"
#include "world.h"

#include "../obj/gameobject.h"

ObjectManager::ObjectManager(World *world)
    :pWorld(world)
{

}

void ObjectManager::add(GameObject *obj)
{
    mObjects[obj->networkID()] = obj;
    mObjectsVect.push_back(obj);
}

void ObjectManager::removeById(uint32_t id)
{

}

uint32_t ObjectManager::getNextID()
{
    static int nextID = 1;
    return 0x40000000 | ++nextID;
}

GameObject *ObjectManager::getByName(std::string name)
{
    for(GameObject *o: mObjectsVect)

        if(o->getName() == name)
            return o;
    return nullptr;
}

void ObjectManager::update()
{

}


