#ifndef CONTENTLOADER_H
#define CONTENTLOADER_H

#include <vector>
#include <string>
#include <memory>
#include <map>
#include "cfgreader.h"

namespace Content
{
class Manager
{
private:
    std::vector<std::string> mBasePaths;
    std::map<std::string, Config> mConfCache;
public:
    std::vector<std::string> basePaths() const;
    void setBasePaths(const std::vector<std::string> &basePaths);
    std::string getFile(std::string path);
    Config& config(std::string path);
};
}

#endif // CONTENTLOADER_H
