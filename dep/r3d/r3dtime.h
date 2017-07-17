#ifndef R3DTIME_H
#define R3DTIME_H

#include <chrono>

class r3dTime
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> mTimerStart;
    float mFrameStart;
    float mLastFrameTime;
public:
    r3dTime();
    void reset();
    void startFrame();
    void endFrame();
    float getFrameStartTime();
    float getTime();
    float getFrameLastTime();
    float frame();
};

#endif // R3DTIME_H
