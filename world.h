#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include "wink.hpp"
#include "scripts/scriptmap.h"
#include "objectmanager.h"
#include "playermanager.h"

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
    PlayerManager mPlayerManager;
    ObjectManager mObjectManager;
    r3dNavGrid mGrid;
    ScriptMap mScriptMap;
    GGameState_s mGameState = GAMESTATE_PREGAME;
    ServerI *pServer;
    GameInfo *pGameInfo;
    r3dTime mTime;
public:
    World(ServerI* server, GameInfo* gameinfo);
    ObjectManager &objectmanager();
    PlayerManager &playerManager();
    r3dTime &time();
    ServerI *server() const;
    GameInfo *gameinfo() const;
    GGameState_s gameState() const;
    void setGameState(const GGameState_s &gameState);
    void LoadWorld();
    void LoadGame();
    void Play();
    void loop(float delta);
};

#endif // WORLD_H
