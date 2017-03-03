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


#endif // NAVGRID_H
