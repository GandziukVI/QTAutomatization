#ifndef SERIALDEVICE_H
#define SERIALDEVICE_H

#include "deviceio_global.h"
#include "IDeviceIO.h"

#include <QMutex>
#include <QtSerialPort/QSerialPort>
#include <QTextStream>


class DEVICEIOSHARED_EXPORT SerialDevice : public IDeviceIO
{
public:
    SerialDevice();
    SerialDevice(const char* portName, int baudRate = QSerialPort::Baud9600,
                 QSerialPort::Parity parity = QSerialPort::NoParity, QSerialPort::DataBits dataBits = QSerialPort::Data8,
                 QSerialPort::StopBits stopBits = QSerialPort::OneStop);
    ~SerialDevice();

    void SendCommandRequest         (const char* RequestString);
    void SendCommandRequest         (const QString RequestString);
    QByteArray ReceiveDeviceAnswer     (void);
    QByteArray ReceiveDeviceAnswer     (int BufferSize = 256, bool readExactOrMax = false);
    QByteArray RequestQuery            (const char* QueryString);
    QByteArray RequestQuery            (const QString QueryString);
    QByteArray RequestQuery            (const char* QueryString,  int ReadBufferSize = 256);
    QByteArray RequestQuery            (const QString QueryString,  int ReadBufferSize = 256);

private:
    // Implementing thread-safety
    mutable QMutex sendCommandRequestMutex;
    mutable QMutex receiveDeviceAnsverMutex;
    mutable QMutex requestQueryMutex;

    mutable QMutex dataCollectionMutex;

    // Data container
    QByteArray  data;
    void        writeDataToStream();

    QSerialPort serialPort;
    bool        isOpen;
    bool        OpenConnection();
    void        CloseConnection();

    char        TerminationCharacters[4];
};

#endif // SERIALDEVICE_H
