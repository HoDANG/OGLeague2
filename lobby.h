#ifndef LOBBY_H
#define LOBBY_H

#include "net/serveri.hpp"
#include "net/onpacket.hpp"
#include "net/packets.hpp"

class ServerI;
class Lobby
    : public OnPacket<EGP_RequestJoinTeam_s>,
      public OnPacket<PKT_C2S_Ping_Load_Info_s>,
      public OnPacket<PKT_C2S_Reconnect_s>,
      public OnPacket<PKT_C2S_QueryStatusReq_s>,
      public OnPacket<PKT_SynchVersionC2S_s>,
      public OnPacket<PKT_C2S_CharSelected_s>,
      public OnPacket<PKT_C2S_ClientReady_s>
{
private:
    ServerI *pServer;
    std::string aChampion;
    std::string aName;
    int aSkin;
    int aMap;
    int syncID;
public:
    Lobby(ServerI *server);

    std::string champion() const;
    std::string name() const;
    int skin();
    int map();
    int syncid();
    void setChampion(const std::string &champion);
    void setName(const std::string &name);
    void setSkin(int &skin);
    void setSyncID(int &syncid);

    void Handle(uint32_t cid, EGP_RequestJoinTeam_s *pkt, size_t size);
    void UpdateRoster();
    void RequestReskin();
    void RequestRename();
    void Handle(uint32_t cid, PKT_C2S_Ping_Load_Info_s *req, size_t size);
    void LoadPingInfo();
    void Handle(uint32_t cid, PKT_C2S_Reconnect_s *req, size_t size);
    void Reconnect();
    void Handle(uint32_t cid, PKT_C2S_QueryStatusReq_s *req, size_t size);
    void QueryStatus();
    void Handle(uint32_t cid, PKT_SynchVersionC2S_s *req, size_t size);
    void SyncVersions();
    void Handle(uint32_t cid, PKT_C2S_CharSelected_s *req, size_t size);
    void StartSpawn();
    void CreateHero();
    void EndSpawn();
    void Handle(uint32_t cid, PKT_C2S_ClientReady_s *req, size_t size);
    void StartGame();
    void EnterVisibility();


};

#endif // LOBBY_H
