#ifndef SPELLDATA_H
#define SPELLDATA_H

#include <string>
#include "../dep/r3d.hpp"


namespace Content
{
class Manager;
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

    void load(std::string name, Manager *manager);
    void load(std::string name, Manager &manager)
    {
        load(name, &manager);
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
}

#endif // SPELLDATA_H
