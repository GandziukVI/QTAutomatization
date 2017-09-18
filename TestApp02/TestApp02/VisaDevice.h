#ifndef VISADEVICE_H
#define VISADEVICE_H

#include "IDeviceIO.h"

#include <visa.h>
#include <visatype.h>

#include <QMutex>
#include <QTextStream>

class VisaDevice : public IDeviceIO
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

    unsigned char buffer[512];

    bool OpenConnection  (const char* ResourceString);
    void CloseConnection ();

    // Implementing thread-safety
    mutable QMutex sendCommandRequestMutex;
    mutable QMutex receiveDeviceAnsverMutex;
    mutable QMutex requestQueryMutex;
};


class ReadBuffer{

public:
    ReadBuffer();
    ReadBuffer(int n);
    ~ReadBuffer();

    ViUInt32 Size;
    ViChar*  Buffer;
};

#endif // VISADEVICE_H
