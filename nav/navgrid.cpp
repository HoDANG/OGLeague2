#include "navgrid.h"

void NavGrid::load(std::string name)
{
    uint8_t majorVersion;
    r3dFile file(name);
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

int NavGrid::GetCellIndex(NavGridCell *cell)
{
    return cell - &mCells[0];
}

bool NavGrid::IsValidCell(float inX, float inY, float width, float height, float border)
{
    return mMaxGridPos.x + mCellSize - width - border >= inX
            && inX >= mMinGridPos.x + border
            && mMaxGridPos.z - height + mCellSize - border >= inY
            && inY >= border + mMinGridPos.z;
}

bool NavGrid::IsValidCell(float inX, float inY)
{
    return mMaxGridPos.x + mCellSize >= inX && inX >= mMinGridPos.x
            && mMaxGridPos.z + mCellSize >= inY && inY >= mMinGridPos.z;
}

bool NavGrid::IsValidCellCellUnits(int inX, int inY)
{
    return !(inX < 0 || inX >= mXCellCount || inY < 0 || inY < mYCellCount);
}

r3dPoint3D NavGrid::GetCellCenter(int x, int y)
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


r3dPoint3D NavGrid::GetCellCenter(NavGridCellLocator &locator)
{
    return GetCellCenter(locator.mX, locator.mY);
}

void NavGrid::GetCellCenterXY(NavGridCell *cell, float &x, float &y)
{
    int offset = GetCellIndex(cell);
    x = (double)(offset % mXCellCount) * mCellSize + mMinGridPos.x + mHalfCellSize;
    y = (double)(offset / mXCellCount) * mCellSize + mMinGridPos.z + mHalfCellSize;
}

NavGridCellLocator NavGrid::GetCellLocator(r3dPoint3D &inPos)
{
    NavGridCellLocator outCellLocator;
    outCellLocator.mX = ((inPos.x - mMinGridPos.x) / mCellSize);
    outCellLocator.mY = ((inPos.z - mMinGridPos.z) / mCellSize);
    return outCellLocator;
}

NavGridCell *NavGrid::GetCell(int y, int x)
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

NavGridCell *NavGrid::GetCell(r3dPoint3D &pos)
{
    return GetCell(((pos.z - mMinGridPos.z) / mCellSize), ((pos.x - mMinGridPos.x) / mCellSize));
}

NavGridCell *NavGrid::GetCellInner(int y, int x)
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

bool NavGrid::IsSolidPassable(r3dPoint3D &pos)
{
    NavGridCellLocator location = GetCellLocator(pos);
    return GetCell(location.mY, location.mX)->isPassable();
}

