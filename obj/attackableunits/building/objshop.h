#ifndef OBJSHOP_H
#define OBJSHOP_H

#include "objbuilding.h"

class ObjShop : public ObjBuilding
{
public:
    ObjShop(World *world);
    bool Load(std::string name);
};

#endif // OBJSHOP_H
