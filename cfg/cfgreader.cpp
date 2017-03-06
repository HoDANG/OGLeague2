#include "cfgreader.h"
#include <iostream>
#include <fstream>
#include "../dep/buffer.hpp"
#include <bitset>
#include <functional>

using namespace std;

std::map<uint32_t, std::string> Config::getStrings() const
{
    return mStrings;
}

void Config::readAscii(std::string fileName)
{
    ifstream file(fileName);
    string section = "";
    while(true)
    {
        string tmp;
        if(!getline(file,tmp))
            break;
        if(tmp[0] == ';')
            continue;
        if(tmp[0] == '[')
        {
            size_t end = tmp.find(']');
            if(end == string::npos)
                continue;
            section = tmp.substr(1, end-1);
            continue;
        }
        size_t eq = tmp.find('=');
        if(eq == string::npos)
            continue;
        if(section == "")
            continue;
        string name = tmp.substr(0, eq);
        string value = tmp.substr(eq+1);
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
}

namespace
{
    typedef struct
    {
        uint8_t val;
    } byte10;

    inline vector<uint32_t> readKeys(ifstream &file)
    {
        uint16_t num;
        std::vector<uint32_t> keys;
        file > num;
        keys.resize(num);
        file > keys;
        return keys;
    }

    template<typename T>
    inline string tostring(T val)
    {
        return to_string(val);
    }

    inline string tostring(byte10 b)
    {
        return to_string(b.val / 10.0f);
    }

    template<typename T, size_t N>
    inline string tostring(array<T,N> arr)
    {
        stringstream ss;
        for(size_t i = 0; i<N; i++)
        {
            if(i != 0)
                ss<<' ';
            ss<<tostring(arr[i]);
        }
        return ss.str();
    }

    template<typename T>
    inline void readNums(ifstream &file, map<uint32_t,string> &vals)
    {
        vector<uint32_t> keys = readKeys(file);
        for(size_t i = 0; i < keys.size(); i++)
        {
            T val;
            file > val;
            vals[keys[i]] = tostring(val);
        }
    }

    inline void readBools(ifstream &file, map<uint32_t,string> &vals)
    {
        vector<uint32_t> keys = readKeys(file);
        size_t len = keys.size() / 8;
        if(keys.size() % 8 > 0)
            ++len;
        vector<uint8_t> buff;
        buff.resize(len);
        file > buff;
        for(size_t i = 0; i < keys.size(); i++)
        {
            vals[keys[i]] = ((buff[i/8] >> i%8) & 0x01) ? "1" : "0";
        }
    }

    inline void readStrings(ifstream &file, map<uint32_t,string> &vals, uint16_t stringsSize)
    {
        vector<uint32_t> keys = readKeys(file);
        vector<uint16_t> offsets;
        offsets.resize(keys.size());
        file > offsets;
        vector<char> data;
        data.resize(stringsSize);
        file > data;
        for(size_t i = 0; i < keys.size(); i++)
        {
            vals[keys[i]] = string(&data[offsets[i]]);
        }
    }
}

void Config::readBinary(std::string fileName)
{
    ifstream file(fileName, ios::binary);
    uint8_t version;

    file > version;
    if(version == 2)
    {
        uint16_t stringsLength;
        uint16_t rawFlags;
        bitset<13> flags;

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
            readNums<array<byte10, 3>>(file, mStrings);
        if(flags[7])
            readNums<array<float, 3>>(file, mStrings);
        if(flags[8])
            readNums<array<byte10, 2>>(file, mStrings);
        if(flags[9])
            readNums<array<float, 2>>(file, mStrings);
        if(flags[10])
            readNums<array<byte10, 4>>(file, mStrings);
        if(flags[11])
            readNums<array<float, 4>>(file, mStrings);
        if(flags[12])
            readStrings(file, mStrings, stringsLength);
    }

    if(version == 1)
    {
        std::array<uint8_t, 3> pad;
        file > pad;
        uint32_t entryCount;
        uint32_t dataCount;
        vector<array<uint32_t, 2>> entries;
        vector<char> data;

        file > entryCount;
        file > dataCount;

        entries.resize(entryCount);
        data.resize(dataCount);

        file > entries;
        file > data;

        for(size_t i = 0; i < entryCount; i++)
        {
            mStrings[entries[i][0]] = string(&data[entries[i][1]]);
        }
    }
}


