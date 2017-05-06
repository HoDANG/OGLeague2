#ifndef CHARACTERINTERMEDIATEREP_H
#define CHARACTERINTERMEDIATEREP_H

#include "replicationmanager.h"

struct CharacterIntermediateRep
{
  Replicate<float> mPercentCooldownMod;
  Replicate<float> mFlatPhysicalDamageMod;
  Replicate<float> mPercentPhysicalDamageMod;
  Replicate<float> mFlatMagicDamageMod;
  Replicate<float> mPercentMagicDamageMod;
  Replicate<float> mFlatMagicReduction;
  Replicate<float> mPercentMagicReduction;
  Replicate<float> mFlatCastRangeMod;
  Replicate<float> mAttackSpeedMod;
  Replicate<float> mBaseAttackDamage;
  Replicate<float> mBaseAbilityDamage;
  Replicate<float> mScaleSkinCoef;
  Replicate<float> mDodge;
  Replicate<float> mCrit;
  Replicate<float> mArmor;
  Replicate<float> mSpellBlock;
  Replicate<float> mHPRegenRate;
  Replicate<float> mPARRegenRate;
  Replicate<float> mMoveSpeed;
  Replicate<float> mAttackRange;
  Replicate<float> mFlatBubbleRadiusMod;
  Replicate<float> mPercentBubbleRadiusMod;
  Replicate<float> mFlatArmorPenetration;
  Replicate<float> mPercentArmorPenetration;
  Replicate<float> mFlatMagicPenetration;
  Replicate<float> mPercentMagicPenetration;
  Replicate<float> mPercentLifeSteal;
  Replicate<float> mPercentSpellVamp;
};

#endif // CHARACTERINTERMEDIATEREP_H
