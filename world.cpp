#include "world.h"
#include <string.h>
#include <iostream>
#include "net/serveri.hpp"

using namespace std;

World::World(ServerI *server, GameInfo *gameinfo)
    : pGameInfo(gameinfo),
      pServer(server),
      mLobby(server, gameinfo),
      mObjectManager(this),
      mScriptMap(this)
{
}

ObjectManager &World::objectmanager()
{
    return mObjectManager;
}

Lobby &World::lobby()
{
    return mLobby;
}

GGameState_s World::gameState() const
{
    return mGameState;
}

void World::setGameState(const GGameState_s &gameState)
{
    mGameState = gameState;
}

ServerI *World::server() const
{
    return pServer;
}

GameInfo *World::gameinfo() const
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
        mObjectManager.CreateWorldObject(name);
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
    mScriptMap.Init(pGameInfo->getMapName());
}

void World::Play()
{
    pServer->start(pGameInfo);
    //Load game
    LoadGame();
    //Update objects
    //Post load game script
    mScriptMap.PostInit();
    //Update objects
    //etc...
    mGameState = GAMESTATE_GAMELOOP;
    loop();
}

void World::loop()
{
    while(mGameState != GAMESTATE_EXIT)
    {
        pServer->host(0);
        mLobby.update();
        mObjectManager.update();
    }
}




