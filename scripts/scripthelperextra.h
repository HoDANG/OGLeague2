#ifndef SCRIPTHELPEREXTRA_H
#define SCRIPTHELPEREXTRA_H

#include "dep/sol.hpp"
#include "dep/r3d.hpp"

struct ScriptHelperExtra
{
    static void RegisterGlobals(sol::global_table state);

    static void DefUpdateAura(sol::stack_object centerObj, float range, int scanType, std::string buffName);
    static bool BBIsTargetBehindMe(sol::stack_object target, sol::stack_object owner);
    static bool BBIsTargetInFrontOfMe(sol::stack_object target, sol::stack_object owner);
    static bool IsDead(sol::stack_object target);
    static float DistanceBetweenObjects(sol::stack_object obj1, sol::stack_object obj2);
    static float DistanceBetweenObjectAndPoint(sol::stack_object obj1, sol::stack_object point);
    static float DistanceBetweenPoints(sol::stack_object point1, sol::stack_object point2);
    static void SetSpellCastRange(float newRange);
};


#endif // SCRIPTHELPEREXTRA_H
