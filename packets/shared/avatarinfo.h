#ifndef AVATARINFO_H
#define AVATARINFO_H

#include <inttypes.h>
#include "talent.h"

#pragma pack(push, 1)
struct AvatarInfo
{
  unsigned int itemIDs[30];
  unsigned int spellHashes[2];
  Talent TalentsHashes[80];
  char level;
};
#pragma pack(pop)

#endif // AVATARINFO_H
