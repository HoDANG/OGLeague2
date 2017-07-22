#include <string.h>
#include <iostream>
#include "world.h"
#include "net/serveri.hpp"
#include "objectmanager.h"
#include "playermanager.h"
#include "scripts/scriptmap.h"

using namespace std;

World::World(ServerI *server, GameInfo *gameinfo)
    : pGameInfo(gameinfo),
      pServer(server),
      pPlayerManager(new PlayerManager(server, gameinfo)),
      pObjectManager(new ObjectManager(this)),
      pScriptMap(new ScriptMap(this))
{
}

ObjectManager* World::objectmanager()
{
    return pObjectManager;
}

PlayerManager* World::playerManager()
{
    return pPlayerManager;
}

r3dTime &World::time()
{
    return mTime;
}

GGameState_s World::gameState()
{
    return mGameState;
}

void World::setGameState(GGameState_s gameState)
{
    mGameState = gameState;
}

ServerI* World::server()
{
    return pServer;
}

GameInfo* World::gameinfo()
{
    return pGameInfo;
}

void World::LoadWorld()
{
    mGrid.load("LEVELS/"+pGameInfo->getMapName()+"/AIPath.aimesh_ngrid");
    r3dFile dsc("LEVELS/"+pGameInfo->getMapName()+"/Scene/room.dsc");
    std::string name, quality;
    while(dsc >> name >> quality)
    {
        if(name.size()<6)
            continue;
        name = name.substr(0, name.size() - 4);
        pObjectManager->CreateWorldObject(name);
    }
}

void World::LoadGame()
{
    //init CharacterDataArraay
    //init SpellManager
    //init objectManager
    //load ai Mesh
    //load world
    LoadWorld();
    //init NavPointManager
    //load mission aka map script
    pScriptMap->Init(pGameInfo->getMapName());
}

void World::Play()
{
    pServer->start(pGameInfo);
    mTime.reset();
    mTime.startFrame();
    //Load game
    LoadGame();
    //Update objects
    //Post load game script
    pScriptMap->PostInit();
    //Update objects
    //etc...
    mGameState = GAMESTATE_PREGAME;
    float delta = 0;
    while(mGameState != GAMESTATE_EXIT)
    {
        mTime.startFrame();
        pServer->host(0);
        pPlayerManager->update(delta);
        loop(delta);
        mTime.endFrame();
        delta = mTime.getFrameLastTime();
    }
}

void World::loop(float delta)
{
    if(mGameState == GAMESTATE_GAMELOOP)
        pObjectManager->update(delta);
}




