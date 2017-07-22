#include "world.h"
#include "objectmanager.h"
#include "playermanager.h"
#include "locationsmanager.h"
#include "visibilitymanager.h"
#include "itemmanager.h"
#include "scriptmanager.h"
#include "spellmanager.h"
#include "scripts/scriptmap.h"
#include "netserver.h"
#include "common/gameinfo.hpp"
#include "r3d.hpp"

World::World()
{
    time = new r3dTime;
    server = new NetServer;
    gameinfo = new GameInfo;
    grid = new r3dNavGrid;
    playermanager = new PlayerManager(this);
    objectmanager = new ObjectManager(this);
    scriptmap = new ScriptMap(this);
    locationsmanager = new LocationsManager(this);
    visibilitymanager = new VisibilityManager(this);
    itemmanager = new ItemManager(this);
    scriptmanager = new ScriptManager(this);
    spellmanager = new SpellManager(this);
}

World::~World()
{
    delete spellmanager;
    delete scriptmanager;
    delete itemmanager;
    delete locationsmanager;
    delete visibilitymanager;
    delete scriptmap;
    delete objectmanager;
    delete playermanager;
    delete grid;
    delete gameinfo;
    delete server;
    delete time;
}
