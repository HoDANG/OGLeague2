#ifndef R3DFILEMANAGER_H
#define R3DFILEMANAGER_H

#include <vector>
#include <string>
#include <fstream>

class r3dFileManager
{
public:
    static std::vector<std::string>& basePaths()
    {
        static std::vector<std::string> man = {"./"};
        return man;
    }

    static std::string getFilePath(std::string path)
    {
        for(auto base: basePaths())
        {
            std::string complete = base+"/"+path;
            if(std::fstream(complete).good())
            {
                return complete;
            }
        }
        return "";
    }

    static void setBasePaths(const std::vector<std::string> &basepaths)
    {
        basePaths() = basepaths;
    }

    static void addBasePath(std::string path)
    {
        basePaths().push_back(path);
    }

    static bool hasFile(std::string path)
    {
        return getFilePath(path) != "";
    }
};

#endif // R3DFILEMANAGER_H
