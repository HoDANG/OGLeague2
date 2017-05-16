#include "scripthelperextra.h"


void ScriptHelperExtra::RegisterGlobals(sol::global_table state)
{
    state["DefUpdateAura"] = &ScriptHelperExtra::DefUpdateAura;
    state["BBIsTargetBehindMe"] = &ScriptHelperExtra::BBIsTargetBehindMe;
    state["BBIsTargetInFrontOfMe"] = &ScriptHelperExtra::BBIsTargetInFrontOfMe;
    state["IsDead"] = &ScriptHelperExtra::IsDead;
    state["DistanceBetweenObjects"] = &ScriptHelperExtra::DistanceBetweenObjects;
    state["DistanceBetweenObjectAndPoint"] = &ScriptHelperExtra::DistanceBetweenObjectAndPoint;
    state["DistanceBetweenPoints"] = &ScriptHelperExtra::DistanceBetweenPoints;
    state["SetSpellCastRange"] = &ScriptHelperExtra::SetSpellCastRange;
}

void ScriptHelperExtra::DefUpdateAura(sol::stack_object centerObj, float range, int scanType, std::string buffName)
{

}

bool ScriptHelperExtra::BBIsTargetBehindMe(sol::stack_object target, sol::stack_object owner)
{
    return bool();
}

bool ScriptHelperExtra::BBIsTargetInFrontOfMe(sol::stack_object target, sol::stack_object owner)
{
    return bool();
}

bool ScriptHelperExtra::IsDead(sol::stack_object target)
{
    return bool();
}

float ScriptHelperExtra::DistanceBetweenObjects(sol::stack_object obj1, sol::stack_object obj2)
{
    return float();
}

float ScriptHelperExtra::DistanceBetweenObjectAndPoint(sol::stack_object obj1, sol::stack_object point)
{
    return float();
}

float ScriptHelperExtra::DistanceBetweenPoints(sol::stack_object point1, sol::stack_object point2)
{
    return float();
}

void ScriptHelperExtra::SetSpellCastRange(float newRange)
{

}
