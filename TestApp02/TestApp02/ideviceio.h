#ifndef IDEVICEIO_H
#define IDEVICEIO_H

#define READ_BUFFER_SIZE 1024

#include <QString>

class IDeviceIO {

public:
    IDeviceIO() { }
    virtual ~IDeviceIO() { }

    virtual void  SendCommandRequest (const char* RequestString) = 0;
    virtual QString ReceiveDeviceAnswer(void) = 0;
    virtual QString ReceiveDeviceAnswer(int BufferSize) = 0;
    virtual QString RequestQuery(const char* QueryString) = 0;
    virtual QString RequestQuery(const char *QueryString, int ReadBufferSize) = 0;
};

#endif // IDEVICEIO_H
