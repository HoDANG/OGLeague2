#ifndef AITIMER_H
#define AITIMER_H

#include <string>

struct AiTimer
{
  float mElapsed;
  float mDelay;
  bool mRepeat;
  bool mEnabled;
  std::string mName;
};

#endif // AITIMER_H
