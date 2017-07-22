#include "scripthelper.h"

void ScriptHelper::Say(sol::stack_object owner, std::string message)
{
}
void ScriptHelper::ApplyStun(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::ApplyPacified(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::ApplyNet(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::ApplyDisarm(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::ApplyRoot(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::ApplySilence(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::ApplySuppression(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::ApplySuppressCallForHelp(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::ApplyIgnoreCallForHelp(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::ApplyCallForHelpSuppresser(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelper::CancelOrder(sol::stack_object owner)
{
}
void ScriptHelper::ChannelingStart(sol::stack_object caster, sol::stack_object target, float duration, float timeBeetwenUpdate)
{
}
void ScriptHelper::ChannelingStop(sol::stack_object caster, int whyStoppedCondition, int whyStoppedSource)
{
}
void ScriptHelper::DrawDefaultHitEffects(sol::stack_object target)
{
}
bool ScriptHelper::GetIsAttackOverride()
{
    return false;
}
int ScriptHelper::GetCastSpellLevelPlusOne()
{
    return 1;
}
sol::object ScriptHelper::GetCastSpellTargetPos()
{
    return sol::nil;
}
int ScriptHelper::GetCastSpellTargetsHitPlusOne()
{
    return 0;
}
sol::object ScriptHelper::GetCastSpellLuaInfo()
{
    return sol::nil;
}
int ScriptHelper::GetCasterID()
{
    return 0;
}
float ScriptHelper::GetHealth(sol::stack_object target, int formal)
{
    return 0;
}
float ScriptHelper::GetHealthPercent(sol::stack_object target ,int formal)
{
    return 0;
}
bool ScriptHelper::GetInvulnerable(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetPhysicalImmune(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetTargetable(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetTargetableToTeam(sol::stack_object target, int team)
{
    return 0;
}
bool ScriptHelper::GetMagicImmune(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPAR(sol::stack_object target, int parType)
{
    return 0;
}
float ScriptHelper::GetPARCost()
{
    return 0;
}
float ScriptHelper::GetPARPercent(sol::stack_object target, int parType)
{
    return 0;
}
int ScriptHelper::GetPARType(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::HasPARType(sol::stack_object target, int parType)
{
    return 0;
}
float ScriptHelper::GetMaxHealth(sol::stack_object target, int formal)
{
    return 0;
}
float ScriptHelper::GetMaxPAR(sol::stack_object target,int parType)
{
    return 0;
}
std::string ScriptHelper::GetName(sol::stack_object obj)
{
    return "";
}
float ScriptHelper::GetArmor(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetSpellBlock(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetDodge(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetMissChance(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetAttackSpeedMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetMovementSpeed(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetLevel(sol::stack_object  target)
{
    return 0;
}
float ScriptHelper::GetTotalAttackDamage(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetSlotSpellCooldownTime(sol::stack_object target, int slot, int spellbookType, int slotType)
{
    return 0;
}
int ScriptHelper::GetSlotSpellLevel(sol::stack_object target, int slot, int spellbookType, int slotType)
{
    return 0;
}
std::string ScriptHelper::GetSlotSpellName(sol::stack_object target, int slot, int spellbookType, int slotType)
{
    return "";
}
std::string ScriptHelper::GetSpellName()
{
    return "";
}
int ScriptHelper::GetSpellSlot()
{
    return 0;
}

bool ScriptHelper::GetNoRender(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetBrushVisibilityFake(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetForceRenderParticles(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetStealthed(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetRevealSpecificUnit(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetTaunted(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetCharmed(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetSuppressed(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetFeared(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetDisableAmbientGold(sol::stack_object target)
{
    return 0;
}
void ScriptHelper::SetDisableAmbientGold(sol::stack_object target, bool value)
{
}
bool ScriptHelper::GetSleep(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetNearSight(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetGhosted(sol::stack_object target)
{
    return 0;
}
bool ScriptHelper::GetGhostProof(sol::stack_object target)
{
    return 0;
}

void ScriptHelper::IncHealth(sol::stack_object target, float value)
{
}
void ScriptHelper::IncMana(sol::stack_object target, float value)
{
}
void ScriptHelper::IncMoveSpeedFloorMod(float value, sol::stack_object target)
{
}
void ScriptHelper::IncFlatDodgeMod(float value, sol::stack_object target)
{
}
void ScriptHelper::IncFlatMissChanceMod(float value, sol::stack_object target)
{
}
void ScriptHelper::IncPercentArmorPenetrationMod(float value, sol::stack_object target)
{
}
void ScriptHelper::IncPercentMagicPenetrationMod(float value, sol::stack_object target)
{
}
void ScriptHelper::IncPercentMultiplicativeAttackSpeedMod(float value, sol::stack_object target)
{
}
void ScriptHelper::IncPercentMultiplicativeMovementSpeedMod(float value, sol::stack_object target)
{
}

void ScriptHelper::IssueOrder(sol::stack_object owner,int order, sol::stack_object pos, sol::stack_object caster)
{
}
void ScriptHelper::RaiseSpellFlag(int flag)
{
}
void ScriptHelper::ReincarnateNonDeadHero(sol::stack_object target)
{
}

void ScriptHelper::SetCanCastWhileDisabled(bool value)
{
}
void ScriptHelper::SetInvulnerable(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetTargetable(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetNotTargetableToTeam(sol::stack_object target, bool value, int team)
{
}
void ScriptHelper::SetPhysicalImmune(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetMagicImmune(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetRooted(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetScaleSkinCoef(float coef, sol::stack_object target)
{
}
void ScriptHelper::SetSilenced(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetSlotSpellCooldownTime(sol::stack_object target, int slot,int spellbookType ,int slotType, float time)
{
}
void ScriptHelper::SetStealthed(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetRevealSpecificUnit(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetStunned(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetPacified(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetNetted(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetDisarmed(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetTaunted(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetCharmed(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetFeared(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetSleep(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetNearSight(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetNoRender(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetForceRenderParticles(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetGhosted(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetSuppressed(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetGhostProof(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetSuppressCallForHelp(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetCallForHelpSuppresser(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetBrushVisibilityFake(sol::stack_object target, bool value)
{
}
void ScriptHelper::SetIgnoreCallForHelp(sol::stack_object target, bool value)
{
}

void ScriptHelper::SpellBuffAdd(sol::stack_object caster, sol::stack_object target, std::string name, int type, int maxStack, float duration, sol::stack_object luaBuffVars)
{
}
void ScriptHelper::SpellBuffAddNoRenew(sol::stack_object caster, sol::stack_object target, std::string name, int type, int maxStack, float duration, sol::stack_object luaBuffVars)
{
}
int ScriptHelper::SpellBuffCount(sol::stack_object target, std::string name, sol::stack_object caster)
{
    return 0;
}
void ScriptHelper::SpellBuffRemove(sol::stack_object target, std::string name, sol::stack_object caster)
{
}
void ScriptHelper::SpellBuffRemoveCurrent(sol::stack_object target)
{
}
void ScriptHelper::SpellBuffRemoveType(sol::stack_object target, int type)
{
}
bool ScriptHelper::HasBuffOfType(sol::stack_object target, int type)
{
    return false;
}
unsigned long ScriptHelper::SpellEffectCreate(std::string effectName,sol::stack_object pos, sol::stack_object bindObject ,sol::stack_object flags)
{
    return 0;
}
void ScriptHelper::TeleportToKeyLocation(sol::stack_object owner, int locationEnum, int team)
{
}
void ScriptHelper::TeleportToPosition(sol::stack_object owner, sol::stack_object position)
{
}
int ScriptHelper::GetAIState(sol::stack_object target)
{
    return 0;
}

bool ScriptHelper::GetCanAttack(sol::stack_object target)
{
    return false;
}
bool ScriptHelper::GetCanCast(sol::stack_object target)
{
    return false;
}
bool ScriptHelper::IsAutoCastOn(sol::stack_object target)
{
    return false;
}
bool ScriptHelper::GetCanMove(sol::stack_object target)
{
    return false;
}
void ScriptHelper::SetCanAttack(sol::stack_object target, bool state)
{
}
void ScriptHelper::SetCanCast(sol::stack_object target, bool state)
{
}
void ScriptHelper::SetCanMove(sol::stack_object target, bool state)
{
}

bool ScriptHelper::IsBaseAI(sol::stack_object obj)
{
    return false;
}
bool ScriptHelper::IsHeroAI(sol::stack_object obj)
{
    return false;
}
bool ScriptHelper::IsMelee(sol::stack_object obj)
{
    return false;
}
bool ScriptHelper::IsRanged(sol::stack_object obj)
{
    return false;
}
bool ScriptHelper::IsMoving(sol::stack_object obj)
{
    return false;
}

void ScriptHelper::IncFlatGoldPer10Mod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatGoldPer10Mod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncBaseAttackDamage(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentBaseAttackDamage(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatArmorMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatArmorMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatArmorPenetrationMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatArmorPenetrationMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatMagicPenetrationMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatMagicPenetrationMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatSpellBlockMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatSpellBlockMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatAttackRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatAttackRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatCastRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatCastRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatCooldownMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatCooldownMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatCritChanceMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatCritChanceMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatCritDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatCritDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatHPPoolMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatHPPoolMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatHPRegenMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatHPRegenMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatMagicDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatMagicDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatMagicReduction(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatMagicReduction(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatMovementSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatMovementSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatPhysicalDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatPhysicalDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatPhysicalReduction(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatPhysicalReduction(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncFlatBubbleRadiusMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentFlatBubbleRadiusMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentHardnessMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentHardnessMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentArmorMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentArmorMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentSpellBlockMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentSpellBlockMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentAttackRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentAttackRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentAttackSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentAttackSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentCastRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentCastRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentCooldownMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentCooldownMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentCritDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentCritDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentEXPBonus(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentEXPBonus(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentHPPoolMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentHPPoolMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentHPRegenMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentHPRegenMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentHealingAmountMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentHealingAmountMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentLifeStealMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentLifeStealMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentSpellVampMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentSpellVampMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentMagicDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentMagicDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentMagicReduction(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentMagicReduction(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentMovementSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentMovementSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentPhysicalDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentPhysicalDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentPhysicalReduction(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentPhysicalReduction(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentRespawnTimeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentRespawnTimeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentGoldLostOnDeathMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentGoldLostOnDeathMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPercentBubbleRadiusMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentPercentBubbleRadiusMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncAcquisitionRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelper::IncPermanentAcquisitionRangeMod(float delta, sol::stack_object target)
{
}
float ScriptHelper::GetFlatGoldPer10Mod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetBaseAttackDamage(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatArmorMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatArmorPenetrationMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatMagicPenetrationMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatSpellBlockMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatAttackRangeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatCastRangeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatCooldownMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatCritChanceMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatCritDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatHPPoolMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatHPRegenMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatMagicDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatMagicReduction(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatMovementSpeedMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatPhysicalDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatPhysicalReduction(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetFlatBubbleRadiusMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentHardnessMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentArmorMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentSpellBlockMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentAttackRangeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentAttackSpeedMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentCastRangeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentCooldownMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentCritDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentEXPBonus(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentHPPoolMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentHPRegenMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentHealingAmountMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentLifeStealMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentSpellVampMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentMagicDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentMagicReduction(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentMovementSpeedMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentPhysicalDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentPhysicalReduction(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentRespawnTimeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentGoldLostOnDeathMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetPercentBubbleRadiusMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelper::GetAcquisitionRangeMod(sol::stack_object target)
{
    return 0;
}
