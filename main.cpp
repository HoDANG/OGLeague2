#include <iostream>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "world.h"
#include "scripts/scriptmap.h"
#include "scripts/scripthelper.h"
#include "net/netserver.hpp"

using namespace std;

int main()
{
    GameInfo* gameinfo;

    GameInfo::PlayerInfo player1;
    player1.heroName = "Annie";
    player1.summonerName = "HoDANG";
    player1.skin = 0;
    player1.syncID = 1;

    gameinfo.basePath = "C:/lol/LoL-1.0.0.673";
    gameinfo.mLevelName = "Map1";
    gameinfo.mapNumber = 1;


    //lobby.pGameInfo->basePath = "C:/lol/LoL-1.0.0.673";
    //lobby.pGameInfo->mLevelName = "Map1";
    //lobby.pGameInfo->mapNumber = 1;



    r3dFileManager::addBasePath(gameinfo.basePath);
    NetServer net(ENET_HOST_ANY, 5119, "GLzvuWtyCfHyGhF2", 12);

    World world(&net);
    Lobby lobby(&net);
    lobby.pGameInfo = &gameinfo;

    lobby.pGameInfo->players[1];


    info.players.push_back(player1);

    world.Play();
    return 0;
}
