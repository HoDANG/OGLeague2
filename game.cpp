#include <string.h>
#include <iostream>
#include "game.h"
#include "net/serveri.hpp"
#include "objectmanager.h"
#include "playermanager.h"
#include "scripts/scriptmap.h"
#include "common/gameinfo.hpp"
#include "world.h"

using namespace std;

Game::Game()
{
    enet_initialize();
    pWorld = new World;
}

void Game::LoadWorld()
{
    pWorld->grid->load("LEVELS/"+pWorld->gameinfo->getMapName()+"/AIPath.aimesh_ngrid");
    r3dFile dsc("LEVELS/"+pWorld->gameinfo->getMapName()+"/Scene/room.dsc");
    std::string name, quality;
    while(dsc >> name >> quality)
    {
        if(name.size()<6)
            continue;
        name = name.substr(0, name.size() - 4);
        pWorld->objectmanager->CreateWorldObject(name);
    }
}

void Game::LoadGame()
{
    //init CharacterDataArraay
    //init SpellManager
    //init objectManager
    //load ai Mesh
    //load world
    LoadWorld();

    //init NavPointManager
    //load mission aka map script
    pWorld->scriptmap->Init(pWorld->gameinfo->getMapName());
}

void Game::Play()
{
    r3dFileManager::setBasePaths(pWorld->gameinfo->basePaths);
    if(!pWorld->server->start(pWorld->gameinfo))
    {
        std::cout<<"Could not start sever!"<<std::endl;
        return;
    }
    pWorld->time->reset();
    pWorld->time->startFrame();
    //Load game
    LoadGame();
    //Update objects
    //Post load game script
    pWorld->scriptmap->PostInit();
    //Update objects
    //etc...
    pWorld->gamestate = GAMESTATE_PREGAME;
    float delta = 0;
    while(pWorld->gamestate != GAMESTATE_EXIT)
    {
        pWorld->time->startFrame();
        pWorld->server->host(0);
        pWorld->objectmanager->update(delta);
        if(pWorld->gamestate == GAMESTATE_GAMELOOP)
        {
            pWorld->objectmanager->update(delta);
        }
        pWorld->time->endFrame();
        delta = pWorld->time->getFrameLastTime();
    }
}

World *Game::world()
{
    return pWorld;
}





