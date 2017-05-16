#include <iostream>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "world.h"
#include "scripts/scriptmap.h"
#include "scripts/scripthelper.h"

using namespace std;

int main()
{
    r3dFileManager::addBasePath("C:/lol/LoL-1.0.0.673");
    World *world = new World();
    return 0;
}
