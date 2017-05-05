#include "chardata.h"
#include "cfgreader.h"
#include "manager.h"

#include <string.h>

using namespace std;
using namespace Content;


void CharData::load(string name, Manager *manager)
{

    Config conf = manager->config("DATA/Characters/"+name+"/"+name+".ini");
    Config general = manager->config("DATA/Characters/GeneralCharacterData.ini");

    bIsMelee = _stricmp(conf.getString("Data", "IsMelee", "no").c_str(),
                       "yes") == 0;
    bIsWaypoint = _stricmp(conf.getString("Data", "IsWaypoint", "no").c_str(),
                          "yes") == 0;

    string klass = conf.getString("Data", "Classification", "Arcane");
    bIsArcane = stricmp(klass.c_str(), "Arcane") > -1;
    bIsDeadly = stricmp(klass.c_str(), "Deadly") > -1;
    bIsStrong = stricmp(klass.c_str(), "Strong") > -1;
    bNeverRender = conf.getNum("Data", "NeverRender", 0) != 0;
    bServerOnly = conf.getNum("Data", "ServerOnly", 0) != 0;
    bNoAutoAttack = conf.getNum("Data", "NoAutoAttack", 0) != 0;
    string partype = conf.getString("Data", "PARType", "MP");
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
        SpellNames[i] = conf.getString("Data", "Spell"+to_string(i+1), "");
    }
    for(int i=0; i<8; i++)
    {
        ExtraSpells[i] = conf.getString("Data", "ExtraSpell"+to_string(i+1), "");
    }
    CritAttackNameStr = conf.getString("Data", "CriticalAttack", "");
    for(int i=0; i<6; i++)
    {
        Passives[i].PassiveNameStr = conf.getString("Data", "Passive"+to_string(i+1)+"Name", "");
        Passives[i].PassiveLuaName = conf.getString("Data", "Passive"+to_string(i+1)+"LuaName", "");
        for(int c = 0; c<6; c++)
        {
            Passives[i].PassiveLevels[c] = conf.getNum("Data", "Passive"+to_string(i+1)+"Level"+to_string(c+1), -1);
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
