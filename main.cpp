#include <iostream>
#include <inttypes.h>
#include <string>
#include "net/netserver.h"

using namespace std;

NetServer *server;
string aChampion = "Annie";
string aName = "Test";
int aSkin = 0;
int aMap = 0;

uint32_t syncID = 1;
uint32_t syncID2 = 1;

void pprintPacket(uint8_t *data, size_t size)
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

class BasicClient : public NetClient
{
public:
    void OnConnected(uint32_t cid)
    {
        cout<<"Got client: "<<cid<<endl;
    }

    void OnPacket(uint32_t cid, PKT_C2S_Reconnect_s* req, size_t size)
    {
        PKT_S2C_Reconnect_s ans;
        ans.cid = cid;
        ans.fromID = cid;
        server->sendPacket(cid, (uint8_t*) &ans, sizeof(ans));
    }

    void OnPacket(uint32_t cid, PKT_C2S_QueryStatusReq_s *req, size_t size)
    {
        PKT_S2C_QueryStatusAns_s ans;
        ans.res = true;
        server->sendPacket(cid, (uint8_t*) &ans, sizeof(ans));
    }

    void OnPacket(uint32_t cid, PKT_SynchVersionC2S_s *req, size_t size)
    {
        PKT_SynchVersionS2C_s ans;
        ans.fromID = cid;
        ans.mIsVersionOk = true;
        strcpy(ans.mMapMode, "Automatic");
        ans.mMapToLoad = aMap;
        strcpy(ans.mVersionString , req->mVersionString);
        ans.playerInfo[0].ID = cid;
        ans.playerInfo[0].summonorLevel = 30;
        ans.playerInfo[0].summonorSpell1 = 0x06496EA8;
        ans.playerInfo[0].summonorSpell2 = 0x06364F24;
        server->sendPacket(cid, (uint8_t*) &ans, sizeof(ans));
    }

    void OnPacket(uint32_t cid, PKT_C2S_CharSelected_s *req, size_t size)
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
    }

    void OnPacket(uint32_t cid, PKT_C2S_ClientReady_s *req, size_t size)
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
        < (uint32_t) syncID2++                     //syncID
        < (float) 26.0f < (float) 280.0f    //x y
        < (float) 26.0f < (float) 280.0f;   //x y
        server->sendPacket(cid, ans2.data(), ans2.size());
    }

    //Not needed but you will not get loadin screen :D
    void OnPacket(uint32_t cid, PKT_C2S_Ping_Load_Info_s *req, size_t size)
    {
        PKT_S2C_Ping_Load_Info_s ans;
        ans.info = req->info;
        server->sendPacket(cid, (uint8_t*)&ans, sizeof(ans));
    }

    //Not needed but you will not get loadin screen :D
    void OnPayload(uint32_t cid, EGP_RequestJoinTeam_s *payload, size_t size)
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
    }

    void OnPayload(uint32_t cid, EGP_Chat_s *payload, size_t size)
    {
        server->sendPacket(cid, (uint8_t*) payload, size, CHANNEL_MIDDLE_TIER_CHAT);
        string chat((char*) &payload->buffer[0]);
        stringstream in;
        string key;
        in<<chat;
        in>>key;
        if(key == "s")
        {
            uint32_t mastern;
            uint32_t fieldn;
            string type;
            uint32_t val = 0;
            in>>mastern;
            in>>fieldn;
            in>>type;
            if(type == "f")
                in>>*((float*)&val);
            if(type == "i")
                in>>*((int32_t*)&val);
            if(type == "u")
                in>>val;

            stringstream buff;
            PKT_OnReplication_s rep;
            rep.syncID = syncID++;
            rep.count = 1;
            rep.fromID = 0;
            RepHeader repheader;
            repheader.networkID = 0x40000001;
            repheader.setMaps = ((uint8_t)1 << (mastern-1));;
            buff<rep;
            buff<repheader;
            buff<((uint32_t)1 << (fieldn-1));
            buff<val;
            string tmp = buff.str();
            server->sendPacket(cid, (uint8_t*) tmp.c_str(), tmp.size());
        }else if(key == "m")
        {
            float x1,y1, x2, y2;
            in>>x1>>y1>>x2>>y2;
            DynamicPacket<PKT_OnEnterVisiblityClient_s> ans2;
            ans2.base()->fromID = 0x40000001;
            for(int i=0;i<13;i++)
                ans2 < (uint8_t) 0;
            ans2 < (float)1.0f;
            for(int i=0;i<13;i++)
                ans2 < (uint8_t) 0;
            ans2 < (uint8_t) 3
            < (uint32_t) syncID2++
            < x1 <  y1    //x y
            < x2  < y2;   //x y
            server->sendPacket(cid, ans2.data(), ans2.size());
        }
    }

    void OnPacket(uint32_t cid, PKT_NPC_IssueOrderReq_s *req, size_t size)
    {
        pprintPacket((uint8_t*) req, size);
    }

    //Spam... xD
    void OnPacket(uint32_t cid, PKT_World_SendCamera_Server_s *req, size_t size){}
};



int main(int argc, char ** argv)
{
    enet_initialize();
    auto client = new BasicClient;
    server = new NetServer(client, ENET_HOST_ANY, 5119, "GLzvuWtyCfHyGhF2", 12);
    if(!server->start())
    {
        cout<<"Failed to start server!"<<endl;
        return 0;
    }
    while(true)
    {
        server->host();
    }
    return 0;
}
