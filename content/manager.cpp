#include "manager.h"
#include <iostream>

using namespace std;
using namespace Content;

std::vector<std::string> Manager::basePaths() const
{
    return mBasePaths;
}

void Manager::setBasePaths(const std::vector<std::string> &basePaths)
{
    mBasePaths = basePaths;
}

string Manager::getFile(string path)
{
    for(auto base: mBasePaths)
    {
        auto complete = base+"/"+path;
        if(fstream(complete).good())
        {
            return complete;
        }
    }
    return "./"+path;
}

Config& Manager::config(string path)
{
    Config& conf = mConfCache[path];
    if(!conf.getTryLoaded())
    {
        conf.readBinary(getFile(path+"bin"));
        conf.readAscii(getFile(path));
    }
    return conf;
}
