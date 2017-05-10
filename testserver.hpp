#ifndef TESTSERVER_H
#define TESTSERVER_H
#include <iostream>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "game/world.h"
#include "obj/gameobjectsall.h"
#include "net/netserver.hpp"
#include "net/packets.hpp"
#include "net/onpacket.h"
#include "net/netpacketstream.hpp"


using namespace std;
using namespace Game;


struct TestServer
        :
        public OnPacket<EGP_RequestJoinTeam_s>,
        public OnPacket<PKT_C2S_Ping_Load_Info_s>,
        public OnPacket<PKT_C2S_Reconnect_s>,
        public OnPacket<PKT_C2S_QueryStatusReq_s>,
        public OnPacket<PKT_SynchVersionC2S_s>,
        public OnPacket<PKT_C2S_CharSelected_s>,
        public OnPacket<PKT_C2S_ClientReady_s>
{
    NetServer *server;
    Game::World world;
    string aChampion = "Bowmaster";
    string aName = "Test";
    std::string basePath = "C:/lol/LoL-1.0.0.673";
    int aSkin = 0;
    int aMap = 1;
    int syncID = 1;
    ObjAiHero *hero;

    TestServer(NetServer* server)
        : server(server),
          OnPacket<EGP_RequestJoinTeam_s>(server),
          OnPacket<PKT_C2S_Ping_Load_Info_s>(server),
          OnPacket<PKT_C2S_Reconnect_s>(server),
          OnPacket<PKT_C2S_QueryStatusReq_s>(server),
          OnPacket<PKT_SynchVersionC2S_s>(server),
          OnPacket<PKT_C2S_CharSelected_s>(server),
          OnPacket<PKT_C2S_ClientReady_s>(server)
    {
    }

    void test()
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

    void Handle(uint32_t cid, const NetPacketStream<EGP_RequestJoinTeam_s>& req)
    {
        EGP_TeamRosterUpdate_s res1;
        res1.orderMembers[0] = cid;
        res1.current_teamsize_order = 1;
        res1.current_teamsize_chaos = 0;
        res1.teamsize_order = 1;
        res1.teamsize_chaos = 0;
        server->sendPacket(cid, res1);

        EGP_RequestReskin_s res3;
        res3.Id_Player = cid;
        res3.skinID = aSkin;
        strcpy(res3.buffer, aChampion.c_str());
        res3.bufferLen = strlen(res3.buffer);
        server->sendPacket(cid, res3);

        EGP_RequestRename_s res2;
        res2.Id_Player = cid;
        res2.skinID = aSkin;
        strcpy(res2.buffer, aName.c_str());
        res2.bufferLen = strlen(res2.buffer);
        server->sendPacket(cid, res2);
    }

    void Handle(uint32_t cid, const NetPacketStream<PKT_C2S_Ping_Load_Info_s> &req)
    {
        PKT_S2C_Ping_Load_Info_s ans;
        ans.info = req.info;
        server->sendPacket(cid, ans);
    }

    void Handle(uint32_t cid, const NetPacketStream<PKT_C2S_Reconnect_s> &req)
    {
        PKT_S2C_Reconnect_s ans;
        ans.cid = cid;
        ans.fromID = cid;
        server->sendPacket(cid, ans);
    }
    void Handle(uint32_t cid, const NetPacketStream<PKT_C2S_QueryStatusReq_s> &req)
    {
        PKT_S2C_QueryStatusAns_s ans;
        ans.res = true;
        server->sendPacket(cid, ans);
    }
    void Handle(uint32_t cid, const NetPacketStream<PKT_SynchVersionC2S_s> &req)
    {
        PKT_SynchVersionS2C_s ans;
        ans.fromID = cid;
        ans.mIsVersionOk = true;
        strcpy(ans.mMapMode, "Automatic");
        ans.mMapToLoad = aMap;
        strcpy(ans.mVersionString , req.mVersionString);
        ans.playerInfo[0].ID = cid;
        ans.playerInfo[0].summonorLevel = 30;
        ans.playerInfo[0].summonorSpell1 = 0;
        ans.playerInfo[0].summonorSpell2 = 0;
        server->sendPacketRaw(cid, (uint8_t*) &ans, sizeof(ans));
    }

    void Handle(uint32_t cid, const NetPacketStream<PKT_C2S_CharSelected_s> &req)
    {
        PKT_S2C_StartSpawn_s ans1;
        ans1.numbBotsChaos = 0;
        ans1.numbBotsOrder = 0;
        server->sendPacketRaw(cid, (uint8_t*)&ans1, sizeof(ans1));

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
        server->sendPacketRaw(cid, (uint8_t*)&ans3, sizeof(ans3));

        PKT_S2C_EndSpawn_s ans2;
        server->sendPacketRaw(cid, (uint8_t*)&ans2, sizeof(ans2));
    }

    void Handle(uint32_t cid, const NetPacketStream<PKT_C2S_ClientReady_s> &req)
    {
        PKT_S2C_StartGame_s ans1;
        server->sendPacketRaw(cid, (uint8_t*)&ans1, sizeof(ans1));
    }
};

#endif // TESTSERVER_H
