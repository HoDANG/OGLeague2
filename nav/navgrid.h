#ifndef NAVGRID_H
#define NAVGRID_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "../dep/r3d.hpp"
#include "navgridcell.h"

struct NavHintGridNode
{
  float mDistances[900];
  NavGridCellLocator mLocator;
};

class NavGrid
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
};


#endif // NAVGRID_H
