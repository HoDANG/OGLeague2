#include "testserver.h"


TestServer::TestServer(NetServer *server)
    : server(server),
      OnPayload<EGP_RequestJoinTeam, EGP_RequestJoinTeam_s>(server),
      OnPacket<PKT_C2S_Ping_Load_Info, PKT_C2S_Ping_Load_Info_s>(server),
      OnPacket<PKT_C2S_Reconnect, PKT_C2S_Reconnect_s>(server),
      OnPacket<PKT_C2S_QueryStatusReq, PKT_C2S_QueryStatusReq_s>(server),
      OnPacket<PKT_SynchVersionC2S, PKT_SynchVersionC2S_s>(server),
      OnPacket<PKT_C2S_CharSelected, PKT_C2S_CharSelected_s>(server),
      OnPacket<PKT_C2S_ClientReady, PKT_C2S_ClientReady_s>(server),
      OnPayload<EGP_Chat, EGP_Chat_s>(server)
{
}

void TestServer::test()
{
    world.content()->setBasePaths({basePath});
    world.setLevelName("Map"+to_string(aMap));
    //world.LoadWorld();
    hero = dynamic_cast<ObjAiHero*>(world.CreateGameObject("ObjAiHero", "Annie", { 26.0f ,100.0f, 280.0f }, 64, 0));
    hero->assignID();
    if(!server->start())
    {
        cout<<"Error starting server!"<<endl;
        return;
    }
    //infinite loop
    for(;;)
    {
        server->host();
    }
}

void TestServer::Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size){
    EGP_TeamRosterUpdate_s res1;
    res1.orderMembers[0] = cid;
    res1.current_teamsize_order = 1;
    res1.current_teamsize_chaos = 0;
    res1.teamsize_order = 1;
    res1.teamsize_chaos = 0;
    server->sendPacket(cid, (uint8_t*) &res1, sizeof(res1), CHANNEL_MIDDLE_TIER_ROSTER);

    EGP_RequestReskin_s res3;
    res3.Id_Player = cid;
    res3.skinID = aSkin;
    strcpy(res3.buffer, aChampion.c_str());
    res3.bufferLen = strlen(res3.buffer);
    server->sendPacket(cid, (uint8_t*) &res3, sizeof(res3), CHANNEL_MIDDLE_TIER_ROSTER);

    EGP_RequestRename_s res2;
    res2.Id_Player = cid;
    res2.skinID = aSkin;
    strcpy(res2.buffer, aName.c_str());
    res2.bufferLen = strlen(res2.buffer);
    server->sendPacket(cid, (uint8_t*) &res2, sizeof(res2), CHANNEL_MIDDLE_TIER_ROSTER);
}

void TestServer::Handle(uint32_t cid, PKT_C2S_Ping_Load_Info_s *req, size_t size)
{
    PKT_S2C_Ping_Load_Info_s ans;
    ans.info = req->info;
    server->sendPacket(cid, (uint8_t*)&ans, sizeof(ans));
}

void TestServer::Handle(uint32_t cid, PKT_C2S_Reconnect_s *pkt, size_t size)
{
    PKT_S2C_Reconnect_s ans;
    ans.cid = cid;
    ans.fromID = cid;
    server->sendPacket(cid, (uint8_t*) &ans, sizeof(ans));
}

void TestServer::Handle(uint32_t cid, PKT_SynchVersionC2S_s *req, size_t size)
{
    PKT_SynchVersionS2C_s ans;
    ans.fromID = cid;
    ans.mIsVersionOk = true;
    strcpy(ans.mMapMode, "Automatic");
    ans.mMapToLoad = aMap;
    strcpy(ans.mVersionString , req->mVersionString);
    ans.playerInfo[0].ID = cid;
    ans.playerInfo[0].summonorLevel = 30;
    ans.playerInfo[0].summonorSpell1 = 0;
    ans.playerInfo[0].summonorSpell2 = 0;
    server->sendPacket(cid, (uint8_t*) &ans, sizeof(ans));
}

void TestServer::Handle(uint32_t cid, PKT_C2S_CharSelected_s *req, size_t size)
{
    PKT_S2C_StartSpawn_s ans1;
    ans1.numbBotsChaos = 0;
    ans1.numbBotsOrder = 0;
    server->sendPacket(cid, (uint8_t*)&ans1, sizeof(ans1));

    PKT_S2C_CreateHero_s ans3;
    ans3.botRank = 0;
    ans3.isBot = 0;
    ans3.teamIsOrder = 1;
    ans3.spawnPosIndex = 1;
    ans3.skinID = aSkin;
    strcpy(ans3.Skin, aChampion.c_str());
    ans3.skillLevel = 1;
    ans3.playerUID = cid;
    ans3.netObjID = hero->networkID();
    ans3.netNodeID = 0x40;
    strcpy(ans3.Name, aName.c_str());
    server->sendPacket(cid, (uint8_t*)&ans3, sizeof(ans3));

    PKT_S2C_EndSpawn_s ans2;
    server->sendPacket(cid, (uint8_t*)&ans2, sizeof(ans2));
}

void TestServer::Handle(uint32_t cid, PKT_C2S_ClientReady_s *req, size_t size)
{
    PKT_S2C_StartGame_s ans1;
    server->sendPacket(cid, (uint8_t*)&ans1, sizeof(ans1));

    DynamicPacket<PKT_OnEnterVisiblityClient_s> ans2;
    ans2.base()->fromID = hero->networkID();
    for(int i=0;i<13;i++)
        ans2 < (uint8_t) 0;             //unk
    ans2 < (float)1.0f;                 //some time?
    for(int i=0;i<13;i++)
        ans2 < (uint8_t) 0;              //unk
    ans2 < (uint8_t) 3                  //type
            < (uint32_t) 1                      //syncID
            < (float) 26.0f < (float) 280.0f    //x y
            < (float) 26.0f < (float) 280.0f;   //x y
    server->sendPacket(cid, ans2.data(), ans2.size());
}

void TestServer::Handle(uint32_t cid, EGP_Chat_s *pkt, size_t size)
{
    string chat((char*) &pkt->buffer[0]);
    cout<<"Got chat message: "<<chat<<endl;
    stringstream in;
    string key;
    in<<chat;
    in>>key;
    server->sendPacket(cid, (uint8_t*) pkt, size, CHANNEL_MIDDLE_TIER_CHAT);
    if(key == "t")
    {
        EGP_Chat_s message;
        strcpy(message.buffer, "Yolo!");
        message.bufferLen = 5;
        message.cid = cid;
        server->sendPacket(cid, (uint8_t*) &message, size, CHANNEL_MIDDLE_TIER_CHAT);
    }
    if(key == "stat")
    {
        string statName, statValue;
        in>>statName;
        in>>statValue;
        auto rep = hero->mReplicationManager.find(statName);
        if(rep != nullptr)
        {
            rep->Set(statValue);
            stringstream buff;
            PKT_OnReplication_s onRep;
            onRep.syncID = syncID++;
            onRep.count = 1;
            onRep.fromID = 0;
            RepHeader header;
            header.networkID  = hero->networkID();
            header.setMaps = rep->Type();
            buff < onRep;
            buff < header;
            buff < ((uint32_t) 1 << rep->Index());
            buff < rep->Value32();
            string tmp2 = buff.str();
            server->sendPacket(cid, (uint8_t*) tmp2.c_str(), tmp2.size());
            cout<<"Stat "<<statName<<" is now "<<rep->Value()<<endl;
        }
    }
}

void TestServer::Handle(uint32_t cid, PKT_C2S_QueryStatusReq_s *req, size_t size)
{
    PKT_S2C_QueryStatusAns_s ans;
    ans.res = true;
    server->sendPacket(cid, (uint8_t*) &ans, sizeof(ans));
}
