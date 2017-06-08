#include "scripthelperspells.h"

void ScriptHelperSpells::Say(sol::stack_object owner, std::string message)
{
}
void ScriptHelperSpells::ApplyStun(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::ApplyPacified(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::ApplyNet(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::ApplyDisarm(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::ApplyRoot(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::ApplySilence(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::ApplySuppression(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::ApplySuppressCallForHelp(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::ApplyIgnoreCallForHelp(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::ApplyCallForHelpSuppresser(sol::stack_object owner, sol::stack_object target, float duration)
{
}
void ScriptHelperSpells::CancelOrder(sol::stack_object owner)
{
}
void ScriptHelperSpells::ChannelingStart(sol::stack_object caster, sol::stack_object target, float duration, float timeBeetwenUpdate)
{
}
void ScriptHelperSpells::ChannelingStop(sol::stack_object caster, int whyStoppedCondition, int whyStoppedSource)
{
}
void ScriptHelperSpells::DrawDefaultHitEffects(sol::stack_object target)
{
}
bool ScriptHelperSpells::GetIsAttackOverride()
{
    return false;
}
int ScriptHelperSpells::GetCastSpellLevelPlusOne()
{
    return 1;
}
sol::object ScriptHelperSpells::GetCastSpellTargetPos()
{
    return sol::nil;
}
int ScriptHelperSpells::GetCastSpellTargetsHitPlusOne()
{
    return 0;
}
sol::object ScriptHelperSpells::GetCastSpellLuaInfo()
{
    return sol::nil;
}
int ScriptHelperSpells::GetCasterID()
{
    return 0;
}
float ScriptHelperSpells::GetHealth(sol::stack_object target, int formal)
{
    return 0;
}
float ScriptHelperSpells::GetHealthPercent(sol::stack_object target ,int formal)
{
    return 0;
}
bool ScriptHelperSpells::GetInvulnerable(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetPhysicalImmune(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetTargetable(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetTargetableToTeam(sol::stack_object target, int team)
{
    return 0;
}
bool ScriptHelperSpells::GetMagicImmune(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPAR(sol::stack_object target, int parType)
{
    return 0;
}
float ScriptHelperSpells::GetPARCost()
{
    return 0;
}
float ScriptHelperSpells::GetPARPercent(sol::stack_object target, int parType)
{
    return 0;
}
int ScriptHelperSpells::GetPARType(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::HasPARType(sol::stack_object target, int parType)
{
    return 0;
}
float ScriptHelperSpells::GetMaxHealth(sol::stack_object target, int formal)
{
    return 0;
}
float ScriptHelperSpells::GetMaxPAR(sol::stack_object target,int parType)
{
    return 0;
}
std::string ScriptHelperSpells::GetName(sol::stack_object obj)
{
    return "";
}
float ScriptHelperSpells::GetArmor(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetSpellBlock(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetDodge(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetMissChance(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetAttackSpeedMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetMovementSpeed(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetLevel(sol::stack_object  target)
{
    return 0;
}
float ScriptHelperSpells::GetTotalAttackDamage(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetSlotSpellCooldownTime(sol::stack_object target, int slot, int spellbookType, int slotType)
{
    return 0;
}
int ScriptHelperSpells::GetSlotSpellLevel(sol::stack_object target, int slot, int spellbookType, int slotType)
{
    return 0;
}
std::string ScriptHelperSpells::GetSlotSpellName(sol::stack_object target, int slot, int spellbookType, int slotType)
{
    return "";
}
std::string ScriptHelperSpells::GetSpellName()
{
    return "";
}
int ScriptHelperSpells::GetSpellSlot()
{
    return 0;
}

bool ScriptHelperSpells::GetNoRender(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetBrushVisibilityFake(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetForceRenderParticles(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetStealthed(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetRevealSpecificUnit(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetTaunted(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetCharmed(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetSuppressed(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetFeared(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetDisableAmbientGold(sol::stack_object target)
{
    return 0;
}
void ScriptHelperSpells::SetDisableAmbientGold(sol::stack_object target, bool value)
{
}
bool ScriptHelperSpells::GetSleep(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetNearSight(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetGhosted(sol::stack_object target)
{
    return 0;
}
bool ScriptHelperSpells::GetGhostProof(sol::stack_object target)
{
    return 0;
}

void ScriptHelperSpells::IncHealth(sol::stack_object target, float value)
{
}
void ScriptHelperSpells::IncMana(sol::stack_object target, float value)
{
}
void ScriptHelperSpells::IncMoveSpeedFloorMod(float value, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatDodgeMod(float value, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatMissChanceMod(float value, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentArmorPenetrationMod(float value, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentMagicPenetrationMod(float value, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentMultiplicativeAttackSpeedMod(float value, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentMultiplicativeMovementSpeedMod(float value, sol::stack_object target)
{
}

void ScriptHelperSpells::IssueOrder(sol::stack_object owner,int order, sol::stack_object pos, sol::stack_object caster)
{
}
void ScriptHelperSpells::RaiseSpellFlag(int flag)
{
}
void ScriptHelperSpells::ReincarnateNonDeadHero(sol::stack_object target)
{
}

void ScriptHelperSpells::SetCanCastWhileDisabled(bool value)
{
}
void ScriptHelperSpells::SetInvulnerable(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetTargetable(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetNotTargetableToTeam(sol::stack_object target, bool value, int team)
{
}
void ScriptHelperSpells::SetPhysicalImmune(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetMagicImmune(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetRooted(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetScaleSkinCoef(float coef, sol::stack_object target)
{
}
void ScriptHelperSpells::SetSilenced(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetSlotSpellCooldownTime(sol::stack_object target, int slot,int spellbookType ,int slotType, float time)
{
}
void ScriptHelperSpells::SetStealthed(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetRevealSpecificUnit(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetStunned(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetPacified(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetNetted(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetDisarmed(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetTaunted(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetCharmed(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetFeared(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetSleep(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetNearSight(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetNoRender(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetForceRenderParticles(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetGhosted(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetSuppressed(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetGhostProof(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetSuppressCallForHelp(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetCallForHelpSuppresser(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetBrushVisibilityFake(sol::stack_object target, bool value)
{
}
void ScriptHelperSpells::SetIgnoreCallForHelp(sol::stack_object target, bool value)
{
}

void ScriptHelperSpells::SpellBuffAdd(sol::stack_object caster, sol::stack_object target, std::string name, int type, int maxStack, float duration, sol::stack_object luaBuffVars)
{
}
void ScriptHelperSpells::SpellBuffAddNoRenew(sol::stack_object caster, sol::stack_object target, std::string name, int type, int maxStack, float duration, sol::stack_object luaBuffVars)
{
}
int ScriptHelperSpells::SpellBuffCount(sol::stack_object target, std::string name, sol::stack_object caster)
{
    return 0;
}
void ScriptHelperSpells::SpellBuffRemove(sol::stack_object target, std::string name, sol::stack_object caster)
{
}
void ScriptHelperSpells::SpellBuffRemoveCurrent(sol::stack_object target)
{
}
void ScriptHelperSpells::SpellBuffRemoveType(sol::stack_object target, int type)
{
}
bool ScriptHelperSpells::HasBuffOfType(sol::stack_object target, int type)
{
    return false;
}
unsigned long ScriptHelperSpells::SpellEffectCreate(std::string effectName,sol::stack_object pos, sol::stack_object bindObject ,sol::stack_object flags)
{
    return 0;
}
void ScriptHelperSpells::TeleportToKeyLocation(sol::stack_object owner, int locationEnum, int team)
{
}
void ScriptHelperSpells::TeleportToPosition(sol::stack_object owner, sol::stack_object position)
{
}
int ScriptHelperSpells::GetAIState(sol::stack_object target)
{
    return 0;
}

bool ScriptHelperSpells::GetCanAttack(sol::stack_object target)
{
    return false;
}
bool ScriptHelperSpells::GetCanCast(sol::stack_object target)
{
    return false;
}
bool ScriptHelperSpells::IsAutoCastOn(sol::stack_object target)
{
    return false;
}
bool ScriptHelperSpells::GetCanMove(sol::stack_object target)
{
    return false;
}
void ScriptHelperSpells::SetCanAttack(sol::stack_object target, bool state)
{
}
void ScriptHelperSpells::SetCanCast(sol::stack_object target, bool state)
{
}
void ScriptHelperSpells::SetCanMove(sol::stack_object target, bool state)
{
}

bool ScriptHelperSpells::IsBaseAI(sol::stack_object obj)
{
    return false;
}
bool ScriptHelperSpells::IsHeroAI(sol::stack_object obj)
{
    return false;
}
bool ScriptHelperSpells::IsMelee(sol::stack_object obj)
{
    return false;
}
bool ScriptHelperSpells::IsRanged(sol::stack_object obj)
{
    return false;
}
bool ScriptHelperSpells::IsMoving(sol::stack_object obj)
{
    return false;
}

void ScriptHelperSpells::IncFlatGoldPer10Mod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatGoldPer10Mod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncBaseAttackDamage(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentBaseAttackDamage(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatArmorMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatArmorMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatArmorPenetrationMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatArmorPenetrationMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatMagicPenetrationMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatMagicPenetrationMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatSpellBlockMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatSpellBlockMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatAttackRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatAttackRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatCastRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatCastRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatCooldownMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatCooldownMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatCritChanceMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatCritChanceMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatCritDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatCritDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatHPPoolMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatHPPoolMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatHPRegenMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatHPRegenMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatMagicDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatMagicDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatMagicReduction(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatMagicReduction(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatMovementSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatMovementSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatPhysicalDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatPhysicalDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatPhysicalReduction(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatPhysicalReduction(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncFlatBubbleRadiusMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentFlatBubbleRadiusMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentHardnessMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentHardnessMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentArmorMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentArmorMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentSpellBlockMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentSpellBlockMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentAttackRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentAttackRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentAttackSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentAttackSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentCastRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentCastRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentCooldownMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentCooldownMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentCritDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentCritDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentEXPBonus(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentEXPBonus(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentHPPoolMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentHPPoolMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentHPRegenMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentHPRegenMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentHealingAmountMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentHealingAmountMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentLifeStealMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentLifeStealMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentSpellVampMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentSpellVampMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentMagicDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentMagicDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentMagicReduction(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentMagicReduction(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentMovementSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentMovementSpeedMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentPhysicalDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentPhysicalDamageMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentPhysicalReduction(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentPhysicalReduction(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentRespawnTimeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentRespawnTimeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentGoldLostOnDeathMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentGoldLostOnDeathMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPercentBubbleRadiusMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentPercentBubbleRadiusMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncAcquisitionRangeMod(float delta, sol::stack_object target)
{
}
void ScriptHelperSpells::IncPermanentAcquisitionRangeMod(float delta, sol::stack_object target)
{
}
float ScriptHelperSpells::GetFlatGoldPer10Mod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetBaseAttackDamage(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatArmorMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatArmorPenetrationMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatMagicPenetrationMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatSpellBlockMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatAttackRangeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatCastRangeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatCooldownMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatCritChanceMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatCritDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatHPPoolMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatHPRegenMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatMagicDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatMagicReduction(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatMovementSpeedMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatPhysicalDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatPhysicalReduction(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetFlatBubbleRadiusMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentHardnessMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentArmorMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentSpellBlockMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentAttackRangeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentAttackSpeedMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentCastRangeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentCooldownMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentCritDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentEXPBonus(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentHPPoolMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentHPRegenMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentHealingAmountMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentLifeStealMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentSpellVampMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentMagicDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentMagicReduction(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentMovementSpeedMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentPhysicalDamageMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentPhysicalReduction(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentRespawnTimeMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentGoldLostOnDeathMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetPercentBubbleRadiusMod(sol::stack_object target)
{
    return 0;
}
float ScriptHelperSpells::GetAcquisitionRangeMod(sol::stack_object target)
{
    return 0;
}
