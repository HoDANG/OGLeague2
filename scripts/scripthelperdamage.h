#ifndef SCRIPTHELPERDAMAGE_H
#define SCRIPTHELPERDAMAGE_H

#include "dep/sol.hpp"
#include "dep/r3d.hpp"
#include <inttypes.h>

enum DamageTypes : uint8_t
{
  PHYSICAL_DAMAGE = 0x0,
  MAGIC_DAMAGE = 0x1,
  TRUE_DAMAGE = 0x2,
  MIXED_DAMAGE = 0x3,
};

enum DamageSource : uint8_t
{
  DAMAGESOURCE_RAW = 0x0,
  DAMAGESOURCE_INTERNALRAW = 0x1,
  DAMAGESOURCE_PERIODIC = 0x2,
  DAMAGESOURCE_PROC = 0x3,
  DAMAGESOURCE_REACTIVE = 0x4,
  DAMAGESOURCE_ONDEATH = 0x5,
  DAMAGESOURCE_SPELL = 0x6,
  DAMAGESOURCE_ATTACK = 0x7,
  DAMAGESOURCE_DEFAULT = 0x8,
  DAMAGESOURCE_SPELLAOE = 0x9,
  DAMAGESOURCE_SPELLPERSIST = 0xA,
  DAMAGESOURCE_Numof = 0xB,
};

struct DamageInfo
{
  DamageTypes mDamageType;
  DamageSource mSpellSourceType;
};

struct ScriptHelperDamage
{
    static DamageInfo* sDamageInfo;

    static void RegisterGlobals(sol::global_table state);

    static int GetDamageType();
    static int GetSourceType();
    static float GetDamageAmount();
    static float GetPercentageOfAttack();
    static sol::object GetAttacker();
    static int GetHitResult();
};

#endif // SCRIPTHELPERDAMAGE_H
