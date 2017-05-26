#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>>
#include "../dep/r3d.hpp"

struct ItemData
{
    struct PARStats
    {
        float flatPARPoolMod = 0;
        float percentPARPoolMod = 0;
        float flatPARRegenMod = 0;
        float percentPARRegenMod = 0;
        float flatPARModPerLevel = 0;
        float flatPARRegenModPerLevel = 0;
    };

    void load(int id)
    {
        ItemID = id;
        std::string name = to_string(id);
        r3dConf conf = r3dConf::cache("DATA/Items/"+name+".ini");
        Name = conf.getString("Data", "Name", name);
        mDisplayName = conf.getString("Data", "DisplayName", Name);
        MaxStack = conf.getNum("Data", "MaxStack", -1);
        Price = conf.getNum("Data", "Price", 100);
        mCanBeSold = conf.getNum("Data", "CanBeSold", 1);
        mCanBeDropped = conf.getNum("Data", "CanBeDropped", 1);
        mDropsOnDeath = conf.getNum("Data", "DropsOnDeath", 0);
        mDisappersOnDeath = conf.getNum("Data", "DisappersOnDeath", 0);
        mUseWhenAcquired = conf.getNum("Data", "UseWhenAcquired", 0);
        ItemClass = conf.getNum("Data", "ItemClass", 0);
        ItemType = conf.getNum("Data", "ItemType", 0);
        //mbIsPurchasable
        IsRecipe = conf.getNum("Data", "IsRecipe", 0);
        ComboItem = conf.getNum("Data", "ComboItem", 0);
        Consumed = conf.getNum("Data", "Consumed", 0);
        UsableInStore = conf.getNum("Data", "UsableInStore", 0);
        for(int i = 0;i<6;i++)
        {
            RecipeItems[i] = conf.getNum("Data", "RecipeItem"+to_string(i+1), 0);
        }
        SpellName = conf.getString("Data", "SpellName", "");
        SpellLevel = conf.getNum("Data", "SpellLevel", 1);
        SpellCharges = conf.getNum("Data", "SpellCharges", 0);
        mFlatCooldownMod = conf.getNum("Data", "FlatCooldownMod", 0.0f);
        mPercentCooldownMod = conf.getNum("Data", "PercentCooldownMod", 0.0f);
        mFlatHPPoolMod = conf.getNum("Data", "FlatHPPoolMod", 0.0f);
        mPercentHPPoolMod = conf.getNum("Data", "PercentHPPoolMod", 0.0f);
        mFlatHPRegenMod = conf.getNum("Data", "FlatHPRegenMod", 0.0f);
        mPercentHPRegenMod = conf.getNum("Data", "PercentHPRegenMod", 0.0f);
        mPercentHardnessMod = conf.getNum("Data", "PercentHardnessMod", 0.0f);
        mFlatMovementSpeedMod = conf.getNum("Data", "FlatMovementSpeedMod", 0.0f);
        mPercentMovementSpeedMod = conf.getNum("Data", "PercentMovementSpeedMod", 0.0f);
        mPercentMultiplicativeMovementSpeedMod = conf.getNum("Data", "PercentMultiplicativeMovementSpeedMod", 0.0f);
        mFlatArmorMod = conf.getNum("Data", "FlatArmorMod", 0.0f);
        mPercentArmorMod = conf.getNum("Data", "PercentArmorMod", 0.0f);
        mFlatArmorPenetrationMod = conf.getNum("Data", "FlatArmorPenetrationMod", 0.0f);
        mPercentArmorPenetrationMod = conf.getNum("Data", "PercentArmorPenetrationMod", 0.0f);
        mFlatSpellBlockMod = conf.getNum("Data", "FlatSpellBlockMod", 0.0f);
        mPercentSpellBlockMod = conf.getNum("Data", "PercentSpellBlockMod", 0.0f);
        mFlatMagicPenetrationMod = conf.getNum("Data", "FlatMagicPenetrationMod", 0.0f);
        mPercentMagicPenetrationMod = conf.getNum("Data", "PercentMagicPenetrationMod", 0.0f);
        mFlatDodgeMod = conf.getNum("Data", "FlatDodgeMod", 0.0f);
        mFlatMissChanceMod = conf.getNum("Data", "FlatMissChanceMod", 0.0f);
        mFlatCritChanceMod = conf.getNum("Data", "FlatCritChanceMod", 0.0f);
        mFlatCritDamageMod = conf.getNum("Data", "FlatCritDamageMod", 0.0f);
        mPercentCritDamageMod = conf.getNum("Data", "PercentCritDamageMod", 0.0f);
        mFlatPhysicalDamageMod = conf.getNum("Data", "FlatPhysicalDamageMod", 0.0f);
        mPercentPhysicalDamageMod = conf.getNum("Data", "PercentPhysicalDamageMod", 0.0f);
        mFlatMagicDamageMod = conf.getNum("Data", "FlatMagicDamageMod", 0.0f);
        mPercentMagicDamageMod = conf.getNum("Data", "PercentMagicDamageMod", 0.0f);
        mFlatPhysicalReduction = conf.getNum("Data", "FlatPhysicalReduction", 0.0f);
        mPercentPhysicalReduction = conf.getNum("Data", "PercentPhysicalReduction", 0.0f);
        mFlatMagicReduction = conf.getNum("Data", "FlatMagicReduction", 0.0f);
        mPercentMagicReduction = conf.getNum("Data", "PercentMagicReduction", 0.0f);
        mPercentEXPBonus = conf.getNum("Data", "PercentEXPBonus", 0.0f);
        mFlatAttackRangeMod = conf.getNum( "Data", "FlatAttackRangeMod", 0.0f);
        mPercentAttackRangeMod = conf.getNum("Data", "PercentAttackRangeMod", 0.0f);
        mFlatCastRangeMod = conf.getNum("Data", "FlatCastRangeMod", 0.0f);
        mPercentCastRangeMod = conf.getNum("Data", "PercentCastRangeMod", 0.0f);
        mPercentAttackSpeedMod = conf.getNum("Data", "PercentAttackSpeedMod", 0.0f);
        mPercentMultiplicativeAttackSpeedMod = conf.getNum("Data", "PercentMultiplicativeAttackSpeedMod", 0.0f);
        mPercentHealingAmountMod = conf.getNum("Data", "PercentHealingAmountMod", 0.0f);
        mPercentLifeStealMod = conf.getNum("Data", "PercentLifeStealMod", 0.0f);
        mPercentSpellVampMod = conf.getNum("Data", "PercentSpellVampMod", 0.0f);
        mPercentSpellEffectivenessMod = conf.getNum("Data", "PercentSpellEffectivenessMod", 0.0f);
        mPercentHealingAmountMod = conf.getNum("Data", "PercentHealingAmountMod", 0.0f);
        mFlatBubbleRadiusMod = conf.getNum("Data", "FlatBubbleRadius", 0.0f);
        mPercentBubbleRadiusMod = conf.getNum("Data", "PercentBubbleRadius", 0.0f);
        mSellBackPercentage = conf.getNum("Data", "SellBackModifier", 0.69999999f);
        m_FlatHPModPerLevel = conf.getNum("Data", "rFlatHPModPerLevel", 0.0f);
        m_FlatArmorModPerLevel = conf.getNum("Data", "rFlatArmorModPerLevel", 0.0f);
        m_FlatSpellBlockModPerLevel = conf.getNum("Data", "rFlatSpellBlockModPerLevel", 0.0f);
        m_FlatHPRegenModPerLevel = conf.getNum("Data", "rFlatHPRegenModPerLevel", 0.0f);
        m_FlatPhysicalDamageModPerLevel = conf.getNum("Data", "rFlatPhysicalDamageModPerLevel", 0.0f);
        m_FlatMagicDamageModPerLevel = conf.getNum("Data", "rFlatMagicDamageModPerLevel", 0.0f);
        m_FlatMovementSpeedModPerLevel = conf.getNum("Data", "rFlatMovementSpeedModPerLevel", 0.0f);
        m_PercentMovementSpeedModPerLevel = conf.getNum("Data", "rPercentMovementSpeedModPerLevel", 0.0f);
        m_PercentAttackSpeedModPerLevel = conf.getNum("Data", "rPercentAttackSpeedModPerLevel", 0.0f);
        m_FlatCritChanceModPerLevel = conf.getNum("Data", "rFlatCritChanceModPerLevel", 0.0f);
        m_FlatCritDamageModPerLevel = conf.getNum("Data", "rFlatCritDamageModPerLevel", 0.0f);
        m_FlatDodgeMod = conf.getNum("Data", "rFlatDodgeMod", 0.0f);
        m_FlatDodgeModPerLevel = conf.getNum("Data", "rFlatDodgeModPerLevel", 0.0f);
        m_FlatArmorPenetrationMod = conf.getNum("Data", "rFlatArmorPenetrationMod", 0.0f);
        m_FlatArmorPenetrationModPerLevel = conf.getNum("Data", "rFlatArmorPenetrationModPerLevel", 0.0f);
        m_PercentArmorPenetrationMod = conf.getNum("Data", "rPercentArmorPenetrationMod", 0.0f);
        m_PercentArmorPenetrationModPerLevel = conf.getNum("Data", "rPercentArmorPenetrationModPerLevel", 0.0f);
        m_PercentCooldownMod = conf.getNum("Data", "rPercentCooldownMod", 0.0f);
        m_PercentCooldownModPerLevel = conf.getNum("Data", "rPercentCooldownModPerLevel", 0.0f);
        m_FlatTimeDeadMod = conf.getNum("Data", "rFlatTimeDeadMod", 0.0f);
        m_FlatTimeDeadModPerLevel = conf.getNum("Data", "rFlatTimeDeadModPerLevel", 0.0f);
        m_PercentTimeDeadMod = conf.getNum("Data", "rPercentTimeDeadMod", 0.0f);
        m_PercentTimeDeadModPerLevel = conf.getNum("Data", "rPercentTimeDeadModPerLevel", 0.0f);
        mFlatGoldPer10Mod = conf.getNum("Data", "rFlatGoldPer10Mod", 0.0f);
        m_FlatMagicPenetrationMod = conf.getNum("Data", "rFlatMagicPenetrationMod", 0.0f);
        m_FlatMagicPenetrationModPerLevel = conf.getNum("Data", "rFlatMagicPenetrationModPerLevel", 0.0f);
        m_PercentMagicPenetrationMod = conf.getNum( "Data", "rPercentMagicPenetrationMod", 0.0f);
        m_PercentMagicPenetrationModPerLevel = conf.getNum("Data", "rPercentMagicPenetrationModPerLevel", 0.0f);
        //Mana
        mPARStatsArray[0].flatPARPoolMod = conf.getNum("Data", "FlatMPPoolMod", 0.0f);
        mPARStatsArray[0].percentPARPoolMod = conf.getNum("Data", "PercentMPPoolMod", 0.0f);
        mPARStatsArray[0].flatPARRegenMod = conf.getNum("Data", "FlatMPRegenMod", 0.0f);
        mPARStatsArray[0].percentPARRegenMod = conf.getNum("Data", "PercentMPRegenMod", 0.0f);
        mPARStatsArray[0].flatPARModPerLevel = conf.getNum("Data", "rFlatMPModPerLevel", 0.0f);
        mPARStatsArray[0].flatPARRegenModPerLevel = conf.getNum("Data", "rFlatMPRegenModPerLevel", 0.0f);
        //Energy
        mPARStatsArray[1].flatPARPoolMod = conf.getNum("Data", "FlatEnergyPoolMod", 0.0f);
        mPARStatsArray[1].percentPARPoolMod = conf.getNum("Data", "PercentEnergyPoolMod", 0.0f);
        mPARStatsArray[1].flatPARRegenMod = conf.getNum("Data", "FlatEnergyRegenMod", 0.0f);
        mPARStatsArray[1].percentPARRegenMod = conf.getNum("Data", "PercentEnergyRegenMod", 0.0f);
        mPARStatsArray[1].flatPARModPerLevel = conf.getNum("Data", "rFlatEnergyModPerLevel", 0.0f);
        mPARStatsArray[1].flatPARRegenModPerLevel = conf.getNum("Data", "rFlatEnergyRegenModPerLevel", 0.0f);
        //Souls
        mPARStatsArray[2].flatPARPoolMod = conf.getNum("Data", "FlatSoulsPoolMod", 0.0f);
        mPARStatsArray[2].percentPARPoolMod = conf.getNum("Data", "PercentSoulsPoolMod", 0.0f);
        mPARStatsArray[2].flatPARRegenMod = conf.getNum("Data", "FlatSoulsRegenMod", 0.0f);
        mPARStatsArray[2].percentPARRegenMod = conf.getNum("Data", "PercentSoulsRegenMod", 0.0f);
        mPARStatsArray[2].flatPARModPerLevel = conf.getNum("Data", "rFlatSoulsModPerLevel", 0.0f);
        mPARStatsArray[2].flatPARRegenModPerLevel = conf.getNum("Data", "rFlatSoulsRegenModPerLevel", 0.0f);
        //Shield
        mPARStatsArray[3].flatPARPoolMod = conf.getNum("Data", "FlatShieldPoolMod", 0.0f);
        mPARStatsArray[3].percentPARPoolMod = conf.getNum("Data", "PercentShieldPoolMod", 0.0f);
        mPARStatsArray[3].flatPARRegenMod = conf.getNum("Data", "FlatShieldRegenMod", 0.0f);
        mPARStatsArray[3].percentPARRegenMod = conf.getNum("Data", "PercentShieldRegenMod", 0.0f);
        mPARStatsArray[3].flatPARModPerLevel = conf.getNum("Data", "rFlatShieldModPerLevel", 0.0f);
        mPARStatsArray[3].flatPARRegenModPerLevel = conf.getNum("Data", "rFlatShieldRegenModPerLevel", 0.0f);
        InStore = conf.getNum("Data", "InStore", 1);
        UseEffect = conf.getNum("Data", "UseEffect", 0);
    }

    std::string Name;
    std::string SpellName;
    std::string mDisplayName;
    int ItemID = 0;
    int MaxStack = 0;
    int Price = 0;
    int Consumed = 0;
    int UsableInStore = 0;
    int ItemClass = 0;
    int ItemType = 0;
    int InStore = 0;
    bool mbIsPurchasable = 0;
    int mCanBeSold = 0;
    int mCanBeDropped = 0;
    int mDropsOnDeath = 0;
    int mDisappersOnDeath = 0;
    int mUseWhenAcquired = 0;
    int IsRecipe = 0;
    int ComboItem = 0;
    int RecipeItems[6] = {0, 0, 0, 0, 0, 0};
    int SpellLevel = 0;
    int SpellCharges = 0;
    float mFlatCooldownMod = 0;
    float mPercentCooldownMod = 0;
    float mFlatHPPoolMod = 0;
    float mPercentHPPoolMod = 0;
    float mFlatHPRegenMod = 0;
    float mPercentHPRegenMod = 0;
    float mPercentHardnessMod = 0;
    float mFlatMovementSpeedMod = 0;
    float mPercentMovementSpeedMod = 0;
    float mPercentMultiplicativeMovementSpeedMod = 0;
    float mFlatArmorMod = 0;
    float mPercentArmorMod = 0;
    float mFlatArmorPenetrationMod = 0;
    float mPercentArmorPenetrationMod = 0;
    float mFlatMagicPenetrationMod = 0;
    float mPercentMagicPenetrationMod = 0;
    float mFlatSpellBlockMod = 0;
    float mPercentSpellBlockMod = 0;
    float mFlatDodgeMod = 0;
    float mFlatCritChanceMod = 0;
    float mFlatMissChanceMod = 0;
    float mFlatCritDamageMod = 0;
    float mPercentCritDamageMod = 0;
    float mFlatPhysicalDamageMod = 0;
    float mPercentPhysicalDamageMod = 0;
    float mFlatMagicDamageMod = 0;
    float mPercentMagicDamageMod = 0;
    float mFlatPhysicalReduction = 0;
    float mPercentPhysicalReduction = 0;
    float mFlatMagicReduction = 0;
    float mPercentMagicReduction = 0;
    float mPercentEXPBonus = 0;
    float mFlatAttackRangeMod = 0;
    float mPercentAttackRangeMod = 0;
    float mFlatCastRangeMod = 0;
    float mPercentCastRangeMod = 0;
    float mPercentAttackSpeedMod = 0;
    float mPercentMultiplicativeAttackSpeedMod = 0;
    float mPercentHealingAmountMod = 0;
    float mPercentLifeStealMod = 0;
    float mPercentSpellVampMod = 0;
    float mPercentSpellEffectivenessMod = 0;
    float mFlatBubbleRadiusMod = 0;
    float mPercentBubbleRadiusMod = 0;
    float mSellBackPercentage = 0.69999999f;
    float m_FlatHPModPerLevel = 0;
    float m_FlatArmorModPerLevel = 0;
    float m_FlatSpellBlockModPerLevel = 0;
    float m_FlatHPRegenModPerLevel = 0;
    float m_FlatPhysicalDamageModPerLevel = 0;
    float m_FlatMagicDamageModPerLevel = 0;
    float m_FlatMovementSpeedModPerLevel = 0;
    float m_PercentMovementSpeedModPerLevel = 0;
    float m_PercentAttackSpeedModPerLevel = 0;
    float m_FlatCritChanceModPerLevel = 0;
    float m_FlatCritDamageModPerLevel = 0;
    float m_FlatDodgeMod = 0;
    float m_FlatDodgeModPerLevel = 0;
    float m_FlatArmorPenetrationMod = 0;
    float m_FlatArmorPenetrationModPerLevel = 0;
    float m_PercentArmorPenetrationMod = 0;
    float m_PercentArmorPenetrationModPerLevel = 0;
    float m_PercentCooldownMod = 0;
    float m_PercentCooldownModPerLevel = 0;
    float m_FlatTimeDeadMod = 0;
    float m_FlatTimeDeadModPerLevel = 0;
    float m_PercentTimeDeadMod = 0;
    float m_PercentTimeDeadModPerLevel = 0;
    float mFlatGoldPer10Mod = 0;
    float m_FlatMagicPenetrationMod = 0;
    float m_FlatMagicPenetrationModPerLevel = 0;
    float m_PercentMagicPenetrationMod = 0;
    float m_PercentMagicPenetrationModPerLevel = 0;
    std::vector<PARStats> mPARStatsArray = {
        PARStats(), PARStats(), PARStats(), PARStats()
    };
    bool UseEffect = 0;
};
#endif // ITEMDATA_H
