#ifndef R3DFILE_H
#define R3DFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "r3dfilemanager.h"

class r3dFile : public std::ifstream
{
public:
    r3dFile(std::string name);
    r3dFile(std::string name, std::ios_base::openmode mode);

    template<typename T>
    bool readb(T &dest, size_t count = 1)
    {
        if(read((char *) &dest, sizeof(T) * count))
            return true;
        return false;
    }

    template<typename T>
    bool readv(std::vector<T> &dest, size_t count)
    {
        dest.resize(count);
        return readb(dest[0], count);
    }

};

#endif // R3DFILE_H
