#ifndef LOBBY_H
#define LOBBY_H

#include "net/serveri.hpp"
#include "net/onpacket.hpp"
#include "net/packets.hpp"

class Lobby :
        public OnPacket<EGP_RequestJoinTeam_s>,
        public OnPacket<PKT_SynchVersionC2S_s>,
        public OnPacket<PKT_C2S_Ping_Load_Info_s>,
        public OnPacket<PKT_C2S_QueryStatusReq_s>,
        public OnPacket<PKT_C2S_CharSelected_s>
{
private:
    ServerI *pServer;
    GameInfo *pGameInfo;
public:
    enum LobbyState
    {
        LOBBY_WAITING,
        LOBBY_RUNNING,
        LOBBY_DONE
    };
    Lobby(ServerI *server, GameInfo *gameinfo);

    void Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_SynchVersionC2S_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_C2S_Ping_Load_Info_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_C2S_QueryStatusReq_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_C2S_CharSelected_s *pkt, size_t size);
    void UpdateRoster(EGP_TeamRosterUpdate_s update);
    void RequestReskin(EGP_RequestReskin_s reskin);
    void RequestRename(EGP_RequestRename_s rename);
    void LoadPingInfo(PKT_S2C_Ping_Load_Info_s ping);
    void QueryStatus(PKT_S2C_QueryStatusAns_s status);
    void StartSpawn(PKT_S2C_StartSpawn_s start);
    void CreateHero(PKT_S2C_CreateHero_s hero);
    void EndSpawn(PKT_S2C_EndSpawn_s end);
    void SyncVersions(PKT_SynchVersionS2C_s versions);
    void update();
};

#endif // LOBBY_H
