#ifndef SERIALDEVICE_H
#define SERIALDEVICE_H

#include "deviceio_global.h"
#include "IDeviceIO.h"

class DEVICEIOSHARED_EXPORT SerialDevice : public IDeviceIO
{
public:
    SerialDevice();

    void SendCommandRequest         (const char* RequestString);
    QString ReceiveDeviceAnswer     (void);
    QString ReceiveDeviceAnswer     (int BufferSize = 256);
    QString RequestQuery            (const char* QueryString);
    QString RequestQuery            (const char *QueryString,  int ReadBufferSize = 256);
};

#endif // SERIALDEVICE_H
