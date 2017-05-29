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
    r3dFileManager::addBasePath("C:/lol/LoL-1.0.0.673");
    NetServer net(ENET_HOST_ANY, 5119, "GLzvuWtyCfHyGhF2", 12);
    World world(&net);
    world.setLevelName("Map1");
    Lobby lobby(&net);
    Lobby.setChampion("Annie");
    Lobby.setName("HoDANG");
    Lobby.setSkin(0);
    Lobby.setSyncID(1);
    world.Play();
    return 0;
}
