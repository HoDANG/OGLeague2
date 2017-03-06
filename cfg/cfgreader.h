#ifndef CFGREADER_H
#define CFGREADER_H

#include <map>
#include <string>
#include <array>
#include <sstream>

class Config
{
private:
    inline uint32_t hash(std::string text)
    {
        uint32_t hash = 0;
        for(char c : text)
        {
            hash = tolower(c) + 65599 * hash;
        }
        return hash;
    }
    inline uint32_t hash(std::string section, std::string name)
    {
        return hash(section+"*"+name);
    }

    std::map<uint32_t, std::string> mStrings;

public:
    void readAscii(std::string fileName);
    void readBinary(std::string fileName);

    inline std::string getString(std::string section, std::string name, std::string def = "")
    {
        auto iter = mStrings.find(hash(section, name));
        if(iter == mStrings.end())
            return def;
        return iter->second;
    }

    template<typename T>
    inline T getNum(std::string section, std::string name, T res = T())
    {
        auto iter = mStrings.find(hash(section, name));
        if(iter == mStrings.end())
            return res;
        std::stringstream ss(iter->second);
        ss>>res;
        return res;
    }

    template<typename T, size_t N>
    inline std::array<T, N> getArray(std::string section, std::string name,
                    std::array<T, N> res = std::array<T, N>())
    {
        auto iter = mStrings.find(hash(section, name));
        if(iter == mStrings.end())
            return res;
        std::stringstream ss(iter->second);
        for(size_t i = 0; i<N; i++ )
        {
            ss>>res[i];
        }
        return res;
    }

    inline bool getBool(std::string section, std::string name, bool res = false)
    {
        auto iter = mStrings.find(hash(section, name));
        if(iter == mStrings.end())
            return res;
        if(iter->second == "true")
            return true;
        if(iter->second == "false")
            return false;
        bool num;
        std::stringstream ss(iter->second);
        ss>>num;
        return num != 0;
    }

    std::map<uint32_t, std::string> getStrings() const;
};

#endif // CFGREADER_H
