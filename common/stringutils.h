#pragma once
#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <algorithm>
#include <cstring>

struct StringUtils
{
    static int stringicmp(std::string str1, std::string str2)
    {
        std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
        std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
        return strcmp(str1.c_str(), str2.c_str());
    }
};

#endif // STRINGUTILS_H
