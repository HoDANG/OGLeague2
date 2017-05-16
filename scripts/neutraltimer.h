#ifndef NEUTRALTIMER_H
#define NEUTRALTIMER_H

#include "aitimer.h"
#include "dep/sol.hpp"

struct NeutralTimer : AiTimer
{
  sol::object mLuaFunction = sol::nil;
};


#endif // NEUTRALTIMER_H
