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
    r3dPoint3D Normalize()
    {
        r3dPoint3D result;
        double tmp = 1.0 / sqrt(y*y +x*x + z+z);
        result.x = tmp * x;
        result.y = tmp * y;
        result.z = tmp * z;
        return result;
    }
    r3dPoint3D& operator=(std::array<float,3> arr)
    {
        this->x = arr[0];
        this->y = arr[1];
        this->z = arr[2];
        return *this;
    }
};

#endif // RD3POINT_H
