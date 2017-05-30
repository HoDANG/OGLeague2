#ifndef LOBBY_H
#define LOBBY_H

#include "net/serveri.hpp"
#include "net/onpacket.hpp"
#include "net/packets.hpp"

class Lobby :
        public OnPacket<EGP_RequestJoinTeam_s>
{
private:
    ServerI *pServer;
    GameInfo *pGameInfo;
public:
    Lobby(ServerI *server, GameInfo* gameinfo) :
        OnPacket<EGP_RequestJoinTeam_s>(server)
    {
    }
    void Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size);
    void UpdateRoster();
};

#endif // LOBBY_H
