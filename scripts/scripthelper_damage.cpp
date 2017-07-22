#include "scripthelper.h"
#include "common/damageinfo.h"

int ScriptHelper::GetDamageType()
{
    if(sDamageInfo == nullptr)
        return 0;
    return sDamageInfo->mDamageType;
}

int ScriptHelper::GetSourceType()
{
    if(sDamageInfo == nullptr)
        return 0;
    return sDamageInfo->mSpellSourceType;
}

float ScriptHelper::GetDamageAmount()
{
    return float();
}

float ScriptHelper::GetPercentageOfAttack()
{
    return float();
}

sol::object ScriptHelper::GetAttacker()
{
    return sol::object();
}

int ScriptHelper::GetHitResult()
{
    return int();
}
