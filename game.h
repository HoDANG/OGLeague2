#ifndef GAME_H
#define GAME_H

#include <memory>
#include "wink.hpp"
#include "r3d.hpp"

class World;
class Game
{
private:
    World *pWorld;
public:
    Game();
    void LoadWorld();
    void LoadGame();
    void Play();
    World* world();
};

#endif // GAME_H
