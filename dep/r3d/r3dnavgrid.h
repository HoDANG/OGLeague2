#ifndef R3DNAVGRID_H
#define R3DNAVGRID_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "r3dfile.h"
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
  bool isPassable() const
  {
      return !mFlags.mNotPassable;
  }
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

    void load(std::string name)
    {
        uint8_t majorVersion;
        r3dFile file(name, std::ios::binary);
        assert(file.is_open());
        assert(file.readb(majorVersion));
        assert(majorVersion == 2);
        assert(file.readb(mMinGridPos));
        assert(file.readb(mMaxGridPos));
        assert(file.readb(mCellSize));
        assert(file.readb(mXCellCount));
        assert(file.readb(mYCellCount));
        mHalfCellSize = mCellSize * 0.5;
        assert(file.readv(mCells, mXCellCount * mYCellCount));
        assert(file.readb(mXSampledHeightCount));
        assert(file.readb(mYSampledHeightCount));
        assert(file.readb(mXSampledHeightDist));
        assert(file.readb(mYSampledHeightDist));
        assert(file.readv(mSampledHeights,  mXSampledHeightCount * mYSampledHeightCount));
        assert(file.readv(mHintGrid, 900));
    }

    int GetCellIndex(NavGridCell* cell)
    {
        return cell - &mCells[0];
    }

    bool IsValidCell(float inX, float inY, float width, float height, float border)
    {
        return mMaxGridPos.x + mCellSize - width - border >= inX
                && inX >= mMinGridPos.x + border
                && mMaxGridPos.z - height + mCellSize - border >= inY
                && inY >= border + mMinGridPos.z;
    }

    bool IsValidCell(float inX, float inY)
    {
        return mMaxGridPos.x + mCellSize >= inX && inX >= mMinGridPos.x
                && mMaxGridPos.z + mCellSize >= inY && inY >= mMinGridPos.z;
    }

    bool IsValidCellCellUnits(int inX, int inY)
    {
        return !(inX < 0 || inX >= mXCellCount || inY < 0 || inY < mYCellCount);
    }

    r3dPoint3D GetCellCenter(int x, int y)
    {
        r3dPoint3D result;
        if(x < 0)
            x = 0;
        if(x >= mXCellCount)
            x = mXCellCount - 1;
        if(y < 0)
            y = 0;
        if(y >= mYCellCount)
            y = mYCellCount - 1;
        result.x = x * mCellSize + mMinGridPos.x + mHalfCellSize;;
        result.y = mCells[x + y * mXCellCount].mCenterHeight;
        result.z = y * mCellSize + mMinGridPos.z + mHalfCellSize;
        return result;
    }

    r3dPoint3D GetCellCenter(NavGridCellLocator &locator)
    {
        return GetCellCenter(locator.mX, locator.mY);
    }

    void GetCellCenterXY(NavGridCell *cell, float &x, float &y)
    {
        int offset = GetCellIndex(cell);
        x = (double)(offset % mXCellCount) * mCellSize + mMinGridPos.x + mHalfCellSize;
        y = (double)(offset / mXCellCount) * mCellSize + mMinGridPos.z + mHalfCellSize;
    }

    NavGridCellLocator GetCellLocator(r3dPoint3D &inPos)
    {
        NavGridCellLocator outCellLocator;
        outCellLocator.mX = ((inPos.x - mMinGridPos.x) / mCellSize);
        outCellLocator.mY = ((inPos.z - mMinGridPos.z) / mCellSize);
        return outCellLocator;
    }

    NavGridCell* GetCell(int y, int x)
    {
        if(x < 0)
            x = 0;
        if(x >=  mXCellCount)
            x =  mXCellCount - 1;
        if(y < 0)
            y = 0;
        if(y >= mYCellCount)
            y = mYCellCount - 1;
        return &mCells[x + y *  mXCellCount];
    }

    NavGridCell* GetCell(r3dPoint3D &pos)
    {
        return GetCell(((pos.z - mMinGridPos.z) / mCellSize), ((pos.x - mMinGridPos.x) / mCellSize));
    }

    NavGridCell* GetCellInner(int y, int x)
    {
        if(x < 0)
            x = 1;
        if(x >=  mXCellCount)
            x =  mXCellCount - 2;
        if(y < 0)
            y = 1;
        if(y >= mYCellCount)
            y = mYCellCount - 2;
        return &mCells[x + y *  mXCellCount];
    }

    bool IsSolidPassable(r3dPoint3D &pos)
    {
        NavGridCellLocator location = GetCellLocator(pos);
        return GetCell(location.mY, location.mX)->isPassable();
    }
};


#endif // R3DNAVGRID_H
