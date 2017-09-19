#include "SerialDevice.h"

SerialDevice::SerialDevice()
{

}


void SerialDevice::SendCommandRequest(const char *RequestString)
{

}

QString SerialDevice::ReceiveDeviceAnswer()
{
    return "";
}

QString SerialDevice::ReceiveDeviceAnswer(int BufferSize)
{
    return "";
}

QString SerialDevice::RequestQuery(const char *QueryString)
{
    return "";
}

QString SerialDevice::RequestQuery(const char *QueryString, int ReadBufferSize)
{
    return "";
}
