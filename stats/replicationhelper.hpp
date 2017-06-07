#ifndef REPLICATIONHELPER_H
#define REPLICATIONHELPER_H

#include "replicationmanager.hpp"
#include "characterintermediaterep.hpp"
#include "characterstate.hpp"
#include "obj/gameobjectsall.h"

struct ReplicationHelper
{
    static void FillBuildingLocalRepData(AttackableUnit *building,
                                         CReplInfo32 *ri, ReplicationManager* manager)
    {
        building->mHealth.mCurrent.SetReplicator("mHP", ri, LOCAL_REP_DATA1, manager);
        building->mIsInvulnerable.SetReplicator("IsInvulnerable", ri, LOCAL_REP_DATA1, manager);
        building->mIsTargetable.SetReplicator("IsTargetable", ri, LOCAL_REP_DATA1, manager);
        building->mIsTargetableToTeam.SetReplicator("IsTargetableToTeam", ri, LOCAL_REP_DATA1, manager);
    }
    static void FillBasicLocalRepDataTower(CharacterIntermediateRep *charInter,
                                           CReplInfo32 *ri, ReplicationManager* manager)
    {
        charInter->mBaseAttackDamage.SetReplicator("mBaseAttackDamage", ri, LOCAL_REP_DATA1, manager);
        charInter->mArmor.SetReplicator("mArmor", ri, LOCAL_REP_DATA1, manager);
        charInter->mSpellBlock.SetReplicator("mSpellBlock", ri, LOCAL_REP_DATA1, manager);
        charInter->mAttackSpeedMod.SetReplicator("mAttackSpeedMod", ri, LOCAL_REP_DATA1, manager);
        charInter->mFlatPhysicalDamageMod.SetReplicator("mFlatPhysicalDamageMod", ri, LOCAL_REP_DATA1, manager);
        charInter->mPercentPhysicalDamageMod.SetReplicator("mPercentPhysicalDamageMod", ri, LOCAL_REP_DATA1, manager);
        charInter->mFlatMagicDamageMod.SetReplicator("mFlatMagicDamageMod", ri, LOCAL_REP_DATA1, manager);
        charInter->mPercentMagicDamageMod.SetReplicator("mPercentPhysicalDamageMod", ri, LOCAL_REP_DATA1, manager);
        charInter->mHPRegenRate.SetReplicator("mHPRegenRate", ri, LOCAL_REP_DATA1, manager);
    }
    static void FillLocalRepData(AttackableUnit *unit, CharacterState *charState,
                                 CReplInfo32 *ri, ReplicationManager* replicator)
    {
        charState->mStates.SetReplicator("ActionState", ri, LOCAL_REP_DATA1, replicator);
        unit->mIsMagicImmune.SetReplicator("MagicImmune", ri, LOCAL_REP_DATA1, replicator);
        unit->mIsInvulnerable.SetReplicator("IsInvulnerable", ri, LOCAL_REP_DATA1, replicator);
        unit->mIsTargetable.SetReplicator("IsTargetable", ri, LOCAL_REP_DATA1, replicator);
        unit->mIsTargetableToTeam.SetReplicator("IsTargetableToTeam", ri, LOCAL_REP_DATA1, replicator);
        unit->mIsPhysicalImmune.SetReplicator("IsPhysicalImmune", ri, LOCAL_REP_DATA1, replicator);
    }
    static void FillBasicMapRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri,
                                    ReplicationManager* replicator)
    {
        charInter->mFlatBubbleRadiusMod.SetReplicator("mFlatBubbleRadiusMod", ri, MAP_REPDATA, replicator);
        charInter->mPercentBubbleRadiusMod.SetReplicator("mPercentBubbleRadiusMod", ri, MAP_REPDATA, replicator);
        charInter->mMoveSpeed.SetReplicator("mMoveSpeed", ri, MAP_REPDATA, replicator);
        charInter->mScaleSkinCoef.SetReplicator("mCrit", ri, MAP_REPDATA, replicator);
    }
    static void FillBasicLocalRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri,
                                      ReplicationManager* replicator)
    {
        charInter->mBaseAttackDamage.SetReplicator("mBaseAttackDamage", ri, LOCAL_REP_DATA1, replicator);
        charInter->mArmor.SetReplicator("mArmor", ri, LOCAL_REP_DATA1, replicator);
        charInter->mSpellBlock.SetReplicator("mSpellBlock", ri, LOCAL_REP_DATA1, replicator);
        charInter->mAttackSpeedMod.SetReplicator("mAttackSpeedMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mFlatPhysicalDamageMod.SetReplicator("mFlatPhysicalDamageMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentPhysicalDamageMod.SetReplicator("mPercentPhysicalDamageMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mFlatMagicDamageMod.SetReplicator("mFlatMagicDamageMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentMagicDamageMod.SetReplicator("mPercentPhysicalDamageMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mHPRegenRate.SetReplicator("mHPRegenRate", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPARRegenRate.SetReplicator("mPARRegenRate", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPARRegenRate.SetReplicator("mPARRegenRate", ri, LOCAL_REP_DATA1, replicator);
        charInter->mFlatMagicReduction.SetReplicator("mFlatMagicReduction", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentCooldownMod.SetReplicator("mPercentMagicReduction", ri, LOCAL_REP_DATA1, replicator);
    }
    static void FillHeroLocalRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri, ReplicationManager* replicator)
    {
        charInter->mBaseAttackDamage.SetReplicator("mBaseAttackDamage", ri, LOCAL_REP_DATA1, replicator);
        charInter->mBaseAbilityDamage.SetReplicator("mBaseAbilityDamage", ri, LOCAL_REP_DATA1, replicator);
        charInter->mDodge.SetReplicator("mDodge", ri, LOCAL_REP_DATA1, replicator);
        charInter->mCrit.SetReplicator("mCrit", ri, LOCAL_REP_DATA1, replicator);
        charInter->mArmor.SetReplicator("mArmor", ri, LOCAL_REP_DATA1, replicator);
        charInter->mSpellBlock.SetReplicator("mSpellBlock", ri, LOCAL_REP_DATA1, replicator);
        charInter->mHPRegenRate.SetReplicator("mHPRegenRate", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPARRegenRate.SetReplicator("mPARRegenRate", ri, LOCAL_REP_DATA1, replicator);
        charInter->mAttackRange.SetReplicator("mAttackRange", ri, LOCAL_REP_DATA1, replicator);
        charInter->mFlatPhysicalDamageMod.SetReplicator("mFlatPhysicalDamageMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentPhysicalDamageMod.SetReplicator("mPercentPhysicalDamageMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mFlatMagicDamageMod.SetReplicator("mFlatMagicDamageMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentMagicDamageMod.SetReplicator("mPercentPhysicalDamageMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mFlatMagicReduction.SetReplicator("mFlatMagicReduction", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentMagicReduction.SetReplicator("mPercentMagicReduction", ri, LOCAL_REP_DATA1, replicator);
        charInter->mAttackSpeedMod.SetReplicator("mAttackSpeedMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mFlatCastRangeMod.SetReplicator("mFlatCastRangeMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentCooldownMod.SetReplicator("mPercentCooldownMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mFlatArmorPenetration.SetReplicator("mFlatArmorPenetration", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentArmorPenetration.SetReplicator("mPercentArmorPenetration", ri, LOCAL_REP_DATA1, replicator);
        charInter->mFlatMagicPenetration.SetReplicator("mFlatMagicPenetration", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentMagicPenetration.SetReplicator("mPercentMagicPenetration", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentLifeSteal.SetReplicator("mPercentLifeStealMod", ri, LOCAL_REP_DATA1, replicator);
        charInter->mPercentSpellVamp.SetReplicator("mPercentSpellVampMod", ri, LOCAL_REP_DATA1, replicator);
    }
    static void FillHeroMapRepData(CharacterIntermediateRep *charInter,  CReplInfo32 *ri, ReplicationManager* replicator)
    {
        charInter->mFlatBubbleRadiusMod.SetReplicator("mFlatBubbleRadiusMod", ri, MAP_REPDATA, replicator);
        charInter->mPercentBubbleRadiusMod.SetReplicator("mPercentBubbleRadiusMod", ri, MAP_REPDATA, replicator);
        charInter->mMoveSpeed.SetReplicator("mMoveSpeed", ri, MAP_REPDATA, replicator);
        charInter->mCrit.SetReplicator("mCrit", ri, MAP_REPDATA, replicator);
    }

};

#endif // REPLICATIONHELPER_H
