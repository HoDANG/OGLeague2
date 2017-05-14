#ifndef SCRIPTHELPERSPELLS_H
#define SCRIPTHELPERSPELLS_H

#include "dep/sol.hpp"
#include "dep/r3d.hpp"
#include "../obj/properties/characterintermediate.hpp"

struct ScriptHelperSpells
{
    static CharacterIntermediate *sCharInter;

    static void RegisterGlobals(sol::state &state);

    static void Say(sol::stack_object owner, std::string message){}
    static void ApplyStun(sol::stack_object owner, sol::stack_object target, float duration){}
    static void ApplyPacified(sol::stack_object owner, sol::stack_object target, float duration){}
    static void ApplyNet(sol::stack_object owner, sol::stack_object target, float duration){}
    static void ApplyDisarm(sol::stack_object owner, sol::stack_object target, float duration){}
    static void ApplyRoot(sol::stack_object owner, sol::stack_object target, float duration){}
    static void ApplySilence(sol::stack_object owner, sol::stack_object target, float duration){}
    static void ApplySuppression(sol::stack_object owner, sol::stack_object target, float duration){}
    static void ApplySuppressCallForHelp(sol::stack_object owner, sol::stack_object target, float duration){}
    static void ApplyIgnoreCallForHelp(sol::stack_object owner, sol::stack_object target, float duration){}
    static void ApplyCallForHelpSuppresser(sol::stack_object owner, sol::stack_object target, float duration){}
    static void CancelOrder(sol::stack_object owner){}
    static void ChannelingStart(sol::stack_object caster, sol::stack_object target, float duration, float timeBeetwenUpdate){}
    static void ChannelingStop(sol::stack_object caster, int whyStoppedCondition, int whyStoppedSource){}
    static void DrawDefaultHitEffects(sol::stack_object target){}
    static bool GetIsAttackOverride(){}
    static int GetCastSpellLevelPlusOne(){}
    static sol::object GetCastSpellTargetPos(){}
    static int GetCastSpellTargetsHitPlusOne(){}
    static sol::object GetCastSpellLuaInfo(){}
    static int GetCasterID(){}
    static float GetHealth(sol::stack_object target, int formal){}
    static float GetHealthPercent(sol::stack_object target ,int formal){}
    static bool GetInvulnerable(sol::stack_object target){}
    static bool GetPhysicalImmune(sol::stack_object target){}
    static bool GetTargetable(sol::stack_object target){}
    static bool GetTargetableToTeam(sol::stack_object target, int team){}
    static bool GetMagicImmune(sol::stack_object target){}
    static float GetPAR(sol::stack_object target, int parType){}
    static float GetPARCost(){}
    static float GetPARPercent(sol::stack_object target, int parType){}
    static int GetPARType(sol::stack_object target){}
    static bool HasPARType(sol::stack_object target, int parType){}
    static float GetMaxHealth(sol::stack_object target, int formal){}
    static float GetMaxPAR(sol::stack_object target,int parType){}
    static std::string GetName(sol::stack_object obj){}
    static float GetArmor(sol::stack_object target){}
    static float GetSpellBlock(sol::stack_object target){}
    static float GetDodge(sol::stack_object target){}
    static float GetMissChance(sol::stack_object target){}
    static float GetAttackSpeedMod(sol::stack_object target){}
    static float GetMovementSpeed(sol::stack_object target){}
    static float GetLevel(sol::stack_object  target){}
    static float GetTotalAttackDamage(sol::stack_object target){}
    static float GetSlotSpellCooldownTime(sol::stack_object target, int slot, int spellbookType, int slotType){}
    static int GetSlotSpellLevel(sol::stack_object target, int slot, int spellbookType, int slotType){}
    static std::string GetSlotSpellName(sol::stack_object target, int slot, int spellbookType, int slotType){}
    static std::string GetSpellName(){}
    static int GetSpellSlot(){}

    static bool GetNoRender(sol::stack_object target){}
    static bool GetBrushVisibilityFake(sol::stack_object target){}
    static bool GetForceRenderParticles(sol::stack_object target){}
    static bool GetStealthed(sol::stack_object target){}
    static bool GetRevealSpecificUnit(sol::stack_object target){}
    static bool GetTaunted(sol::stack_object target){}
    static bool GetCharmed(sol::stack_object target){}
    static bool GetSuppressed(sol::stack_object target){}
    static bool GetFeared(sol::stack_object target){}
    static bool GetDisableAmbientGold(sol::stack_object target){}
    static void SetDisableAmbientGold(sol::stack_object target, bool value){}
    static bool GetSleep(sol::stack_object target){}
    static bool GetNearSight(sol::stack_object target){}
    static bool GetGhosted(sol::stack_object target){}
    static bool GetGhostProof(sol::stack_object target){}

    static void IncHealth(sol::stack_object target, float value){}
    static void IncMana(sol::stack_object target, float value){}
    static void IncMoveSpeedFloorMod(float value, sol::stack_object target){}
    static void IncFlatDodgeMod(float value, sol::stack_object target){}
    static void IncFlatMissChanceMod(float value, sol::stack_object target){}
    static void IncPercentArmorPenetrationMod(float value, sol::stack_object target){}
    static void IncPercentMagicPenetrationMod(float value, sol::stack_object target){}
    static void IncPercentMultiplicativeAttackSpeedMod(float value, sol::stack_object target){}
    static void IncPercentMultiplicativeMovementSpeedMod(float value, sol::stack_object target){}

    static void IssueOrder(sol::stack_object owner,int order, sol::stack_object pos, sol::stack_object caster){}
    static void RaiseSpellFlag(int flag){}
    static void ReincarnateNonDeadHero(sol::stack_object target){}

    static void SetCanCastWhileDisabled(bool value){}
    static void SetInvulnerable(sol::stack_object target, bool value){}
    static void SetTargetable(sol::stack_object target, bool value){}
    static void SetNotTargetableToTeam(sol::stack_object target, bool value, int team){}
    static void SetPhysicalImmune(sol::stack_object target, bool value){}
    static void SetMagicImmune(sol::stack_object target, bool value){}
    static void SetRooted(sol::stack_object target, bool value){}
    static void SetScaleSkinCoef(float coef, sol::stack_object target){}
    static void SetSilenced(sol::stack_object target, bool value){}
    static void SetSlotSpellCooldownTime(sol::stack_object target, int slot,int spellbookType ,int slotType, float time){}
    static void SetStealthed(sol::stack_object target, bool value){}
    static void SetRevealSpecificUnit(sol::stack_object target, bool value){}
    static void SetStunned(sol::stack_object target, bool value){}
    static void SetPacified(sol::stack_object target, bool value){}
    static void SetNetted(sol::stack_object target, bool value){}
    static void SetDisarmed(sol::stack_object target, bool value){}
    static void SetTaunted(sol::stack_object target, bool value){}
    static void SetCharmed(sol::stack_object target, bool value){}
    static void SetFeared(sol::stack_object target, bool value){}
    static void SetSleep(sol::stack_object target, bool value){}
    static void SetNearSight(sol::stack_object target, bool value){}
    static void SetNoRender(sol::stack_object target, bool value){}
    static void SetForceRenderParticles(sol::stack_object target, bool value){}
    static void SetGhosted(sol::stack_object target, bool value){}
    static void SetSuppressed(sol::stack_object target, bool value){}
    static void SetGhostProof(sol::stack_object target, bool value){}
    static void SetSuppressCallForHelp(sol::stack_object target, bool value){}
    static void SetCallForHelpSuppresser(sol::stack_object target, bool value){}
    static void SetBrushVisibilityFake(sol::stack_object target, bool value){}
    static void SetIgnoreCallForHelp(sol::stack_object target, bool value){}

    static void SpellBuffAdd(sol::stack_object caster, sol::stack_object target, std::string name, int type, int maxStack, float duration, sol::stack_object luaBuffVars){}
    static void SpellBuffAddNoRenew(sol::stack_object caster, sol::stack_object target, std::string name, int type, int maxStack, float duration, sol::stack_object luaBuffVars){}
    static int SpellBuffCount(sol::stack_object target, std::string name, sol::stack_object caster){}
    static void SpellBuffRemove(sol::stack_object target, std::string name, sol::stack_object caster){}
    static void SpellBuffRemoveCurrent(sol::stack_object target){}
    static void SpellBuffRemoveType(sol::stack_object target, int type){}
    static bool HasBuffOfType(sol::stack_object target, int type){}
    static unsigned long SpellEffectCreate(std::string effectName,sol::stack_object pos, sol::stack_object bindObject ,sol::stack_object flags){}
    static void TeleportToKeyLocation(sol::stack_object owner, int locationEnum, int team){}
    static void TeleportToPosition(sol::stack_object owner, sol::stack_object position){}
    static int GetAIState(sol::stack_object target){}

    static bool GetCanAttack(sol::stack_object target){}
    static bool GetCanCast(sol::stack_object target){}
    static bool IsAutoCastOn(sol::stack_object target){}
    static bool GetCanMove(sol::stack_object target){}
    static void SetCanAttack(sol::stack_object target, bool state){}
    static void SetCanCast(sol::stack_object target, bool state){}
    static void SetCanMove(sol::stack_object target, bool state){}

    static bool IsBaseAI(sol::stack_object obj){}
    static bool IsHeroAI(sol::stack_object obj){}
    static bool IsMelee(sol::stack_object obj){}
    static bool IsRanged(sol::stack_object obj){}
    static bool IsMoving(sol::stack_object obj){}

    static void IncFlatGoldPer10Mod(float delta, sol::stack_object target){}
    static void IncPermanentFlatGoldPer10Mod(float delta, sol::stack_object target){}
    static void IncBaseAttackDamage(float delta, sol::stack_object target){}
    static void IncPermanentBaseAttackDamage(float delta, sol::stack_object target){}
    static void IncFlatArmorMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatArmorMod(float delta, sol::stack_object target){}
    static void IncFlatArmorPenetrationMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatArmorPenetrationMod(float delta, sol::stack_object target){}
    static void IncFlatMagicPenetrationMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatMagicPenetrationMod(float delta, sol::stack_object target){}
    static void IncFlatSpellBlockMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatSpellBlockMod(float delta, sol::stack_object target){}
    static void IncFlatAttackRangeMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatAttackRangeMod(float delta, sol::stack_object target){}
    static void IncFlatCastRangeMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatCastRangeMod(float delta, sol::stack_object target){}
    static void IncFlatCooldownMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatCooldownMod(float delta, sol::stack_object target){}
    static void IncFlatCritChanceMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatCritChanceMod(float delta, sol::stack_object target){}
    static void IncFlatCritDamageMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatCritDamageMod(float delta, sol::stack_object target){}
    static void IncFlatHPPoolMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatHPPoolMod(float delta, sol::stack_object target){}
    static void IncFlatHPRegenMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatHPRegenMod(float delta, sol::stack_object target){}
    static void IncFlatMagicDamageMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatMagicDamageMod(float delta, sol::stack_object target){}
    static void IncFlatMagicReduction(float delta, sol::stack_object target){}
    static void IncPermanentFlatMagicReduction(float delta, sol::stack_object target){}
    static void IncFlatMovementSpeedMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatMovementSpeedMod(float delta, sol::stack_object target){}
    static void IncFlatPhysicalDamageMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatPhysicalDamageMod(float delta, sol::stack_object target){}
    static void IncFlatPhysicalReduction(float delta, sol::stack_object target){}
    static void IncPermanentFlatPhysicalReduction(float delta, sol::stack_object target){}
    static void IncFlatBubbleRadiusMod(float delta, sol::stack_object target){}
    static void IncPermanentFlatBubbleRadiusMod(float delta, sol::stack_object target){}
    static void IncPercentHardnessMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentHardnessMod(float delta, sol::stack_object target){}
    static void IncPercentArmorMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentArmorMod(float delta, sol::stack_object target){}
    static void IncPercentSpellBlockMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentSpellBlockMod(float delta, sol::stack_object target){}
    static void IncPercentAttackRangeMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentAttackRangeMod(float delta, sol::stack_object target){}
    static void IncPercentAttackSpeedMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentAttackSpeedMod(float delta, sol::stack_object target){}
    static void IncPercentCastRangeMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentCastRangeMod(float delta, sol::stack_object target){}
    static void IncPercentCooldownMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentCooldownMod(float delta, sol::stack_object target){}
    static void IncPercentCritDamageMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentCritDamageMod(float delta, sol::stack_object target){}
    static void IncPercentEXPBonus(float delta, sol::stack_object target){}
    static void IncPermanentPercentEXPBonus(float delta, sol::stack_object target){}
    static void IncPercentHPPoolMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentHPPoolMod(float delta, sol::stack_object target){}
    static void IncPercentHPRegenMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentHPRegenMod(float delta, sol::stack_object target){}
    static void IncPercentHealingAmountMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentHealingAmountMod(float delta, sol::stack_object target){}
    static void IncPercentLifeStealMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentLifeStealMod(float delta, sol::stack_object target){}
    static void IncPercentSpellVampMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentSpellVampMod(float delta, sol::stack_object target){}
    static void IncPercentMagicDamageMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentMagicDamageMod(float delta, sol::stack_object target){}
    static void IncPercentMagicReduction(float delta, sol::stack_object target){}
    static void IncPermanentPercentMagicReduction(float delta, sol::stack_object target){}
    static void IncPercentMovementSpeedMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentMovementSpeedMod(float delta, sol::stack_object target){}
    static void IncPercentPhysicalDamageMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentPhysicalDamageMod(float delta, sol::stack_object target){}
    static void IncPercentPhysicalReduction(float delta, sol::stack_object target){}
    static void IncPermanentPercentPhysicalReduction(float delta, sol::stack_object target){}
    static void IncPercentRespawnTimeMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentRespawnTimeMod(float delta, sol::stack_object target){}
    static void IncPercentGoldLostOnDeathMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentGoldLostOnDeathMod(float delta, sol::stack_object target){}
    static void IncPercentBubbleRadiusMod(float delta, sol::stack_object target){}
    static void IncPermanentPercentBubbleRadiusMod(float delta, sol::stack_object target){}
    static void IncAcquisitionRangeMod(float delta, sol::stack_object target){}
    static void IncPermanentAcquisitionRangeMod(float delta, sol::stack_object target){}
    static float GetFlatGoldPer10Mod(sol::stack_object target){}
    static float GetBaseAttackDamage(sol::stack_object target){}
    static float GetFlatArmorMod(sol::stack_object target){}
    static float GetFlatArmorPenetrationMod(sol::stack_object target){}
    static float GetFlatMagicPenetrationMod(sol::stack_object target){}
    static float GetFlatSpellBlockMod(sol::stack_object target){}
    static float GetFlatAttackRangeMod(sol::stack_object target){}
    static float GetFlatCastRangeMod(sol::stack_object target){}
    static float GetFlatCooldownMod(sol::stack_object target){}
    static float GetFlatCritChanceMod(sol::stack_object target){}
    static float GetFlatCritDamageMod(sol::stack_object target){}
    static float GetFlatHPPoolMod(sol::stack_object target){}
    static float GetFlatHPRegenMod(sol::stack_object target){}
    static float GetFlatMagicDamageMod(sol::stack_object target){}
    static float GetFlatMagicReduction(sol::stack_object target){}
    static float GetFlatMovementSpeedMod(sol::stack_object target){}
    static float GetFlatPhysicalDamageMod(sol::stack_object target){}
    static float GetFlatPhysicalReduction(sol::stack_object target){}
    static float GetFlatBubbleRadiusMod(sol::stack_object target){}
    static float GetPercentHardnessMod(sol::stack_object target){}
    static float GetPercentArmorMod(sol::stack_object target){}
    static float GetPercentSpellBlockMod(sol::stack_object target){}
    static float GetPercentAttackRangeMod(sol::stack_object target){}
    static float GetPercentAttackSpeedMod(sol::stack_object target){}
    static float GetPercentCastRangeMod(sol::stack_object target){}
    static float GetPercentCooldownMod(sol::stack_object target){}
    static float GetPercentCritDamageMod(sol::stack_object target){}
    static float GetPercentEXPBonus(sol::stack_object target){}
    static float GetPercentHPPoolMod(sol::stack_object target){}
    static float GetPercentHPRegenMod(sol::stack_object target){}
    static float GetPercentHealingAmountMod(sol::stack_object target){}
    static float GetPercentLifeStealMod(sol::stack_object target){}
    static float GetPercentSpellVampMod(sol::stack_object target){}
    static float GetPercentMagicDamageMod(sol::stack_object target){}
    static float GetPercentMagicReduction(sol::stack_object target){}
    static float GetPercentMovementSpeedMod(sol::stack_object target){}
    static float GetPercentPhysicalDamageMod(sol::stack_object target){}
    static float GetPercentPhysicalReduction(sol::stack_object target){}
    static float GetPercentRespawnTimeMod(sol::stack_object target){}
    static float GetPercentGoldLostOnDeathMod(sol::stack_object target){}
    static float GetPercentBubbleRadiusMod(sol::stack_object target){}
    static float GetAcquisitionRangeMod(sol::stack_object target){}
};

#endif // SCRIPTHELPERSPELLS_H
