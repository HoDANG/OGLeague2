#ifndef NETCLIENT_H
#define NETCLIENT_H

#include <stdint.h>
#include "../dep/enet.hpp"
#include "../dep/blowfish.hpp"
#include "packets.hpp"

class NetClient
{
private:
public:
    virtual ~NetClient(){}
    virtual void OnNetworkPacket(uint32_t cid, uint8_t channel, uint8_t *data, size_t size);
    virtual void OnConnected(uint32_t cid);
    virtual void OnDisconnected(int32_t cid);

    virtual void OnPacket(uint32_t cid, PKT_Dummy_s *packet, size_t size); //0
    virtual void OnPacket(uint32_t cid, PKT_C2S_ClientConnect_NamedPipe_s *packet, size_t size); //1
    virtual void OnPacket(uint32_t cid, PKT_CHAT_s *packet, size_t size); //2
    virtual void OnPacket(uint32_t cid, PKT_C2S_QueryStatusReq_s *packet, size_t size); //3
    virtual void OnPacket(uint32_t cid, PKT_S2C_QueryStatusAns_s *packet, size_t size); //4
    virtual void OnPacket(uint32_t cid, PKT_S2C_StartSpawn_s *packet, size_t size); //5
    virtual void OnPacket(uint32_t cid, PKT_S2C_CreateHero_s *packet, size_t size); //6
    virtual void OnPacket(uint32_t cid, PKT_S2C_CreateNeutral_s *packet, size_t size); //7
    virtual void OnPacket(uint32_t cid, PKT_S2C_CreateTurret_s *packet, size_t size); //8
    virtual void OnPacket(uint32_t cid, PKT_S2C_PlayAnimation_s *packet, size_t size); //9
    virtual void OnPacket(uint32_t cid, PKT_C2S_PlayEmote_s *packet, size_t size); //10
    virtual void OnPacket(uint32_t cid, PKT_S2C_PlayEmote_s *packet, size_t size); //11
    virtual void OnPacket(uint32_t cid, PKT_S2C_EndSpawn_s *packet, size_t size); //12
    virtual void OnPacket(uint32_t cid, PKT_S2C_StartGame_s *packet, size_t size); //13
    virtual void OnPacket(uint32_t cid, PKT_S2C_EndGame_s *packet, size_t size); //14
    virtual void OnPacket(uint32_t cid, PKT_C2S_CharSelected_s *packet, size_t size); //15
    virtual void OnPacket(uint32_t cid, PKT_C2S_ClientReady_s *packet, size_t size); //16
    virtual void OnPacket(uint32_t cid, PKT_C2S_ClientFinished_s *packet, size_t size); //17
    virtual void OnPacket(uint32_t cid, PKT_NPC_UpgradeSpellReq_s *packet, size_t size); //18
    virtual void OnPacket(uint32_t cid, PKT_NPC_UpgradeSpellAns_s *packet, size_t size); //19
    virtual void OnPacket(uint32_t cid, PKT_NPC_IssueOrderReq_s *packet, size_t size); //20
    virtual void OnPacket(uint32_t cid, PKT_FX_Create_Group_s *packet, size_t size); //21
    virtual void OnPacket(uint32_t cid, PKT_FX_Kill_s *packet, size_t size); //22
    virtual void OnPacket(uint32_t cid, PKT_UnitApplyDamage_s *packet, size_t size); //23
    virtual void OnPacket(uint32_t cid, PKT_Pause_s *packet, size_t size); //24
    virtual void OnPacket(uint32_t cid, PKT_C2S_MapPing_s *packet, size_t size); //25
    virtual void OnPacket(uint32_t cid, PKT_S2C_MapPing_s *packet, size_t size); //26
    virtual void OnPacket(uint32_t cid, PKT_UnitAddGold_s *packet, size_t size); //27
    virtual void OnPacket(uint32_t cid, PKT_UnitAddEXP_s *packet, size_t size); //28
    virtual void OnPacket(uint32_t cid, PKT_UserMessagesStart_s *packet, size_t size); //29
    virtual void OnPacket(uint32_t cid, PKT_NPC_MessageToClient_s *packet, size_t size); //30
    virtual void OnPacket(uint32_t cid, PKT_AI_Command_s *packet, size_t size); //31
    virtual void OnPacket(uint32_t cid, PKT_CHAR_SpawnPet_s *packet, size_t size); //32
    virtual void OnPacket(uint32_t cid, PKT_CHAR_SetCooldown_s *packet, size_t size); //33
    virtual void OnPacket(uint32_t cid, PKT_NPC_Die_s *packet, size_t size); //34
    virtual void OnPacket(uint32_t cid, PKT_NPC_CastSpellReq_s *packet, size_t size); //36
    virtual void OnPacket(uint32_t cid, PKT_NPC_CastSpellAns_s *packet, size_t size); //37
    virtual void OnPacket(uint32_t cid, PKT_NPC_BuffAdd2_s *packet, size_t size); //38
    virtual void OnPacket(uint32_t cid, PKT_NPC_BuffRemove2_s *packet, size_t size); //42
    virtual void OnPacket(uint32_t cid, PKT_NPC_SetAutocast_s *packet, size_t size); //44
    virtual void OnPacket(uint32_t cid, PKT_BuyItemReq_s *packet, size_t size); //46
    virtual void OnPacket(uint32_t cid, PKT_BuyItemAns_s *packet, size_t size); //47
    virtual void OnPacket(uint32_t cid, PKT_RemoveItemReq_s *packet, size_t size); //48
    virtual void OnPacket(uint32_t cid, PKT_RemoveItemAns_s *packet, size_t size); //49
    virtual void OnPacket(uint32_t cid, PKT_SwapItemReq_s *packet, size_t size); //50
    virtual void OnPacket(uint32_t cid, PKT_SwapItemAns_s *packet, size_t size); //51
    virtual void OnPacket(uint32_t cid, PKT_NPC_LevelUp_s *packet, size_t size); //53
    virtual void OnPacket(uint32_t cid, PKT_NPC_InstantStop_Attack_s *packet, size_t size); //54
    virtual void OnPacket(uint32_t cid, PKT_Barrack_SpawnUnit_s *packet, size_t size); //55
    virtual void OnPacket(uint32_t cid, PKT_Turret_Fire_s *packet, size_t size); //56
    virtual void OnPacket(uint32_t cid, PKT_Turret_CreateTurret_s *packet, size_t size); //57
    virtual void OnPacket(uint32_t cid, pkt32_s *packet, size_t size); //58
    virtual void OnPacket(uint32_t cid, PKT_Basic_Attack_s *packet, size_t size); //59
    virtual void OnPacket(uint32_t cid, PKT_Basic_Attack_Pos_s *packet, size_t size); //60
    virtual void OnPacket(uint32_t cid, PKT_OnEnterVisiblityClient_s *packet, size_t size); //61
    virtual void OnPacket(uint32_t cid, PKT_OnLeaveVisiblityClient_s *packet, size_t size); //62
    virtual void OnPacket(uint32_t cid, PKT_OnEnterLocalVisiblityClient_s *packet, size_t size); //63
    virtual void OnPacket(uint32_t cid, PKT_OnLeaveLocalVisiblityClient_s *packet, size_t size); //64
    virtual void OnPacket(uint32_t cid, PKT_World_SendCamera_Server_s *packet, size_t size); //65
    virtual void OnPacket(uint32_t cid, PKT_World_LockCamera_Server_s *packet, size_t size); //66
    virtual void OnPacket(uint32_t cid, PKT_SendSelectedObjID_s *packet, size_t size); //67
    virtual void OnPacket(uint32_t cid, PKT_UnitApplyHeal_s *packet, size_t size); //68
    virtual void OnPacket(uint32_t cid, PKT_MissileReplication_s *packet, size_t size); //69
    virtual void OnPacket(uint32_t cid, PKT_ServerTick_s *packet, size_t size); //70
    virtual void OnPacket(uint32_t cid, PKT_DampenerSwitch_s *packet, size_t size); //71
    virtual void OnPacket(uint32_t cid, PKT_GlobalCombatMessage_s *packet, size_t size); //72
    virtual void OnPacket(uint32_t cid, PKT_SynchVersionC2S_s *packet, size_t size); //73
    virtual void OnPacket(uint32_t cid, PKT_SynchVersionS2C_s *packet, size_t size); //74
    virtual void OnPacket(uint32_t cid, PKT_AI_TargetS2C_s *packet, size_t size); //75
    virtual void OnPacket(uint32_t cid, PKT_AI_TargetHeroS2C_s *packet, size_t size); //76
    virtual void OnPacket(uint32_t cid, PKT_ReloadScripts_s *packet, size_t size); //77
    virtual void OnPacket(uint32_t cid, PKT_CheatPacketsBegin_s *packet, size_t size); //78
    virtual void OnPacket(uint32_t cid, PKT_CheatUnitAddExperience_s *packet, size_t size); //79
    virtual void OnPacket(uint32_t cid, PKT_CheatToggleCallForHelp_s *packet, size_t size); //80
    virtual void OnPacket(uint32_t cid, PKT_CheatUnitAddGold_s *packet, size_t size); //81
    virtual void OnPacket(uint32_t cid, PKT_CheatUnitAddHealth_s *packet, size_t size); //82
    virtual void OnPacket(uint32_t cid, PKT_CheatUnitAddMana_s *packet, size_t size); //83
    virtual void OnPacket(uint32_t cid, PKT_CheatDamageUnit_s *packet, size_t size); //84
    virtual void OnPacket(uint32_t cid, PKT_CheatDestroyUnit_s *packet, size_t size); //85
    virtual void OnPacket(uint32_t cid, PKT_CheatGiveAvatarSpell_s *packet, size_t size); //86
    virtual void OnPacket(uint32_t cid, PKT_CheatUnitStun_s *packet, size_t size); //87
    virtual void OnPacket(uint32_t cid, PKT_CheatUnitClearBuffs_s *packet, size_t size); //88
    virtual void OnPacket(uint32_t cid, PKT_CheatClearCooldowns_s *packet, size_t size); //89
    virtual void OnPacket(uint32_t cid, PKT_CheatToggleSpectator_s *packet, size_t size); //90
    virtual void OnPacket(uint32_t cid, PKT_CheatToggleInvulnerable_s *packet, size_t size); //91
    virtual void OnPacket(uint32_t cid, PKT_CheatToggleTargetInvulnerable_s *packet, size_t size); //92
    virtual void OnPacket(uint32_t cid, PKT_CheatSpawnMinionC2S_s *packet, size_t size); //93
    virtual void OnPacket(uint32_t cid, PKT_CheatSpawnMinionS2C_s *packet, size_t size); //94
    virtual void OnPacket(uint32_t cid, PKT_CheatSpawnBotC2S_s *packet, size_t size); //95
    virtual void OnPacket(uint32_t cid, PKT_CheatBarrackTurnOnOff_s *packet, size_t size); //97
    virtual void OnPacket(uint32_t cid, PKT_CheatMakeMinionsInvulnerable_s *packet, size_t size); //99
    virtual void OnPacket(uint32_t cid, PKT_CheatTeleport_s *packet, size_t size); //100
    virtual void OnPacket(uint32_t cid, PKT_CheatSetRespawnTime_s *packet, size_t size); //101
    virtual void OnPacket(uint32_t cid, PKT_CheatFoW_LocalCulling_s *packet, size_t size); //102
    virtual void OnPacket(uint32_t cid, PKT_CheatFOW_ServerBroadcastAll_s *packet, size_t size); //103
    virtual void OnPacket(uint32_t cid, PKT_CheatChangePlayerHero_s *packet, size_t size); //104
    virtual void OnPacket(uint32_t cid, PKT_CheatRunTest_s *packet, size_t size); //105
    virtual void OnPacket(uint32_t cid, PKT_CheatRunBVT_s *packet, size_t size); //106
    virtual void OnPacket(uint32_t cid, PKT_C2S_PlayAnimation_s *packet, size_t size); //107
    virtual void OnPacket(uint32_t cid, PKT_CheatPacketsEnd_s *packet, size_t size); //118
    virtual void OnPacket(uint32_t cid, PKT_CheatDebugPoint_s *packet, size_t size); //108
    virtual void OnPacket(uint32_t cid, PKT_Cheat_Pause_Toggle_s *packet, size_t size); //110
    virtual void OnPacket(uint32_t cid, PKT_Cheat_IncTime_s *packet, size_t size); //111
    virtual void OnPacket(uint32_t cid, PKT_Cheat_DecTime_s *packet, size_t size); //112
    virtual void OnPacket(uint32_t cid, PKT_SPM_HierarchicalProfilerUpdate_s *packet, size_t size); //119
    virtual void OnPacket(uint32_t cid, PKT_SPM_HierarchicalMemoryUpdate_s *packet, size_t size); //120
    virtual void OnPacket(uint32_t cid, PKT_SPM_HierarchicalBBProfileUpdate_s *packet, size_t size); //121
    virtual void OnPacket(uint32_t cid, PKT_SPM_SamplingProfilerUpdate_s *packet, size_t size); //122
    virtual void OnPacket(uint32_t cid, PKT_SPM_AddBBProfileListener_s *packet, size_t size); //123
    virtual void OnPacket(uint32_t cid, PKT_SPM_RemoveBBProfileListener_s *packet, size_t size); //124
    virtual void OnPacket(uint32_t cid, PKT_HeroReincarnateAlive_s *packet, size_t size); //125
    virtual void OnPacket(uint32_t cid, PKT_HeroReincarnate_s *packet, size_t size); //126
    virtual void OnPacket(uint32_t cid, PKT_Building_Die_s *packet, size_t size); //127
    virtual void OnPacket(uint32_t cid, PKT_SynchSimTimeS2C_s *packet, size_t size); //128
    virtual void OnPacket(uint32_t cid, PKT_SynchSimTimeC2S_s *packet, size_t size); //129
    virtual void OnPacket(uint32_t cid, PKT_SyncSimTimeFinalS2C_s *packet, size_t size); //130
    virtual void OnPacket(uint32_t cid, PKT_WaypointList_s *packet, size_t size); //131
    virtual void OnPacket(uint32_t cid, PKT_WaypointListHeroWithSpeed_s *packet, size_t size); //132
    virtual void OnPacket(uint32_t cid, PKT_ServerGameSettings_s *packet, size_t size); //133
    virtual void OnPacket(uint32_t cid, PKT_NPC_BuffUpdateCount_s *packet, size_t size); //134
    virtual void OnPacket(uint32_t cid, PKT_C2S_PlayEmoticon_s *packet, size_t size); //136
    virtual void OnPacket(uint32_t cid, PKT_S2C_PlayEmoticon_s *packet, size_t size); //137
    virtual void OnPacket(uint32_t cid, PKT_AvatarInfo_Server_s *packet, size_t size); //138
    virtual void OnPacket(uint32_t cid, PKT_RemovePerceptionBubble_s *packet, size_t size); //139
    virtual void OnPacket(uint32_t cid, PKT_AddUnitPerceptionBubble_s *packet, size_t size); //140
    virtual void OnPacket(uint32_t cid, PKT_AddPosPerceptionBubble_s *packet, size_t size); //141
    virtual void OnPacket(uint32_t cid, PKT_SpawnMinionS2C_s *packet, size_t size); //142
    virtual void OnPacket(uint32_t cid, PKT_S2C_StopAnimation_s *packet, size_t size); //143
    virtual void OnPacket(uint32_t cid, PKT_UpdateGoldRedirectTarget_s *packet, size_t size); //145
    virtual void OnPacket(uint32_t cid, PKT_S2C_ChangeCharacterData_s *packet, size_t size); //146
    virtual void OnPacket(uint32_t cid, PKT_S2C_PopCharacterData_s *packet, size_t size); //147
    virtual void OnPacket(uint32_t cid, PKT_S2C_PopAllCharacterData_s *packet, size_t size); //148
    virtual void OnPacket(uint32_t cid, PKT_S2C_FaceDirection_s *packet, size_t size); //149
    virtual void OnPacket(uint32_t cid, PKT_S2C_CameraBehavior_s *packet, size_t size); //150
    virtual void OnPacket(uint32_t cid, PKT_SPM_AddListener_s *packet, size_t size); //151
    virtual void OnPacket(uint32_t cid, PKT_SPM_RemoveListener_s *packet, size_t size); //152
    virtual void OnPacket(uint32_t cid, PKT_SPM_AddMemoryListener_s *packet, size_t size); //153
    virtual void OnPacket(uint32_t cid, PKT_SPM_RemoveMemoryListener_s *packet, size_t size); //154
    virtual void OnPacket(uint32_t cid, PKT_S2C_DestroyClientMissile_s *packet, size_t size); //155
    virtual void OnPacket(uint32_t cid, PKT_S2C_ChainMissileSync_s *packet, size_t size); //156
    virtual void OnPacket(uint32_t cid, PKT_MissileReplication_ChainMissile_s *packet, size_t size); //157
    virtual void OnPacket(uint32_t cid, PKT_S2C_BotAI_s *packet, size_t size); //158
    virtual void OnPacket(uint32_t cid, PKT_S2C_AI_TargetSelection_s *packet, size_t size); //159
    virtual void OnPacket(uint32_t cid, PKT_S2C_AI_State_s *packet, size_t size); //160
    virtual void OnPacket(uint32_t cid, PKT_OnEvent_s *packet, size_t size); //161
    virtual void OnPacket(uint32_t cid, PKT_OnDisconnected_s *packet, size_t size); //162
    virtual void OnPacket(uint32_t cid, PKT_World_SendCamera_Server_Acknologment_s *packet, size_t size); //163
    virtual void OnPacket(uint32_t cid, PKT_World_SendGameNumber_s *packet, size_t size); //164
    virtual void OnPacket(uint32_t cid, PKT_NPC_Die_EventHistroy_s *packet, size_t size); //165
    virtual void OnPacket(uint32_t cid, PKT_C2S_Ping_Load_Info_s *packet, size_t size); //166
    virtual void OnPacket(uint32_t cid, PKT_S2C_Ping_Load_Info_s *packet, size_t size); //167
    virtual void OnPacket(uint32_t cid, PKT_C2S_Exit_s *packet, size_t size); //168
    virtual void OnPacket(uint32_t cid, PKT_S2C_Exit_s *packet, size_t size); //169
    virtual void OnPacket(uint32_t cid, PKT_C2S_Reconnect_s *packet, size_t size); //170
    virtual void OnPacket(uint32_t cid, PKT_S2C_Reconnect_s *packet, size_t size); //171
    virtual void OnPacket(uint32_t cid, PKT_S2C_Reconnect_Done_s *packet, size_t size); //172
    virtual void OnPacket(uint32_t cid, PKT_Waypoint_Acc_s *packet, size_t size); //173
    virtual void OnPacket(uint32_t cid, PKT_WaypointGroup_s *packet, size_t size); //174
    virtual void OnPacket(uint32_t cid, PKT_WaypointGroupWithSpeed_s *packet, size_t size); //175
    virtual void OnPacket(uint32_t cid, PKT_Connected_s *packet, size_t size); //176
    virtual void OnPacket(uint32_t cid, PKT_S2C_ToggleInputLockingFlag_s *packet, size_t size); //177
    virtual void OnPacket(uint32_t cid, PKT_S2C_ToggleFoW_s *packet, size_t size); //178
    virtual void OnPacket(uint32_t cid, PKT_S2C_SetCircularCameraRestriction_s *packet, size_t size); //180
    virtual void OnPacket(uint32_t cid, PKT_S2C_LockCamera_s *packet, size_t size); //181
    virtual void OnPacket(uint32_t cid, PKT_OnReplication_s *packet, size_t size); //182
    virtual void OnPacket(uint32_t cid, PKT_OnReplication_Acc_s *packet, size_t size); //183
    virtual void OnPacket(uint32_t cid, PKT_S2C_MoveCameraToPoint_s *packet, size_t size); //184
    virtual void OnPacket(uint32_t cid, PKT_ChangeSlotSpellType_s *packet, size_t size); //191
    virtual void OnPacket(uint32_t cid, PKT_PausePacket_s *packet, size_t size); //192
    virtual void OnPacket(uint32_t cid, PKT_ResumePacket_s *packet, size_t size); //193
    virtual void OnPacket(uint32_t cid, PKT_SetFrequency_s *packet, size_t size); //194
    virtual void OnPacket(uint32_t cid, PKT_SetFadeOut_Push_s *packet, size_t size); //195
    virtual void OnPacket(uint32_t cid, PKT_SetFadeOut_Pop_s *packet, size_t size); //196
    virtual void OnPacket(uint32_t cid, PKT_S2C_CreateUnitHighlight_s *packet, size_t size); //197
    virtual void OnPacket(uint32_t cid, PKT_S2C_RemoveUnitHighlight_s *packet, size_t size); //198
    virtual void OnPacket(uint32_t cid, PKT_S2C_OpenTutorialPopup_s *packet, size_t size); //199
    virtual void OnPacket(uint32_t cid, PKT_C2S_OnTutorialPopupClosed_s *packet, size_t size); //200
    virtual void OnPacket(uint32_t cid, PKT_S2C_OpenAFKWarningMessage_s *packet, size_t size); //201
    virtual void OnPacket(uint32_t cid, PKT_S2C_CloseShop_s *packet, size_t size); //202

    virtual void OnPayload(uint32_t cid, EGP_RequestJoinTeam_s *payload, size_t size); //0x64
    virtual void OnPayload(uint32_t cid, EGP_RequestReskin_s *payload, size_t size); //0x65
    virtual void OnPayload(uint32_t cid, EGP_RequestRename_s *payload, size_t size); //0x66
    virtual void OnPayload(uint32_t cid, EGP_TeamRosterUpdate_s *payload, size_t size); //0x67
    virtual void OnPayload(uint32_t cid, EGP_Chat_s *payload, size_t size);
};

#endif // NETCLIENT_H
