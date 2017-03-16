#include "world.h"

using namespace std;
using namespace Game;

Content::Manager *World::content()
{
    return &mContent;
}

Map *World::gamemap()
{
    return &mMap;
}

void World::init()
{

}
