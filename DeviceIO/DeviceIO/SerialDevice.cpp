#include "SerialDevice.h"

#include "DeviceIOException.h"

SerialDevice::SerialDevice()
{
    strncpy(TerminationCharacters, "\n\r\r\n\f\0", 5);
}

SerialDevice::SerialDevice(const char *portName, int baudRate, QSerialPort::Parity parity, QSerialPort::DataBits dataBits, QSerialPort::StopBits stopBits)
{
    strncpy(TerminationCharacters, "\n\r\r\n\f\0", 5);

    serialPort.setPortName(portName);
    serialPort.setBaudRate(baudRate);
    serialPort.setParity(parity);
    serialPort.setDataBits(dataBits);
    serialPort.setStopBits(stopBits);

    OpenConnection();

    if(!isOpen) {
        CloseConnection();
        throw DeviceIOException(QObject::tr("Cannot open connection to the port %1, error %2").arg(portName).arg(serialPort.errorString()));
    }
}

SerialDevice::~SerialDevice()
{
    CloseConnection();
}

bool SerialDevice::OpenConnection()
{
    isOpen = serialPort.open(QIODevice::ReadWrite);
    return isOpen;
}

void SerialDevice::CloseConnection()
{
    if(isOpen)
        serialPort.close();
}

void SerialDevice::SendCommandRequest(const char* RequestString)
{
    QMutexLocker queryLocker(&requestQueryMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);
    QMutexLocker commandLocker(&sendCommandRequestMutex);

    if(!isOpen)
        throw DeviceIOException(QObject::tr("Serial port %1 is closed.").arg(serialPort.portName()));

    // Flushing serial port before writing a new command to it
    while(serialPort.bytesAvailable() > 0)
        serialPort.readAll();

    QByteArray toWrite(RequestString);

    qint64 bytesWritten = serialPort.write(toWrite);

    if (bytesWritten == -1) {
        throw DeviceIOException(QObject::tr("Failed to write the data to port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString()));
    } else if (bytesWritten != toWrite.size()) {
        throw DeviceIOException(QObject::tr("Failed to write all the data to port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString()));
    } else if (!serialPort.waitForBytesWritten(5000)) {
        throw DeviceIOException(QObject::tr("Operation timed out or an error occurred for port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString()));
    }
}

QString SerialDevice::ReceiveDeviceAnswer()
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker queryLocker(&requestQueryMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);

    if(!isOpen)
        throw DeviceIOException(QObject::tr("Serial port %1 is closed.").arg(serialPort.portName()));

    // Reading data from the port
    data = serialPort.readAll();
    while(true) {
        if(strchr(TerminationCharacters, *data.end()))
            break;
        while (serialPort.waitForReadyRead(INT_MAX))
            data.append(serialPort.readAll());
    }

    return QString(data);
}

QString SerialDevice::ReceiveDeviceAnswer(int BufferSize, bool readExactOrMax)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker queryLocker(&requestQueryMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);

    if(!isOpen)
        throw DeviceIOException(QObject::tr("Serial port %1 is closed.").arg(serialPort.portName()));

    // Reading data from the port
    data = serialPort.read(BufferSize);
    while(true) {
        if(strchr(TerminationCharacters, *data.end()))
            break;
        if(readExactOrMax == true && data.count() == BufferSize)
            break;
        else if (readExactOrMax == true && data.count() > BufferSize)
            throw DeviceIOException(QObject::tr("Read buffer size exceeded maximum value."));

        while (serialPort.waitForReadyRead(INT_MAX)) {
            if(!readExactOrMax)
                data.append(serialPort.read(BufferSize));
            else
                data.append(serialPort.read(BufferSize - data.count()));
        }
    }

    return QString(data);
}

QString SerialDevice::RequestQuery(const char* QueryString)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);
    QMutexLocker queryLocker(&requestQueryMutex);

    // Flushing serial port before writing a new command to it
    while(serialPort.bytesAvailable() > 0)
        serialPort.readAll();

    QByteArray toWrite(QueryString);

    qint64 bytesWritten = serialPort.write(toWrite);

    if (bytesWritten == -1) {
        throw DeviceIOException(QObject::tr("Failed to write the data to port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString()));
    } else if (bytesWritten != toWrite.size()) {
        throw DeviceIOException(QObject::tr("Failed to write all the data to port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString()));
    } else if (!serialPort.waitForBytesWritten(5000)) {
        throw DeviceIOException(QObject::tr("Operation timed out or an error occurred for port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString()));
    }

    // Reading data from the port
    data = serialPort.readAll();
    while(true) {
        if(strchr(TerminationCharacters, *data.end()))
            break;
        while (serialPort.waitForReadyRead(INT_MAX))
            data.append(serialPort.readAll());
    }

    return QString(data);
}

QString SerialDevice::RequestQuery(const char* QueryString, int ReadBufferSize)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);
    QMutexLocker queryLocker(&requestQueryMutex);

    if(!isOpen)
        throw DeviceIOException(QObject::tr("Serial port %1 is closed.").arg(serialPort.portName()));

    // Flushing serial port before writing a new command to it
    while(serialPort.bytesAvailable() > 0)
        serialPort.readAll();

    QByteArray toWrite(QueryString);

    qint64 bytesWritten = serialPort.write(toWrite);

    if (bytesWritten == -1) {
        throw DeviceIOException(QObject::tr("Failed to write the data to port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString()));
    } else if (bytesWritten != toWrite.size()) {
        throw DeviceIOException(QObject::tr("Failed to write all the data to port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString()));
    } else if (!serialPort.waitForBytesWritten(5000)) {
        throw DeviceIOException(QObject::tr("Operation timed out or an error occurred for port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString()));
    }

    // Reading data from the port
    data = serialPort.read(ReadBufferSize);
    while(true) {
        if(strchr(TerminationCharacters, *data.end()))
            break;
        while (serialPort.waitForReadyRead(INT_MAX))
            data.append(serialPort.read(ReadBufferSize));
    }

    return QString(data);
}
