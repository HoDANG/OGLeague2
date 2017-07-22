#ifndef SPELLDATA_H
#define SPELLDATA_H

#include <string>
#include "r3d.hpp"


struct SpellData
{
    enum sflags_e
    {
        SPELL_Autocast = 0x2,
        SPELL_Instacast = 0x4,
        SPELL_PersistThroughDeath = 0x8,
        SPELL_NonDispellable = 0x10,
        SPELL_NoClick = 0x20,
        SPELL_AffectEnemies = 0x400,
        SPELL_AffectFriends = 0x800,
        SPELL_AffectNeutral = 0x4000,
        SPELL_AffectsAllSides = 0x4C00,
        SPELL_AffectBuildings = 0x1000,
        SPELL_AffectMinions = 0x8000,
        SPELL_AffectHeroes = 0x10000,
        SPELL_AffectTurrets = 0x20000,
        SPELL_AffectsAllUnitTypes = 0x38000,
        SPELL_AffectNotPet = 0x100000,
        SPELL_NotAffectSelf = 0x2000,
        SPELL_AlwaysSelf = 0x40000,
        SPELL_AffectDead = 0x80000,
        SPELL_AffectBarrackOnly = 0x200000,
        SPELL_IgnoreVisibilityCheck = 0x400000,
        SPELL_NonTargetableAlly = 0x800000,
        SPELL_NonTargetableEnemy = 0x1000000,
        SPELL_TargetableToAll = 0x2000000,
        SPELL_NonTargetableAll = 0x1800000
    };

    enum SpellToggleState
    {
        eToggleNone = 0x0,
        eToggleOff = 0x1,
        eToggleOn = 0x2
    };

    enum missiletypes_e
    {
        MISSILE_NORMAL = 0x3E8,
        MISSILE_RICOCHET = 0x3E9
    };

    enum ctype_e
    {
        CAST_Instant = 0x0,
        CAST_Missile = 0x1,
        CAST_ChainMissile = 0x2,
        CAST_ArcMissile = 0x3,
        CAST_FORCEDWORD = 0x7FFFFFFF
    };

    enum fxtype_e
    {
        FXTYPE_None = 0x0,
        FXTYPE_EffPosition = 0x1,
        FXTYPE_EffBone = 0x2,
        FXTYPE_WStreak = 0x3
    };

    enum fxflags_e
    {
        FXFLAGS_Disabled = 0x2,
        FXFLAGS_AlongBone = 0x8
    };

    enum FXTRACK_EX_HEADER_FLAGS
    {
        FXTRACK_EX_HEADER_FLAG_TARGET_BONE = 0x1
    };

    enum ttype_e
    {
        TTYPE_Invalid = 0xFFFFFFFF,
        TTYPE_Self = 0x0,
        TTYPE_Target = 0x1,
        TTYPE_Area = 0x2,
        TTYPE_Cone = 0x3,
        TTYPE_SelfAOE = 0x4,
        TTYPE_TargetOrLocation = 0x5,
        TTYPE_Location = 0x6,
        TTYPE_Direction = 0x7,
        TYPEE_Numof = 0x8,
        TTYPE_FORCEDWORD = 0x7FFFFFFF,
    };

    enum SelectionPreference_e
    {
        PREFERENCE_INVALID = 0x0,
        PREFERENCE_FOE = 0x1,
        PREFERENCE_FRIEND = 0x2,
        PREFERENCE_NONE = 0x3,
    };

    struct fxtrack_s
    {
        unsigned int flags;
        fxtype_e type;
        float startFrame;
        float endFrame;
        std::string particleName;
        std::string boneName;
        r3dPoint3D spawnOffset;
    };

    struct LocationTargettingTypeInfo
    {
      float mWidth[6];
      float mLength[6];
    };

    void load(std::string name)
    {
        r3dConf conf = r3dConf::cache("DATA/Spells/"+name+".ini");
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

    unsigned int Flags;
    unsigned int mHash;
    std::string mName;
    float mEffectAmount[5][7];
    float mCoefficient;
    float mCoefficient2;
    std::string mAnimationName;
    std::string mAnimationLoopName;
    std::string mAnimationWindownName;
    std::string mSound_CastName;
    std::string mSound_HitName;
    std::string mImgIconName;
    float mCastTime;
    float mChannelDuration;
    float CooldownTime[7];
    float DelayCastOffsetPercent;
    float DelayTotalTimePercent;
    float mStartCooldown;
    bool cannotBeSuppressed;
    bool canCastWhileDisabled;
    bool mCantCancelWhileWindingUp;
    bool mCantCancelWhileChanneling;
    bool cantCastWhileRooted;
    bool mApplyAttackDamage;
    bool mBelongsToAvatar;
    bool mIsDisabledWhileDead;
    bool canOnlyCastWhileDead;
    bool mLineMissileEndsAtTargetPoint;
    bool mSpellRevealsChampion;
    bool mOverrideForceSpellCancel;
    bool mOverrideForceSpellAnimation;
    bool mLineMissileCollisionFromStartPoint;
    bool mLineMissileTrackUnits;
    missiletypes_e MissileType;
    float CastRange[7];
    bool CastRangeUseBoundingBoxes;
    float CastRangeDisplayOverride;
    float CastRadius;
    float CastRadiusSecondary;
    float CastConeAngle;
    float CastConeDistance;
    float CastTargetAdditionalUnitsRadius;
    float BounceRadius;
    float MissileGravity;
    float mMissileTargetHeightAugment;
    float mLineMissileTargetHeightAugment;
    float LineMissileDelayDestroyAtEndSeconds;
    float LineMissileTimePulseBetweenCollisionSpellHits;
    float LuaOnMissileUpdateDistanceInterval;
    int mi_MaximumHits[6];
    int mi_CanHitSelf;
    int mi_CanHitSameTarget;
    int mi_CanHitSameTargetConsecutively;
    int mi_CanHitFriends;
    int mi_CanHitEnemies;
    SelectionPreference_e SelectionPriority;
    ctype_e CastType;
    float CastFrame;
    float mSpellDamageRatio;
    float mPhysicalDamageRatio;
    float MissileSpeed;
    float MissileAccel;
    float MissileMaxSpeed;
    float MissileMinSpeed;
    std::string mMissileEffectName;
    std::string mMissileBoneName;
    float mMissilePerceptionBubbleRadius;
    bool mMissilePerceptionBubbleRevealsStealth;
    fxtrack_s fxTracks[8];
    std::string m_FxTrackExTargetBone[8];
    int bHaveHitEffect;
    int bHaveHitBone;
    int bHaveAfterEffect;
    int bHavePointEffect;
    int bIsToggleSpell;
    float mLineWidth;
    int bLineMissileBounces;
    int bTriggersGlobalCooldown;
    int bSubjectToGlobalCooldown;
    std::string mHitBoneName;
    std::string mHitEffectName;
    std::string mAfterEffectName;
    std::string mPointEffectName;
    int SoundID[8];
    int mDeathRecapPriority;
    ttype_e TTargetingType;
    bool LockConeToPlayer;
    LocationTargettingTypeInfo mLocationTargettingTypeInfo;
    r3dPoint3D mParticleStartOffset;
    int mFloatVarsDecimals[6];
    int mFloatStaticsDecimals[6];
    unsigned int m_FileChangeNotificationHandleFX;
    unsigned int m_FileChangeNotificationHandleINI;
    float Mana[6];
};

#endif // SPELLDATA_H
