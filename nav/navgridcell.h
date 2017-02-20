#ifndef NAVGRIDCELL_H
#define NAVGRIDCELL_H

#include <string>
#include <vector>
#include <cassert>
#include "../dep/r3d.hpp"

struct NavGridCellFlags
{
    uint8_t mHasWallOfGrass : 1;
    uint8_t mNotPassable : 1;
    uint8_t mBusy : 1;
    uint8_t mTargetted : 1;
    uint8_t mMarked : 1;
    uint8_t mPathedOn : 1;
    uint8_t mSeeThrough : 1;
    uint8_t mOtherDirectionEndToStart : 1;
};

struct NavGridCellLocator
{
  uint16_t mX;
  uint16_t mY;
};

struct  NavGridCell
{
  float mCenterHeight;
  int mSessionID;
  float mArrivalCost;
  bool mIsOpen;
  float mHeuristic;
  uint32_t mActorList; //pointer
  NavGridCellLocator mLocator;
  float mAdditionalCost;
  float mHintAsGoodCell;
  int mAdditionalCostRefCount;
  int mGoodCellSessionID;
  float mRefHintWeight;
  char mArrivalDirection;
  NavGridCellFlags mFlags;
  uint16_t mRefHintNode[2];
};

#endif // NAVGRIDCELL_H
