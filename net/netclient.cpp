#include "netclient.h"
#include <iostream>

void printPacket(uint8_t *data, size_t size)
{
    std::cout<<std::hex;
    for(int i=0;i<size;i++)
    {
        if(i != 0  && i%8 == 0) std::cout<<std::endl;
        if(data[i] < 16) std::cout<<0;
        std::cout<<(uint32_t) data[i]<<" ";
    }
    std::cout<<std::dec<<std::endl;
}

void NetClient::OnNetworkPacket(uint32_t cid, uint8_t channel, uint8_t *data, size_t size)
{
    switch(channel)
    {
        case CHANNEL_GENERIC_APP_TO_SERVER:
        switch(data[0])
        {
        case PKT_Dummy: OnPacket(cid, (PKT_Dummy_s*) data, size); break; //0
        case PKT_C2S_ClientConnect_NamedPipe: OnPacket(cid, (PKT_C2S_ClientConnect_NamedPipe_s*) data, size); break; //1
        case PKT_CHAT: OnPacket(cid, (PKT_CHAT_s*) data, size); break; //2
        case PKT_C2S_QueryStatusReq: OnPacket(cid, (PKT_C2S_QueryStatusReq_s*) data, size); break; //3
        case PKT_S2C_QueryStatusAns: OnPacket(cid, (PKT_S2C_QueryStatusAns_s*) data, size); break; //4
        case PKT_S2C_StartSpawn: OnPacket(cid, (PKT_S2C_StartSpawn_s*) data, size); break; //5
        case PKT_S2C_CreateHero: OnPacket(cid, (PKT_S2C_CreateHero_s*) data, size); break; //6
        case PKT_S2C_CreateNeutral: OnPacket(cid, (PKT_S2C_CreateNeutral_s*) data, size); break; //7
        case PKT_S2C_CreateTurret: OnPacket(cid, (PKT_S2C_CreateTurret_s*) data, size); break; //8
        case PKT_S2C_PlayAnimation: OnPacket(cid, (PKT_S2C_PlayAnimation_s*) data, size); break; //9
        case PKT_C2S_PlayEmote: OnPacket(cid, (PKT_C2S_PlayEmote_s*) data, size); break; //10
        case PKT_S2C_PlayEmote: OnPacket(cid, (PKT_S2C_PlayEmote_s*) data, size); break; //11
        case PKT_S2C_EndSpawn: OnPacket(cid, (PKT_S2C_EndSpawn_s*) data, size); break; //12
        case PKT_S2C_StartGame: OnPacket(cid, (PKT_S2C_StartGame_s*) data, size); break; //13
        case PKT_S2C_EndGame: OnPacket(cid, (PKT_S2C_EndGame_s*) data, size); break; //14
        case PKT_C2S_CharSelected: OnPacket(cid, (PKT_C2S_CharSelected_s*) data, size); break; //15
        case PKT_C2S_ClientReady: OnPacket(cid, (PKT_C2S_ClientReady_s*) data, size); break; //16
        case PKT_C2S_ClientFinished: OnPacket(cid, (PKT_C2S_ClientFinished_s*) data, size); break; //17
        case PKT_NPC_UpgradeSpellReq: OnPacket(cid, (PKT_NPC_UpgradeSpellReq_s*) data, size); break; //18
        case PKT_NPC_UpgradeSpellAns: OnPacket(cid, (PKT_NPC_UpgradeSpellAns_s*) data, size); break; //19
        case PKT_NPC_IssueOrderReq: OnPacket(cid, (PKT_NPC_IssueOrderReq_s*) data, size); break; //20
        case PKT_FX_Create_Group: OnPacket(cid, (PKT_FX_Create_Group_s*) data, size); break; //21
        case PKT_FX_Kill: OnPacket(cid, (PKT_FX_Kill_s*) data, size); break; //22
        case PKT_UnitApplyDamage: OnPacket(cid, (PKT_UnitApplyDamage_s*) data, size); break; //23
        case PKT_Pause: OnPacket(cid, (PKT_Pause_s*) data, size); break; //24
        case PKT_C2S_MapPing: OnPacket(cid, (PKT_C2S_MapPing_s*) data, size); break; //25
        case PKT_S2C_MapPing: OnPacket(cid, (PKT_S2C_MapPing_s*) data, size); break; //26
        case PKT_UnitAddGold: OnPacket(cid, (PKT_UnitAddGold_s*) data, size); break; //27
        case PKT_UnitAddEXP: OnPacket(cid, (PKT_UnitAddEXP_s*) data, size); break; //28
        case PKT_UserMessagesStart: OnPacket(cid, (PKT_UserMessagesStart_s*) data, size); break; //29
        case PKT_NPC_MessageToClient: OnPacket(cid, (PKT_NPC_MessageToClient_s*) data, size); break; //30
        case PKT_AI_Command: OnPacket(cid, (PKT_AI_Command_s*) data, size); break; //31
        case PKT_CHAR_SpawnPet: OnPacket(cid, (PKT_CHAR_SpawnPet_s*) data, size); break; //32
        case PKT_CHAR_SetCooldown: OnPacket(cid, (PKT_CHAR_SetCooldown_s*) data, size); break; //33
        case PKT_NPC_Die: OnPacket(cid, (PKT_NPC_Die_s*) data, size); break; //34
        case PKT_NPC_ForceDead: OnPacket(cid, (PKT_NPC_ForceDead_s*) data, size); break; //35
        case PKT_NPC_CastSpellReq: OnPacket(cid, (PKT_NPC_CastSpellReq_s*) data, size); break; //36
        case PKT_NPC_CastSpellAns: OnPacket(cid, (PKT_NPC_CastSpellAns_s*) data, size); break; //37
        case PKT_NPC_BuffAdd2: OnPacket(cid, (PKT_NPC_BuffAdd2_s*) data, size); break; //38
        case PKT_NPC_BuffAddGroup: OnPacket(cid, (PKT_NPC_BuffAddGroup_s*) data, size); break; //39
        case PKT_NPC_BuffReplace: OnPacket(cid, (PKT_NPC_BuffReplace_s*) data, size); break; //40
        case PKT_NPC_BuffReplaceGroup: OnPacket(cid, (PKT_NPC_BuffReplaceGroup_s*) data, size); break; //41
        case PKT_NPC_BuffRemove2: OnPacket(cid, (PKT_NPC_BuffRemove2_s*) data, size); break; //42
        case PKT_NPC_BuffRemoveGroup: OnPacket(cid, (PKT_NPC_BuffRemoveGroup_s*) data, size); break; //43
        case PKT_NPC_SetAutocast: OnPacket(cid, (PKT_NPC_SetAutocast_s*) data, size); break; //44
        case PKT_SetItem: OnPacket(cid, (PKT_SetItem_s*) data, size); break; //46 -> 45
        case PKT_BuyItemReq: OnPacket(cid, (PKT_BuyItemReq_s*) data, size); break; //46
        case PKT_BuyItemAns: OnPacket(cid, (PKT_BuyItemAns_s*) data, size); break; //47
        case PKT_RemoveItemReq: OnPacket(cid, (PKT_RemoveItemReq_s*) data, size); break; //48
        case PKT_RemoveItemAns: OnPacket(cid, (PKT_RemoveItemAns_s*) data, size); break; //49
        case PKT_SwapItemReq: OnPacket(cid, (PKT_SwapItemReq_s*) data, size); break; //50
        case PKT_SwapItemAns: OnPacket(cid, (PKT_SwapItemAns_s*) data, size); break; //51
        case PKT_UseItemAns: OnPacket(cid, (PKT_UseItemAns_s*) data, size); break; //52
        case PKT_NPC_LevelUp: OnPacket(cid, (PKT_NPC_LevelUp_s*) data, size); break; //53
        case PKT_NPC_InstantStop_Attack: OnPacket(cid, (PKT_NPC_InstantStop_Attack_s*) data, size); break; //54
        case PKT_Barrack_SpawnUnit: OnPacket(cid, (PKT_Barrack_SpawnUnit_s*) data, size); break; //55
        case PKT_Turret_Fire: OnPacket(cid, (PKT_Turret_Fire_s*) data, size); break; //56
        case PKT_Turret_CreateTurret: OnPacket(cid, (PKT_Turret_CreateTurret_s*) data, size); break; //57
        case pkt32: OnPacket(cid, (pkt32_s*) data, size); break; //58
        case PKT_Basic_Attack: OnPacket(cid, (PKT_Basic_Attack_s*) data, size); break; //59
        case PKT_Basic_Attack_Pos: OnPacket(cid, (PKT_Basic_Attack_Pos_s*) data, size); break; //60
        case PKT_OnEnterVisiblityClient: OnPacket(cid, (PKT_OnEnterVisiblityClient_s*) data, size); break; //61
        case PKT_OnLeaveVisiblityClient: OnPacket(cid, (PKT_OnLeaveVisiblityClient_s*) data, size); break; //62
        case PKT_OnEnterLocalVisiblityClient: OnPacket(cid, (PKT_OnEnterLocalVisiblityClient_s*) data, size); break; //63
        case PKT_OnLeaveLocalVisiblityClient: OnPacket(cid, (PKT_OnLeaveLocalVisiblityClient_s*) data, size); break; //64
        case PKT_World_SendCamera_Server: OnPacket(cid, (PKT_World_SendCamera_Server_s*) data, size); break; //65
        case PKT_World_LockCamera_Server: OnPacket(cid, (PKT_World_LockCamera_Server_s*) data, size); break; //66
        case PKT_SendSelectedObjID: OnPacket(cid, (PKT_SendSelectedObjID_s*) data, size); break; //67
        case PKT_UnitApplyHeal: OnPacket(cid, (PKT_UnitApplyHeal_s*) data, size); break; //68
        case PKT_MissileReplication: OnPacket(cid, (PKT_MissileReplication_s*) data, size); break; //69
        case PKT_ServerTick: OnPacket(cid, (PKT_ServerTick_s*) data, size); break; //70
        case PKT_DampenerSwitch: OnPacket(cid, (PKT_DampenerSwitch_s*) data, size); break; //71
        case PKT_GlobalCombatMessage: OnPacket(cid, (PKT_GlobalCombatMessage_s*) data, size); break; //72
        case PKT_SynchVersionC2S: OnPacket(cid, (PKT_SynchVersionC2S_s*) data, size); break; //73
        case PKT_SynchVersionS2C: OnPacket(cid, (PKT_SynchVersionS2C_s*) data, size); break; //74
        case PKT_AI_TargetS2C: OnPacket(cid, (PKT_AI_TargetS2C_s*) data, size); break; //75
        case PKT_AI_TargetHeroS2C: OnPacket(cid, (PKT_AI_TargetHeroS2C_s*) data, size); break; //76
        case PKT_ReloadScripts: OnPacket(cid, (PKT_ReloadScripts_s*) data, size); break; //77
        case PKT_CheatPacketsBegin: OnPacket(cid, (PKT_CheatPacketsBegin_s*) data, size); break; //78
        case PKT_CheatUnitAddExperience: OnPacket(cid, (PKT_CheatUnitAddExperience_s*) data, size); break; //79
        case PKT_CheatToggleCallForHelp: OnPacket(cid, (PKT_CheatToggleCallForHelp_s*) data, size); break; //80
        case PKT_CheatUnitAddGold: OnPacket(cid, (PKT_CheatUnitAddGold_s*) data, size); break; //81
        case PKT_CheatUnitAddHealth: OnPacket(cid, (PKT_CheatUnitAddHealth_s*) data, size); break; //82
        case PKT_CheatUnitAddMana: OnPacket(cid, (PKT_CheatUnitAddMana_s*) data, size); break; //83
        case PKT_CheatDamageUnit: OnPacket(cid, (PKT_CheatDamageUnit_s*) data, size); break; //84
        case PKT_CheatDestroyUnit: OnPacket(cid, (PKT_CheatDestroyUnit_s*) data, size); break; //85
        case PKT_CheatGiveAvatarSpell: OnPacket(cid, (PKT_CheatGiveAvatarSpell_s*) data, size); break; //86
        case PKT_CheatUnitStun: OnPacket(cid, (PKT_CheatUnitStun_s*) data, size); break; //87
        case PKT_CheatUnitClearBuffs: OnPacket(cid, (PKT_CheatUnitClearBuffs_s*) data, size); break; //88
        case PKT_CheatClearCooldowns: OnPacket(cid, (PKT_CheatClearCooldowns_s*) data, size); break; //89
        case PKT_CheatToggleSpectator: OnPacket(cid, (PKT_CheatToggleSpectator_s*) data, size); break; //90
        case PKT_CheatToggleInvulnerable: OnPacket(cid, (PKT_CheatToggleInvulnerable_s*) data, size); break; //91
        case PKT_CheatToggleTargetInvulnerable: OnPacket(cid, (PKT_CheatToggleTargetInvulnerable_s*) data, size); break; //92
        case PKT_CheatSpawnMinionC2S: OnPacket(cid, (PKT_CheatSpawnMinionC2S_s*) data, size); break; //93
        case PKT_CheatSpawnMinionS2C: OnPacket(cid, (PKT_CheatSpawnMinionS2C_s*) data, size); break; //94
        case PKT_CheatSpawnBotC2S: OnPacket(cid, (PKT_CheatSpawnBotC2S_s*) data, size); break; //95
        case PKT_CheatBarrackTurnOnOff: OnPacket(cid, (PKT_CheatBarrackTurnOnOff_s*) data, size); break; //97
        case PKT_CheatKillTurrets: OnPacket(cid, (PKT_CheatKillTurrets_s*) data, size); break; //98
        case PKT_CheatMakeMinionsInvulnerable: OnPacket(cid, (PKT_CheatMakeMinionsInvulnerable_s*) data, size); break; //99
        case PKT_CheatTeleport: OnPacket(cid, (PKT_CheatTeleport_s*) data, size); break; //100
        case PKT_CheatSetRespawnTime: OnPacket(cid, (PKT_CheatSetRespawnTime_s*) data, size); break; //101
        case PKT_CheatFoW_LocalCulling: OnPacket(cid, (PKT_CheatFoW_LocalCulling_s*) data, size); break; //102
        case PKT_CheatFOW_ServerBroadcastAll: OnPacket(cid, (PKT_CheatFOW_ServerBroadcastAll_s*) data, size); break; //103
        case PKT_CheatChangePlayerHero: OnPacket(cid, (PKT_CheatChangePlayerHero_s*) data, size); break; //104
        case PKT_CheatRunTest: OnPacket(cid, (PKT_CheatRunTest_s*) data, size); break; //105
        case PKT_CheatRunBVT: OnPacket(cid, (PKT_CheatRunBVT_s*) data, size); break; //106
        case PKT_C2S_PlayAnimation: OnPacket(cid, (PKT_C2S_PlayAnimation_s*) data, size); break; //107
        case PKT_CheatPacketsEnd: OnPacket(cid, (PKT_CheatPacketsEnd_s*) data, size); break; //118
        case PKT_CheatDebugPoint: OnPacket(cid, (PKT_CheatDebugPoint_s*) data, size); break; //108
        case PKT_Cheat_StepTime: OnPacket(cid, (PKT_Cheat_StepTime_s*) data, size); break; //109
        case PKT_Cheat_Pause_Toggle: OnPacket(cid, (PKT_Cheat_Pause_Toggle_s*) data, size); break; //110
        case PKT_Cheat_IncTime: OnPacket(cid, (PKT_Cheat_IncTime_s*) data, size); break; //111
        case PKT_Cheat_DecTime: OnPacket(cid, (PKT_Cheat_DecTime_s*) data, size); break; //112
        case PKT_Cheat_ResetGameC2S: OnPacket(cid, (PKT_Cheat_ResetGameC2S_s*) data, size); break; //113
        case PKT_Cheat_ResetTurretS2C: OnPacket(cid, (PKT_Cheat_ResetTurretS2C_s*) data, size); break; //114
        case PKT_SPM_HierarchicalProfilerUpdate: OnPacket(cid, (PKT_SPM_HierarchicalProfilerUpdate_s*) data, size); break; //119
        case PKT_SPM_HierarchicalMemoryUpdate: OnPacket(cid, (PKT_SPM_HierarchicalMemoryUpdate_s*) data, size); break; //120
        case PKT_SPM_HierarchicalBBProfileUpdate: OnPacket(cid, (PKT_SPM_HierarchicalBBProfileUpdate_s*) data, size); break; //121
        case PKT_SPM_SamplingProfilerUpdate: OnPacket(cid, (PKT_SPM_SamplingProfilerUpdate_s*) data, size); break; //122
        case PKT_SPM_AddBBProfileListener: OnPacket(cid, (PKT_SPM_AddBBProfileListener_s*) data, size); break; //123
        case PKT_SPM_RemoveBBProfileListener: OnPacket(cid, (PKT_SPM_RemoveBBProfileListener_s*) data, size); break; //124
        case PKT_HeroReincarnateAlive: OnPacket(cid, (PKT_HeroReincarnateAlive_s*) data, size); break; //125
        case PKT_HeroReincarnate: OnPacket(cid, (PKT_HeroReincarnate_s*) data, size); break; //126
        case PKT_Building_Die: OnPacket(cid, (PKT_Building_Die_s*) data, size); break; //127
        case PKT_SynchSimTimeS2C: OnPacket(cid, (PKT_SynchSimTimeS2C_s*) data, size); break; //128
        case PKT_SynchSimTimeC2S: OnPacket(cid, (PKT_SynchSimTimeC2S_s*) data, size); break; //129
        case PKT_SyncSimTimeFinalS2C: OnPacket(cid, (PKT_SyncSimTimeFinalS2C_s*) data, size); break; //130
        case PKT_WaypointList: OnPacket(cid, (PKT_WaypointList_s*) data, size); break; //131
        case PKT_WaypointListHeroWithSpeed: OnPacket(cid, (PKT_WaypointListHeroWithSpeed_s*) data, size); break; //132
        case PKT_ServerGameSettings: OnPacket(cid, (PKT_ServerGameSettings_s*) data, size); break; //133
        case PKT_NPC_BuffUpdateCount: OnPacket(cid, (PKT_NPC_BuffUpdateCount_s*) data, size); break; //134
        case PKT_NPC_BuffUpdateCountGroup: OnPacket(cid, (PKT_NPC_BuffUpdateCountGroup_s*) data, size); break; //135
        case PKT_C2S_PlayEmoticon: OnPacket(cid, (PKT_C2S_PlayEmoticon_s*) data, size); break; //136
        case PKT_S2C_PlayEmoticon: OnPacket(cid, (PKT_S2C_PlayEmoticon_s*) data, size); break; //137
        case PKT_AvatarInfo_Server: OnPacket(cid, (PKT_AvatarInfo_Server_s*) data, size); break; //138
        case PKT_RemovePerceptionBubble: OnPacket(cid, (PKT_RemovePerceptionBubble_s*) data, size); break; //139
        case PKT_AddUnitPerceptionBubble: OnPacket(cid, (PKT_AddUnitPerceptionBubble_s*) data, size); break; //140
        case PKT_AddPosPerceptionBubble: OnPacket(cid, (PKT_AddPosPerceptionBubble_s*) data, size); break; //141
        case PKT_SpawnMinionS2C: OnPacket(cid, (PKT_SpawnMinionS2C_s*) data, size); break; //142
        case PKT_S2C_StopAnimation: OnPacket(cid, (PKT_S2C_StopAnimation_s*) data, size); break; //143
        case PKT_S2C_ShowHealthBar: OnPacket(cid, (PKT_S2C_ShowHealthBar_s*) data, size); break; //144
        case PKT_UpdateGoldRedirectTarget: OnPacket(cid, (PKT_UpdateGoldRedirectTarget_s*) data, size); break; //145
        case PKT_S2C_ChangeCharacterData: OnPacket(cid, (PKT_S2C_ChangeCharacterData_s*) data, size); break; //146
        case PKT_S2C_PopCharacterData: OnPacket(cid, (PKT_S2C_PopCharacterData_s*) data, size); break; //147
        case PKT_S2C_PopAllCharacterData: OnPacket(cid, (PKT_S2C_PopAllCharacterData_s*) data, size); break; //148
        case PKT_S2C_FaceDirection: OnPacket(cid, (PKT_S2C_FaceDirection_s*) data, size); break; //149
        case PKT_S2C_CameraBehavior: OnPacket(cid, (PKT_S2C_CameraBehavior_s*) data, size); break; //150
        case PKT_SPM_AddListener: OnPacket(cid, (PKT_SPM_AddListener_s*) data, size); break; //151
        case PKT_SPM_RemoveListener: OnPacket(cid, (PKT_SPM_RemoveListener_s*) data, size); break; //152
        case PKT_SPM_AddMemoryListener: OnPacket(cid, (PKT_SPM_AddMemoryListener_s*) data, size); break; //153
        case PKT_SPM_RemoveMemoryListener: OnPacket(cid, (PKT_SPM_RemoveMemoryListener_s*) data, size); break; //154
        case PKT_S2C_DestroyClientMissile: OnPacket(cid, (PKT_S2C_DestroyClientMissile_s*) data, size); break; //155
        case PKT_S2C_ChainMissileSync: OnPacket(cid, (PKT_S2C_ChainMissileSync_s*) data, size); break; //156
        case PKT_MissileReplication_ChainMissile: OnPacket(cid, (PKT_MissileReplication_ChainMissile_s*) data, size); break; //157
        case PKT_S2C_BotAI: OnPacket(cid, (PKT_S2C_BotAI_s*) data, size); break; //158
        case PKT_S2C_AI_TargetSelection: OnPacket(cid, (PKT_S2C_AI_TargetSelection_s*) data, size); break; //159
        case PKT_S2C_AI_State: OnPacket(cid, (PKT_S2C_AI_State_s*) data, size); break; //160
        case PKT_OnEvent: OnPacket(cid, (PKT_OnEvent_s*) data, size); break; //161
        case PKT_OnDisconnected: OnPacket(cid, (PKT_OnDisconnected_s*) data, size); break; //162
        case PKT_World_SendCamera_Server_Acknologment: OnPacket(cid, (PKT_World_SendCamera_Server_Acknologment_s*) data, size); break; //163
        case PKT_World_SendGameNumber: OnPacket(cid, (PKT_World_SendGameNumber_s*) data, size); break; //164
        case PKT_NPC_Die_EventHistroy: OnPacket(cid, (PKT_NPC_Die_EventHistroy_s*) data, size); break; //165
        case PKT_C2S_Ping_Load_Info: OnPacket(cid, (PKT_C2S_Ping_Load_Info_s*) data, size); break; //166
        case PKT_S2C_Ping_Load_Info: OnPacket(cid, (PKT_S2C_Ping_Load_Info_s*) data, size); break; //167
        case PKT_C2S_Exit: OnPacket(cid, (PKT_C2S_Exit_s*) data, size); break; //168
        case PKT_S2C_Exit: OnPacket(cid, (PKT_S2C_Exit_s*) data, size); break; //169
        case PKT_C2S_Reconnect: OnPacket(cid, (PKT_C2S_Reconnect_s*) data, size); break; //170
        case PKT_S2C_Reconnect: OnPacket(cid, (PKT_S2C_Reconnect_s*) data, size); break; //171
        case PKT_S2C_Reconnect_Done: OnPacket(cid, (PKT_S2C_Reconnect_Done_s*) data, size); break; //172
        case PKT_Waypoint_Acc: OnPacket(cid, (PKT_Waypoint_Acc_s*) data, size); break; //173
        case PKT_WaypointGroup: OnPacket(cid, (PKT_WaypointGroup_s*) data, size); break; //174
        case PKT_WaypointGroupWithSpeed: OnPacket(cid, (PKT_WaypointGroupWithSpeed_s*) data, size); break; //175
        case PKT_Connected: OnPacket(cid, (PKT_Connected_s*) data, size); break; //176
        case PKT_S2C_ToggleInputLockingFlag: OnPacket(cid, (PKT_S2C_ToggleInputLockingFlag_s*) data, size); break; //177
        case PKT_S2C_ToggleFoW: OnPacket(cid, (PKT_S2C_ToggleFoW_s*) data, size); break; //178
        case PKT_S2C_SetFoWStatus: OnPacket(cid, (PKT_S2C_SetFoWStatus_s*) data, size); break; //179
        case PKT_S2C_SetCircularCameraRestriction: OnPacket(cid, (PKT_S2C_SetCircularCameraRestriction_s*) data, size); break; //180
        case PKT_S2C_LockCamera: OnPacket(cid, (PKT_S2C_LockCamera_s*) data, size); break; //181
        case PKT_OnReplication: OnPacket(cid, (PKT_OnReplication_s*) data, size); break; //182
        case PKT_OnReplication_Acc: OnPacket(cid, (PKT_OnReplication_Acc_s*) data, size); break; //183
        case PKT_S2C_MoveCameraToPoint: OnPacket(cid, (PKT_S2C_MoveCameraToPoint_s*) data, size); break; //184
        case PKT_S2C_PlayVOAudioEvent: OnPacket(cid, (PKT_S2C_PlayVOAudioEvent_s*) data, size); break; //190
        case PKT_ChangeSlotSpellType: OnPacket(cid, (PKT_ChangeSlotSpellType_s*) data, size); break; //191
        case PKT_PausePacket: OnPacket(cid, (PKT_PausePacket_s*) data, size); break; //192
        case PKT_ResumePacket: OnPacket(cid, (PKT_ResumePacket_s*) data, size); break; //193
        case PKT_SetFrequency: OnPacket(cid, (PKT_SetFrequency_s*) data, size); break; //194
        case PKT_SetFadeOut_Push: OnPacket(cid, (PKT_SetFadeOut_Push_s*) data, size); break; //195
        case PKT_SetFadeOut_Pop: OnPacket(cid, (PKT_SetFadeOut_Pop_s*) data, size); break; //196
        case PKT_S2C_CreateUnitHighlight: OnPacket(cid, (PKT_S2C_CreateUnitHighlight_s*) data, size); break; //197
        case PKT_S2C_RemoveUnitHighlight: OnPacket(cid, (PKT_S2C_RemoveUnitHighlight_s*) data, size); break; //198
        case PKT_S2C_OpenTutorialPopup: OnPacket(cid, (PKT_S2C_OpenTutorialPopup_s*) data, size); break; //199
        case PKT_C2S_OnTutorialPopupClosed: OnPacket(cid, (PKT_C2S_OnTutorialPopupClosed_s*) data, size); break; //200
        case PKT_S2C_OpenAFKWarningMessage: OnPacket(cid, (PKT_S2C_OpenAFKWarningMessage_s*) data, size); break; //201
        case PKT_S2C_CloseShop: OnPacket(cid, (PKT_S2C_CloseShop_s*) data, size); break; //202
        case PKT_S2C_SetInputLockingFlag: OnPacket(cid, (PKT_S2C_SetInputLockingFlag_s*) data, size); break; //203
        case PKT_C2S_OnShopOpened: OnPacket(cid, (PKT_C2S_OnShopOpened_s*) data, size); break; //204
        case PKT_S2C_ShowObjectiveText: OnPacket(cid, (PKT_S2C_ShowObjectiveText_s*) data, size); break; //206
        case PKT_S2C_HideObjectiveText: OnPacket(cid, (PKT_S2C_HideObjectiveText_s*) data, size); break; //207
        case PKT_S2C_RefreshObjectiveText: OnPacket(cid, (PKT_S2C_RefreshObjectiveText_s*) data, size); break; //208
        case PKT_S2C_ShowAuxiliaryText: OnPacket(cid, (PKT_S2C_ShowAuxiliaryText_s*) data, size); break; //209
        case PKT_S2C_HideAuxiliaryText: OnPacket(cid, (PKT_S2C_HideAuxiliaryText_s*) data, size); break; //210
        case PKT_S2C_RefreshAuxiliaryText: OnPacket(cid, (PKT_S2C_RefreshAuxiliaryText_s*) data, size); break; //211
        case PKT_S2C_HighlightHUDElement: OnPacket(cid, (PKT_S2C_HighlightHUDElement_s*) data, size); break; //212
        case PKT_S2C_HighlightShopElement: OnPacket(cid, (PKT_S2C_HighlightShopElement_s*) data, size); break; //213
        case PKT_C2S_TeamSurrenderVote: OnPacket(cid, (PKT_C2S_TeamSurrenderVote_s*) data, size); break; //214
        case PKT_S2C_TeamSurrenderVote: OnPacket(cid, (PKT_S2C_TeamSurrenderVote_s*) data, size); break; //215
        case PKT_S2C_TeamSurrenderCountDown: OnPacket(cid, (PKT_S2C_TeamSurrenderCountDown_s*) data, size); break; //216
        case PKT_S2C_TeamSurrenderStatus: OnPacket(cid, (PKT_S2C_TeamSurrenderStatus_s*) data, size); break; //217
        case PKT_S2C_LineMissileHitList: OnPacket(cid, (PKT_S2C_LineMissileHitList_s*) data, size); break; //218
        case PKT_C2S_TutorialAudioEventFinished: OnPacket(cid, (PKT_C2S_TutorialAudioEventFinished_s*) data, size); break; //219
        case PKT_S2C_HighlightTitanBarElement: OnPacket(cid, (PKT_S2C_HighlightTitanBarElement_s*) data, size); break; //220
        case PKT_S2C_ToggleUIHighlight: OnPacket(cid, (PKT_S2C_ToggleUIHighlight_s*) data, size); break; //221
        case PKT_S2C_DisplayLocalizedTutorialChatText: OnPacket(cid, (PKT_S2C_DisplayLocalizedTutorialChatText_s*) data, size); break; //222
        case PKT_S2C_ToolTipVars: OnPacket(cid, (PKT_S2C_ToolTipVars_s*) data, size); break; //223
        case PKT_S2C_MuteVolumeCategory: OnPacket(cid, (PKT_S2C_MuteVolumeCategory_s*) data, size); break; //224
        case PKT_S2C_OnEventWorld: OnPacket(cid, (PKT_S2C_OnEventWorld_s*) data, size); break; //225
        case PKT_S2C_AnimatedBuildingSetCurrentSkin: OnPacket(cid, (PKT_S2C_AnimatedBuildingSetCurrentSkin_s*) data, size); break; //226
        case PKT_S2C_SetGreyscaleEnabledWhenDead: OnPacket(cid, (PKT_S2C_SetGreyscaleEnabledWhenDead_s*) data, size); break; //227
        case PKT_S2C_DisableHUDForEndOfGame: OnPacket(cid, (PKT_S2C_DisableHUDForEndOfGame_s*) data, size); break; //228
        case PKT_ChangeSlotSpellName: OnPacket(cid, (PKT_ChangeSlotSpellName_s*) data, size); break; //229
        case PKT_S2C_SwitchNexusesToOnIdleParticles: OnPacket(cid, (PKT_S2C_SwitchNexusesToOnIdleParticles_s*) data, size); break; //230
        case PKT_S2C_FadeMinions: OnPacket(cid, (PKT_S2C_FadeMinions_s*) data, size); break; //231
        case PKT_S2C_FadeOutMainSFX: OnPacket(cid, (PKT_S2C_FadeOutMainSFX_s*) data, size); break; //232
        case PKT_S2C_HeroStats: OnPacket(cid, (PKT_S2C_HeroStats_s*) data, size); break; //233
        case PKT_S2C_SetAnimStates: OnPacket(cid, (PKT_S2C_SetAnimStates_s*) data, size); break; //234
        case PKT_ClientCheatDetectionSignal: OnPacket(cid, (PKT_ClientCheatDetectionSignal_s*) data, size); break; //235
        case PKT_S2C_AddDebugCircle: OnPacket(cid, (PKT_S2C_AddDebugCircle_s*) data, size); break; //236
        case PKT_S2C_RemoveDebugCircle: OnPacket(cid, (PKT_S2C_RemoveDebugCircle_s*) data, size); break; //237
        case PKT_S2C_ModifyDebugCircleRadius: OnPacket(cid, (PKT_S2C_ModifyDebugCircleRadius_s*) data, size); break; //238
        case PKT_S2C_ModifyDebugCircleColor: OnPacket(cid, (PKT_S2C_ModifyDebugCircleColor_s*) data, size); break; //239
        case PKT_S2C_HandleQuestUpdate: OnPacket(cid, (PKT_S2C_HandleQuestUpdate_s*) data, size); break; //185
        case PKT_S2C_HandleTipUpdate: OnPacket(cid, (PKT_S2C_HandleTipUpdate_s*) data, size); break; //187
        case PKT_S2C_HandleUIHighlight: OnPacket(cid, (PKT_S2C_HandleUIHighlight_s*) data, size); break; //188
        case PKT_C2S_OnTipEvent: OnPacket(cid, (PKT_C2S_OnTipEvent_s*) data, size); break; //189
        case PKT_C2S_OnQuestEvent: OnPacket(cid, (PKT_C2S_OnQuestEvent_s*) data, size); break; //186
        case PKT_Undefined: OnPacket(cid, (PKT_Undefined_s*) data, size); break; //240
        case PKT_S2C_Neutral_Camp_Empty: OnPacket(cid, (PKT_S2C_Neutral_Camp_Empty_s*) data, size); break; //241
        case PKT_Batched: OnPacket(cid, (PKT_Batched_s*) data, size); break; //255
        default:
            std::cout<<"Unkown packet ID: "<<(uint32_t)(data[0])<<std::endl;
            break;
        }
        break;
    case CHANNEL_MIDDLE_TIER_CHAT:
    case CHANNEL_MIDDLE_TIER_ROSTER:
        switch(data[0])
        {
        case EGP_RequestJoinTeam: OnPayload(cid, (EGP_RequestJoinTeam_s*)data, size); break; //0x64
        case EGP_RequestReskin: OnPayload(cid, (EGP_RequestReskin_s*)data, size); break; //0x65
        case EGP_RequestRename: OnPayload(cid, (EGP_RequestRename_s*)data, size); break; //0x66
        case EGP_TeamRosterUpdate: OnPayload(cid, (EGP_TeamRosterUpdate_s*)data, size); break; //0x67
        default:
            OnPayload(cid, (EGP_Chat_s*) data, size);
            break;
        }
        break;
    default:
        std::cout<<"Unkown channel: "<<(uint32_t)channel<<std::endl;
        break;
    }
}

void NetClient::OnConnected(uint32_t cid)
{

}

void NetClient::OnDisconnected(int32_t cid)
{

}

void NetClient::OnPacket(uint32_t cid, PKT_Dummy_s *packet, size_t size) //0
{
    std::cout<<"Unhandled packet PKT_Dummy(0)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_ClientConnect_NamedPipe_s *packet, size_t size) //1
{
    std::cout<<"Unhandled packet PKT_C2S_ClientConnect_NamedPipe(1)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CHAT_s *packet, size_t size) //2
{
    std::cout<<"Unhandled packet PKT_CHAT(2)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_QueryStatusReq_s *packet, size_t size) //3
{
    std::cout<<"Unhandled packet PKT_C2S_QueryStatusReq(3)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_QueryStatusAns_s *packet, size_t size) //4
{
    std::cout<<"Unhandled packet PKT_S2C_QueryStatusAns(4)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_StartSpawn_s *packet, size_t size) //5
{
    std::cout<<"Unhandled packet PKT_S2C_StartSpawn(5)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_CreateHero_s *packet, size_t size) //6
{
    std::cout<<"Unhandled packet PKT_S2C_CreateHero(6)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_CreateNeutral_s *packet, size_t size) //7
{
    std::cout<<"Unhandled packet PKT_S2C_CreateNeutral(7)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_CreateTurret_s *packet, size_t size) //8
{
    std::cout<<"Unhandled packet PKT_S2C_CreateTurret(8)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_PlayAnimation_s *packet, size_t size) //9
{
    std::cout<<"Unhandled packet PKT_S2C_PlayAnimation(9)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_PlayEmote_s *packet, size_t size) //10
{
    std::cout<<"Unhandled packet PKT_C2S_PlayEmote(10)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_PlayEmote_s *packet, size_t size) //11
{
    std::cout<<"Unhandled packet PKT_S2C_PlayEmote(11)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_EndSpawn_s *packet, size_t size) //12
{
    std::cout<<"Unhandled packet PKT_S2C_EndSpawn(12)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_StartGame_s *packet, size_t size) //13
{
    std::cout<<"Unhandled packet PKT_S2C_StartGame(13)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_EndGame_s *packet, size_t size) //14
{
    std::cout<<"Unhandled packet PKT_S2C_EndGame(14)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_CharSelected_s *packet, size_t size) //15
{
    std::cout<<"Unhandled packet PKT_C2S_CharSelected(15)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_ClientReady_s *packet, size_t size) //16
{
    std::cout<<"Unhandled packet PKT_C2S_ClientReady(16)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_ClientFinished_s *packet, size_t size) //17
{
    std::cout<<"Unhandled packet PKT_C2S_ClientFinished(17)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_UpgradeSpellReq_s *packet, size_t size) //18
{
    std::cout<<"Unhandled packet PKT_NPC_UpgradeSpellReq(18)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_UpgradeSpellAns_s *packet, size_t size) //19
{
    std::cout<<"Unhandled packet PKT_NPC_UpgradeSpellAns(19)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_IssueOrderReq_s *packet, size_t size) //20
{
    std::cout<<"Unhandled packet PKT_NPC_IssueOrderReq(20)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_FX_Create_Group_s *packet, size_t size) //21
{
    std::cout<<"Unhandled packet PKT_FX_Create_Group(21)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_FX_Kill_s *packet, size_t size) //22
{
    std::cout<<"Unhandled packet PKT_FX_Kill(22)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_UnitApplyDamage_s *packet, size_t size) //23
{
    std::cout<<"Unhandled packet PKT_UnitApplyDamage(23)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Pause_s *packet, size_t size) //24
{
    std::cout<<"Unhandled packet PKT_Pause(24)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_MapPing_s *packet, size_t size) //25
{
    std::cout<<"Unhandled packet PKT_C2S_MapPing(25)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_MapPing_s *packet, size_t size) //26
{
    std::cout<<"Unhandled packet PKT_S2C_MapPing(26)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_UnitAddGold_s *packet, size_t size) //27
{
    std::cout<<"Unhandled packet PKT_UnitAddGold(27)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_UnitAddEXP_s *packet, size_t size) //28
{
    std::cout<<"Unhandled packet PKT_UnitAddEXP(28)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_UserMessagesStart_s *packet, size_t size) //29
{
    std::cout<<"Unhandled packet PKT_UserMessagesStart(29)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_MessageToClient_s *packet, size_t size) //30
{
    std::cout<<"Unhandled packet PKT_NPC_MessageToClient(30)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_AI_Command_s *packet, size_t size) //31
{
    std::cout<<"Unhandled packet PKT_AI_Command(31)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CHAR_SpawnPet_s *packet, size_t size) //32
{
    std::cout<<"Unhandled packet PKT_CHAR_SpawnPet(32)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CHAR_SetCooldown_s *packet, size_t size) //33
{
    std::cout<<"Unhandled packet PKT_CHAR_SetCooldown(33)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_Die_s *packet, size_t size) //34
{
    std::cout<<"Unhandled packet PKT_NPC_Die(34)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_ForceDead_s *packet, size_t size) //35
{
    std::cout<<"Unhandled packet PKT_NPC_ForceDead(35)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_CastSpellReq_s *packet, size_t size) //36
{
    std::cout<<"Unhandled packet PKT_NPC_CastSpellReq(36)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_CastSpellAns_s *packet, size_t size) //37
{
    std::cout<<"Unhandled packet PKT_NPC_CastSpellAns(37)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_BuffAdd2_s *packet, size_t size) //38
{
    std::cout<<"Unhandled packet PKT_NPC_BuffAdd2(38)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_BuffAddGroup_s *packet, size_t size) //39
{
    std::cout<<"Unhandled packet PKT_NPC_BuffAddGroup(39)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_BuffReplace_s *packet, size_t size) //40
{
    std::cout<<"Unhandled packet PKT_NPC_BuffReplace(40)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_BuffReplaceGroup_s *packet, size_t size) //41
{
    std::cout<<"Unhandled packet PKT_NPC_BuffReplaceGroup(41)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_BuffRemove2_s *packet, size_t size) //42
{
    std::cout<<"Unhandled packet PKT_NPC_BuffRemove2(42)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_BuffRemoveGroup_s *packet, size_t size) //43
{
    std::cout<<"Unhandled packet PKT_NPC_BuffRemoveGroup(43)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_SetAutocast_s *packet, size_t size) //44
{
    std::cout<<"Unhandled packet PKT_NPC_SetAutocast(44)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SetItem_s *packet, size_t size) //46
{
    std::cout<<"Unhandled packet PKT_SetItem(46)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_BuyItemReq_s *packet, size_t size) //46
{
    std::cout<<"Unhandled packet PKT_BuyItemReq(46)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_BuyItemAns_s *packet, size_t size) //47
{
    std::cout<<"Unhandled packet PKT_BuyItemAns(47)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_RemoveItemReq_s *packet, size_t size) //48
{
    std::cout<<"Unhandled packet PKT_RemoveItemReq(48)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_RemoveItemAns_s *packet, size_t size) //49
{
    std::cout<<"Unhandled packet PKT_RemoveItemAns(49)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SwapItemReq_s *packet, size_t size) //50
{
    std::cout<<"Unhandled packet PKT_SwapItemReq(50)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SwapItemAns_s *packet, size_t size) //51
{
    std::cout<<"Unhandled packet PKT_SwapItemAns(51)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_UseItemAns_s *packet, size_t size) //52
{
    std::cout<<"Unhandled packet PKT_UseItemAns(52)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_LevelUp_s *packet, size_t size) //53
{
    std::cout<<"Unhandled packet PKT_NPC_LevelUp(53)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_InstantStop_Attack_s *packet, size_t size) //54
{
    std::cout<<"Unhandled packet PKT_NPC_InstantStop_Attack(54)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Barrack_SpawnUnit_s *packet, size_t size) //55
{
    std::cout<<"Unhandled packet PKT_Barrack_SpawnUnit(55)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Turret_Fire_s *packet, size_t size) //56
{
    std::cout<<"Unhandled packet PKT_Turret_Fire(56)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Turret_CreateTurret_s *packet, size_t size) //57
{
    std::cout<<"Unhandled packet PKT_Turret_CreateTurret(57)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, pkt32_s *packet, size_t size) //58
{
    std::cout<<"Unhandled packet pkt32(58)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Basic_Attack_s *packet, size_t size) //59
{
    std::cout<<"Unhandled packet PKT_Basic_Attack(59)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Basic_Attack_Pos_s *packet, size_t size) //60
{
    std::cout<<"Unhandled packet PKT_Basic_Attack_Pos(60)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_OnEnterVisiblityClient_s *packet, size_t size) //61
{
    std::cout<<"Unhandled packet PKT_OnEnterVisiblityClient(61)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_OnLeaveVisiblityClient_s *packet, size_t size) //62
{
    std::cout<<"Unhandled packet PKT_OnLeaveVisiblityClient(62)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_OnEnterLocalVisiblityClient_s *packet, size_t size) //63
{
    std::cout<<"Unhandled packet PKT_OnEnterLocalVisiblityClient(63)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_OnLeaveLocalVisiblityClient_s *packet, size_t size) //64
{
    std::cout<<"Unhandled packet PKT_OnLeaveLocalVisiblityClient(64)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_World_SendCamera_Server_s *packet, size_t size) //65
{
    std::cout<<"Unhandled packet PKT_World_SendCamera_Server(65)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_World_LockCamera_Server_s *packet, size_t size) //66
{
    std::cout<<"Unhandled packet PKT_World_LockCamera_Server(66)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SendSelectedObjID_s *packet, size_t size) //67
{
    std::cout<<"Unhandled packet PKT_SendSelectedObjID(67)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_UnitApplyHeal_s *packet, size_t size) //68
{
    std::cout<<"Unhandled packet PKT_UnitApplyHeal(68)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_MissileReplication_s *packet, size_t size) //69
{
    std::cout<<"Unhandled packet PKT_MissileReplication(69)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_ServerTick_s *packet, size_t size) //70
{
    std::cout<<"Unhandled packet PKT_ServerTick(70)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_DampenerSwitch_s *packet, size_t size) //71
{
    std::cout<<"Unhandled packet PKT_DampenerSwitch(71)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_GlobalCombatMessage_s *packet, size_t size) //72
{
    std::cout<<"Unhandled packet PKT_GlobalCombatMessage(72)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SynchVersionC2S_s *packet, size_t size) //73
{
    std::cout<<"Unhandled packet PKT_SynchVersionC2S(73)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SynchVersionS2C_s *packet, size_t size) //74
{
    std::cout<<"Unhandled packet PKT_SynchVersionS2C(74)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_AI_TargetS2C_s *packet, size_t size) //75
{
    std::cout<<"Unhandled packet PKT_AI_TargetS2C(75)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_AI_TargetHeroS2C_s *packet, size_t size) //76
{
    std::cout<<"Unhandled packet PKT_AI_TargetHeroS2C(76)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_ReloadScripts_s *packet, size_t size) //77
{
    std::cout<<"Unhandled packet PKT_ReloadScripts(77)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatPacketsBegin_s *packet, size_t size) //78
{
    std::cout<<"Unhandled packet PKT_CheatPacketsBegin(78)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatUnitAddExperience_s *packet, size_t size) //79
{
    std::cout<<"Unhandled packet PKT_CheatUnitAddExperience(79)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatToggleCallForHelp_s *packet, size_t size) //80
{
    std::cout<<"Unhandled packet PKT_CheatToggleCallForHelp(80)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatUnitAddGold_s *packet, size_t size) //81
{
    std::cout<<"Unhandled packet PKT_CheatUnitAddGold(81)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatUnitAddHealth_s *packet, size_t size) //82
{
    std::cout<<"Unhandled packet PKT_CheatUnitAddHealth(82)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatUnitAddMana_s *packet, size_t size) //83
{
    std::cout<<"Unhandled packet PKT_CheatUnitAddMana(83)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatDamageUnit_s *packet, size_t size) //84
{
    std::cout<<"Unhandled packet PKT_CheatDamageUnit(84)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatDestroyUnit_s *packet, size_t size) //85
{
    std::cout<<"Unhandled packet PKT_CheatDestroyUnit(85)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatGiveAvatarSpell_s *packet, size_t size) //86
{
    std::cout<<"Unhandled packet PKT_CheatGiveAvatarSpell(86)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatUnitStun_s *packet, size_t size) //87
{
    std::cout<<"Unhandled packet PKT_CheatUnitStun(87)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatUnitClearBuffs_s *packet, size_t size) //88
{
    std::cout<<"Unhandled packet PKT_CheatUnitClearBuffs(88)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatClearCooldowns_s *packet, size_t size) //89
{
    std::cout<<"Unhandled packet PKT_CheatClearCooldowns(89)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatToggleSpectator_s *packet, size_t size) //90
{
    std::cout<<"Unhandled packet PKT_CheatToggleSpectator(90)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatToggleInvulnerable_s *packet, size_t size) //91
{
    std::cout<<"Unhandled packet PKT_CheatToggleInvulnerable(91)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatToggleTargetInvulnerable_s *packet, size_t size) //92
{
    std::cout<<"Unhandled packet PKT_CheatToggleTargetInvulnerable(92)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatSpawnMinionC2S_s *packet, size_t size) //93
{
    std::cout<<"Unhandled packet PKT_CheatSpawnMinionC2S(93)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatSpawnMinionS2C_s *packet, size_t size) //94
{
    std::cout<<"Unhandled packet PKT_CheatSpawnMinionS2C(94)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatSpawnBotC2S_s *packet, size_t size) //95
{
    std::cout<<"Unhandled packet PKT_CheatSpawnBotC2S(95)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatBarrackTurnOnOff_s *packet, size_t size) //97
{
    std::cout<<"Unhandled packet PKT_CheatBarrackTurnOnOff(97)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatKillTurrets_s *packet, size_t size) //98
{
    std::cout<<"Unhandled packet PKT_CheatKillTurrets(98)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatMakeMinionsInvulnerable_s *packet, size_t size) //99
{
    std::cout<<"Unhandled packet PKT_CheatMakeMinionsInvulnerable(99)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatTeleport_s *packet, size_t size) //100
{
    std::cout<<"Unhandled packet PKT_CheatTeleport(100)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatSetRespawnTime_s *packet, size_t size) //101
{
    std::cout<<"Unhandled packet PKT_CheatSetRespawnTime(101)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatFoW_LocalCulling_s *packet, size_t size) //102
{
    std::cout<<"Unhandled packet PKT_CheatFoW_LocalCulling(102)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatFOW_ServerBroadcastAll_s *packet, size_t size) //103
{
    std::cout<<"Unhandled packet PKT_CheatFOW_ServerBroadcastAll(103)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatChangePlayerHero_s *packet, size_t size) //104
{
    std::cout<<"Unhandled packet PKT_CheatChangePlayerHero(104)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatRunTest_s *packet, size_t size) //105
{
    std::cout<<"Unhandled packet PKT_CheatRunTest(105)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatRunBVT_s *packet, size_t size) //106
{
    std::cout<<"Unhandled packet PKT_CheatRunBVT(106)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_PlayAnimation_s *packet, size_t size) //107
{
    std::cout<<"Unhandled packet PKT_C2S_PlayAnimation(107)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatPacketsEnd_s *packet, size_t size) //118
{
    std::cout<<"Unhandled packet PKT_CheatPacketsEnd(118)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_CheatDebugPoint_s *packet, size_t size) //108
{
    std::cout<<"Unhandled packet PKT_CheatDebugPoint(108)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Cheat_StepTime_s *packet, size_t size) //109
{
    std::cout<<"Unhandled packet PKT_Cheat_StepTime(109)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Cheat_Pause_Toggle_s *packet, size_t size) //110
{
    std::cout<<"Unhandled packet PKT_Cheat_Pause_Toggle(110)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Cheat_IncTime_s *packet, size_t size) //111
{
    std::cout<<"Unhandled packet PKT_Cheat_IncTime(111)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Cheat_DecTime_s *packet, size_t size) //112
{
    std::cout<<"Unhandled packet PKT_Cheat_DecTime(112)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Cheat_ResetGameC2S_s *packet, size_t size) //113
{
    std::cout<<"Unhandled packet PKT_Cheat_ResetGameC2S(113)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Cheat_ResetTurretS2C_s *packet, size_t size) //114
{
    std::cout<<"Unhandled packet PKT_Cheat_ResetTurretS2C(114)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_HierarchicalProfilerUpdate_s *packet, size_t size) //119
{
    std::cout<<"Unhandled packet PKT_SPM_HierarchicalProfilerUpdate(119)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_HierarchicalMemoryUpdate_s *packet, size_t size) //120
{
    std::cout<<"Unhandled packet PKT_SPM_HierarchicalMemoryUpdate(120)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_HierarchicalBBProfileUpdate_s *packet, size_t size) //121
{
    std::cout<<"Unhandled packet PKT_SPM_HierarchicalBBProfileUpdate(121)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_SamplingProfilerUpdate_s *packet, size_t size) //122
{
    std::cout<<"Unhandled packet PKT_SPM_SamplingProfilerUpdate(122)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_AddBBProfileListener_s *packet, size_t size) //123
{
    std::cout<<"Unhandled packet PKT_SPM_AddBBProfileListener(123)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_RemoveBBProfileListener_s *packet, size_t size) //124
{
    std::cout<<"Unhandled packet PKT_SPM_RemoveBBProfileListener(124)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_HeroReincarnateAlive_s *packet, size_t size) //125
{
    std::cout<<"Unhandled packet PKT_HeroReincarnateAlive(125)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_HeroReincarnate_s *packet, size_t size) //126
{
    std::cout<<"Unhandled packet PKT_HeroReincarnate(126)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Building_Die_s *packet, size_t size) //127
{
    std::cout<<"Unhandled packet PKT_Building_Die(127)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SynchSimTimeS2C_s *packet, size_t size) //128
{
    std::cout<<"Unhandled packet PKT_SynchSimTimeS2C(128)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SynchSimTimeC2S_s *packet, size_t size) //129
{
    std::cout<<"Unhandled packet PKT_SynchSimTimeC2S(129)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SyncSimTimeFinalS2C_s *packet, size_t size) //130
{
    std::cout<<"Unhandled packet PKT_SyncSimTimeFinalS2C(130)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_WaypointList_s *packet, size_t size) //131
{
    std::cout<<"Unhandled packet PKT_WaypointList(131)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_WaypointListHeroWithSpeed_s *packet, size_t size) //132
{
    std::cout<<"Unhandled packet PKT_WaypointListHeroWithSpeed(132)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_ServerGameSettings_s *packet, size_t size) //133
{
    std::cout<<"Unhandled packet PKT_ServerGameSettings(133)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_BuffUpdateCount_s *packet, size_t size) //134
{
    std::cout<<"Unhandled packet PKT_NPC_BuffUpdateCount(134)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_BuffUpdateCountGroup_s *packet, size_t size) //135
{
    std::cout<<"Unhandled packet PKT_NPC_BuffUpdateCountGroup(135)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_PlayEmoticon_s *packet, size_t size) //136
{
    std::cout<<"Unhandled packet PKT_C2S_PlayEmoticon(136)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_PlayEmoticon_s *packet, size_t size) //137
{
    std::cout<<"Unhandled packet PKT_S2C_PlayEmoticon(137)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_AvatarInfo_Server_s *packet, size_t size) //138
{
    std::cout<<"Unhandled packet PKT_AvatarInfo_Server(138)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_RemovePerceptionBubble_s *packet, size_t size) //139
{
    std::cout<<"Unhandled packet PKT_RemovePerceptionBubble(139)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_AddUnitPerceptionBubble_s *packet, size_t size) //140
{
    std::cout<<"Unhandled packet PKT_AddUnitPerceptionBubble(140)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_AddPosPerceptionBubble_s *packet, size_t size) //141
{
    std::cout<<"Unhandled packet PKT_AddPosPerceptionBubble(141)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SpawnMinionS2C_s *packet, size_t size) //142
{
    std::cout<<"Unhandled packet PKT_SpawnMinionS2C(142)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_StopAnimation_s *packet, size_t size) //143
{
    std::cout<<"Unhandled packet PKT_S2C_StopAnimation(143)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ShowHealthBar_s *packet, size_t size) //144
{
    std::cout<<"Unhandled packet PKT_S2C_ShowHealthBar(144)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_UpdateGoldRedirectTarget_s *packet, size_t size) //145
{
    std::cout<<"Unhandled packet PKT_UpdateGoldRedirectTarget(145)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ChangeCharacterData_s *packet, size_t size) //146
{
    std::cout<<"Unhandled packet PKT_S2C_ChangeCharacterData(146)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_PopCharacterData_s *packet, size_t size) //147
{
    std::cout<<"Unhandled packet PKT_S2C_PopCharacterData(147)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_PopAllCharacterData_s *packet, size_t size) //148
{
    std::cout<<"Unhandled packet PKT_S2C_PopAllCharacterData(148)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_FaceDirection_s *packet, size_t size) //149
{
    std::cout<<"Unhandled packet PKT_S2C_FaceDirection(149)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_CameraBehavior_s *packet, size_t size) //150
{
    std::cout<<"Unhandled packet PKT_S2C_CameraBehavior(150)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_AddListener_s *packet, size_t size) //151
{
    std::cout<<"Unhandled packet PKT_SPM_AddListener(151)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_RemoveListener_s *packet, size_t size) //152
{
    std::cout<<"Unhandled packet PKT_SPM_RemoveListener(152)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_AddMemoryListener_s *packet, size_t size) //153
{
    std::cout<<"Unhandled packet PKT_SPM_AddMemoryListener(153)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SPM_RemoveMemoryListener_s *packet, size_t size) //154
{
    std::cout<<"Unhandled packet PKT_SPM_RemoveMemoryListener(154)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_DestroyClientMissile_s *packet, size_t size) //155
{
    std::cout<<"Unhandled packet PKT_S2C_DestroyClientMissile(155)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ChainMissileSync_s *packet, size_t size) //156
{
    std::cout<<"Unhandled packet PKT_S2C_ChainMissileSync(156)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_MissileReplication_ChainMissile_s *packet, size_t size) //157
{
    std::cout<<"Unhandled packet PKT_MissileReplication_ChainMissile(157)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_BotAI_s *packet, size_t size) //158
{
    std::cout<<"Unhandled packet PKT_S2C_BotAI(158)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_AI_TargetSelection_s *packet, size_t size) //159
{
    std::cout<<"Unhandled packet PKT_S2C_AI_TargetSelection(159)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_AI_State_s *packet, size_t size) //160
{
    std::cout<<"Unhandled packet PKT_S2C_AI_State(160)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_OnEvent_s *packet, size_t size) //161
{
    std::cout<<"Unhandled packet PKT_OnEvent(161)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_OnDisconnected_s *packet, size_t size) //162
{
    std::cout<<"Unhandled packet PKT_OnDisconnected(162)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_World_SendCamera_Server_Acknologment_s *packet, size_t size) //163
{
    std::cout<<"Unhandled packet PKT_World_SendCamera_Server_Acknologment(163)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_World_SendGameNumber_s *packet, size_t size) //164
{
    std::cout<<"Unhandled packet PKT_World_SendGameNumber(164)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_NPC_Die_EventHistroy_s *packet, size_t size) //165
{
    std::cout<<"Unhandled packet PKT_NPC_Die_EventHistroy(165)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_Ping_Load_Info_s *packet, size_t size) //166
{
    std::cout<<"Unhandled packet PKT_C2S_Ping_Load_Info(166)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_Ping_Load_Info_s *packet, size_t size) //167
{
    std::cout<<"Unhandled packet PKT_S2C_Ping_Load_Info(167)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_Exit_s *packet, size_t size) //168
{
    std::cout<<"Unhandled packet PKT_C2S_Exit(168)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_Exit_s *packet, size_t size) //169
{
    std::cout<<"Unhandled packet PKT_S2C_Exit(169)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_Reconnect_s *packet, size_t size) //170
{
    std::cout<<"Unhandled packet PKT_C2S_Reconnect(170)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_Reconnect_s *packet, size_t size) //171
{
    std::cout<<"Unhandled packet PKT_S2C_Reconnect(171)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_Reconnect_Done_s *packet, size_t size) //172
{
    std::cout<<"Unhandled packet PKT_S2C_Reconnect_Done(172)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Waypoint_Acc_s *packet, size_t size) //173
{
    std::cout<<"Unhandled packet PKT_Waypoint_Acc(173)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_WaypointGroup_s *packet, size_t size) //174
{
    std::cout<<"Unhandled packet PKT_WaypointGroup(174)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_WaypointGroupWithSpeed_s *packet, size_t size) //175
{
    std::cout<<"Unhandled packet PKT_WaypointGroupWithSpeed(175)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Connected_s *packet, size_t size) //176
{
    std::cout<<"Unhandled packet PKT_Connected(176)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ToggleInputLockingFlag_s *packet, size_t size) //177
{
    std::cout<<"Unhandled packet PKT_S2C_ToggleInputLockingFlag(177)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ToggleFoW_s *packet, size_t size) //178
{
    std::cout<<"Unhandled packet PKT_S2C_ToggleFoW(178)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_SetFoWStatus_s *packet, size_t size) //179
{
    std::cout<<"Unhandled packet PKT_S2C_SetFoWStatus(179)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_SetCircularCameraRestriction_s *packet, size_t size) //180
{
    std::cout<<"Unhandled packet PKT_S2C_SetCircularCameraRestriction(180)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_LockCamera_s *packet, size_t size) //181
{
    std::cout<<"Unhandled packet PKT_S2C_LockCamera(181)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_OnReplication_s *packet, size_t size) //182
{
    std::cout<<"Unhandled packet PKT_OnReplication(182)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_OnReplication_Acc_s *packet, size_t size) //183
{
    std::cout<<"Unhandled packet PKT_OnReplication_Acc(183)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_MoveCameraToPoint_s *packet, size_t size) //184
{
    std::cout<<"Unhandled packet PKT_S2C_MoveCameraToPoint(184)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_PlayVOAudioEvent_s *packet, size_t size) //190
{
    std::cout<<"Unhandled packet PKT_S2C_PlayVOAudioEvent(190)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_ChangeSlotSpellType_s *packet, size_t size) //191
{
    std::cout<<"Unhandled packet PKT_ChangeSlotSpellType(191)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_PausePacket_s *packet, size_t size) //192
{
    std::cout<<"Unhandled packet PKT_PausePacket(192)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_ResumePacket_s *packet, size_t size) //193
{
    std::cout<<"Unhandled packet PKT_ResumePacket(193)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SetFrequency_s *packet, size_t size) //194
{
    std::cout<<"Unhandled packet PKT_SetFrequency(194)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SetFadeOut_Push_s *packet, size_t size) //195
{
    std::cout<<"Unhandled packet PKT_SetFadeOut_Push(195)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_SetFadeOut_Pop_s *packet, size_t size) //196
{
    std::cout<<"Unhandled packet PKT_SetFadeOut_Pop(196)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_CreateUnitHighlight_s *packet, size_t size) //197
{
    std::cout<<"Unhandled packet PKT_S2C_CreateUnitHighlight(197)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_RemoveUnitHighlight_s *packet, size_t size) //198
{
    std::cout<<"Unhandled packet PKT_S2C_RemoveUnitHighlight(198)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_OpenTutorialPopup_s *packet, size_t size) //199
{
    std::cout<<"Unhandled packet PKT_S2C_OpenTutorialPopup(199)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_OnTutorialPopupClosed_s *packet, size_t size) //200
{
    std::cout<<"Unhandled packet PKT_C2S_OnTutorialPopupClosed(200)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_OpenAFKWarningMessage_s *packet, size_t size) //201
{
    std::cout<<"Unhandled packet PKT_S2C_OpenAFKWarningMessage(201)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_CloseShop_s *packet, size_t size) //202
{
    std::cout<<"Unhandled packet PKT_S2C_CloseShop(202)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_SetInputLockingFlag_s *packet, size_t size) //203
{
    std::cout<<"Unhandled packet PKT_S2C_SetInputLockingFlag(203)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_OnShopOpened_s *packet, size_t size) //204
{
    std::cout<<"Unhandled packet PKT_C2S_OnShopOpened(204)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ShowObjectiveText_s *packet, size_t size) //206
{
    std::cout<<"Unhandled packet PKT_S2C_ShowObjectiveText(206)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_HideObjectiveText_s *packet, size_t size) //207
{
    std::cout<<"Unhandled packet PKT_S2C_HideObjectiveText(207)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_RefreshObjectiveText_s *packet, size_t size) //208
{
    std::cout<<"Unhandled packet PKT_S2C_RefreshObjectiveText(208)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ShowAuxiliaryText_s *packet, size_t size) //209
{
    std::cout<<"Unhandled packet PKT_S2C_ShowAuxiliaryText(209)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_HideAuxiliaryText_s *packet, size_t size) //210
{
    std::cout<<"Unhandled packet PKT_S2C_HideAuxiliaryText(210)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_RefreshAuxiliaryText_s *packet, size_t size) //211
{
    std::cout<<"Unhandled packet PKT_S2C_RefreshAuxiliaryText(211)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_HighlightHUDElement_s *packet, size_t size) //212
{
    std::cout<<"Unhandled packet PKT_S2C_HighlightHUDElement(212)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_HighlightShopElement_s *packet, size_t size) //213
{
    std::cout<<"Unhandled packet PKT_S2C_HighlightShopElement(213)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_TeamSurrenderVote_s *packet, size_t size) //214
{
    std::cout<<"Unhandled packet PKT_C2S_TeamSurrenderVote(214)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_TeamSurrenderVote_s *packet, size_t size) //215
{
    std::cout<<"Unhandled packet PKT_S2C_TeamSurrenderVote(215)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_TeamSurrenderCountDown_s *packet, size_t size) //216
{
    std::cout<<"Unhandled packet PKT_S2C_TeamSurrenderCountDown(216)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_TeamSurrenderStatus_s *packet, size_t size) //217
{
    std::cout<<"Unhandled packet PKT_S2C_TeamSurrenderStatus(217)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_LineMissileHitList_s *packet, size_t size) //218
{
    std::cout<<"Unhandled packet PKT_S2C_LineMissileHitList(218)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_TutorialAudioEventFinished_s *packet, size_t size) //219
{
    std::cout<<"Unhandled packet PKT_C2S_TutorialAudioEventFinished(219)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_HighlightTitanBarElement_s *packet, size_t size) //220
{
    std::cout<<"Unhandled packet PKT_S2C_HighlightTitanBarElement(220)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ToggleUIHighlight_s *packet, size_t size) //221
{
    std::cout<<"Unhandled packet PKT_S2C_ToggleUIHighlight(221)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_DisplayLocalizedTutorialChatText_s *packet, size_t size) //222
{
    std::cout<<"Unhandled packet PKT_S2C_DisplayLocalizedTutorialChatText(222)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ToolTipVars_s *packet, size_t size) //223
{
    std::cout<<"Unhandled packet PKT_S2C_ToolTipVars(223)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_MuteVolumeCategory_s *packet, size_t size) //224
{
    std::cout<<"Unhandled packet PKT_S2C_MuteVolumeCategory(224)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_OnEventWorld_s *packet, size_t size) //225
{
    std::cout<<"Unhandled packet PKT_S2C_OnEventWorld(225)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_AnimatedBuildingSetCurrentSkin_s *packet, size_t size) //226
{
    std::cout<<"Unhandled packet PKT_S2C_AnimatedBuildingSetCurrentSkin(226)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_SetGreyscaleEnabledWhenDead_s *packet, size_t size) //227
{
    std::cout<<"Unhandled packet PKT_S2C_SetGreyscaleEnabledWhenDead(227)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_DisableHUDForEndOfGame_s *packet, size_t size) //228
{
    std::cout<<"Unhandled packet PKT_S2C_DisableHUDForEndOfGame(228)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_ChangeSlotSpellName_s *packet, size_t size) //229
{
    std::cout<<"Unhandled packet PKT_ChangeSlotSpellName(229)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_SwitchNexusesToOnIdleParticles_s *packet, size_t size) //230
{
    std::cout<<"Unhandled packet PKT_S2C_SwitchNexusesToOnIdleParticles(230)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_FadeMinions_s *packet, size_t size) //231
{
    std::cout<<"Unhandled packet PKT_S2C_FadeMinions(231)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_FadeOutMainSFX_s *packet, size_t size) //232
{
    std::cout<<"Unhandled packet PKT_S2C_FadeOutMainSFX(232)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_HeroStats_s *packet, size_t size) //233
{
    std::cout<<"Unhandled packet PKT_S2C_HeroStats(233)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_SetAnimStates_s *packet, size_t size) //234
{
    std::cout<<"Unhandled packet PKT_S2C_SetAnimStates(234)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_ClientCheatDetectionSignal_s *packet, size_t size) //235
{
    std::cout<<"Unhandled packet PKT_ClientCheatDetectionSignal(235)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_AddDebugCircle_s *packet, size_t size) //236
{
    std::cout<<"Unhandled packet PKT_S2C_AddDebugCircle(236)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_RemoveDebugCircle_s *packet, size_t size) //237
{
    std::cout<<"Unhandled packet PKT_S2C_RemoveDebugCircle(237)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ModifyDebugCircleRadius_s *packet, size_t size) //238
{
    std::cout<<"Unhandled packet PKT_S2C_ModifyDebugCircleRadius(238)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_ModifyDebugCircleColor_s *packet, size_t size) //239
{
    std::cout<<"Unhandled packet PKT_S2C_ModifyDebugCircleColor(239)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_HandleQuestUpdate_s *packet, size_t size) //185
{
    std::cout<<"Unhandled packet PKT_S2C_HandleQuestUpdate(185)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_HandleTipUpdate_s *packet, size_t size) //187
{
    std::cout<<"Unhandled packet PKT_S2C_HandleTipUpdate(187)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_HandleUIHighlight_s *packet, size_t size) //188
{
    std::cout<<"Unhandled packet PKT_S2C_HandleUIHighlight(188)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_OnTipEvent_s *packet, size_t size) //189
{
    std::cout<<"Unhandled packet PKT_C2S_OnTipEvent(189)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_C2S_OnQuestEvent_s *packet, size_t size) //186
{
    std::cout<<"Unhandled packet PKT_C2S_OnQuestEvent(186)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Undefined_s *packet, size_t size) //240
{
    std::cout<<"Unhandled packet PKT_Undefined(240)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_S2C_Neutral_Camp_Empty_s *packet, size_t size) //241
{
    std::cout<<"Unhandled packet PKT_S2C_Neutral_Camp_Empty(241)"<<std::endl;
}

void NetClient::OnPacket(uint32_t cid, PKT_Batched_s *packet, size_t size) //255
{
    std::cout<<"Unhandled packet PKT_Batched(255)"<<std::endl;
}

void NetClient::OnPayload(uint32_t cid, EGP_RequestJoinTeam_s *payload, size_t size) //0x64
{

}

void NetClient::OnPayload(uint32_t cid, EGP_RequestReskin_s *payload, size_t size) //0x65
{

}

void NetClient::OnPayload(uint32_t cid, EGP_RequestRename_s *payload, size_t size) //0x66
{

}

void NetClient::OnPayload(uint32_t cid, EGP_TeamRosterUpdate_s *payload, size_t size) //0x67
{

}

void NetClient::OnPayload(uint32_t cid, EGP_Chat_s *payload, size_t size)
{

}
