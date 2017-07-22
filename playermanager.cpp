#include "playermanager.h"
#include "net/serveri.hpp"
#include "timemanager.h"

void PlayerManager::Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size)
{
    EGP_TeamRosterUpdate_s res1;
    res1.orderMembers[0] = cid;
    res1.current_teamsize_order = 1;
    res1.current_teamsize_chaos = 0;
    res1.teamsize_order = 1;
    res1.teamsize_chaos = 0;
    pServer->sendPacket(cid, res1);

    EGP_RequestReskin_s res3;
    res3.Id_Player = cid;
    res3.skinID = 0;
    strcpy(res3.buffer, "Annie");
    res3.bufferLen = strlen(res3.buffer);
    pServer->sendPacket(cid, res3);

    EGP_RequestRename_s res2;
    res2.Id_Player = cid;
    res2.skinID = 0;
    strcpy(res2.buffer, "Test");
    res2.bufferLen = strlen(res2.buffer);
    pServer->sendPacket(cid, res2);
}

void PlayerManager::Handle(uint32_t cid, PKT_C2S_Ping_Load_Info_s *pkt, size_t size)
{
    PKT_S2C_Ping_Load_Info_s ans;
    ans.info = pkt->info;
    pServer->sendPacket(cid, ans);
}

void PlayerManager::Handle(uint32_t cid, PKT_C2S_Reconnect_s *pkt, size_t size)
{
    PKT_S2C_Reconnect_s ans;
    ans.cid = cid;
    ans.fromID = cid;
    pServer->sendPacket(cid, ans);
}

void PlayerManager::Handle(uint32_t cid, PKT_C2S_QueryStatusReq_s *pkt, size_t size)
{
    PKT_S2C_QueryStatusAns_s ans;
    ans.res = true;
    ans.fromID = cid;
    pServer->sendPacket(cid, ans);
}

void PlayerManager::Handle(uint32_t cid, PKT_C2S_CharSelected_s *pkt, size_t size)
{
    PKT_S2C_StartSpawn_s ans1;
    ans1.numbBotsChaos = 0;
    ans1.numbBotsOrder = 0;
    pServer->sendPacket(cid, ans1);

    PKT_S2C_CreateHero_s ans3;
    ans3.botRank = 0;
    ans3.isBot = 0;
    ans3.teamIsOrder = 1;
    ans3.spawnPosIndex = 1;
    ans3.skinID = 0;
    strcpy(ans3.Skin, "Annie");
    ans3.skillLevel = 1;
    ans3.playerUID = cid;
    ans3.netObjID = 0x40000001;
    ans3.netNodeID = 0x40;
    strcpy(ans3.Name, "Test");
    pServer->sendPacket(cid, ans3);

    PKT_S2C_EndSpawn_s ans2;
    pServer->sendPacket(cid, ans2);
}

void PlayerManager::Handle(uint32_t cid, PKT_SynchVersionC2S_s *pkt, size_t size)
{
    PKT_SynchVersionS2C_s ans;
    ans.fromID = cid;
    ans.mIsVersionOk = true;
    strcpy(ans.mMapMode, pWorld->gameinfo->getMapName().c_str());
    ans.mMapToLoad = pWorld->gameinfo->mapNumber;
    strcpy(ans.mVersionString , pkt->mVersionString);
    ans.playerInfo[0].ID = cid;
    ans.playerInfo[0].summonorLevel = 30;
    ans.playerInfo[0].summonorSpell1 = 0;
    ans.playerInfo[0].summonorSpell2 = 0;
    pServer->sendPacket(cid, ans);
}

void PlayerManager::Handle(uint32_t cid, PKT_C2S_ClientReady_s *pkt, size_t size)
{
    PKT_S2C_StartGame_s ans1;
    pServer->sendPacket(cid, ans1);

    PacketStream<PKT_OnEnterVisiblityClient_s> ans2;
    ans2->fromID = 0x40000001;
    for(int i=0;i<13;i++)
        ans2 < (uint8_t) 0;             //unk
    ans2 < (float)1.0f;                 //some time?
    for(int i=0;i<13;i++)
        ans2 < (uint8_t) 0;              //unk
    ans2 < (uint8_t) 3                  //type
            < (uint32_t) 1                      //syncID
            < (float) 26.0f < (float) 280.0f    //x y
            < (float) 26.0f < (float) 280.0f;   //x y
    pServer->sendStream(cid, ans2);
}

void PlayerManager::UpdateRoster(EGP_TeamRosterUpdate_s update)
{
    pServer->eachClient([update](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, update);
    });
}

void PlayerManager::update(float delta)
{

}
