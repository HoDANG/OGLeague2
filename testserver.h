#ifndef TESTSERVER_H
#define TESTSERVER_H
#include <iostream>
#include <inttypes.h>
#include <string>
#include <sstream>
#include "game/world.h"
#include "obj/gameobjectsall.h"
#include "net/netserver.h"
#include "net/packets.hpp"
#include "net/onpacket.h"


using namespace std;
using namespace Game;


struct TestServer:
        public OnPayload<EGP_RequestJoinTeam, EGP_RequestJoinTeam_s> ,
        public OnPacket<PKT_C2S_Ping_Load_Info, PKT_C2S_Ping_Load_Info_s>,
        public OnPacket<PKT_C2S_Reconnect, PKT_C2S_Reconnect_s>,
        public OnPacket<PKT_C2S_QueryStatusReq, PKT_C2S_QueryStatusReq_s>,
        public OnPacket<PKT_SynchVersionC2S, PKT_SynchVersionC2S_s>,
        public OnPacket<PKT_C2S_CharSelected, PKT_C2S_CharSelected_s>,
        public OnPacket<PKT_C2S_ClientReady, PKT_C2S_ClientReady_s>,
        public OnPayload<EGP_Chat, EGP_Chat_s>

{
    NetServer *server;
    Game::World world;
    string aChampion = "Bowmaster";
    string aName = "Mitric";
    std::string basePath = "C:/lol/LoL-1.0.0.673";
    int aSkin = 0;
    int aMap = 1;
    int syncID = 1;
    ObjAiHero *hero;

    TestServer(NetServer* server);


    void test();

    void Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size);

    void Handle(uint32_t cid, PKT_C2S_Ping_Load_Info_s *req, size_t size);

    void Handle(uint32_t cid, PKT_C2S_Reconnect_s* pkt, size_t size);

    void Handle(uint32_t cid, PKT_C2S_QueryStatusReq_s *req, size_t size);

    void Handle(uint32_t cid, PKT_SynchVersionC2S_s* req, size_t size);

    void Handle(uint32_t cid, PKT_C2S_CharSelected_s* req, size_t size);

    void Handle(uint32_t cid, PKT_C2S_ClientReady_s* req, size_t size);

    void Handle(uint32_t cid, EGP_Chat_s *pkt, size_t size);
};

#endif // TESTSERVER_H
