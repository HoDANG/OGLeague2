#ifndef CHARDATA_H
#define CHARDATA_H

#include <vector>
#include <string>
#include <array>
#include "stringutils.hpp"
#include "r3d.hpp"

struct CharData
{
    struct PassiveData
    {
        std::string PassiveNameStr;
        std::string PassiveLuaName;
        int PassiveLevels[6];
    };
    void load(std::string name)
    {
        r3dConf conf = r3dConf::cache("DATA/Characters/"+name+"/"+name+".ini");
        r3dConf general = r3dConf::cache("DATA/Characters/GeneralCharacterData.ini");
        bIsMelee = StringUtils::stringicmp(conf.getString("Data", "IsMelee", "no"),
                                           "yes") == 0;
        bIsWaypoint = StringUtils::stringicmp(conf.getString("Data", "IsWaypoint", "no"),
                                              "yes") == 0;
        std::string klass = conf.getString("Data", "Classification", "Arcane");
        bIsArcane = StringUtils::stringicmp(klass.c_str(), "Arcane") > -1;
        bIsDeadly = StringUtils::stringicmp(klass.c_str(), "Deadly") > -1;
        bIsStrong = StringUtils::stringicmp(klass.c_str(), "Strong") > -1;
        bNeverRender = conf.getNum("Data", "NeverRender", 0) != 0;
        bServerOnly = conf.getNum("Data", "ServerOnly", 0) != 0;
        bNoAutoAttack = conf.getNum("Data", "NoAutoAttack", 0) != 0;
        std::string partype = conf.getString("Data", "PARType", "MP");
        //TODO: convert string partype to int
        mBaseHP = conf.getNum("Data", "BaseHP", 100.0f);
        mBasePAR = conf.getNum("Data", "BaseMP", 100.0f);
        mHPPerLevel = conf.getNum("Data", "HPPerLevel", 10.0f);
        mPARPerLevel = conf.getNum("Data", "MPPerLevel", 10.0f);
        mHPRegenPerLevel = conf.getNum("Data", "HPRegenPerLevel", 0.0f);
        mPARRegenPerLevel = conf.getNum("Data", "MPRegenPerLevel", 0.0f);
        mBaseStaticHPRegen = conf.getNum("Data", "BaseStaticHPRegen", 0.30000001f);
        mBaseFactorHPRegen = conf.getNum("Data", "BaseFactorHPRegen", 0.0015f);
        mBaseStaticPARRegen = conf.getNum("Data", "BaseStaticMPRegen", 0.30000001f);
        mBaseFactorPARRegen = conf.getNum("Data", "BaseFactorMPRegen", 0.0015f);
        mBasePhysicalDamage = conf.getNum("Data", "BaseDamage", 10.0f);
        mDamagePerLevel = conf.getNum("Data", "DamagePerLevel", 10.0f);
        mBaseArmor = conf.getNum("Data", "Armor", 1.0f);
        mArmorPerLevel = conf.getNum("Data", "ArmorPerLevel", 1.0f);
        mBaseSpellBlock = conf.getNum("Data", "SpellBlock", 0.0f);
        mSpellBlockPerLevel = conf.getNum("Data", "SpellBlockPerLevel", 0.0f);
        mBaseDodge = conf.getNum("Data", "BaseDodge", 0.0f);
        mDodgePerLevel = conf.getNum("Data", "LevelDodge", 0.0f);
        mBaseMissChance = conf.getNum("Data", "BaseMissChance", 0.0f);
        mBaseCrit = conf.getNum("Data", "BaseCritChance", 0.0f);
        mCritPerLevel = conf.getNum("Data", "CritPerLevel", 0.0f);
        mCritDamageMultiplier = conf.getNum("Data", "CritDamageBonus", 2.0f);
        mBaseMoveSpeed = conf.getNum("Data", "MoveSpeed", 100.0f);
        mAttackRange = conf.getNum("Data", "AttackRange", 100.0f);
        mAttackAutoInterruptPercent = general.getNum("AttackData", "AttackAutoInterruptPercent", 0.0f);
        mAttackAutoInterruptPercent = conf.getNum("Data", "AttackAutoInterruptPercent", mAttackAutoInterruptPercent);
        mAcquisitionRange = conf.getNum("Data", "AcquisitionRange", 750.0f);
        mAttackDelayCastOffsetPercent[0] = conf.getNum("Data", "AttackDelayCastOffsetPercent", 0.0f);
        mAttackDelayOffsetPercent[0] = conf.getNum("Data", "AttackDelayOffsetPercent", 0.0f);
        mAttackProbability[0] = conf.getNum("Data", "BaseAttack_Probability", 1.0f);
        mAttackSpeedPerLevel = conf.getNum("Data", "AttackSpeedPerLevel", 0.0f) / 100.0f;
        mExpGivenOnDeath = conf.getNum("Data", "ExpGivenOnDeath", 48.0f);
        mGoldGivenOnDeath = conf.getNum("Data", "GoldGivenOnDeath", 25.0f);
        mSoulGivenOnDeath = conf.getNum("Data", "SoulGivenOnDeath", 0.0f);
        mGlobalGoldGivenOnDeath = conf.getNum("Data", "GlobalGoldGivenOnDeath", 0.0f);
        mGlobalExpGivenOnDeath = conf.getNum("Data", "GlobalExpGivenOnDeath", 0.0f);
        mAbilityPower = conf.getNum("Data", "BaseAbilityPower", 0.0f);
        mAbilityPowerIncPerLevel = conf.getNum("Data", "AbilityPowerIncPerLevel", 0.0f);
        mPerceptionBubbleRadius = conf.getNum("Data", "PerceptionBubbleRadius", 1350.0f);

        for(int i=0; i<4; i++)
        {
            SpellNames[i] = conf.getString("Data", "Spell"+std::to_string(i+1), "");
        }
        for(int i=0; i<8; i++)
        {
            ExtraSpells[i] = conf.getString("Data", "ExtraSpell"+std::to_string(i+1), "");
        }
        CritAttackNameStr = conf.getString("Data", "CriticalAttack", "");
        for(int i=0; i<6; i++)
        {
            Passives[i].PassiveNameStr = conf.getString("Data", "Passive"+std::to_string(i+1)+"Name", "");
            Passives[i].PassiveLuaName = conf.getString("Data", "Passive"+std::to_string(i+1)+"LuaName", "");
            for(int c = 0; c<6; c++)
            {
                Passives[i].PassiveLevels[c] = conf.getNum("Data", "Passive"+std::to_string(i+1)+"Level"+std::to_string(c+1), -1);
            }
        }
        mHitFxScale = conf.getNum("Data", "HitFxScale", 1.0f);
        for(int i=0;i<6;i++)
        {
            //m_RecItems[i] = conf.getNum("Data", "RecItem"+to_string(), )
        }
        mOverrideCollisionHeight = conf.getNum("Data", "SelectionHeight", -1.0f);
        mOverrideCollisionRadius = conf.getNum("Data", "SelectionRadius", -1.0f);
        PathfindingCollisionRadius = conf.getNum("Data", "PathfindingCollisionRadius", -1.0f);
        GameplayCollisionRadius = general.getNum("GeneralDataHero", "DefaultChampionCollisionRadius", 65.0f);
        GameplayCollisionRadius = conf.getNum("Data", "GameplayCollisionRadius", GameplayCollisionRadius);

        mSpellMaxLevelsOverride = conf.getArray<unsigned int, 4>("Data", "MaxLevels", {5, 5, 5, 3});
        mSpellsUpLevelsOverride[0] = conf.getArray<unsigned int, 6>("Data", "SpellsUpLevels1", {1, 3, 5, 7, 9, 99});
        mSpellsUpLevelsOverride[1] = conf.getArray<unsigned int, 6>("Data", "SpellsUpLevels2", {1, 3, 5, 7, 9, 99});
        mSpellsUpLevelsOverride[2] = conf.getArray<unsigned int, 6>("Data", "SpellsUpLevels3", {1, 3, 5, 7, 9, 99});
        mSpellsUpLevelsOverride[3] = conf.getArray<unsigned int, 6>("Data", "SpellsUpLevels4", {1, 3, 5, 7, 9, 99});

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

#endif // CHARDATA_H
