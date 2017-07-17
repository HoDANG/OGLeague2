#include "r3dtime.h"

using namespace std::chrono;

r3dTime::r3dTime()
{
    reset();
}

void r3dTime::reset()
{
    mTimerStart = high_resolution_clock::now();
}

void r3dTime::startFrame()
{
    mFrameStart = getTime();
}

void r3dTime::endFrame()
{
    mLastFrameTime = getTime() - mFrameStart;
}

float r3dTime::getFrameStartTime()
{
    return mFrameStart;
}

float r3dTime::getTime()
{
    return duration_cast<microseconds>(high_resolution_clock::now()
    - mTimerStart).count() / 1000000.0;
}

float r3dTime::getFrameLastTime()
{
    return mLastFrameTime;
}

float r3dTime::frame()
{
    endFrame();
    startFrame();
    return mLastFrameTime;
}
