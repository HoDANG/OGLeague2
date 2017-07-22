#include "world.h"
#include "objectmanager.h"
#include "playermanager.h"
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
}

World::~World()
{
    delete scriptmap;
    delete objectmanager;
    delete playermanager;
    delete grid;
    delete gameinfo;
    delete server;
    delete time;
}
