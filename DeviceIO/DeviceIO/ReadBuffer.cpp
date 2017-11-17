#include "IDeviceIO.h"
#include "ReadBuffer.h"

ReadBuffer::ReadBuffer()
{
    Size = READ_BUFFER_SIZE;
    Buffer = new unsigned char[READ_BUFFER_SIZE + 1];
}

ReadBuffer::ReadBuffer(int n)
{
    Size = n;
    Buffer = new unsigned char[n + 1];
}

ReadBuffer::~ReadBuffer()
{
    delete[] Buffer;
}
