#include "r3dnavgrid.h"
#include "r3dfile.h"
#include <cassert>

bool NavGridCell::isPassable() const
{
    return !mFlags.mNotPassable;
}

void r3dNavGrid::load(std::string name)
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

int r3dNavGrid::GetCellIndex(NavGridCell *cell)
{
    return cell - &mCells[0];
}

bool r3dNavGrid::IsValidCell(float inX, float inY, float width, float height, float border)
{
    return mMaxGridPos.x + mCellSize - width - border >= inX
            && inX >= mMinGridPos.x + border
            && mMaxGridPos.z - height + mCellSize - border >= inY
            && inY >= border + mMinGridPos.z;
}

bool r3dNavGrid::IsValidCell(float inX, float inY)
{
    return mMaxGridPos.x + mCellSize >= inX && inX >= mMinGridPos.x
            && mMaxGridPos.z + mCellSize >= inY && inY >= mMinGridPos.z;
}

bool r3dNavGrid::IsValidCellCellUnits(int inX, int inY)
{
    return !(inX < 0 || inX >= mXCellCount || inY < 0 || inY < mYCellCount);
}

r3dPoint3D r3dNavGrid::GetCellCenter(int x, int y)
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

r3dPoint3D r3dNavGrid::GetCellCenter(NavGridCellLocator &locator)
{
    return GetCellCenter(locator.mX, locator.mY);
}

void r3dNavGrid::GetCellCenterXY(NavGridCell *cell, float &x, float &y)
{
    int offset = GetCellIndex(cell);
    x = (double)(offset % mXCellCount) * mCellSize + mMinGridPos.x + mHalfCellSize;
    y = (double)(offset / mXCellCount) * mCellSize + mMinGridPos.z + mHalfCellSize;
}

NavGridCellLocator r3dNavGrid::GetCellLocator(r3dPoint3D &inPos)
{
    NavGridCellLocator outCellLocator;
    outCellLocator.mX = ((inPos.x - mMinGridPos.x) / mCellSize);
    outCellLocator.mY = ((inPos.z - mMinGridPos.z) / mCellSize);
    return outCellLocator;
}

NavGridCell *r3dNavGrid::GetCell(int y, int x)
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

NavGridCell *r3dNavGrid::GetCell(r3dPoint3D &pos)
{
    return GetCell(((pos.z - mMinGridPos.z) / mCellSize), ((pos.x - mMinGridPos.x) / mCellSize));
}

NavGridCell *r3dNavGrid::GetCellInner(int y, int x)
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

bool r3dNavGrid::IsSolidPassable(r3dPoint3D &pos)
{
    NavGridCellLocator location = GetCellLocator(pos);
    return GetCell(location.mY, location.mX)->isPassable();
}
