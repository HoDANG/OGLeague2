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
    GameInfo gameinfo;
    gameinfo.basePaths = { "C:/lol/LoL-1.0.0.673" };
    r3dFileManager::setBasePaths(gameinfo.basePaths);
    NetServer server;
    World world(&server, &gameinfo);
    world.Play();
    return 0;
}
