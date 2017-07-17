#ifndef SPEEDPARAMS_H
#define SPEEDPARAMS_H
#include <inttypes.h>

#pragma pack(push, 1)
struct SpeedParms
{
  float pathSpeedOverride;
  float ParabolicGravity;
  float parabolicStartPoint[2];
};
#pragma pack(pop)

#endif // SPEEDPARAMS_H
