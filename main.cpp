#include <iostream>
#include <iomanip>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "game.h"
#include "world.h"
#include "common/gameinfo.hpp"

using namespace std;

int main()
{
    Game game;
    game.world()->gameinfo->basePaths = { "C:/lol/LoL-1.0.0.673" };
    game.Play();
    return 0;
}
