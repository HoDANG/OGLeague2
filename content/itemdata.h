#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <string>
#include <vector>

namespace Content
{
class Manager;
struct PARStats
{
    float flatPARPoolMod;
    float percentPARPoolMod;
    float flatPARRegenMod;
    float percentPARRegenMod;
    float flatPARModPerLevel;
    float flatPARRegenModPerLevel;
};
struct ItemData
{
    void load(int id, Manager *manager);
    void load(int id, Manager &manager)
    {
        load(id, &manager);
    }
    std::string Name;
    std::string SpellName;
    std::string mDisplayName;
    int ItemID;
    int MaxStack;
    int Price;
    int Consumed;
    int UsableInStore;
    int ItemClass;
    int ItemType;
    int InStore;
    bool mbIsPurchasable;
    int mCanBeSold;
    int mCanBeDropped;
    int mDropsOnDeath;
    int mDisappersOnDeath;
    int mUseWhenAcquired;
    int IsRecipe;
    int ComboItem;
    int RecipeItems[6];
    int SpellLevel;
    int SpellCharges;
    float mFlatCooldownMod;
    float mPercentCooldownMod;
    float mFlatHPPoolMod;
    float mPercentHPPoolMod;
    float mFlatHPRegenMod;
    float mPercentHPRegenMod;
    float mPercentHardnessMod;
    float mFlatMovementSpeedMod;
    float mPercentMovementSpeedMod;
    float mPercentMultiplicativeMovementSpeedMod;
    float mFlatArmorMod;
    float mPercentArmorMod;
    float mFlatArmorPenetrationMod;
    float mPercentArmorPenetrationMod;
    float mFlatMagicPenetrationMod;
    float mPercentMagicPenetrationMod;
    float mFlatSpellBlockMod;
    float mPercentSpellBlockMod;
    float mFlatDodgeMod;
    float mFlatCritChanceMod;
    float mFlatMissChanceMod;
    float mFlatCritDamageMod;
    float mPercentCritDamageMod;
    float mFlatPhysicalDamageMod;
    float mPercentPhysicalDamageMod;
    float mFlatMagicDamageMod;
    float mPercentMagicDamageMod;
    float mFlatPhysicalReduction;
    float mPercentPhysicalReduction;
    float mFlatMagicReduction;
    float mPercentMagicReduction;
    float mPercentEXPBonus;
    float mFlatAttackRangeMod;
    float mPercentAttackRangeMod;
    float mFlatCastRangeMod;
    float mPercentCastRangeMod;
    float mPercentAttackSpeedMod;
    float mPercentMultiplicativeAttackSpeedMod;
    float mPercentHealingAmountMod;
    float mPercentLifeStealMod;
    float mPercentSpellVampMod;
    float mPercentSpellEffectivenessMod;
    float mFlatBubbleRadiusMod;
    float mPercentBubbleRadiusMod;
    float mSellBackPercentage;
    float m_FlatHPModPerLevel;
    float m_FlatArmorModPerLevel;
    float m_FlatSpellBlockModPerLevel;
    float m_FlatHPRegenModPerLevel;
    float m_FlatPhysicalDamageModPerLevel;
    float m_FlatMagicDamageModPerLevel;
    float m_FlatMovementSpeedModPerLevel;
    float m_PercentMovementSpeedModPerLevel;
    float m_PercentAttackSpeedModPerLevel;
    float m_FlatCritChanceModPerLevel;
    float m_FlatCritDamageModPerLevel;
    float m_FlatDodgeMod;
    float m_FlatDodgeModPerLevel;
    float m_FlatArmorPenetrationMod;
    float m_FlatArmorPenetrationModPerLevel;
    float m_PercentArmorPenetrationMod;
    float m_PercentArmorPenetrationModPerLevel;
    float m_PercentCooldownMod;
    float m_PercentCooldownModPerLevel;
    float m_FlatTimeDeadMod;
    float m_FlatTimeDeadModPerLevel;
    float m_PercentTimeDeadMod;
    float m_PercentTimeDeadModPerLevel;
    float mFlatGoldPer10Mod;
    float m_FlatMagicPenetrationMod;
    float m_FlatMagicPenetrationModPerLevel;
    float m_PercentMagicPenetrationMod;
    float m_PercentMagicPenetrationModPerLevel;
    std::vector<PARStats> mPARStatsArray;
};
}
#endif // ITEMDATA_H
