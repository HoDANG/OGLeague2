#include "lobby.h"
#include "world.h"

Lobby::Lobby(ServerI *server, GameInfo *gameinfo)
    : pServer(server),
      pGameInfo(gameinfo),
      OnPacket<EGP_RequestJoinTeam_s>(server),
      OnPacket<PKT_SynchVersionC2S_s>(server),
      OnPacket<PKT_C2S_Ping_Load_Info_s>(server),
      OnPacket<PKT_C2S_QueryStatusReq_s>(server),
      OnPacket<PKT_C2S_CharSelected_s>(server)
{

}

void Lobby::Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size)
{
    EGP_TeamRosterUpdate_s res1;
    res1.orderMembers[0] = cid;
    res1.current_teamsize_order = 1;
    res1.current_teamsize_chaos = 0;
    res1.teamsize_order = 1;
    res1.teamsize_chaos = 0;
    UpdateRoster(res1);

    EGP_RequestReskin_s res3;
    res3.Id_Player = cid;
    res3.skinID = pGameInfo->players[0].skin;
    strcpy(res3.buffer, pGameInfo->players[0].heroName.c_str());
    res3.bufferLen = strlen(res3.buffer);
    RequestReskin(res3);

    EGP_RequestRename_s res2;
    res2.Id_Player = cid;
    res2.skinID = pGameInfo->players[0].skin;
    strcpy(res2.buffer, pGameInfo->players[0].playerName.c_str());
    res2.bufferLen = strlen(res2.buffer);
    RequestRename(res2);
}

void Lobby::Handle(uint32_t cid, PKT_C2S_Ping_Load_Info_s *pkt, size_t size)
{
    PKT_S2C_Ping_Load_Info_s ans;
    ans.info = pkt->info;
    LoadPingInfo(ans);
}

void Lobby::Handle(uint32_t cid, PKT_C2S_QueryStatusReq_s *pkt, size_t size)
{
    std::cout<<"Got query status ans: "<<std::endl;
    PKT_S2C_QueryStatusAns_s ans;
    ans.res = true;
    ans.fromID = cid;
    QueryStatus(ans);
}

void Lobby::Handle(uint32_t cid, PKT_C2S_CharSelected_s *pkt, size_t size)
{
    PKT_S2C_StartSpawn_s ans1;
    ans1.numbBotsChaos = 0;
    ans1.numbBotsOrder = 0;
    StartSpawn(ans1);

    PKT_S2C_CreateHero_s ans3;
    ans3.botRank = 0;
    ans3.isBot = 0;
    ans3.teamIsOrder = 1;
    ans3.spawnPosIndex = 1;
    ans3.skinID = pGameInfo->players[0].skin;
    strcpy(ans3.Skin, pGameInfo->players[0].heroName.c_str());
    ans3.skillLevel = 1;
    ans3.playerUID = cid;
    ans3.netObjID = pGameInfo->players[0].clientID;
    ans3.netNodeID = 0x40;
    strcpy(ans3.Name, pGameInfo->players[0].playerName.c_str());
    CreateHero(ans3);

    PKT_S2C_EndSpawn_s ans2;
    EndSpawn(ans2);
}

void Lobby::Handle(uint32_t cid, PKT_SynchVersionC2S_s *pkt, size_t size)
{
    PKT_SynchVersionS2C_s ans;
    ans.fromID = cid;
    ans.mIsVersionOk = true;
    strcpy(ans.mMapMode, pGameInfo->getMapName().c_str());
    ans.mMapToLoad = pGameInfo->mapNumber;
    strcpy(ans.mVersionString , pkt->mVersionString);
    ans.playerInfo[0].ID = cid;
    ans.playerInfo[0].summonorLevel = 30;
    ans.playerInfo[0].summonorSpell1 = 0;
    ans.playerInfo[0].summonorSpell2 = 0;
    SyncVersions(ans);
}



void Lobby::UpdateRoster(EGP_TeamRosterUpdate_s update)
{
    pServer->eachClient([update](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, update);
    });
}

void Lobby::RequestReskin(EGP_RequestReskin_s reskin)
{
    pServer->eachClient([reskin](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, reskin);
    });
}

void Lobby::RequestRename(EGP_RequestRename_s rename)
{
    pServer->eachClient([rename](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, rename);
    });
}

void Lobby::LoadPingInfo(PKT_S2C_Ping_Load_Info_s ping)
{
    pServer->eachClient([ping](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, ping);
    });
}

void Lobby::QueryStatus(PKT_S2C_QueryStatusAns_s status)
{
    pServer->eachClient([status](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, status);
    });
}

void Lobby::StartSpawn(PKT_S2C_StartSpawn_s start)
{
    pServer->eachClient([start](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, start);
    });
}

void Lobby::CreateHero(PKT_S2C_CreateHero_s hero)
{
    pServer->eachClient([hero](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, hero);
    });
}

void Lobby::EndSpawn(PKT_S2C_EndSpawn_s end)
{
    pServer->eachClient([end](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, end);
    });
}

void Lobby::SyncVersions(PKT_SynchVersionS2C_s versions)
{
    pServer->eachClient([versions](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, versions);
    });
}

void Lobby::update()
{

}
