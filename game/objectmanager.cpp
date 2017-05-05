#include "objectmanager.h"
#include "world.h"

#include "../obj/gameobject.h"

using namespace Game;

ObjectManager::ObjectManager(World *world)
    :pWorld(world)
{

}

void ObjectManager::add(GameObject *obj)
{
    mObjects[obj->networkID()] = obj;
}

void ObjectManager::removeById(uint32_t id)
{

}


