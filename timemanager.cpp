#include "timemanager.h"
#include "world.h"

TimeManager::TimeManager(World *world)
    : pWorld(world),
      r3dTime()
{

}

void TimeManager::startGameTime()
{
    mStartGameTime = getTime();
}

float TimeManager::gameTime()
{
    return getTime() - mStartGameTime;
}
