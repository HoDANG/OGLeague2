#ifndef ORDERINFO_H
#define ORDERINFO_H
#include <inttypes.h>
#include "r3d.hpp"

#pragma pack(push, 1)
struct OrderInfo
{
    char order;
    r3dPoint3D pos;
    unsigned int targetNetID;
};
#pragma pack(pop)

#endif // ORDERINFO_H
