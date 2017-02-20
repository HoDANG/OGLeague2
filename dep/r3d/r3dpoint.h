#ifndef RD3POINT_H
#define RD3POINT_H

#include <math.h>

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
    r3dPoint3D Normalize()
    {
        r3dPoint3D result;
        double tmp = 1.0 / sqrt(y*y +x*x + z+z);
        result.x = tmp * x;
        result.y = tmp * y;
        result.z = tmp * z;
        return result;
    }
};

#endif // RD3POINT_H
