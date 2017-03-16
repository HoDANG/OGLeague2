#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include "../content/manager.h"
#include "../dep/wink.hpp"
#include "map.h"

namespace Game
{
class World
{
private:
    Content::Manager mContent;
    Map mMap = Map(this);
public:
    Content::Manager *content();
    Map* gamemap();
    void init();
};
}

#endif // WORLD_H
