#ifndef NETPACKET_HPP
#define NETPACKET_HPP

#include "../dep/buffer.hpp"

template<class PKT>
class NetPacketStream :
        public PKT
{
private:
    std::vector<uint8_t> mData;
    size_t mWritePos = 0;
    size_t mReadPos = 0;
public:
    NetPacketStream()
    {
    }
    NetPacketStream(PKT pkt)
    {
        std::copy((uint8_t*) &pkt, (uint8_t*)&pkt+sizeof(PKT), (uint8_t*)this);
    }

    NetPacketStream(std::vector<uint8_t> data)
    {
        std::copy(&data[0], &data[std::min(sizeof(PKT), data.size())], (uint8_t*)this);
        if(data.size() > sizeof(PKT))
            std::copy(&data[sizeof(PKT)], &data[data.size()], mData.begin());
    }

    NetPacketStream& write(uint8_t* data, size_t size)
    {
        std::copy(data, data+size, mData.begin()+mWritePos);
    }

    NetPacketStream& read(uint8_t* data, size_t size)
    {

    }
};

template <typename T, class... StreamArgs>
inline NetPacketStream<StreamArgs...> &
operator << (NetPacketStream<StreamArgs...> & out, T const & data)
{

}

template <typename T, class... StreamArgs>
inline NetPacketStream<StreamArgs...> &
operator << (NetPacketStream<StreamArgs...> & out, std::vector<T> const & data)
{

}


template <typename T, class... StreamArgs>
inline NetPacketStream<StreamArgs...> &
operator >> (NetPacketStream<StreamArgs...> & out, T & data)
{

}

template <typename T, class... StreamArgs>
inline NetPacketStream<StreamArgs...> &
operator >> (NetPacketStream<StreamArgs...> & out, std::vector<T> & data)
{

}



#endif // NETPACKET_HPP
