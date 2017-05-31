#include "lobby.h"

void Lobby::Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size)
{

}

void Lobby::Handle(uint32_t cid, PKT_C2S_Ping_Load_Info_s *pkt, size_t size)
{

}

void Lobby::Handle(uint32_t cid, PKT_C2S_QueryStatusReq_s *pkt, size_t size)
{

}

void Lobby::Handle(uint32_t cid, PKT_C2S_CharSelected_s *pkt, size_t size)
{

}

void Lobby::Handle(uint32_t cid, PKT_SynchVersionC2S_s *pkt, size_t size)
{

}



void Lobby::UpdateRoster(EGP_TeamRosterUpdate_s update)
{
    pServer->eachClient([update](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, update);
    });
}

void Lobby::update()
{

}
