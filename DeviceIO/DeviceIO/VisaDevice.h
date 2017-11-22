#ifndef VISADEVICE_H
#define VISADEVICE_H

#include "deviceio_global.h"
#include "IDeviceIO.h"

#include <visa.h>
#include <visatype.h>

#include <QMutex>
#include <QTextCodec>
#include <QTextStream>

class DEVICEIOSHARED_EXPORT VisaDevice : public IDeviceIO
{

public:
    VisaDevice();
    VisaDevice(const char* ResourceString);
    ~VisaDevice();

    void SendCommandRequest      (const char* RequestString);
    void SendCommandRequest      (const QString& RequestString);
    QByteArray ReceiveDeviceAnswer  (void);
    QByteArray ReceiveDeviceAnswer  (int BufferSize = 256, bool readExactOrMax = false);
    QByteArray RequestQuery         (const char* QueryString);
    QByteArray RequestQuery         (const QString& QueryString);
    QByteArray RequestQuery         (const char* QueryString,  int ReadBufferSize = 256);
    QByteArray RequestQuery         (const QString& QueryString,  int ReadBufferSize = 256);

private:
    ViSession defaultRM;
    ViSession instr;
    ViStatus  status;
    ViUInt32  retCount;
    ViUInt32  writeCount;

    ViUInt32 standardReadBufSize;
    ViUInt32 currentReadBufferSize;

    ViChar TerminationCharacters[4];

    bool OpenConnection  (const char* ResourceString);
    void CloseConnection ();

    // Implementing thread-safety
    mutable QMutex sendCommandRequestMutex;
    mutable QMutex receiveDeviceAnsverMutex;
    mutable QMutex requestQueryMutex;

    QTextCodec* codec;
};

#endif // VISADEVICE_H
