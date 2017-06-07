#include "r3dmesh.h"
#include "r3dfile.h"
#include <cassert>

void r3dMesh::loadBinary(std::string filename)
{
    uint64_t signature;
    uint16_t minor;
    uint16_t major;
    r3dFile file(filename, std::ios::binary);

    assert(file.is_open());
    assert(file.readb(signature));
    assert(signature == 0x6873654d32643372); //r3d2Mesh
    assert(file.readb(major));
    assert(file.readb(minor));
    assert(major == 2);
    assert(minor == 2);
    assert(file.readb(mName));
    assert(file.readb(mVerticeCount));
    assert(file.readb(mFaceCount));
    assert(file.readb(mHasVCP));
    assert(file.readb(mBBox));
    assert(file.readv(mVertices, mVerticeCount));
    assert(file.readb(mCentralPoint));
    assert(file.readv(mFaces, mFaceCount));
    //Some color shit at the end
}

void r3dMesh::loadAscii(std::string filename)
{
    std::string line;
    r3dFile file(filename);
    assert(file.is_open());
    int indiceCount;
    while(file>>line)
    {
        if(line == "[ObjectBegin]")
            continue;
        else if(line == "[ObjectEnd]")
            break;
        else if(line == "Name=")
            file>>mName;
        else if(line == "CentralPoint=")
            file>>mCentralPoint.x
                    >>mCentralPoint.y
                    >>mCentralPoint.z;
        else if(line == "Verts=")
        {
            file>>mVerticeCount;
            mVertices.resize(mVerticeCount);
            for(uint32_t i = 0; i<mVerticeCount; i++)
                file>>mVertices[i].x
                        >>mVertices[i].y
                        >>mVertices[i].z;
        }
        else if(line == "Faces=")
        {
            file>>mFaceCount;
            mFaces.resize(mFaceCount);
            for(uint32_t i = 0; i<mFaceCount; i++)
                file>>indiceCount
                        >>mFaces[i].mIndices[0]>>mFaces[i].mIndices[1]>>mFaces[i].mIndices[2]
                        >>mFaces[i].mMaterialName
                        >>mFaces[i].mUVs[0].u>>mFaces[i].mUVs[0].v
                        >>mFaces[i].mUVs[1].u>>mFaces[i].mUVs[1].v
                        >>mFaces[i].mUVs[2].u>>mFaces[i].mUVs[2].v;
        }
    }
}
