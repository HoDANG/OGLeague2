#ifndef R3DMESH_H
#define R3DMESH_H

#include <vector>
#include <string>
#include <array>
#include "r3dpoint.h"
#include "r3dbox3d.h"

struct r3dMeshFaceUV
{
    float u;
    float v;
};

struct r3dMeshFace
{
    std::array<uint32_t, 3> mIndices;
    char mMaterialName[64];
    std::array<r3dMeshFaceUV, 3> mUVs;
};

struct r3dMesh
{
    char mName[128];
    uint32_t mVerticeCount;
    uint32_t mFaceCount;
    uint32_t mHasVCP;
    r3dBox3D mBBox;
    std::vector<r3dPoint3D> mVertices;
    r3dPoint3D mCentralPoint;
    std::vector<r3dMeshFace> mFaces;

    void loadBinary(std::string filename);
    void loadAscii(std::string filename);
};

#endif // R3DMESH_H
