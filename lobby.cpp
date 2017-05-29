#include "lobby.h"

using namespace std;

Lobby::Lobby(ServerI *server)
    : OnPacket<EGP_RequestJoinTeam_s>(server),
      OnPacket<PKT_C2S_Ping_Load_Info_s>(server),
      OnPacket<PKT_C2S_Reconnect_s>(server),
      OnPacket<PKT_C2S_QueryStatusReq_s>(server),
      OnPacket<PKT_SynchVersionC2S_s>(server),
      OnPacket<PKT_C2S_CharSelected_s>(server),
      OnPacket<PKT_C2S_ClientReady_s>(server)
{
}

string Lobby::champion() const
{
    aChampion = pServer->pGameInfo->PlayerInfo.heroName;
    return aChampion;
}

string Lobby::name() const
{
    aName = pServer->pGameInfo->PlayerInfo.summonerName;
    return aName;
}

int Lobby::skin()
{
    aSkin = pServer->pGameInfo->PlayerInfo.skin;
    return aSkin;
}

int Lobby::map()
{
    aMap = pServer->pGameInfo->mapNumber;
    return aMap;
}

int Lobby::syncid()
{
    syncID = pServer->pGameInfo->PlayerInfo.syncID;
    return syncID;
}

void Lobby::Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size)
{
    EGP_TeamRosterUpdate_s res1;
    res1.orderMembers[0] = cid;
    res1.current_teamsize_order = 1;
    res1.current_teamsize_chaos = 0;
    res1.teamsize_order = 1;
    res1.teamsize_chaos = 0;
    UpdateRoster();

    EGP_RequestReskin_s res3;
    res3.Id_Player = cid;
    res3.skinID = aSkin;
    strcpy(res3.buffer, aChampion.c_str());
    res3.bufferLen = strlen(res3.buffer);
    RequestReskin();

    EGP_RequestRename_s res2;
    res2.Id_Player = cid;
    res2.skinID = aSkin;
    strcpy(res2.buffer, aName.c_str());
    res2.bufferLen = strlen(res2.buffer);
    RequestRename();
}

void Lobby::UpdateRoster()
{
    EGP_TeamRosterUpdate_s update;
    pServer->eachClient([update](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, update);
    });
}

void Lobby::RequestReskin()
{
    EGP_RequestReskin_s reskin;
    pServer->eachClient([reskin](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, reskin);
    });
}

void Lobby::RequestRename()
{
    EGP_RequestRename_s rename;
    pServer->eachClient([rename](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, rename);
    });
}

void Lobby::Handle(uint32_t cid, PKT_C2S_Ping_Load_Info_s *req, size_t size)
{
    PKT_S2C_Ping_Load_Info_s ans;
    ans.info = req->info;
    LoadPingInfo();
}

void Lobby::LoadPingInfo()
{
    PKT_S2C_Ping_Load_Info_s ping;
    pServer->eachClient([ping](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, ping);
    });
}

void Lobby::Handle(uint32_t cid, PKT_C2S_Reconnect_s *req, size_t size)
{
    PKT_S2C_Reconnect_s ans;
    ans.cid = cid;
    ans.fromID = cid;
    Reconnect();
}

void Lobby::Reconnect()
{
    PKT_S2C_Reconnect_s player;
    pServer->eachClient([player](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, player);
    });
}

void Lobby::Handle(uint32_t cid, PKT_C2S_QueryStatusReq_s *req, size_t size)
{
    cout<<"Got query status ans: "<<endl;
    PKT_S2C_QueryStatusAns_s ans;
    ans.res = true;
    ans.fromID = cid;
    QueryStatus();
}

void Lobby::QueryStatus()
{
    PKT_S2C_QueryStatusAns_s status;
    pServer->eachClient([status](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, status);
    });
}

void Lobby::Handle(uint32_t cid, PKT_SynchVersionC2S_s *req, size_t size)
{
    PKT_SynchVersionS2C_s ans;
    ans.fromID = cid;
    ans.mIsVersionOk = true;
    strcpy(ans.mMapMode, world.levelName().c_str());
    ans.mMapToLoad = aMap;
    strcpy(ans.mVersionString , req->mVersionString);
    ans.playerInfo[0].ID = cid;
    ans.playerInfo[0].summonorLevel = 30;
    ans.playerInfo[0].summonorSpell1 = 0;
    ans.playerInfo[0].summonorSpell2 = 0;
    SyncVersions();
}

void Lobby::SyncVersions()
{
    PKT_SynchVersionS2C_s versions;
    pServer->eachClient([versions](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, versions);
    });
}

void Lobby::Handle(uint32_t cid, PKT_C2S_CharSelected_s *req, size_t size)
{
    PKT_S2C_StartSpawn_s ans1;
    ans1.numbBotsChaos = 0;
    ans1.numbBotsOrder = 0;
    StartSpawn();

    PKT_S2C_CreateHero_s ans3;
    ans3.botRank = 0;
    ans3.isBot = 0;
    ans3.teamIsOrder = 1;
    ans3.spawnPosIndex = 1;
    ans3.skinID = aSkin;
    strcpy(ans3.Skin, aChampion.c_str());
    ans3.skillLevel = 1;
    ans3.playerUID = cid;
    ans3.netObjID = ans3->networkID();
    ans3.netNodeID = 0x40;
    strcpy(ans3.Name, aName.c_str());
    CreateHero();

    PKT_S2C_EndSpawn_s ans2;
    EndSpawn();
}

void Lobby::StartSpawn()
{
    PKT_S2C_StartSpawn_s start;
    pServer->eachClient([start](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, start);
    });
}

void Lobby::CreateHero()
{
    PKT_S2C_CreateHero_s hero;
    pServer->eachClient([hero](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, hero);
    });
}

void Lobby::EndSpawn()
{
    PKT_S2C_EndSpawn_s end;
    pServer->eachClient([end](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, end);
    });
}

void Lobby::Handle(uint32_t cid, PKT_C2S_ClientReady_s *req, size_t size)
{
    PKT_S2C_StartGame_s ans1;
    pServer->sendPacket(cid, ans1);

    PacketStream<PKT_OnEnterVisiblityClient_s> ans2;
    ans2->fromID = ans2->networkID();
    for(int i=0;i<13;i++)
        ans2 < (uint8_t) 0;             //unk
    ans2 < (float)1.0f;                 //some time?
    for(int i=0;i<13;i++)
        ans2 < (uint8_t) 0;              //unk
    ans2 < (uint8_t) 3                  //type
            < (uint32_t) 1                      //syncID
            < (float) 26.0f < (float) 280.0f    //x y
            < (float) 26.0f < (float) 280.0f;   //x y
    EnterVisibility();
}

void Lobby::StartGame()
{
    PKT_S2C_StartGame_s startgame;
    pServer->eachClient([startgame](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, startgame);
    });
}

void Lobby::EnterVisibility()
{
    PacketStream<PKT_OnEnterVisiblityClient_s> visibility;
    pServer->eachClient([visibility](uint32_t cid, ServerI *server)
    {
        server->sendStream(cid, visibility);
    });
}
