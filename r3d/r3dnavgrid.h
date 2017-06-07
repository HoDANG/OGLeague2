#ifndef R3DNAVGRID_H
#define R3DNAVGRID_H

#include <string>
#include <vector>
#include "r3dpoint.h"

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
  bool isPassable() const;
};

struct NavHintGridNode
{
  float mDistances[900];
  NavGridCellLocator mLocator;
};

class r3dNavGrid
{
public:
    r3dPoint3D mMinGridPos;
    r3dPoint3D mMaxGridPos;
    float mCellSize;
    float mHalfCellSize;
    int mXCellCount;
    int mYCellCount;
    int mXSampledHeightCount;
    int mYSampledHeightCount;
    float mXSampledHeightDist;
    float mYSampledHeightDist;

    std::vector<NavGridCell> mCells;
    std::vector<float> mSampledHeights;
    std::vector<NavHintGridNode> mHintGrid;

    void load(std::string name);

    int GetCellIndex(NavGridCell* cell);

    bool IsValidCell(float inX, float inY, float width, float height, float border);

    bool IsValidCell(float inX, float inY);

    bool IsValidCellCellUnits(int inX, int inY);

    r3dPoint3D GetCellCenter(int x, int y);

    r3dPoint3D GetCellCenter(NavGridCellLocator &locator);

    void GetCellCenterXY(NavGridCell *cell, float &x, float &y);

    NavGridCellLocator GetCellLocator(r3dPoint3D &inPos);

    NavGridCell* GetCell(int y, int x);

    NavGridCell* GetCell(r3dPoint3D &pos);

    NavGridCell* GetCellInner(int y, int x);

    bool IsSolidPassable(r3dPoint3D &pos);
};


#endif // R3DNAVGRID_H
