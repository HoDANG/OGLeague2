#include <iostream>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "game/world.h"
#include "obj/gameobjectsall.h"
#include "net/netserver.h"
#include "net/packets.hpp"

using namespace std;
using namespace Game;

NetServer *server;
Game::World world;
string aChampion = "Annie";
string aName = "Test";
int aSkin = 0;
int aMap = 1;
int syncID = 0;
int syncID2 = 0;

void testRepLication(int cid)
{
    auto o = world.objectmanager()->getByName("HQ_T1");
    if(o == nullptr)
    {
        cout<<"HQ_T1 not found!"<<endl;
        return;
    }
    auto b = dynamic_cast<ObjHQ*>(o);
    if(b == nullptr)
    {
        cout<<"dynamic_cast<ObjBarracks> faile!"<<endl;
        return;
    }
    b->mHealth.mCurrent.Set(300);


    stringstream buff1;
    PKT_OnEnterVisiblityClient_s ans2;
    ans2.fromID = b->networkID();
    buff1<ans2;
    for(int i=0;i<13;i++)
        buff1 < (uint8_t) 0;             //unk
    buff1 < (float)1.0f;                 //some time?
    for(int i=0;i<13;i++)
        buff1 < (uint8_t) 0;              //unk
    buff1 < (uint8_t) 3                  //type
            < (uint32_t) 1                      //syncID
            < (float) 26.0f < (float) 280.0f    //x y
            < (float) 26.0f < (float) 280.0f;   //x y
    string tmp1 = buff1.str();
    server->sendPacket(cid, (uint8_t*) &ans2, sizeof(ans2));

    stringstream buff;
    PKT_OnReplication_s rep;
    rep.syncID = syncID++;
    rep.count = 1;
    rep.fromID = 0;
    RepHeader repheader;
    repheader.networkID = b->networkID();
    repheader.setMaps = b->mHealth.mCurrent.mType;
    buff<rep;
    buff<repheader;
    buff<((uint32_t)1 << b->mHealth.mCurrent.mIndex);
    buff<b->mHealth.mCurrent.mValue;
    string tmp2 = buff.str();
    //server->sendPacket(cid, (uint8_t*) tmp2.c_str(), tmp2.size());
    //cout<<"Sent rep for: "<<hex<<b->networkID()<<endl;
    //cout<<"Type: "<<b->mHealth.mCurrent.mType<<", index: "<<b->mHealth.mCurrent.mIndex<<endl;
}

void basicServer()
{
    enet_initialize();

    world.content()->setBasePaths({"C:/lol/LoL-1.0.0.673"});
    world.setLevelName("Map1");
    world.LoadWorld();
    server = new NetServer(ENET_HOST_ANY, 5119, "GLzvuWtyCfHyGhF2", 12);

    server->OnConnected.connect([](uint32 cid){
        cout<<"Connected: "<<cid<<endl;
    });

    server->OnDisconnected.connect([](uint32 cid){
        cout<<"Disconnected: "<<cid<<endl;
    });

    server->OnPayload[EGP_Chat].connect([](uint32_t cid, uint8_t* data, size_t size)
    {
        EGP_Chat_s* payload = (EGP_Chat_s*)data;
        string chat((char*) &payload->buffer[0]);
        cout<<"Got chat message: "<<chat<<endl;
        stringstream in;
        string key;
        in<<chat;
        in>>key;
        if(key == "t")
        {
            testRepLication(cid);
        }

        //server->sendPacket(cid, data, size, CHANNEL_MIDDLE_TIER_CHAT);
    });

    server->OnPayload[EGP_RequestJoinTeam].connect([](uint32_t cid, uint8_t* data, size_t size)
    {
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
    });

    server->OnPacket[PKT_C2S_Ping_Load_Info].connect([](uint32_t cid, uint8_t * data, size_t size)
    {
        PKT_C2S_Ping_Load_Info_s *req = (PKT_C2S_Ping_Load_Info_s*)data;
        PKT_S2C_Ping_Load_Info_s ans;
        ans.info = req->info;
        server->sendPacket(cid, (uint8_t*)&ans, sizeof(ans));
    });

    server->OnPacket[PKT_C2S_Reconnect].connect([](uint32_t cid, uint8_t * data, size_t size)
    {
        PKT_S2C_Reconnect_s ans;
        ans.cid = cid;
        ans.fromID = cid;
        server->sendPacket(cid, (uint8_t*) &ans, sizeof(ans));
    });

    server->OnPacket[PKT_C2S_QueryStatusReq].connect([](uint32_t cid, uint8_t * data, size_t size)
    {
        PKT_S2C_QueryStatusAns_s ans;
        ans.res = true;
        server->sendPacket(cid, (uint8_t*) &ans, sizeof(ans));
    });

    server->OnPacket[PKT_SynchVersionC2S].connect([](uint32_t cid, uint8_t * data, size_t size)
    {
        PKT_SynchVersionC2S_s *req = (PKT_SynchVersionC2S_s*) data;
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
    });

    server->OnPacket[PKT_C2S_CharSelected].connect([](uint32_t cid, uint8_t * data, size_t size)
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
        ans3.netObjID = 0x40000001;
        ans3.netNodeID = 0x40;
        strcpy(ans3.Name, aName.c_str());
        server->sendPacket(cid, (uint8_t*)&ans3, sizeof(ans3));

        PKT_S2C_EndSpawn_s ans2;
        server->sendPacket(cid, (uint8_t*)&ans2, sizeof(ans2));
    });

    server->OnPacket[PKT_C2S_ClientReady].connect([](uint32_t cid, uint8_t * data, size_t size)
    {
        PKT_S2C_StartGame_s ans1;
        server->sendPacket(cid, (uint8_t*)&ans1, sizeof(ans1));

        DynamicPacket<PKT_OnEnterVisiblityClient_s> ans2;
        ans2.base()->fromID = 0x40000001;
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
    });


    if(!server->start())
    {
        cout<<"Error starting server!"<<endl;
        return;
    }
LOOP:
    server->host();
    goto LOOP;
}

int main()
{
    basicServer();
    return 0;
}
