#include "scripthelperdamage.h"

DamageInfo* ScriptHelperDamage::sDamageInfo = nullptr;

void ScriptHelperDamage::RegisterGlobals(sol::global_table state)
{
    state["DAMAGESOURCE_RAW"] = 0;
    state["DAMAGESOURCE_INTERNALRAW"] = 1;
    state["DAMAGESOURCE_PERIODIC"] = 2;
    state["DAMAGESOURCE_PROC"] = 3;
    state["DAMAGESOURCE_REACTIVE"] = 4;
    state["DAMAGESOURCE_ONDEATH"] = 5;
    state["DAMAGESOURCE_SPELL"] = 6;
    state["DAMAGESOURCE_ATTACK"] = 7;
    state["DAMAGESOURCE_DEFAULT"] = 8;
    state["DAMAGESOURCE_SPELLAOE"] = 9;
    state["DAMAGESOURCE_SPELLPERSIST"] = 10;

    state["GetDamageType"] = &ScriptHelperDamage::GetDamageType;
    state["GetSourceType"] = &ScriptHelperDamage::GetSourceType;
    state["GetDamageAmount"] = &ScriptHelperDamage::GetDamageAmount;
    state["GetPercentageOfAttack"] = &ScriptHelperDamage::GetPercentageOfAttack;
    state["GetAttacker"] = &ScriptHelperDamage::GetAttacker;
    state["GetHitResult"] = &ScriptHelperDamage::GetHitResult;
}

int ScriptHelperDamage::GetDamageType()
{
    if(sDamageInfo == nullptr)
        return 0;
    return sDamageInfo->mDamageType;
}

int ScriptHelperDamage::GetSourceType()
{
    if(sDamageInfo == nullptr)
        return 0;
    return sDamageInfo->mSpellSourceType;
}

//Low priority
float ScriptHelperDamage::GetDamageAmount()
{
    return float();
}

float ScriptHelperDamage::GetPercentageOfAttack()
{
    return float();
}

sol::object ScriptHelperDamage::GetAttacker()
{
    return sol::object();
}

int ScriptHelperDamage::GetHitResult()
{
    return int();
}
