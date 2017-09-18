#include "VisaDevice.h"

#include <memory>

VisaDevice::VisaDevice()
{
}

VisaDevice::VisaDevice(const char *ResourceString)
{
    OpenConnection(ResourceString);
}

VisaDevice::~VisaDevice()
{
    CloseConnection();
}

void VisaDevice::SendCommandRequest(const char* RequestString)
{
    QMutexLocker queryLocker(&requestQueryMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);
    QMutexLocker commandLocker(&sendCommandRequestMutex);

    status = viWrite(instr, (ViBuf)RequestString, (ViUInt32)strlen(RequestString), &writeCount);
}

QString VisaDevice::ReceiveDeviceAnswer(void)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker queryLocker(&requestQueryMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);

    ViChar rdBuffer[READ_BUFFER_SIZE];

    status = viRead(instr, (ViBuf)rdBuffer, READ_BUFFER_SIZE, &retCount);

    return QString(rdBuffer);
}

QString VisaDevice::ReceiveDeviceAnswer(int BufferSize)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker queryLocker(&requestQueryMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);

    ReadBuffer buffer(BufferSize);

    status = viRead(instr, (ViBuf)buffer.Buffer, buffer.Size, &retCount);

    if (retCount < buffer.Size) {
        buffer.Buffer[retCount] = (ViChar)'\0';
        return QString(buffer.Buffer);
    }
//    else if ((retCount == buffer.Size) && (buffer.Buffer[buffer.Size - 1] == '\n') ||
//             (retCount == buffer.Size) && (buffer.Buffer[buffer.Size - 1] == '\r') ||
//             (retCount == buffer.Size) && (buffer.Buffer[buffer.Size - 1] == '\0') ||
//             (retCount == buffer.Size) && (buffer.Buffer[buffer.Size - 1] == '\f')) {

//        viFlush(instr, VI_READ_BUF);
//        return QString(buffer.Buffer);
//    }
    else {
        QString     containerString;
        QTextStream container(&containerString);
        buffer.Buffer[retCount] = (ViChar)'\0';
        container << buffer.Buffer;

        while(true) {

            ReadBuffer tempBuffer(BufferSize);

            status = viRead(instr, (ViBuf)tempBuffer.Buffer, tempBuffer.Size, &retCount);

            tempBuffer.Buffer[retCount] = (ViChar)'\0';

            if(retCount < tempBuffer.Size) {
                container << tempBuffer.Buffer;
                break;
            }
            else if (retCount == tempBuffer.Size) {
                container << tempBuffer.Buffer << '\0';
                if (tempBuffer.Buffer[tempBuffer.Size - 1] == (ViChar)'\0')
                    break;
                if (tempBuffer.Buffer[tempBuffer.Size - 1] == (ViChar)'\n')
                    break;
                if (tempBuffer.Buffer[tempBuffer.Size - 1] == (ViChar)'\r')
                    break;
            }
            else
                break;
        }

        return containerString;
    }
}

QString VisaDevice::RequestQuery(const char *QueryString)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);
    QMutexLocker queryLocker(&requestQueryMutex);

    status = viWrite(instr, (ViBuf)QueryString, (ViUInt32)strlen(QueryString), &writeCount);

    ViChar rdBuffer[READ_BUFFER_SIZE];
    status = viRead(instr, (ViBuf)rdBuffer, READ_BUFFER_SIZE, &retCount);

    return QString(rdBuffer);
}

QString VisaDevice::RequestQuery(const char *QueryString, int ReadBufferSize)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);
    QMutexLocker queryLocker(&requestQueryMutex);

    status = viWrite(instr, (ViBuf)QueryString, (ViUInt32)strlen(QueryString), &writeCount);

    ReadBuffer buffer(ReadBufferSize);

    status = viRead(instr, (ViBuf)buffer.Buffer, buffer.Size, &retCount);

    if (retCount < buffer.Size) {
        buffer.Buffer[retCount] = (ViChar)'\0';
        return QString(buffer.Buffer);
    }
    else {
        QString     containerString;
        QTextStream container(&containerString);
        buffer.Buffer[retCount] = (ViChar)'\0';
        container << buffer.Buffer;

        while(true) {

            ReadBuffer tempBuffer(ReadBufferSize);

            status = viRead(instr, (ViBuf)tempBuffer.Buffer, tempBuffer.Size, &retCount);

            tempBuffer.Buffer[retCount] = (ViChar)'\0';

            if(retCount < tempBuffer.Size) {
                container << tempBuffer.Buffer;
                break;
            }
            else if (retCount == tempBuffer.Size) {
                container << tempBuffer.Buffer << '\0';
                if (tempBuffer.Buffer[tempBuffer.Size - 1] == (ViChar)'\0')
                    break;
                if (tempBuffer.Buffer[tempBuffer.Size - 1] == (ViChar)'\n')
                    break;
                if (tempBuffer.Buffer[tempBuffer.Size - 1] == (ViChar)'\r')
                    break;
            }
            else
                break;
        }

        return containerString;
    }
}

bool VisaDevice::OpenConnection(const char* ResourceString)
{
    // First we must call viOpenDefaultRM to get the resource manager
    // handle.  We will store this handle in defaultRM.
    status = viOpenDefaultRM (&defaultRM);
    if (status < VI_SUCCESS) {
        return false;
    }

    status = viOpen(defaultRM, (ViString)ResourceString, VI_NULL, VI_NULL, &instr);
    if(status < VI_SUCCESS) {
        CloseConnection();
        return false;
    }

    // Setting timeout to max possible integer value
    status = viSetAttribute (instr, VI_ATTR_TMO_VALUE, VI_TMO_INFINITE);
    if(status < VI_SUCCESS) {
        CloseConnection();
        return false;
    }

    return true;
}

void VisaDevice::CloseConnection()
{
    status = viClose(instr);
    status = viClose(defaultRM);
}


ReadBuffer::ReadBuffer()
{
    Size = READ_BUFFER_SIZE;
    Buffer = new ViChar[READ_BUFFER_SIZE + 1];
}

ReadBuffer::ReadBuffer(int n)
{
    Size = n;
    Buffer = new ViChar[n + 1];
}

ReadBuffer::~ReadBuffer()
{
    delete[] Buffer;
}
