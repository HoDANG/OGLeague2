#ifndef CHARDATA_H
#define CHARDATA_H

#include <vector>
#include <string>
#include <array>

namespace Content
{
class Manager;
struct PassiveData
{
    std::string PassiveNameStr;
    std::string PassiveLuaName;
    int PassiveLevels[6];
};

struct CharData
{
    void load(std::string name, Manager *manager);
    void load(std::string name, Manager &manager)
    {
        load(name, &manager);
    }

    std::string CritAttackNameStr;
    bool bIsWaypoint;
    bool bIsMelee;
    bool bIsArcane;
    bool bIsDeadly;
    bool bIsStrong;
    bool bNeverRender;
    bool bServerOnly;
    bool bNoAutoAttack;
    int mPARType;
    float mBaseHP;
    float mBasePAR;
    float mHPPerLevel;
    float mPARPerLevel;
    float mHPRegenPerLevel;
    float mPARRegenPerLevel;
    float mBaseStaticHPRegen;
    float mBaseFactorHPRegen;
    float mBaseStaticPARRegen;
    float mBaseFactorPARRegen;
    float mBasePhysicalDamage;
    float mDamagePerLevel;
    float mBaseArmor;
    float mArmorPerLevel;
    float mBaseSpellBlock;
    float mSpellBlockPerLevel;
    float mBaseDodge;
    float mDodgePerLevel;
    float mBaseMissChance;
    float mBaseCrit;
    float mCritPerLevel;
    float mCritDamageMultiplier;
    float mBaseMoveSpeed;
    float mAttackRange;

    //missingo
    float mAttackDelayCastOffsetPercent[7];
    float mAttackDelayOffsetPercent[7];
    float mAttackProbability[7];

    float mAttackSpeedPerLevel;
    float mAcquisitionRange;
    float mAttackAutoInterruptPercent;
    float mGoldGivenOnDeath;
    float mExpGivenOnDeath;
    float mSoulGivenOnDeath;
    float mGlobalGoldGivenOnDeath;
    float mGlobalExpGivenOnDeath;
    float mPerceptionBubbleRadius;
    float mAbilityPower;
    float mAbilityPowerIncPerLevel;

    std::string SpellNames[4];
    std::string ExtraSpells[8];
    PassiveData Passives[6];
    float mHitFxScale;

    //missingo v2
    int m_RecItems[6];
    unsigned int mNumberOfAttacksAnims;
    std::vector<std::string> attackNames;
    int validAttackNames;

    float mOverrideCollisionHeight;
    float mOverrideCollisionRadius;
    float PathfindingCollisionRadius;
    float GameplayCollisionRadius;
    std::array<std::array<unsigned int, 6>, 4> mSpellsUpLevelsOverride;
    std::array<unsigned int, 4> mSpellMaxLevelsOverride;
    //GlobalCharacterData::DataStruct *m_GlobalData;
};
}

#endif // CHARDATA_H
