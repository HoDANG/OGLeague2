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

    GameInfo info;
    GameInfo::PlayerInfo hodang;
    hodang.heroName = "Annie";
    hodang.summonerName = "HoDANG";
    hodang.skin = 0;
    hodang.syncID = 1;
    info.players.push_back(hodang);
    GameInfo::PlayerInfo = info.players.front();


    r3dFileManager::addBasePath(info.basePath);
    NetServer net(ENET_HOST_ANY, 5119, "GLzvuWtyCfHyGhF2", 12);

    World world(&net);
    Lobby lobby(&net);
    world.Play();
    return 0;
}
