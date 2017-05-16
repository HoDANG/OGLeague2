#ifndef AITIMER_H
#define AITIMER_H

#include <string>

struct AiTimer
{
  float mElapsed = 0;
  float mDelay = 0;
  bool mRepeat = 0;
  bool mEnabled = 0;
  std::string mName = "";
};

#endif // AITIMER_H
