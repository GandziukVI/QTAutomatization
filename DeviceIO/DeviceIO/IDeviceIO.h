#ifndef IDEVICEIO_H
#define IDEVICEIO_H

#include "deviceio_global.h"

#define READ_BUFFER_SIZE 256

class DEVICEIOSHARED_EXPORT IDeviceIO {

public:
    IDeviceIO() { }
    virtual ~IDeviceIO() { }

    virtual void  SendCommandRequest (const char* RequestString) = 0;
    virtual void  SendCommandRequest (const QString& RequestString) = 0;
    virtual QByteArray ReceiveDeviceAnswer(void) = 0;
    virtual QByteArray ReceiveDeviceAnswer(int BufferSize, bool readExactOrMax) = 0;
    virtual QByteArray RequestQuery(const char* QueryString) = 0;
    virtual QByteArray RequestQuery(const QString& QueryString) = 0;
    virtual QByteArray RequestQuery(const char* QueryString, int ReadBufferSize) = 0;
    virtual QByteArray RequestQuery(const QString& QueryString, int ReadBufferSize) = 0;
};

#endif // IDEVICEIO_H
