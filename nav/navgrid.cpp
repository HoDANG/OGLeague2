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
