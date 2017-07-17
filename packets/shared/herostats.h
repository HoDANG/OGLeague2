#ifndef HEROSTATS_H
#define HEROSTATS_H

#include <inttypes.h>

struct __declspec(align(8)) HeroStats
{
    int64_t mPlayerID;
    int mTeamID;
    int mNumDeaths;
    int mNumMinionsKilled;
    int mNumHeroesKilled;
    int mNumTurretsKilled;
    int mNumBarracksKilled;
    int mNumMinionsDenied;
    int mNumNeutralMinionsKilled;
    int mNumSuperMonsterKilled;
    int mNumHQsKilled;
    int mGoldSpent;
    float mGoldEarned;
    int mNumTimesSpellCast[4];
    int mNumTimesAvatarSpellCast[2];
    int mMinionStreak;
    int mNumItemsBrought;
    int mNumConsumablesBrought;
    float mTotalDamageDealt;
    float mTotalDamageTaken;
    bool mTookFirstBlood;
    int mNumDoubleKills;
    int mNumTripleKills;
    int mNumQuadraKills;
    int mNumPentaKills;
    int mNumUnrealKills;
    int mNumKillingSprees;
    int mLargestHeroSpree;
    int mLargestMultiKill;
    float mTotalMagicDamageTaken;
    float mTotalPhysicalDamageTaken;
    float mTotalTrueDamageTaken;
    float mTotalMagicDamageDealt;
    float mTotalPhysicalDamageDealt;
    float mTotalTrueDamageDealt;
    float mLargestCriticalStrike;
    float mLongestTimeSpentLiving;
    float mTotalTimeDead;
    float mTimeDeathStart;
    float mTimeSpentDisconnect;
    float mTimeOfFromLastDisconnect;
    float mHealedAmount;
    int mHealedUnits;
    int mAssists;
};

#endif // HEROSTATS_H
