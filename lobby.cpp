#include "lobby.h"

void Lobby::Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size)
{

}

void Lobby::UpdateRoster()
{
    EGP_TeamRosterUpdate_s update;
    pServer->eachClient([update](uint32_t cid, ServerI *server)
    {
        server->sendPacket(cid, update);
    });
}
