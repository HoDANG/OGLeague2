#ifndef PLAYERLITEINFO_H
#define PLAYERLITEINFO_H

#include <stdint.h>

struct PlayerLiteInfo
{
    uint64_t ID = 0;
    uint16_t summonorLevel = 0;
    uint32_t summonorSpell1 = 0;
    uint32_t summonorSpell2 = 0;
};

#endif // PLAYERLITEINFO_H
