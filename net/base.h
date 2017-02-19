#ifndef PKT_BASE_H
#define PKT_BASE_H

#include <string>
#include <stdint.h>
#include <vector>
#include <sstream>
#include "../dep/enet.hpp"
#include "../dep/buffer.hpp"
#include "common/connectioninfo.h"
#include "common/playerliteinfo.h"
#include "pkt_enums.h"

struct PKT_KeyCheck_s
{
    uint8_t cmd;
    uint32_t clientID;
    uint64_t playerID;
    uint64_t checkId;
};

//CHANNEL_MIDDLE_TIER_ROSTER
template<uint8_t ID>
struct DefaultPayload
{
    uint8_t type = ID;
};

//CHANNEL_GENERIC_APP_BROADCAST
template<uint8_t ID>
struct DefaultPacket
{
    uint8_t eventID = ID;
    uint32_t fromID;
};

template<class FROM>
class DynamicPacket : public std::stringstream
{
public:
    struct hack : public std::basic_streambuf<char>
    {
        char *eback()
        {
            return std::basic_streambuf<char>::eback();
        }
    };

    DynamicPacket()
    {
        *this < FROM();
    }
    DynamicPacket(const FROM &from)
    {
        *this < from;
    }
    DynamicPacket(FROM *from)
    {
        *this < *from;
    }
    size_t size()
    {
        return str().size();
    }
    uint8_t* data()
    {
        return (uint8_t*) ((hack*)rdbuf())->eback();
    }
    FROM* base()
    {
        return (FROM*) data();
    }
};


#endif // PKT_BASE_H
