#include <iostream>
#include <inttypes.h>
#include <string>
#include "game/world.h"

using namespace std;

int main()
{
    Game::World world;
    world.content()->setBasePaths({"C:/lol/LoL-1.0.0.673"});
    world.setLevelName("Map1");
    world.LoadWorld();
    return 0;
}
