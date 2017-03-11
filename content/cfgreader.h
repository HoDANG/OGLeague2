#ifndef CFGREADER_H
#define CFGREADER_H

#include <map>
#include <string>
#include <array>
#include <sstream>
#include <fstream>

namespace Content
{
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
    bool mLoaded = false;
    bool mTryLoaded = false;
public:
    void readAscii(std::ifstream &file);
    void readBinary(std::ifstream &file);
    void read(std::ifstream &file)
    {
        if(file.flags() & std::ios::binary)
            readBinary(file);
        else
            readAscii(file);
    }

    void readAscii(std::string fileName)
    {
        readAscii(std::ifstream(fileName));
    }
    void readBinary(std::string fileName)
    {
        readBinary(std::ifstream(fileName, std::ios::binary));
    }

    inline bool has(std::string section, std::string name)
    {
        return mStrings.find(hash(section, name)) != mStrings.end();
    }

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
    bool getLoaded() const;
    bool getTryLoaded() const;
};
}

#endif // CFGREADER_H
