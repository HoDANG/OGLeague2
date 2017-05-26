#include "scripthelperspells.h"

void ScriptHelperSpells::Say(sol::stack_object owner, std::string message){}
void ScriptHelperSpells::ApplyStun(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::ApplyPacified(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::ApplyNet(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::ApplyDisarm(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::ApplyRoot(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::ApplySilence(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::ApplySuppression(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::ApplySuppressCallForHelp(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::ApplyIgnoreCallForHelp(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::ApplyCallForHelpSuppresser(sol::stack_object owner, sol::stack_object target, float duration){}
void ScriptHelperSpells::CancelOrder(sol::stack_object owner){}
void ScriptHelperSpells::ChannelingStart(sol::stack_object caster, sol::stack_object target, float duration, float timeBeetwenUpdate){}
void ScriptHelperSpells::ChannelingStop(sol::stack_object caster, int whyStoppedCondition, int whyStoppedSource){}
void ScriptHelperSpells::DrawDefaultHitEffects(sol::stack_object target){}
bool ScriptHelperSpells::GetIsAttackOverride(){}
int ScriptHelperSpells::GetCastSpellLevelPlusOne(){}
sol::object ScriptHelperSpells::GetCastSpellTargetPos(){}
int ScriptHelperSpells::GetCastSpellTargetsHitPlusOne(){}
sol::object ScriptHelperSpells::GetCastSpellLuaInfo(){}
int ScriptHelperSpells::GetCasterID(){}
float ScriptHelperSpells::GetHealth(sol::stack_object target, int formal){}
float ScriptHelperSpells::GetHealthPercent(sol::stack_object target ,int formal){}
bool ScriptHelperSpells::GetInvulnerable(sol::stack_object target){}
bool ScriptHelperSpells::GetPhysicalImmune(sol::stack_object target){}
bool ScriptHelperSpells::GetTargetable(sol::stack_object target){}
bool ScriptHelperSpells::GetTargetableToTeam(sol::stack_object target, int team){}
bool ScriptHelperSpells::GetMagicImmune(sol::stack_object target){}
float ScriptHelperSpells::GetPAR(sol::stack_object target, int parType){}
float ScriptHelperSpells::GetPARCost(){}
float ScriptHelperSpells::GetPARPercent(sol::stack_object target, int parType){}
int ScriptHelperSpells::GetPARType(sol::stack_object target){}
bool ScriptHelperSpells::HasPARType(sol::stack_object target, int parType){}
float ScriptHelperSpells::GetMaxHealth(sol::stack_object target, int formal){}
float ScriptHelperSpells::GetMaxPAR(sol::stack_object target,int parType){}
std::string ScriptHelperSpells::GetName(sol::stack_object obj){}
float ScriptHelperSpells::GetArmor(sol::stack_object target){}
float ScriptHelperSpells::GetSpellBlock(sol::stack_object target){}
float ScriptHelperSpells::GetDodge(sol::stack_object target){}
float ScriptHelperSpells::GetMissChance(sol::stack_object target){}
float ScriptHelperSpells::GetAttackSpeedMod(sol::stack_object target){}
float ScriptHelperSpells::GetMovementSpeed(sol::stack_object target){}
float ScriptHelperSpells::GetLevel(sol::stack_object  target){}
float ScriptHelperSpells::GetTotalAttackDamage(sol::stack_object target){}
float ScriptHelperSpells::GetSlotSpellCooldownTime(sol::stack_object target, int slot, int spellbookType, int slotType){}
int ScriptHelperSpells::GetSlotSpellLevel(sol::stack_object target, int slot, int spellbookType, int slotType){}
std::string ScriptHelperSpells::GetSlotSpellName(sol::stack_object target, int slot, int spellbookType, int slotType){}
std::string ScriptHelperSpells::GetSpellName(){}
int ScriptHelperSpells::GetSpellSlot(){}

bool ScriptHelperSpells::GetNoRender(sol::stack_object target){}
bool ScriptHelperSpells::GetBrushVisibilityFake(sol::stack_object target){}
bool ScriptHelperSpells::GetForceRenderParticles(sol::stack_object target){}
bool ScriptHelperSpells::GetStealthed(sol::stack_object target){}
bool ScriptHelperSpells::GetRevealSpecificUnit(sol::stack_object target){}
bool ScriptHelperSpells::GetTaunted(sol::stack_object target){}
bool ScriptHelperSpells::GetCharmed(sol::stack_object target){}
bool ScriptHelperSpells::GetSuppressed(sol::stack_object target){}
bool ScriptHelperSpells::GetFeared(sol::stack_object target){}
bool ScriptHelperSpells::GetDisableAmbientGold(sol::stack_object target){}
void ScriptHelperSpells::SetDisableAmbientGold(sol::stack_object target, bool value){}
bool ScriptHelperSpells::GetSleep(sol::stack_object target){}
bool ScriptHelperSpells::GetNearSight(sol::stack_object target){}
bool ScriptHelperSpells::GetGhosted(sol::stack_object target){}
bool ScriptHelperSpells::GetGhostProof(sol::stack_object target){}

void ScriptHelperSpells::IncHealth(sol::stack_object target, float value){}
void ScriptHelperSpells::IncMana(sol::stack_object target, float value){}
void ScriptHelperSpells::IncMoveSpeedFloorMod(float value, sol::stack_object target){}
void ScriptHelperSpells::IncFlatDodgeMod(float value, sol::stack_object target){}
void ScriptHelperSpells::IncFlatMissChanceMod(float value, sol::stack_object target){}
void ScriptHelperSpells::IncPercentArmorPenetrationMod(float value, sol::stack_object target){}
void ScriptHelperSpells::IncPercentMagicPenetrationMod(float value, sol::stack_object target){}
void ScriptHelperSpells::IncPercentMultiplicativeAttackSpeedMod(float value, sol::stack_object target){}
void ScriptHelperSpells::IncPercentMultiplicativeMovementSpeedMod(float value, sol::stack_object target){}

void ScriptHelperSpells::IssueOrder(sol::stack_object owner,int order, sol::stack_object pos, sol::stack_object caster){}
void ScriptHelperSpells::RaiseSpellFlag(int flag){}
void ScriptHelperSpells::ReincarnateNonDeadHero(sol::stack_object target){}

void ScriptHelperSpells::SetCanCastWhileDisabled(bool value){}
void ScriptHelperSpells::SetInvulnerable(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetTargetable(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetNotTargetableToTeam(sol::stack_object target, bool value, int team){}
void ScriptHelperSpells::SetPhysicalImmune(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetMagicImmune(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetRooted(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetScaleSkinCoef(float coef, sol::stack_object target){}
void ScriptHelperSpells::SetSilenced(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetSlotSpellCooldownTime(sol::stack_object target, int slot,int spellbookType ,int slotType, float time){}
void ScriptHelperSpells::SetStealthed(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetRevealSpecificUnit(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetStunned(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetPacified(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetNetted(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetDisarmed(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetTaunted(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetCharmed(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetFeared(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetSleep(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetNearSight(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetNoRender(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetForceRenderParticles(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetGhosted(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetSuppressed(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetGhostProof(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetSuppressCallForHelp(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetCallForHelpSuppresser(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetBrushVisibilityFake(sol::stack_object target, bool value){}
void ScriptHelperSpells::SetIgnoreCallForHelp(sol::stack_object target, bool value){}

void ScriptHelperSpells::SpellBuffAdd(sol::stack_object caster, sol::stack_object target, std::string name, int type, int maxStack, float duration, sol::stack_object luaBuffVars){}
void ScriptHelperSpells::SpellBuffAddNoRenew(sol::stack_object caster, sol::stack_object target, std::string name, int type, int maxStack, float duration, sol::stack_object luaBuffVars){}
int ScriptHelperSpells::SpellBuffCount(sol::stack_object target, std::string name, sol::stack_object caster){}
void ScriptHelperSpells::SpellBuffRemove(sol::stack_object target, std::string name, sol::stack_object caster){}
void ScriptHelperSpells::SpellBuffRemoveCurrent(sol::stack_object target){}
void ScriptHelperSpells::SpellBuffRemoveType(sol::stack_object target, int type){}
bool ScriptHelperSpells::HasBuffOfType(sol::stack_object target, int type){}
unsigned long ScriptHelperSpells::SpellEffectCreate(std::string effectName,sol::stack_object pos, sol::stack_object bindObject ,sol::stack_object flags){}
void ScriptHelperSpells::TeleportToKeyLocation(sol::stack_object owner, int locationEnum, int team){}
void ScriptHelperSpells::TeleportToPosition(sol::stack_object owner, sol::stack_object position){}
int ScriptHelperSpells::GetAIState(sol::stack_object target){}

bool ScriptHelperSpells::GetCanAttack(sol::stack_object target){}
bool ScriptHelperSpells::GetCanCast(sol::stack_object target){}
bool ScriptHelperSpells::IsAutoCastOn(sol::stack_object target){}
bool ScriptHelperSpells::GetCanMove(sol::stack_object target){}
void ScriptHelperSpells::SetCanAttack(sol::stack_object target, bool state){}
void ScriptHelperSpells::SetCanCast(sol::stack_object target, bool state){}
void ScriptHelperSpells::SetCanMove(sol::stack_object target, bool state){}

bool ScriptHelperSpells::IsBaseAI(sol::stack_object obj){}
bool ScriptHelperSpells::IsHeroAI(sol::stack_object obj){}
bool ScriptHelperSpells::IsMelee(sol::stack_object obj){}
bool ScriptHelperSpells::IsRanged(sol::stack_object obj){}
bool ScriptHelperSpells::IsMoving(sol::stack_object obj){}

void ScriptHelperSpells::IncFlatGoldPer10Mod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatGoldPer10Mod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncBaseAttackDamage(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentBaseAttackDamage(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatArmorMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatArmorMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatArmorPenetrationMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatArmorPenetrationMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatMagicPenetrationMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatMagicPenetrationMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatSpellBlockMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatSpellBlockMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatAttackRangeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatAttackRangeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatCastRangeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatCastRangeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatCooldownMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatCooldownMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatCritChanceMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatCritChanceMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatCritDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatCritDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatHPPoolMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatHPPoolMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatHPRegenMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatHPRegenMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatMagicDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatMagicDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatMagicReduction(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatMagicReduction(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatMovementSpeedMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatMovementSpeedMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatPhysicalDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatPhysicalDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatPhysicalReduction(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatPhysicalReduction(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncFlatBubbleRadiusMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentFlatBubbleRadiusMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentHardnessMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentHardnessMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentArmorMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentArmorMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentSpellBlockMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentSpellBlockMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentAttackRangeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentAttackRangeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentAttackSpeedMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentAttackSpeedMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentCastRangeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentCastRangeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentCooldownMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentCooldownMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentCritDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentCritDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentEXPBonus(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentEXPBonus(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentHPPoolMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentHPPoolMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentHPRegenMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentHPRegenMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentHealingAmountMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentHealingAmountMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentLifeStealMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentLifeStealMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentSpellVampMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentSpellVampMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentMagicDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentMagicDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentMagicReduction(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentMagicReduction(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentMovementSpeedMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentMovementSpeedMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentPhysicalDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentPhysicalDamageMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentPhysicalReduction(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentPhysicalReduction(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentRespawnTimeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentRespawnTimeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentGoldLostOnDeathMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentGoldLostOnDeathMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPercentBubbleRadiusMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentPercentBubbleRadiusMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncAcquisitionRangeMod(float delta, sol::stack_object target){}
void ScriptHelperSpells::IncPermanentAcquisitionRangeMod(float delta, sol::stack_object target){}
float ScriptHelperSpells::GetFlatGoldPer10Mod(sol::stack_object target){}
float ScriptHelperSpells::GetBaseAttackDamage(sol::stack_object target){}
float ScriptHelperSpells::GetFlatArmorMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatArmorPenetrationMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatMagicPenetrationMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatSpellBlockMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatAttackRangeMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatCastRangeMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatCooldownMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatCritChanceMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatCritDamageMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatHPPoolMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatHPRegenMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatMagicDamageMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatMagicReduction(sol::stack_object target){}
float ScriptHelperSpells::GetFlatMovementSpeedMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatPhysicalDamageMod(sol::stack_object target){}
float ScriptHelperSpells::GetFlatPhysicalReduction(sol::stack_object target){}
float ScriptHelperSpells::GetFlatBubbleRadiusMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentHardnessMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentArmorMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentSpellBlockMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentAttackRangeMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentAttackSpeedMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentCastRangeMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentCooldownMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentCritDamageMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentEXPBonus(sol::stack_object target){}
float ScriptHelperSpells::GetPercentHPPoolMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentHPRegenMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentHealingAmountMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentLifeStealMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentSpellVampMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentMagicDamageMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentMagicReduction(sol::stack_object target){}
float ScriptHelperSpells::GetPercentMovementSpeedMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentPhysicalDamageMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentPhysicalReduction(sol::stack_object target){}
float ScriptHelperSpells::GetPercentRespawnTimeMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentGoldLostOnDeathMod(sol::stack_object target){}
float ScriptHelperSpells::GetPercentBubbleRadiusMod(sol::stack_object target){}
float ScriptHelperSpells::GetAcquisitionRangeMod(sol::stack_object target){}
