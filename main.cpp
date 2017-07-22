#include <iostream>
#include <iomanip>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "world.h"
#include "enet.hpp"
#include "common/gameinfo.hpp"

using namespace std;

int main()
{
    enet_initialize();
    GameInfo gameinfo;
    gameinfo.basePaths = { "C:/lol/LoL-1.0.0.673" };
    World world(&gameinfo);
    world.Play();
    return 0;
}
