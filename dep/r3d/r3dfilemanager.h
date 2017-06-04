#ifndef R3DFILEMANAGER_H
#define R3DFILEMANAGER_H

#include <vector>
#include <string>
#include <fstream>

class r3dFileManager
{
public:
    static std::vector<std::string>& basePaths();

    static std::string getFilePath(std::string path);

    static void setBasePaths(const std::vector<std::string> &basepaths);

    static void addBasePath(std::string path);

    static bool hasFile(std::string path);
};

#endif // R3DFILEMANAGER_H
