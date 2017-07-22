#ifndef IWORLD_H
#define IWORLD_H

enum GGameState_s : int
{
  GAMESTATE_PREGAME = 0x0,
  GAMESTATE_SPAWN = 0x1,
  GAMESTATE_GAMELOOP = 0x2,
  GAMESTATE_ENDGAME = 0x3,
  GAMESTATE_PRE_EXIT = 0x4,
  GAMESTATE_EXIT = 0x5
};

class NavigationManager;
class TimeManager;
class ServerI;
class PlayerManager;
class ObjectManager;
class r3dNavGrid;
class GameInfo;
class ScriptMap;
class r3dTime;
class LocationsManager;
class VisibilityManager;
class ItemManager;
class ScriptManager;
class SpellManager;
struct World
{
    TimeManager *timemanager;
    NavigationManager *navigationmanager;
    PlayerManager *playermanager;
    ObjectManager *objectmanager;
    LocationsManager *locationsmanager;
    VisibilityManager *visibilitymanager;
    ScriptMap *scriptmap;
    ServerI *server;
    GameInfo *gameinfo;
    ItemManager *itemmanager;
    ScriptManager *scriptmanager;
    SpellManager *spellmanager;
    GGameState_s gamestate = GAMESTATE_PREGAME;
    World();
    ~World();
};

#endif // IWORLD_H
