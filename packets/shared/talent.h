#ifndef TALENT_H
#define TALENT_H

#include <inttypes.h>

#pragma pack(push, 1)
struct Talent
{
    uint32_t hash;
    int8_t level;
};
#pragma pack(pop)

#endif // TALENT_H
