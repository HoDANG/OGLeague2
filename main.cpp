#include <iostream>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "world.h"

using namespace std;

int main()
{
    r3dFileManager::setBasePaths({"C:/lol/LoL-1.0.0.673"});
    World world;
    world.setLevelName("Map1");

    world.LoadWorld();
    return 0;
}
