#ifndef VISADEVICE_H
#define VISADEVICE_H

#include "deviceio_global.h"
#include "IDeviceIO.h"

#include <visa.h>
#include <visatype.h>

#include <QMutex>
#include <QTextStream>

class DEVICEIOSHARED_EXPORT VisaDevice : public IDeviceIO
{

public:
    VisaDevice();
    VisaDevice(const char* ResourceString);
    ~VisaDevice();

    void SendCommandRequest         (const char* RequestString);
    QString ReceiveDeviceAnswer     (void);
    QString ReceiveDeviceAnswer     (int BufferSize = 256);
    QString RequestQuery            (const char* QueryString);
    QString RequestQuery            (const char *QueryString,  int ReadBufferSize = 256);

private:
    ViSession defaultRM;
    ViSession instr;
    ViStatus  status;
    ViUInt32  retCount;
    ViUInt32  writeCount;

    ViChar TerminationCharacters[5];

    bool OpenConnection  (const char* ResourceString);
    void CloseConnection ();

    // Implementing thread-safety
    mutable QMutex sendCommandRequestMutex;
    mutable QMutex receiveDeviceAnsverMutex;
    mutable QMutex requestQueryMutex;
};


class DEVICEIOSHARED_EXPORT ReadBuffer{

public:
    ReadBuffer();
    ReadBuffer(int n);
    ~ReadBuffer();

    ViUInt32 Size;
    ViChar*  Buffer;
};

#endif // VISADEVICE_H
