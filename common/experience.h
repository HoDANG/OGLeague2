#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include "../rep/replicationmanager.h"

struct Experience
{
  Replicate<float> mExp;
  Replicate<int> mLevel;
};

#endif // EXPERIENCE_H
