#include "chardata.h"
#include "cfgreader.h"
#include "manager.h"
using namespace std;
using namespace Content;


void CharData::load(string name, Manager *manager)
{

    Config conf = manager->config("DATA/Characters/"+name+"/"+name+".ini");
    Config general = manager->config("DATA/Characters/GeneralCharacterData.ini");

    bIsMelee = stricmp(conf.getString("Data", "IsMelee", "no").c_str(),
                       "yes") == 0;
    bIsWaypoint = stricmp(conf.getString("Data", "IsWaypoint", "no").c_str(),
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
    mAttackAutoInterruptPercent = conf.getNum("AttackData", "AttackAutoInterruptPercent", 0.0f);
    mAttackAutoInterruptPercent = conf.getNum("Data", "AttackAutoInterruptPercent", mAttackAutoInterruptPercent);
    mAcquisitionRange = conf.getNum("Data", "AcquisitionRange", 750.0f);
    //mAttackDelayCastOffsetPercent = conf.getNum("Data", "AttackDelayCastOffsetPercent", 0.0);

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
}
