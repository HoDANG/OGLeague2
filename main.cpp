#include <iostream>
#include <iomanip>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "world.h"
#include "netserver.h"

using namespace std;

int main()
{
    enet_initialize();
    GameInfo gameinfo;
    gameinfo.basePaths = { "C:/lol/LoL-1.0.0.673" };
    r3dFileManager::setBasePaths(gameinfo.basePaths);
    NetServer server;
    server.OnConnected.connect([](uint32_t cid){
        cout<<"Connected: "<<cid<<endl;
    });
    World world(&server, &gameinfo);
    world.Play();
    return 0;
}
