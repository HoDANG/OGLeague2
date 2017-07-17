#ifndef HPP_032_PKT_CHAR_SpawnPet_HPP
#define HPP_032_PKT_CHAR_SpawnPet_HPP
#include "base.hpp"

#pragma pack(push, 1)
struct PKT_CHAR_SpawnPet_s : DefaultPacket<PKT_CHAR_SpawnPet>
{
  unsigned int netObjID;
  char netNodeID;
  r3dPoint3D pos;
  int castSpellLevelPlusOne;
  float duration;
  int DamageBonus;
  int HealthBonus;
  char name[32];
  char skin[32];
  int skinID;
  char buffName[64];
  unsigned int cloneID;
  int8_t copyInventory : 1;
  char aiscript[32];
};
#pragma pack(pop)

#endif
