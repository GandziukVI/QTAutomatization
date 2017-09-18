#include "VisaDevice.h"

#include <memory>

VisaDevice::VisaDevice()
{
    strncpy(TerminationCharacters, "\n\r\r\n\f\0", 5);
}

VisaDevice::VisaDevice(const char *ResourceString)
{
    strncpy(TerminationCharacters, "\n\r\r\n\f\0", 5);
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

    QString     containerString;
    QTextStream container(&containerString);

    while(true) {

        ViChar tempBuffer[READ_BUFFER_SIZE + 1];

        status = viRead(instr, (ViBuf)tempBuffer, READ_BUFFER_SIZE, &retCount);

        tempBuffer[retCount] = (ViChar)'\0';

        if(retCount < READ_BUFFER_SIZE) {
            container << tempBuffer;
            break;
        }
        else if (retCount == READ_BUFFER_SIZE) {
            container << tempBuffer;
            if(strchr(TerminationCharacters, tempBuffer[retCount - 1]) != NULL)
                break;
        }
        else
            break;
    }

    return containerString;
}

QString VisaDevice::ReceiveDeviceAnswer(int BufferSize)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker queryLocker(&requestQueryMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);

    QString     containerString;
    QTextStream container(&containerString);

    while(true) {

        ReadBuffer tempBuffer(BufferSize);

        status = viRead(instr, (ViBuf)tempBuffer.Buffer, tempBuffer.Size, &retCount);

        tempBuffer.Buffer[retCount] = (ViChar)'\0';

        if(retCount < tempBuffer.Size) {
            container << tempBuffer.Buffer;
            break;
        }
        else if (retCount == tempBuffer.Size) {
            container << tempBuffer.Buffer;
            if(strchr(TerminationCharacters, tempBuffer.Buffer[retCount - 1]) != NULL)
                break;
        }
        else
            break;
    }

    return containerString;
}

QString VisaDevice::RequestQuery(const char *QueryString)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);
    QMutexLocker queryLocker(&requestQueryMutex);

    status = viWrite(instr, (ViBuf)QueryString, (ViUInt32)strlen(QueryString), &writeCount);

    QString     containerString;
    QTextStream container(&containerString);

    while(true) {

        ViChar tempBuffer[READ_BUFFER_SIZE + 1];

        status = viRead(instr, (ViBuf)tempBuffer, READ_BUFFER_SIZE, &retCount);

        tempBuffer[retCount] = (ViChar)'\0';

        if(retCount < READ_BUFFER_SIZE) {
            container << tempBuffer;
            break;
        }
        else if (retCount == READ_BUFFER_SIZE) {
            container << tempBuffer;
            if(strchr(TerminationCharacters, tempBuffer[retCount - 1]) != NULL)
                break;
        }
        else
            break;
    }

    return containerString;
}

QString VisaDevice::RequestQuery(const char *QueryString, int ReadBufferSize)
{
    QMutexLocker commandLocker(&sendCommandRequestMutex);
    QMutexLocker receiveAnswerLocker(&receiveDeviceAnsverMutex);
    QMutexLocker queryLocker(&requestQueryMutex);

    status = viWrite(instr, (ViBuf)QueryString, (ViUInt32)strlen(QueryString), &writeCount);

    ViUInt32 prevRDBufSize;
    status = viGetAttribute(instr, VI_ATTR_RD_BUF_SIZE, &prevRDBufSize);
    if(ReadBufferSize > prevRDBufSize)
        status = viSetBuf(instr)

    QString     containerString;
    QTextStream container(&containerString);

    while(true) {

        ReadBuffer tempBuffer(ReadBufferSize);

        status = viRead(instr, (ViBuf)tempBuffer.Buffer, tempBuffer.Size, &retCount);

        tempBuffer.Buffer[retCount] = (ViChar)'\0';

        if(retCount < tempBuffer.Size) {
            container << tempBuffer.Buffer;
            break;
        }
        else if (retCount == tempBuffer.Size) {
            container << tempBuffer.Buffer;
            if(strchr(TerminationCharacters, tempBuffer.Buffer[retCount - 1]) != NULL)
                break;
        }
        else
            break;
    }

    return containerString;
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
