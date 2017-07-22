#include "scripthelper.h"

void ScriptHelper::DefUpdateAura(sol::stack_object centerObj, float range, int scanType, std::string buffName)
{

}

bool ScriptHelper::BBIsTargetBehindMe(sol::stack_object target, sol::stack_object owner)
{
    return bool();
}

bool ScriptHelper::BBIsTargetInFrontOfMe(sol::stack_object target, sol::stack_object owner)
{
    return bool();
}

bool ScriptHelper::IsDead(sol::stack_object target)
{
    return bool();
}

float ScriptHelper::DistanceBetweenObjects(sol::stack_object obj1, sol::stack_object obj2)
{
    return float();
}

float ScriptHelper::DistanceBetweenObjectAndPoint(sol::stack_object obj1, sol::stack_object point)
{
    return float();
}

float ScriptHelper::DistanceBetweenPoints(sol::stack_object point1, sol::stack_object point2)
{
    return float();
}

void ScriptHelper::SetSpellCastRange(float newRange)
{

}
