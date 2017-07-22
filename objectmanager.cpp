#include "objectmanager.h"
#include "world.h"
#include "object/gameobjectsall.h"

using namespace std;

ObjectManager::ObjectManager(World *world)
    : pWorld(world)
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

void ObjectManager::update(float delta)
{
    for(auto o: mObjectsVect)
        o->update();
}

GameObject *ObjectManager::CreateGameObject(string className, string loadName, r3dPoint3D pos, int flags, void *data)
{
    GameObject *obj;
    if(className == "ObjAiBase")
        obj = new ObjAiBase(pWorld);
    else if(className == "ObjAiMinion")
        obj = new ObjAiMinion(pWorld);
    else if(className == "ObjAiHero")
        obj = new ObjAiHero(pWorld);
    else if(className == "ObjAiTurret")
        obj = new ObjAiTurret(pWorld);
    else if(className == "AttackableUnit")
        obj = new AttackableUnit(pWorld);
    else if(className == "ObjAnimatedBuilding")
        obj = new ObjAnimatedBuilding(pWorld);
    else if(className == "ObjBarracksDampener")
        obj = new ObjBarracksDampener(pWorld);
    else if(className == "ObjHQ")
        obj = new ObjHQ(pWorld);
    else if(className == "ObjTurret")
        obj = new ObjTurret(pWorld);
    else if(className == "ObjBarracks")
        obj = new ObjBarracks(pWorld);
    else if(className == "ObjBuilding")
        obj = new ObjBuilding(pWorld);
    else if(className == "ObjLake")
        obj = new ObjLake(pWorld);
    else if(className == "ObjLevelSizer")
        obj = new ObjLevelSizer(pWorld);
    else if(className == "ObjNavPoint")
        obj = new ObjNavPoint(pWorld);
    else if(className == "ObjShop")
        obj = new ObjShop(pWorld);
    else if(className == "ObjSpawnPoint")
        obj = new ObjSpawnPoint(pWorld);
    else if(className == "ObjSpellMissile")
        obj = new ObjSpellMissile(pWorld);
    else if(className == "GameObject")
        obj = new GameObject(pWorld);
    else
        return nullptr;

    obj->Load(loadName);
    cout<<"Created "<<loadName<<" as "<<className<<": "<<(obj!=nullptr?"true":"false")<<endl;
    return obj;
}

GameObject *ObjectManager::CreateWorldObject(string loadName)
{

    static struct {
        string name; //String identifier in loadName
        string obj;  //Object class name
        bool client; //Client only
    } objs[] = {
        {"Spawn_Barracks",  "ObjBarracks",          0},
        {"__Spawn_",        "ObjSpawnPoint",		0},
        {"__LevelSize_",    "ObjLevelSizer",		0},
        {"Barracks",        "ObjBarracksDampener",	0},
        {"__ANIMS_",        "ObjAnimatedBuilding",	1},
        {"HQ_",             "ObjHQ",                0},
        {"Turret",          "ObjTurret",            0},
        {"Shop",            "ObjShop",              0},
        {"Lake",            "ObjLake",              1},
        {"__NAV_",          "ObjNavPoint",          0}
    };
    for(auto o : objs)
    {
        if(strstr(loadName.c_str(), o.name.c_str())!=0)
        {
            if(o.client)
                return nullptr;
            r3dPoint3D pos;
            pos.x = 0;
            pos.y = 0;
            pos.z = 0;
            GameObject* obj = CreateGameObject(o.obj, loadName, pos, 64, 0);
            obj->assignIDByName();
            return obj;
        }
    }
    return nullptr;
}
