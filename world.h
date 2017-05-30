#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include "dep/wink.hpp"
#include "dep/r3d.hpp"
#include "scripts/scriptmap.h"
#include "objectmanager.h"
#include "lobby.h"
#include "net/netserver.hpp"


enum GGameState_s : int
{
  GAMESTATE_PREGAME = 0x0,
  GAMESTATE_SPAWN = 0x1,
  GAMESTATE_GAMELOOP = 0x2,
  GAMESTATE_ENDGAME = 0x3,
  GAMESTATE_PRE_EXIT = 0x4,
  GAMESTATE_EXIT = 0x5
};

class ServerI;
class World
{
private:
    ObjectManager mObjectManager;
    Lobby mLobby;
    r3dNavGrid mGrid;
    std::string mLevelName = mLobby.pGameInfo->mLevelName;
    ScriptMap mScriptMap;
    GGameState_s mGameState = GAMESTATE_PREGAME;
    ServerI *pServer;
public:
    World(ServerI* server);
    Lobby &lobby();
    ObjectManager &objectmanager();
    void init();
    void LoadWorld();
    void LoadGame();
    void UpdateObjects();
    void Play();
    GGameState_s gameState() const;
    void setGameState(const GGameState_s &gameState);
    ServerI *server() const;
    void loop();
};

#endif // WORLD_H
