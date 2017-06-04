#include "r3dfilemanager.h"

std::vector<std::string> &r3dFileManager::basePaths()
{
    static std::vector<std::string> man = {"./"};
    return man;
}

std::string r3dFileManager::getFilePath(std::string path)
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

void r3dFileManager::setBasePaths(const std::vector<std::string> &basepaths)
{
    basePaths() = basepaths;
}

void r3dFileManager::addBasePath(std::string path)
{
    basePaths().push_back(path);
}

bool r3dFileManager::hasFile(std::string path)
{
    return getFilePath(path) != "";
}
