#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <string>
#include <vector>

struct GameInfo
{
    struct PlayerInfo
    {
       std::string summonerName;
       std::string heroName;
       int skin;
       int team;
       bool isBot;
       int syncID;
       std::vector<int> runes;
    };

    std::vector<PlayerInfo> playerInfoArray;
    int mapNumber = 1;
    std::string mLevelName = "Map1";
    std::string basePath = "C:/lol/LoL-1.0.0.673";
    uint16_t port = 5119;
    std::string key = "GLzvuWtyCfHyGhF2";
    uint32_t maxclients = 12;


}


#endif // GAMEINFO_H
