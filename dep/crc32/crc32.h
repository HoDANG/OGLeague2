#ifndef CRC32_H
#define CRC32_H

#include <string.h>

const unsigned long CRC32_NEGL = 0xffffffffL;
typedef unsigned char byte;
typedef unsigned long word32;

class CRC32
{
public:
    CRC32();
    void Update(const byte *input, unsigned int length);
    void Final(byte *hash);
    unsigned int DigestSize() const;

    void Reset();
    void UpdateByte(byte b);
    word32 GetCrc();
    unsigned int GetHash(const char* value);
private:
    static const unsigned long crc_32_tab[256];
    unsigned long curr_crc;
};

#endif //CRC32_H
