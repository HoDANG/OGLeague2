#ifndef NETPACKETSTREAM_H
#define NETPACKETSTREAM_H

#include "../dep/buffer.hpp"

template<class PKT>
class PacketStream
        : public std::stringstream
{
private:
    PKT mBase;
public:
    PacketStream()
    {
    }
    PacketStream(PKT* pkt, size_t size)
    {
       std::copy((uint8_t*)pkt,(uint8_t*)pkt+std::min(size, sizeof(PKT)), (uint8_t*)&mBase);
       if(size > sizeof(PKT))
          write((const char*)pkt + sizeof(PKT), size - sizeof(PKT));
    }

    PKT* operator->()
    {
        return &mBase;
    }

    std::vector<uint8_t> data() const
    {
        auto tmp = str();
        std::vector<uint8_t> ret((uint8_t*)&mBase, (uint8_t*)&mBase+sizeof(PKT));
        ret.insert(ret.end(),(uint8_t*)&tmp[0], (uint8_t*)&tmp[tmp.size()]);
        return ret;
    }
};

#endif // NETPACKETSTREAM_H
