#include "r3dfile.h"


r3dFile::r3dFile(std::string name)
    : std::ifstream(r3dFileManager::getFilePath(name))
{

}

r3dFile::r3dFile(std::string name, std::ios_base::openmode mode)
    : std::ifstream(r3dFileManager::getFilePath(name), mode)
{

}
