#include "r3dpoint.h"



r3dPoint3D::r3dPoint3D() : x(0), y(0), z(0)
{

}

r3dPoint3D::r3dPoint3D(float X, float Y, float Z) : x(X), y(Y), z(Z)
{

}

r3dPoint3D r3dPoint3D::Normalize()
{
    r3dPoint3D result;
    double tmp = 1.0 / sqrt(y*y +x*x + z+z);
    result.x = tmp * x;
    result.y = tmp * y;
    result.z = tmp * z;
    return result;
}

r3dPoint3D &r3dPoint3D::operator=(std::array<float, 3> arr)
{
    this->x = arr[0];
    this->y = arr[1];
    this->z = arr[2];
    return *this;
}
