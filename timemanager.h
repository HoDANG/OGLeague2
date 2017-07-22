#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "r3d.hpp"

class World;
class TimeManager : public r3dTime
{
private:
    World* pWorld;
    float mStartGameTime;
public:
    TimeManager(World* world);
    void startGameTime();
    float gameTime();
};

#endif // TIMEMANAGER_H
