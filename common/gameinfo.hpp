#ifndef GAMEINFO_HPP
#define GAMEINFO_HPP

#include <vector>
#include <string>
#include "team_e.hpp"
#include "blowfish.hpp"

struct GameInfo
{
    struct PlayerInfo
    {
        int clientID = 1;
        std::string playerName = "Test";
        std::string heroName = "Annie";
        int skin = 0;
        int team = TEAM_ORDER;
        bool isBot = false;
        std::vector<int> runes = {};
        std::vector<int> masteries = {};
    };
    std::vector<PlayerInfo> players = { PlayerInfo() };
    int mapNumber = 1;
    std::vector<std::string> basePaths = { "./" };
    uint16_t port = 5119;
    uint32_t address = 0;
    BlowFish blowfish = BlowFish((uint8_t*)"GLzvuWtyCfHyGhF2", 16);

    int getHumans()
    {
        int num = 1;
        for(auto p: players)
            if(!p.isBot)
                num++;
        return num;
    }
    std::string getMapName()
    {
        return "Map"+std::to_string(mapNumber);
    }
};


#endif // GAMEINFO_HPP
