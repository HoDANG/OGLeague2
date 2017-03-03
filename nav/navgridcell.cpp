#include "navgridcell.h"

bool NavGridCell::isPassable()
{
    return !mFlags.mNotPassable;
}
