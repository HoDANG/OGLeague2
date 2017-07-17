#ifndef COMBATMESSAGE_H
#define COMBATMESSAGE_H

enum CombatMessage
{
    GlobalCombatMessageGroup_Start = 0xFFFFFFFE,
    CombatMessage_MultiKillStart = 0xFFFFFFFF,
    DoubleKill = 0x0,
    TripleKill = 0x1,
    QuadraKill = 0x2,
    PentaKill = 0x3,
    UnrealKill = 0x4,
    CombatMessage_MultiKillEnd = 0x5,
    CombatMessage_KillingSpreeStart = 0x6,
    IsOnFire = 0x7,
    IsOnKillingSpree = 0x8,
    HasAnUberKill = 0x9,
    IsPwning = 0xA,
    IsImba = 0xB,
    IsWTF_Owning = 0xC,
    IsDevestating = 0xD,
    IsJuggernaut = 0xE,
    IsGodlike = 0xF,
    IsBeyondGodlike = 0x10,
    OMG_Guinsoo = 0x11,
    IsUnreal = 0x12,
    HasLudicrousKill = 0x13,
    CombatMessage_KillingSpreeEnd = 0x14,
    CombatMessage_SpreeEndStart = 0x15,
    WasShutdown = 0x16,
    WasIced = 0x17,
    KillingSpreeEnd = 0x18,
    CombatMessage_SpreeEndEnd = 0x19,
    KilledByNeutral = 0x1A,
    DrewFirstBlood = 0x1B,
    GlobalCombatMessageGroup_End = 0x1C,
    PlayerOnlyGroup_Start = 0x1D,
    YouBeenSlain = 0x1E,
    YouAllySlain = 0x1F,
    PlayerOnlyGroup_End = 0x20,
};

#endif // COMBATMESSAGE_H
