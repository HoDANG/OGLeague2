#ifndef SCRIPTHELPERDAMAGE_H
#define SCRIPTHELPERDAMAGE_H

#include <inttypes.h>
#include "sol.hpp"
#include "r3d.hpp"
#include "common/damageinfo.h"

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
