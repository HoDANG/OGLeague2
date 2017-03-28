#include "spelldata.h"
#include "cfgreader.h"
#include "manager.h"
#include <iostream>>


using namespace std;
using namespace Content;

void SpellData::load(string name, Manager *manager)
{
    Config conf = manager->config("DATA/Spells/"+name+".ini");
    mName = name;
    for(int i = 0; i < 5; i++)
    {
        for(int c = 0; c < 5; c++)
        {
            mEffectAmount[i][c] = conf.getNum("SpellData",
                                                "Effect"+to_string(i+1)+"Level"+to_string(c)+"Amount", 0.0f);
        }
    }
    mCoefficient = conf.getNum("SpellData", "Coefficient", 0.0f);
    mCoefficient2 = conf.getNum("SpellData", "Coefficient2", 0.0f);
    mAnimationName = conf.getString("SpellData", "AnimationName", "Attack1");
    mAnimationLoopName = conf.getString("SpellData", "AnimationLoopName", "");
    mAnimationWindownName = conf.getString("SpellData", "AnimationWindownName", "");
    mSound_CastName = conf.getString("SpellData", "Sound_CastName", "none.wav");
    mSound_HitName = conf.getString("SpellData", "Sound_HitName", "none.wav");
    mImgIconName = conf.getString("SpellData", "InventoryIcon", "");
    CooldownTime[0] = conf.getNum("SpellData", "Cooldown", 10.0f);
    CastRange[0] = conf.getNum("SpellData", "CastRange", 400.0);

    for(int i = 0; i < 6 ; i++)
    {
        Mana[i] = conf.getNum("SpellData", "Mana"+to_string(i+1), 0.0f);
    }
    for(int i = 1; i < 7; i++)
    {
        CooldownTime[i] = conf.getNum("SpellData", "Cooldown"+to_string(i), CooldownTime[0]);
        CastRange[i] = conf.getNum("SpellData", "CastRange"+to_string(i), CastRange[0]);
    }

    TTargetingType = (ttype_e) conf.getNum<int>("SpellData", "TargettingType", TTYPE_Target);
    CastRangeUseBoundingBoxes = conf.getBool("SpellData", "CastRangeUseBoundingBoxes", false);
    CastRangeDisplayOverride = conf.getNum("SpellData", "CastRangeDisplayOverride", 0.0f);
    CastRadius = conf.getNum("SpellData", "CastRadius", 0.0f);
    CastRadiusSecondary = conf.getNum("SpellData", "CastRadiusSecondary", 0.0f);
    CastConeDistance = conf.getNum("SpellData", "CastConeDistance", 400.0f);
    CastConeAngle = conf.getNum("SpellData", "CastConeAngle", 45.0f);
    Flags = conf.getNum("SpellData", "Flags", 0);
    CastType = (ctype_e) conf.getNum<int>("SpellData", "CastType", CAST_Instant);
    CastFrame = conf.getNum("SpellData", "CastFrame", 0.0f);
    MissileSpeed = conf.getNum("SpellData", "MissileSpeed", 500.0f);
    MissileAccel = conf.getNum("SpellData", "MissileAccel", 0.0f);
    MissileMaxSpeed = conf.getNum("SpellData", "MissileMaxSpeed", MissileSpeed);
    MissileMinSpeed = conf.getNum("SpellData", "MissileMinSpeed", MissileSpeed);
    mMissileEffectName = conf.getString("SpellData", "MissileEffect", "");
    mMissileBoneName = conf.getString("SpellData", "MissileBoneName", "R_Hand");
    mMissilePerceptionBubbleRadius = conf.getNum("SpellData", "MissilePerceptionBubbleRadius", 0.0f);
    mMissilePerceptionBubbleRevealsStealth = conf.getNum("SpellData","MissilePerceptionBubbleRevealsStealth", 0) != 0;

    bHaveHitEffect = conf.getNum("SpellData", "HaveHitEffect", 0);
    bHaveHitBone = conf.getNum("SpellData", "HaveHitBone", 0);
    bHaveAfterEffect = conf.getNum("SpellData", "HaveAfterEffect", 0);
    bHavePointEffect = conf.getNum("SpellData", "HavePointEffect", 0);
    bIsToggleSpell = conf.getNum("SpellData", "IsToggleSpell", 0);
    bTriggersGlobalCooldown = conf.getNum("SpellData", "TriggersGlobalCooldown", 1);
    bSubjectToGlobalCooldown = conf.getNum("SpellData", "SubjectToGlobalCooldown", 1);

    mHitEffectName = conf.getString("SpellData", "HitEffectName", "");
    mHitBoneName = conf.getString("SpellData", "HitBoneName", "");
    mAfterEffectName = conf.getString("SpellData", "AfterEffectName", "");
    mPointEffectName = conf.getString("SpellData", "PointEffectName", "");
    DelayCastOffsetPercent = conf.getNum("SpellData", "DelayCastOffsetPercent", 0.0f);
    DelayTotalTimePercent = conf.getNum("SpellData", "DelayTotalTimePercent", 0.0f);
    CastTargetAdditionalUnitsRadius = conf.getNum("SpellData", "CastTargetAdditionalUnitsRadius", 0.0f);

    mLineWidth = conf.getNum("SpellData", "LineWidth", 0.0f);
    bLineMissileBounces = conf.getNum("SpellData", "LineMissileBounces", 0);
    mLineMissileEndsAtTargetPoint = conf.getNum("SpellData", "LineMissileEndsAtTargetPoint", 0) != 0;
    mCantCancelWhileWindingUp = conf.getNum("SpellData", "CantCancelWhileWindingUp", 0) != 0;
    mCantCancelWhileChanneling = conf.getNum("SpellData", "CantCancelWhileChanneling", 0) != 0;
    mApplyAttackDamage = conf.getNum("SpellData", "ApplyAttackDamage", 0) != 0;
    mBelongsToAvatar = conf.getNum("SpellData", "BelongsToAvatar", 0) != 0;
    mIsDisabledWhileDead = conf.getNum("SpellData", "IsDisabledWhileDead", 1) != 0;
    canCastWhileDisabled = conf.getNum("SpellData", "CanCastWhileDisabled", 0) != 0;
    canOnlyCastWhileDead = conf.getNum("SpellData", "CanOnlyCastWhileDead", 0) != 0;
    mStartCooldown = conf.getNum("SpellData", "StartCooldown", 0.0f);
    MissileGravity = conf.getNum("SpellData", "MissileGravity", 0.0f) * 100.0f;
    LineMissileDelayDestroyAtEndSeconds = conf.getNum("SpellData", "LineMissileDelayDestroyAtEndSeconds", 0.0f);
    LineMissileTimePulseBetweenCollisionSpellHits = conf.getNum("SpellData", "LineMissileTimePulseBetweenCollisionSpellHits", 0.0f);
    LuaOnMissileUpdateDistanceInterval = conf.getNum("SpellData", "LuaOnMissileUpdateDistanceInterval", 0.0f);
    mMissileTargetHeightAugment = conf.getNum("SpellData", "MissileTargetHeightAugment", 100.0f);
    mLineMissileTargetHeightAugment = conf.getNum("SpellData", "LineMissileTargetHeightAugment", 0.0f);
    BounceRadius = conf.getNum("SpellData", "BounceRadius", 450.0f);

    cantCastWhileRooted = conf.getNum("SpellData", "CantCastWhileRooted", 0) != 0;
    cannotBeSuppressed = conf.getNum("SpellData", "CannotBeSuppressed", 0) != 0;
    mDeathRecapPriority = conf.getNum("SpellData", "DeathRecapPriority", 0);
    LockConeToPlayer = conf.getNum("SpellData", "LockConeToPlayer", 0) != 0;
    mOverrideForceSpellCancel = conf.getNum("SpellData", "OverrideForceSpellCancel", 0) != 0;
    mOverrideForceSpellAnimation = conf.getNum("SpellData", "OverrideForceSpellAnimation", 0) != 0;
    mLineMissileCollisionFromStartPoint = conf.getNum("SpellData", "LineMissileCollisionFromStartPoint", 0) != 0;
    mLineMissileTrackUnits = conf.getNum("SpellData", "LineMissileTrackUnits", 0) != 0;
    mLocationTargettingTypeInfo.mWidth[0] = conf.getNum("SpellData", "LocationTargettingWidth1", -1.0f);

    for(int i = 1; i<7; i++)
    {
        mLocationTargettingTypeInfo.mWidth[i] = conf.getNum("SpellData", "LocationTargettingWidth"+to_string(i), 0.0f);
        mLocationTargettingTypeInfo.mLength[i] = conf.getNum("SpellData", "LocationTargettingLength"+to_string(i), 0.0f);
    }
    mParticleStartOffset = conf.getArray<float,3>("SpellData", "ParticleStartOffset", {0, 0, 0});
    mSpellRevealsChampion = conf.getNum("SpellData", "SpellRevealsChampion", 1) != 0;
    string prefrence = conf.getString("SpellData", "SelectionPreference", "none");
    if(prefrence == "friend")
        SelectionPriority = PREFERENCE_FRIEND;
    else if(prefrence == "foe")
        SelectionPriority = PREFERENCE_FOE;
    else
        SelectionPriority = PREFERENCE_NONE;
}
