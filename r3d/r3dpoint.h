#ifndef RD3POINT_H
#define RD3POINT_H

#include <math.h>
#include <array>

struct r3dPoint2D
{
    float x = 0.0;
    float y = 0.0;
};

struct r3dPoint3D
{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    r3dPoint3D();
    r3dPoint3D(float X, float Y, float Z);
    r3dPoint3D Normalize();
    r3dPoint3D& operator=(std::array<float,3> arr);
};

#endif // RD3POINT_H
