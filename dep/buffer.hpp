#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <sstream>
#include <vector>

template <typename T, class... StreamArgs>
inline std::basic_ostream<StreamArgs...> &
operator < (std::basic_ostream<StreamArgs...> & out, T const & data)
{
    return out.write(reinterpret_cast<char const *>(&data), sizeof(T));
}

template <typename T, class... StreamArgs>
inline std::basic_ostream<StreamArgs...> &
operator < (std::basic_ostream<StreamArgs...> & out, std::vector<T> const & data)
{
    return out.write(reinterpret_cast<char const *>(&data[0]), data.size());
}


template <typename T, class... StreamArgs>
inline std::basic_istream<StreamArgs...> &
operator > (std::basic_istream<StreamArgs...> & out, T & data)
{
    return out.read(reinterpret_cast<char *>(&data), sizeof(T));
}

template <typename T, class... StreamArgs>
inline std::basic_istream<StreamArgs...> &
operator > (std::basic_istream<StreamArgs...> & out, std::vector<T> & data)
{
    return out.read(reinterpret_cast<char *>(&data[0]), data.size());
}

#endif // BUFFER_HPP
