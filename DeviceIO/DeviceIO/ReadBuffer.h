#ifndef READBUFFER_H
#define READBUFFER_H

#include "deviceio_global.h"

class DEVICEIOSHARED_EXPORT ReadBuffer{

public:
    ReadBuffer();
    ReadBuffer(int n);
    ~ReadBuffer();

    unsigned int   Size;
    char           *Buffer;
};

#endif // READBUFFER_H
