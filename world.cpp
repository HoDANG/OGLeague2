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

r3dTime &World::time()
{
    return mTime;
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
    mTime.reset();
    mTime.startFrame();
    //Load game
    LoadGame();
    //Update objects
    //Post load game script
    mScriptMap.PostInit();
    //Update objects
    //etc...
    mGameState = GAMESTATE_GAMELOOP;
    float delta = 0;
    while(mGameState != GAMESTATE_EXIT)
    {
        mTime.startFrame();
        pServer->host(0);
        loop(delta);
        mTime.endFrame();
        delta = mTime.getFrameLastTime();
    }
}

void World::loop(float delta)
{
    switch(mGameState)
    {
        case GAMESTATE_PREGAME:
            mLobby.wait(delta);
        break;
        case GAMESTATE_SPAWN:
        break;
        case GAMESTATE_GAMELOOP:
            mLobby.update(delta);
            mObjectManager.update();
        break;
        case GAMESTATE_ENDGAME:
        break;
        case GAMESTATE_PRE_EXIT:
        break;
        case GAMESTATE_EXIT:
        break;
    }
}




