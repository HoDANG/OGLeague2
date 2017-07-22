#ifndef LOBBY_H
#define LOBBY_H

#include "net/onpacket.hpp"
#include "packets/packets.hpp"

class ServerI;
class PlayerManager :
        public OnPacket<EGP_RequestJoinTeam_s>,
        public OnPacket<PKT_SynchVersionC2S_s>,
        public OnPacket<PKT_C2S_Ping_Load_Info_s>,
        public OnPacket<PKT_C2S_Reconnect_s>,
        public OnPacket<PKT_C2S_QueryStatusReq_s>,
        public OnPacket<PKT_C2S_CharSelected_s>,
        public OnPacket<PKT_C2S_ClientReady_s>
{
private:
    ServerI *pServer;
    GameInfo *pGameInfo;
public:
    PlayerManager(ServerI *server, GameInfo* gameinfo) :
        OnPacket<EGP_RequestJoinTeam_s>(server),
        OnPacket<PKT_SynchVersionC2S_s>(server),
        OnPacket<PKT_C2S_Ping_Load_Info_s>(server),
        OnPacket<PKT_C2S_Reconnect_s>(server),
        OnPacket<PKT_C2S_QueryStatusReq_s>(server),
        OnPacket<PKT_C2S_CharSelected_s>(server),
        OnPacket<PKT_C2S_ClientReady_s>(server)
    {
    }
    void Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_SynchVersionC2S_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_C2S_Ping_Load_Info_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_C2S_Reconnect_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_C2S_QueryStatusReq_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_C2S_CharSelected_s *pkt, size_t size);
    void Handle(uint32_t cid, PKT_C2S_ClientReady_s *pkt, size_t size);
    void UpdateRoster(EGP_TeamRosterUpdate_s update);
    void update(float delta);
};

#endif // LOBBY_H
