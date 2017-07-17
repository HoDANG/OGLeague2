#ifndef COMMONBASICATTACK_H
#define COMMONBASICATTACK_H

#include <inttypes.h>
#include "talent.h"

#pragma pack(push, 1)
struct CommonBasicAttack
{
    unsigned int targetNetID;
    char extraTime;
    unsigned int missileNextID;
    char attackSlot;
};
#pragma pack(pop)
#endif // COMMONBASICATTACK_H
