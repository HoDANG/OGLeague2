#include "r3dconf.h"
#include <array>
#include <sstream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <bitset>
#include <functional>
#include "r3dbuffer.h"
#include "r3dfile.h"


namespace {
typedef struct
{
    uint8_t val;
} byte10;

inline std::vector<uint32_t> readKeys(std::ifstream &file)
{
    uint16_t num;
    std::vector<uint32_t> keys;
    file > num;
    keys.resize(num);
    file > keys;
    return keys;
}

template<typename T>
inline std::string to_string(T val)
{
    return to_string(val);
}

inline std::string to_string(byte10 b)
{
    return to_string(b.val / 10.0f);
}

template<typename T, size_t N>
inline std::string to_string(std::array<T,N> arr)
{
    std::stringstream ss;
    for(size_t i = 0; i<N; i++)
    {
        if(i != 0)
            ss<<' ';
        ss<<to_string(arr[i]);
    }
    return ss.str();
}

template<typename T>
inline void readNums(std::ifstream &file, std::map<uint32_t,std::string> &vals)
{
    std::vector<uint32_t> keys = readKeys(file);
    for(size_t i = 0; i < keys.size(); i++)
    {
        T val;
        file > val;
        vals[keys[i]] = to_string(val);
    }
}

inline void readBools(std::ifstream &file, std::map<uint32_t,std::string> &vals)
{
    std::vector<uint32_t> keys = readKeys(file);
    size_t len = keys.size() / 8;
    if(keys.size() % 8 > 0)
        ++len;
    std::vector<uint8_t> buff;
    buff.resize(len);
    file > buff;
    for(size_t i = 0; i < keys.size(); i++)
    {
        vals[keys[i]] = ((buff[i/8] >> i%8) & 0x01) ? "1" : "0";
    }
}

inline void readStrings(std::ifstream &file, std::map<uint32_t,std::string> &vals, uint16_t stringsSize)
{
    std::vector<uint32_t> keys = readKeys(file);
    std::vector<uint16_t> offsets;
    offsets.resize(keys.size());
    file > offsets;
    std::vector<char> data;
    data.resize(stringsSize);
    file > data;
    for(size_t i = 0; i < keys.size(); i++)
    {
        vals[keys[i]] = std::string(&data[offsets[i]]);
    }
}
}

bool r3dConf::readAscii(std::string filename)
{
    r3dFile file(filename);
    if(!file.is_open())
        return false;
    std::string section = "";
    while(true)
    {
        std::string tmp;
        if(!getline(file,tmp))
            break;
        if(tmp[0] == ';')
            continue;
        if(tmp[0] == '[')
        {
            size_t end = tmp.find(']');
            if(end == std::string::npos)
                continue;
            section = tmp.substr(1, end-1);
            continue;
        }
        size_t eq = tmp.find('=');
        if(eq == std::string::npos)
            continue;
        if(section == "")
            continue;
        std::string name = tmp.substr(0, eq);
        std::string value = tmp.substr(eq+1);
        value.erase(0, value.find_first_not_of(' '));
        name.erase(name.find_last_not_of(' ')+1, name.length());
        if(name == "")
            continue;
        if(section == "*")
        {
            mStrings[stoi(name)] = value;
            continue;
        }
        mStrings[hash(section, name)] = value;
    }
    return true;
}

bool r3dConf::readBinary(std::string filename)
{
    r3dFile file(filename, std::ios_base::binary);
    if(!file.is_open())
        return false;
    uint8_t version;
    file > version;
    if(version == 2)
    {
        uint16_t stringsLength;
        uint16_t rawFlags;
        std::bitset<13> flags;

        file > stringsLength;
        file > rawFlags;
        flags = rawFlags;

        if(flags[0])
            readNums<uint32_t>(file, mStrings);
        if(flags[1])
            readNums<float>(file, mStrings);
        if(flags[2])
            readNums<byte10>(file, mStrings);
        if(flags[3])
            readNums<uint16_t>(file, mStrings);
        if(flags[4])
            readNums<uint8_t>(file, mStrings);
        if(flags[5])
            readBools(file, mStrings);
        if(flags[6])
            readNums<std::array<byte10, 3>>(file, mStrings);
        if(flags[7])
            readNums<std::array<float, 3>>(file, mStrings);
        if(flags[8])
            readNums<std::array<byte10, 2>>(file, mStrings);
        if(flags[9])
            readNums<std::array<float, 2>>(file, mStrings);
        if(flags[10])
            readNums<std::array<byte10, 4>>(file, mStrings);
        if(flags[11])
            readNums<std::array<float, 4>>(file, mStrings);
        if(flags[12])
            readStrings(file, mStrings, stringsLength);
        return true;
    }

    if(version == 1)
    {
        std::array<uint8_t, 3> pad;
        file > pad;
        uint32_t entryCount;
        uint32_t dataCount;
        std::vector<std::array<uint32_t, 2>> entries;
        std::vector<char> data;

        file > entryCount;
        file > dataCount;

        entries.resize(entryCount);
        data.resize(dataCount);

        file > entries;
        file > data;

        for(size_t i = 0; i < entryCount; i++)
        {
            mStrings[entries[i][0]] = std::string(&data[entries[i][1]]);
        }
        return true;
    }
    return false;
}

bool r3dConf::read(std::string fileName)
{
    bool read = false;
    if(readBinary(fileName+"bin"))
        read = true;
    if(readAscii(fileName))
        read = true;
    mTryLoaded = read;
    return read;
}

bool r3dConf::has(std::string section, std::string name)
{
    return mStrings.find(hash(section, name)) != mStrings.end();
}

std::string r3dConf::getString(std::string section, std::string name, std::string def)
{
    auto iter = mStrings.find(hash(section, name));
    return iter == mStrings.end() ? def : iter->second;
}

bool r3dConf::getBool(std::string section, std::string name, bool res)
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

bool r3dConf::getTryLoaded() const
{
    return mTryLoaded;
}

r3dConf &r3dConf::cache(std::string name)
{
    static std::map<std::string, r3dConf> mConfCache;
    r3dConf &conf = mConfCache[name];
    if(!conf.getTryLoaded())
        conf.read(name);
    return conf;
}
