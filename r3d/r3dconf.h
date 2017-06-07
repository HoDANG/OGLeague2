#ifndef R3DCONF_H
#define R3DCONF_H

#include <map>
#include <string>

class r3dConf
{
private:
    std::map<uint32_t, std::string> mStrings;
    bool mTryLoaded = false;
    inline uint32_t hash(std::string text)
    {
        uint32_t hash = 0;
        for(char c : text)
            hash = tolower(c) + 65599 * hash;
        return hash;
    }

    inline uint32_t hash(std::string section, std::string name)
    {
        return hash(section+"*"+name);
    }

    bool readAscii(std::string filename);

    bool readBinary(std::string filename);
public:
    bool read(std::string fileName);

    bool has(std::string section, std::string name);

    std::string getString(std::string section, std::string name, std::string def = "");

    template<typename T>
    T getNum(std::string section, std::string name, T res = T())
    {
        auto iter = mStrings.find(hash(section, name));
        if(iter == mStrings.end())
            return res;
        std::stringstream ss(iter->second);
        ss>>res;
        return res;
    }

    template<typename T, size_t N>
    std::array<T, N> getArray(std::string section, std::string name,
                    std::array<T, N> res = std::array<T, N>())
    {
        auto iter = mStrings.find(hash(section, name));
        if(iter == mStrings.end())
            return res;
        std::stringstream ss(iter->second);
        for(size_t i = 0; i<N; i++ )
            ss>>res[i];
        return res;
    }

    bool getBool(std::string section, std::string name, bool res = false);

    bool getTryLoaded() const;

    static r3dConf& cache(std::string name);
};

#endif // R3DCONF_H


