#include "replicationhelper.h"

using namespace Game;

ReplicationHelper::FillBuildingLocalRepData(AttackableUnit *building, CReplInfo32 *ri, ReplicationManager* manager,
                                            void* base)
{
    building->mHealth.mCurrent.SetReplicator(base, "mHP", ri, LOCAL_REP_DATA1, manager);
    building->mIsInvulnerable.SetReplicator(base, "IsInvulnerable", ri, LOCAL_REP_DATA1, manager);
    building->mIsTargetable.SetReplicator(base, "IsTargetable", ri, LOCAL_REP_DATA1, manager);
    building->mIsTargetableToTeam.SetReplicator(base, "IsTargetableToTeam", ri, LOCAL_REP_DATA1, manager);
}

ReplicationHelper::FillBasicLocalRepDataTower(CharacterIntermediateRep *charInter, CReplInfo32 *ri, ReplicationManager *manager, void *base)
{
    charInter->mBaseAttackDamage.SetReplicator(base, "mBaseAttackDamage", ri, LOCAL_REP_DATA1, manager);
    charInter->mArmor.SetReplicator(base, "mArmor", ri, LOCAL_REP_DATA1, manager);
    charInter->mSpellBlock.SetReplicator(base, "mSpellBlock", ri, LOCAL_REP_DATA1, manager);
    charInter->mAttackSpeedMod.SetReplicator(base, "mAttackSpeedMod", ri, LOCAL_REP_DATA1, manager);
    charInter->mFlatPhysicalDamageMod.SetReplicator(base, "mFlatPhysicalDamageMod", ri, LOCAL_REP_DATA1, manager);
    charInter->mPercentPhysicalDamageMod.SetReplicator(base, "mPercentPhysicalDamageMod", ri, LOCAL_REP_DATA1, manager);
    charInter->mFlatMagicDamageMod.SetReplicator(base, "mFlatMagicDamageMod", ri, LOCAL_REP_DATA1, manager);
    charInter->mPercentMagicDamageMod.SetReplicator(base, "mPercentPhysicalDamageMod", ri, LOCAL_REP_DATA1, manager);
    charInter->mHPRegenRate.SetReplicator(base, "mHPRegenRate", ri, LOCAL_REP_DATA1, manager);
}

ReplicationHelper::FillLocalRepData(AttackableUnit *unit, CharacterState *charState, CReplInfo32 *ri,
                                    ReplicationManager *replicator, void *base)
{
    charState->mStates.mIndex = ri->addVar(base, charState, "ActionState");
    charState->mStates.mType = LOCAL_REP_DATA1;
    charState->mStates.mReplicator = replicator;
    unit->mIsMagicImmune.mIndex = ri->addVar(base, &unit->mIsMagicImmune, "MagicImmune");
    unit->mIsMagicImmune.mType = LOCAL_REP_DATA1;
    unit->mIsMagicImmune.mReplicator = replicator;
    unit->mIsInvulnerable.mIndex = ri->addVar(base, &unit->mIsInvulnerable, "IsInvulnerable");
    unit->mIsInvulnerable.mType = LOCAL_REP_DATA1;
    unit->mIsInvulnerable.mReplicator = replicator;
    unit->mIsTargetable.mIndex = ri->addVar(base, &unit->mIsTargetable, "IsTargetable");
    unit->mIsTargetable.mType = LOCAL_REP_DATA1;
    unit->mIsTargetable.mReplicator = replicator;
    unit->mIsTargetableToTeam.mIndex = ri->addVar(base, &unit->mIsTargetableToTeam, "IsTargetableToTeam");
    unit->mIsTargetableToTeam.mType = LOCAL_REP_DATA1;
    unit->mIsTargetableToTeam.mReplicator = replicator;
    charState->mStates.mIndex = ri->addVar(base, &unit->mIsPhysicalImmune, "IsPhysicalImmune");
    charState->mStates.mType = LOCAL_REP_DATA1;
}

ReplicationHelper::FillBasicMapRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri, ReplicationManager *replicator, void *base)
{
    charInter->mFlatBubbleRadiusMod.mIndex = ri->addVar(base, &charInter->mFlatBubbleRadiusMod, "mFlatBubbleRadiusMod");
    charInter->mFlatBubbleRadiusMod.mType = MAP_REPDATA;
    charInter->mFlatBubbleRadiusMod.mReplicator = replicator;
    charInter->mPercentBubbleRadiusMod.mIndex = ri->addVar(base, &charInter->mPercentBubbleRadiusMod, "mPercentBubbleRadiusMod");
    charInter->mPercentBubbleRadiusMod.mType = MAP_REPDATA;
    charInter->mPercentBubbleRadiusMod.mReplicator = replicator;
    charInter->mMoveSpeed.mIndex = ri->addVar(base, &charInter->mMoveSpeed, "mMoveSpeed");
    charInter->mMoveSpeed.mType = MAP_REPDATA;
    charInter->mMoveSpeed.mReplicator = replicator;
    charInter->mScaleSkinCoef.mIndex = ri->addVar(base, &charInter->mScaleSkinCoef, "mCrit");
    charInter->mScaleSkinCoef.mType = MAP_REPDATA;
    charInter->mScaleSkinCoef.mReplicator = replicator;
}

ReplicationHelper::FillBasicLocalRepData(CharacterIntermediateRep *charInter, CReplInfo32 *ri, ReplicationManager *replicator, void *base)
{
      charInter->mBaseAttackDamage.mIndex = ri->addVar(base, &charInter->mBaseAttackDamage, "mBaseAttackDamage");
      charInter->mBaseAttackDamage.mType = LOCAL_REP_DATA1;
      charInter->mBaseAttackDamage.mReplicator = replicator;
      charInter->mArmor.mIndex = ri->addVar(base, &charInter->mArmor, "mArmor");
      charInter->mArmor.mType = LOCAL_REP_DATA1;
      charInter->mArmor.mReplicator = replicator;
      charInter->mSpellBlock.mIndex = ri->addVar(base, &charInter->mSpellBlock, "mSpellBlock");
      charInter->mSpellBlock.mType = LOCAL_REP_DATA1;
      charInter->mSpellBlock.mReplicator = replicator;
      charInter->mAttackSpeedMod.mIndex = ri->addVar(base, &charInter->mAttackSpeedMod, "mAttackSpeedMod");
      charInter->mAttackSpeedMod.mType = LOCAL_REP_DATA1;
      charInter->mAttackSpeedMod.mReplicator = replicator;
      charInter->mFlatPhysicalDamageMod.mIndex = ri->addVar(base, &charInter->mFlatPhysicalDamageMod, "mFlatPhysicalDamageMod");
      charInter->mFlatPhysicalDamageMod.mType = LOCAL_REP_DATA1;
      charInter->mFlatPhysicalDamageMod.mReplicator = replicator;
      charInter->mPercentPhysicalDamageMod.mIndex = ri->addVar(base, &charInter->mPercentPhysicalDamageMod, "mPercentPhysicalDamageMod");
      charInter->mPercentPhysicalDamageMod.mType = LOCAL_REP_DATA1;
      charInter->mPercentPhysicalDamageMod.mReplicator = replicator;
      charInter->mFlatMagicDamageMod.mIndex = ri->addVar(base, &charInter->mFlatMagicDamageMod, "mFlatMagicDamageMod");
      charInter->mFlatMagicDamageMod.mType = LOCAL_REP_DATA1;
      charInter->mFlatMagicDamageMod.mReplicator = replicator;
      charInter->mPercentMagicDamageMod.mIndex = ri->addVar(base, &charInter->mPercentMagicDamageMod, "mPercentPhysicalDamageMod");
      charInter->mPercentMagicDamageMod.mType = LOCAL_REP_DATA1;
      charInter->mPercentMagicDamageMod.mReplicator = replicator;
      charInter->mHPRegenRate.mIndex = ri->addVar(base, &charInter->mHPRegenRate, "mHPRegenRate");
      charInter->mHPRegenRate.mType = LOCAL_REP_DATA1;
      charInter->mHPRegenRate.mReplicator = replicator;
      charInter->mPARRegenRate.mIndex = ri->addVar(base, &charInter->mPARRegenRate, "mPARRegenRate");
      charInter->mPARRegenRate.mType = LOCAL_REP_DATA1;
      charInter->mPARRegenRate.mReplicator = replicator;
      //idk
      charInter->mPARRegenRate.mIndex = ri->addVar(base, &charInter->mPARRegenRate, "mPARRegenRate");
      charInter->mPARRegenRate.mType = LOCAL_REP_DATA1;
      charInter->mPARRegenRate.mReplicator = replicator;
      charInter->mFlatMagicReduction.mIndex = ri->addVar(base, &charInter->mFlatMagicReduction, "mFlatMagicReduction");
      charInter->mFlatMagicReduction.mType = LOCAL_REP_DATA1;
      charInter->mFlatMagicReduction.mReplicator = replicator;
      //yea...
      charInter->mPercentCooldownMod.mIndex = ri->addVar(base, &charInter->mPercentCooldownMod, "mPercentMagicReduction");
      charInter->mPercentCooldownMod.mType = LOCAL_REP_DATA1;
      charInter->mPercentCooldownMod.mReplicator = replicator;
}
