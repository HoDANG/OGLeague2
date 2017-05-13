#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <string>
#include <vector>


struct PARStats
{
    float flatPARPoolMod = 0;
    float percentPARPoolMod = 0;
    float flatPARRegenMod = 0;
    float percentPARRegenMod = 0;
    float flatPARModPerLevel = 0;
    float flatPARRegenModPerLevel = 0;
};
struct ItemData
{
    void load(int id);
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
