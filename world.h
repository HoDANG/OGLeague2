#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include "wink.hpp"
#include "r3d.hpp"

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
class PlayerManager;
class ObjectManager;
class r3dNavGrid;
class GameInfo;
class ScriptMap;
class World
{
private:
    r3dNavGrid mGrid;
    r3dTime mTime;
    PlayerManager *pPlayerManager;
    ObjectManager *pObjectManager;
    ScriptMap *pScriptMap;
    GGameState_s mGameState;
    ServerI *pServer;
    GameInfo *pGameInfo;
public:
    World(ServerI* server, GameInfo* gameinfo);
    ObjectManager *objectmanager();
    PlayerManager *playerManager();
    r3dTime& time();
    ServerI *server();
    GameInfo *gameinfo();
    GGameState_s gameState();
    void setGameState(GGameState_s gameState);
    void LoadWorld();
    void LoadGame();
    void Play();
    void loop(float delta);
};

#endif // WORLD_H
