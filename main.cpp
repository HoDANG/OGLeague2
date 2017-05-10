#include <iostream>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "testserver.hpp"

using namespace std;

int main()
{
    enet_initialize();
    TestServer gameServer(new NetServer(ENET_HOST_ANY, 5119, "GLzvuWtyCfHyGhF2", 12));
    gameServer.test();
    return 0;
}
