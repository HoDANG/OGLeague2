#ifndef PKT_BASE_H
#define PKT_BASE_H

#include <string>
#include <stdint.h>
#include <vector>
#include <sstream>
#include "../dep/buffer.hpp"
#include "../dep/enet.hpp"
#include "common/connectioninfo.h"
#include "common/playerliteinfo.h"

enum pkttype_e
{
    PKT_Dummy = 0,
    PKT_C2S_ClientConnect_NamedPipe = 1,
    PKT_CHAT = 2,
    PKT_C2S_QueryStatusReq = 3,
    PKT_S2C_QueryStatusAns = 4,
    PKT_S2C_StartSpawn = 5,
    PKT_S2C_CreateHero = 6,
    PKT_S2C_CreateNeutral = 7,
    PKT_S2C_CreateTurret = 8,
    PKT_S2C_PlayAnimation = 9,
    PKT_C2S_PlayEmote = 10,
    PKT_S2C_PlayEmote = 11,
    PKT_S2C_EndSpawn = 12,
    PKT_S2C_StartGame = 13,
    PKT_S2C_EndGame = 14,
    PKT_C2S_CharSelected = 15,
    PKT_C2S_ClientReady = 16,
    PKT_C2S_ClientFinished = 17,
    PKT_NPC_UpgradeSpellReq = 18,
    PKT_NPC_UpgradeSpellAns = 19,
    PKT_NPC_IssueOrderReq = 20,
    PKT_FX_Create_Group = 21,
    PKT_FX_Kill = 22,
    PKT_UnitApplyDamage = 23,
    PKT_Pause = 24,
    PKT_C2S_MapPing = 25,
    PKT_S2C_MapPing = 26,
    PKT_UnitAddGold = 27,
    PKT_UnitAddEXP = 28,
    PKT_UserMessagesStart = 29,
    PKT_NPC_MessageToClient = 30,
    PKT_AI_Command = 31,
    PKT_CHAR_SpawnPet = 32,
    PKT_CHAR_SetCooldown = 33,
    PKT_NPC_Die = 34,
    PKT_NPC_ForceDead = 35,
    PKT_NPC_CastSpellReq = 36,
    PKT_NPC_CastSpellAns = 37,
    PKT_NPC_BuffAdd2 = 38,
    PKT_NPC_BuffAddGroup = 39,
    PKT_NPC_BuffReplace = 40,
    PKT_NPC_BuffReplaceGroup = 41,
    PKT_NPC_BuffRemove2 = 42,
    PKT_NPC_BuffRemoveGroup = 43,
    PKT_NPC_SetAutocast = 44,
    PKT_SetItem = 45,
    PKT_BuyItemReq = 46,
    PKT_BuyItemAns = 47,
    PKT_RemoveItemReq = 48,
    PKT_RemoveItemAns = 49,
    PKT_SwapItemReq = 50,
    PKT_SwapItemAns = 51,
    PKT_UseItemAns = 52,
    PKT_NPC_LevelUp = 53,
    PKT_NPC_InstantStop_Attack = 54,
    PKT_Barrack_SpawnUnit = 55,
    PKT_Turret_Fire = 56,
    PKT_Turret_CreateTurret = 57,
    pkt32 = 58,
    PKT_Basic_Attack = 59,
    PKT_Basic_Attack_Pos = 60,
    PKT_OnEnterVisiblityClient = 61,
    PKT_OnLeaveVisiblityClient = 62,
    PKT_OnEnterLocalVisiblityClient = 63,
    PKT_OnLeaveLocalVisiblityClient = 64,
    PKT_World_SendCamera_Server = 65,
    PKT_World_LockCamera_Server = 66,
    PKT_SendSelectedObjID = 67,
    PKT_UnitApplyHeal = 68,
    PKT_MissileReplication = 69,
    PKT_ServerTick = 70,
    PKT_DampenerSwitch = 71,
    PKT_GlobalCombatMessage = 72,
    PKT_SynchVersionC2S = 73,
    PKT_SynchVersionS2C = 74,
    PKT_AI_TargetS2C = 75,
    PKT_AI_TargetHeroS2C = 76,
    PKT_ReloadScripts = 77,
    PKT_CheatPacketsBegin = 78,
    PKT_CheatUnitAddExperience = 79,
    PKT_CheatToggleCallForHelp = 80,
    PKT_CheatUnitAddGold = 81,
    PKT_CheatUnitAddHealth = 82,
    PKT_CheatUnitAddMana = 83,
    PKT_CheatDamageUnit = 84,
    PKT_CheatDestroyUnit = 85,
    PKT_CheatGiveAvatarSpell = 86,
    PKT_CheatUnitStun = 87,
    PKT_CheatUnitClearBuffs = 88,
    PKT_CheatClearCooldowns = 89,
    PKT_CheatToggleSpectator = 90,
    PKT_CheatToggleInvulnerable = 91,
    PKT_CheatToggleTargetInvulnerable = 92,
    PKT_CheatSpawnMinionC2S = 93,
    PKT_CheatSpawnMinionS2C = 94,
    PKT_CheatSpawnBotC2S = 95,
    PKT_CheatBarrackTurnOnOff = 97,
    PKT_CheatKillTurrets = 98,
    PKT_CheatMakeMinionsInvulnerable = 99,
    PKT_CheatTeleport = 100,
    PKT_CheatSetRespawnTime = 101,
    PKT_CheatFoW_LocalCulling = 102,
    PKT_CheatFOW_ServerBroadcastAll = 103,
    PKT_CheatChangePlayerHero = 104,
    PKT_CheatRunTest = 105,
    PKT_CheatRunBVT = 106,
    PKT_C2S_PlayAnimation = 107,
    PKT_CheatPacketsEnd = 118,
    PKT_CheatDebugPoint = 108,
    PKT_Cheat_StepTime = 109,
    PKT_Cheat_Pause_Toggle = 110,
    PKT_Cheat_IncTime = 111,
    PKT_Cheat_DecTime = 112,
    PKT_Cheat_ResetGameC2S = 113,
    PKT_Cheat_ResetTurretS2C = 114,
    PKT_SPM_HierarchicalProfilerUpdate = 119,
    PKT_SPM_HierarchicalMemoryUpdate = 120,
    PKT_SPM_HierarchicalBBProfileUpdate = 121,
    PKT_SPM_SamplingProfilerUpdate = 122,
    PKT_SPM_AddBBProfileListener = 123,
    PKT_SPM_RemoveBBProfileListener = 124,
    PKT_HeroReincarnateAlive = 125,
    PKT_HeroReincarnate = 126,
    PKT_Building_Die = 127,
    PKT_SynchSimTimeS2C = 128,
    PKT_SynchSimTimeC2S = 129,
    PKT_SyncSimTimeFinalS2C = 130,
    PKT_WaypointList = 131,
    PKT_WaypointListHeroWithSpeed = 132,
    PKT_ServerGameSettings = 133,
    PKT_NPC_BuffUpdateCount = 134,
    PKT_NPC_BuffUpdateCountGroup = 135,
    PKT_C2S_PlayEmoticon = 136,
    PKT_S2C_PlayEmoticon = 137,
    PKT_AvatarInfo_Server = 138,
    PKT_RemovePerceptionBubble = 139,
    PKT_AddUnitPerceptionBubble = 140,
    PKT_AddPosPerceptionBubble = 141,
    PKT_SpawnMinionS2C = 142,
    PKT_S2C_StopAnimation = 143,
    PKT_S2C_ShowHealthBar = 144,
    PKT_UpdateGoldRedirectTarget = 145,
    PKT_S2C_ChangeCharacterData = 146,
    PKT_S2C_PopCharacterData = 147,
    PKT_S2C_PopAllCharacterData = 148,
    PKT_S2C_FaceDirection = 149,
    PKT_S2C_CameraBehavior = 150,
    PKT_SPM_AddListener = 151,
    PKT_SPM_RemoveListener = 152,
    PKT_SPM_AddMemoryListener = 153,
    PKT_SPM_RemoveMemoryListener = 154,
    PKT_S2C_DestroyClientMissile = 155,
    PKT_S2C_ChainMissileSync = 156,
    PKT_MissileReplication_ChainMissile = 157,
    PKT_S2C_BotAI = 158,
    PKT_S2C_AI_TargetSelection = 159,
    PKT_S2C_AI_State = 160,
    PKT_OnEvent = 161,
    PKT_OnDisconnected = 162,
    PKT_World_SendCamera_Server_Acknologment = 163,
    PKT_World_SendGameNumber = 164,
    PKT_NPC_Die_EventHistroy = 165,
    PKT_C2S_Ping_Load_Info = 166,
    PKT_S2C_Ping_Load_Info = 167,
    PKT_C2S_Exit = 168,
    PKT_S2C_Exit = 169,
    PKT_C2S_Reconnect = 170,
    PKT_S2C_Reconnect = 171,
    PKT_S2C_Reconnect_Done = 172,
    PKT_Waypoint_Acc = 173,
    PKT_WaypointGroup = 174,
    PKT_WaypointGroupWithSpeed = 175,
    PKT_Connected = 176,
    PKT_S2C_ToggleInputLockingFlag = 177,
    PKT_S2C_ToggleFoW = 178,
    PKT_S2C_SetFoWStatus = 179,
    PKT_S2C_SetCircularCameraRestriction = 180,
    PKT_S2C_LockCamera = 181,
    PKT_OnReplication = 182,
    PKT_OnReplication_Acc = 183,
    PKT_S2C_MoveCameraToPoint = 184,
    PKT_S2C_PlayVOAudioEvent = 190,
    PKT_ChangeSlotSpellType = 191,
    PKT_PausePacket = 192,
    PKT_ResumePacket = 193,
    PKT_SetFrequency = 194,
    PKT_SetFadeOut_Push = 195,
    PKT_SetFadeOut_Pop = 196,
    PKT_S2C_CreateUnitHighlight = 197,
    PKT_S2C_RemoveUnitHighlight = 198,
    PKT_S2C_OpenTutorialPopup = 199,
    PKT_C2S_OnTutorialPopupClosed = 200,
    PKT_S2C_OpenAFKWarningMessage = 201,
    PKT_S2C_CloseShop = 202,
    PKT_S2C_SetInputLockingFlag = 203,
    PKT_C2S_OnShopOpened = 204,
    PKT_S2C_ShowObjectiveText = 206,
    PKT_S2C_HideObjectiveText = 207,
    PKT_S2C_RefreshObjectiveText = 208,
    PKT_S2C_ShowAuxiliaryText = 209,
    PKT_S2C_HideAuxiliaryText = 210,
    PKT_S2C_RefreshAuxiliaryText = 211,
    PKT_S2C_HighlightHUDElement = 212,
    PKT_S2C_HighlightShopElement = 213,
    PKT_C2S_TeamSurrenderVote = 214,
    PKT_S2C_TeamSurrenderVote = 215,
    PKT_S2C_TeamSurrenderCountDown = 216,
    PKT_S2C_TeamSurrenderStatus = 217,
    PKT_S2C_LineMissileHitList = 218,
    PKT_C2S_TutorialAudioEventFinished = 219,
    PKT_S2C_HighlightTitanBarElement = 220,
    PKT_S2C_ToggleUIHighlight = 221,
    PKT_S2C_DisplayLocalizedTutorialChatText = 222,
    PKT_S2C_ToolTipVars = 223,
    PKT_S2C_MuteVolumeCategory = 224,
    PKT_S2C_OnEventWorld = 225,
    PKT_S2C_AnimatedBuildingSetCurrentSkin = 226,
    PKT_S2C_SetGreyscaleEnabledWhenDead = 227,
    PKT_S2C_DisableHUDForEndOfGame = 228,
    PKT_ChangeSlotSpellName = 229,
    PKT_S2C_SwitchNexusesToOnIdleParticles = 230,
    PKT_S2C_FadeMinions = 231,
    PKT_S2C_FadeOutMainSFX = 232,
    PKT_S2C_HeroStats = 233,
    PKT_S2C_SetAnimStates = 234,
    PKT_ClientCheatDetectionSignal = 235,
    PKT_S2C_AddDebugCircle = 236,
    PKT_S2C_RemoveDebugCircle = 237,
    PKT_S2C_ModifyDebugCircleRadius = 238,
    PKT_S2C_ModifyDebugCircleColor = 239,
    PKT_S2C_HandleQuestUpdate = 185,
    PKT_S2C_HandleTipUpdate = 187,
    PKT_S2C_HandleUIHighlight = 188,
    PKT_C2S_OnTipEvent = 189,
    PKT_C2S_OnQuestEvent = 186,
    PKT_Undefined = 240,
    PKT_S2C_Neutral_Camp_Empty = 241,
    PKT_Batched = 255
};

enum egptype_en
{
  EGP_RequestJoinTeam = 0x64,
  EGP_RequestReskin = 0x65,
  EGP_RequestRename = 0x66,
  EGP_TeamRosterUpdate = 0x67,
  EGP_Chat = 0x68,
  EGP_sendToServer = 0x69,
  EGP_broadcastToClients = 0x6A,
};

enum EnetChannels
{
  CHANNEL_DEFAULT = 0x0,
  CHANNEL_GENERIC_APP_TO_SERVER = 0x1,
  CHANNEL_SYNCHCLOCK = 0x2,
  CHANNEL_GENERIC_APP_BROADCAST = 0x3,
  CHANNEL_GENERIC_APP_BROADCAST_UNRELIABLE = 0x4,
  CHANNEL_MIDDLE_TIER_CHAT = 0x5,
  CHANNEL_MIDDLE_TIER_ROSTER = 0x6,
  CHANNEL_NUM_TOTAL = 0x7
};


//CHANNEL_MIDDLE_TIER_ROSTER
template<uint8_t ID>
struct DefaultPayload
{
    uint8_t type = ID;
};

//CHANNEL_GENERIC_APP_BROADCAST
#pragma pack(push, 1)
template<uint8_t ID>
struct DefaultPacket
{
    uint8_t eventID = ID;
    uint32_t fromID;
};
#pragma pack(pop)

struct PKT_KeyCheck_s
{
    uint8_t cmd;
    uint32_t clientID;
    uint64_t playerID;
    uint64_t checkId;
};

template<class FROM>
class DynamicPacket : public std::stringstream
{
public:
    struct hack : public std::basic_streambuf<char>
    {
        char *eback()
        {
            return std::basic_streambuf<char>::eback();
        }
    };

    DynamicPacket()
    {
        *this < FROM();
    }
    DynamicPacket(const FROM &from)
    {
        *this < from;
    }
    DynamicPacket(FROM *from)
    {
        *this < *from;
    }
    size_t size()
    {
        return str().size();
    }
    uint8_t* data()
    {
        return (uint8_t*) ((hack*)rdbuf())->eback();
    }
    FROM* base()
    {
        return (FROM*) data();
    }
};


#endif // PKT_BASE_H
