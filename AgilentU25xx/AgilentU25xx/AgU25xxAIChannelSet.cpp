#include "AgU25xxAIChannelSet.h"
#include "AgU25xxException.h"

#include <QDebug>
#include <QTextStream>

AgU25xxAIChannelSet::AgU25xxAIChannelSet()
    : IAgU25xxSubsystemExtensions()
{
    AIChannels = new AgU25xxAIChannel*[4];
}

AgU25xxAIChannelSet::AgU25xxAIChannelSet(IDeviceIO &driver)
    : IAgU25xxSubsystemExtensions()
{
    initialize(driver);
}

AgU25xxAIChannelSet::~AgU25xxAIChannelSet()
{
    delete[] AIChannels;
    delete mDriver;
}

AgU25xxAIChannel &AgU25xxAIChannelSet::operator [](const int index)
{
    if(index < 0 || index > 3)
        throw AgU25xxException(QString("Invalid index."));

    return *AIChannels[index];
}

AgU25xxAIChannel &AgU25xxAIChannelSet::operator [](const AgU25xxEnumAIChannels channelID)
{
    return *AIChannels[(int)channelID];
}

void AgU25xxAIChannelSet::initialize(IDeviceIO &driver)
{
    AIChannels = new AgU25xxAIChannel*[4];

    int i = 0;
    for (; i != 4; ) {
        AIChannels[i] = new AgU25xxAIChannel(static_cast<AgU25xxEnumAIChannels>(i), driver);
        ++i;
    }

    mDriver = &driver;
}

void AgU25xxAIChannelSet::acquireSingleShot(int samplingFreq)
{       
    QString cmdSetSamplingFreq = mACQuireCommands.cmdSetSamplingRate(samplingFreq);
    QString cmdSetPOINOutput   = mACQuireCommands.cmdSetPointsSingleShot(samplingFreq);
    QString cmdStartSingleShot = mRootCommands.cmdStartSingleShotAcquisition();

    mDriver->SendCommandRequest(cmdSetSamplingFreq);
    mDriver->SendCommandRequest(cmdSetPOINOutput);
    mDriver->SendCommandRequest(cmdStartSingleShot);

    QString queryStatus = mWAVeformCommands.cmdGetAcquisitionConpleteStatus();

    while(true) {
        QString acquisitionStatus = mDriver->RequestQuery(queryStatus);
        if (extGetWAWeformSingleShotStatus(acquisitionStatus) == AgU25xxEnumAcquisitionStates::Complete)
            break;
    }

    fetchScale();
}

void AgU25xxAIChannelSet::startContinuousAcquisition()
{
    QString cmd = mRootCommands.cmdStartContinuousAcquisition();
    mDriver->SendCommandRequest(cmd);
}

void AgU25xxAIChannelSet::stopAcquisition()
{
    QString cmd = mRootCommands.cmdStopAcquisition();
    mDriver->SendCommandRequest(cmd);
}

bool AgU25xxAIChannelSet::checkDataReady()
{
    QString cmd = mWAVeformCommands.cmdGetBufferStatus();
    if (extGetWAWeformBufferStatus(cmd) == AgU25xxEnumBufferStatus::DATA)
        return true;
    else if (extGetWAWeformBufferStatus(cmd) == AgU25xxEnumBufferStatus::OVER)
        throw AgU25xxException(QString("Device buffer overflow."));
    else
        return false;
}

void AgU25xxAIChannelSet::fetch(short *data)
{
    QString cmdGetData = mWAVeformCommands.cmdQueryAcquisitionData();

    mDriver->SendCommandRequest(cmdGetData);

    QString dataStr             = readAgU25xxIEEEBlock();
    const char *dataStrResponse = dataStr.toStdString().c_str();

    int i = 0, j = 0;
    int bufSize = strlen(dataStrResponse);

    data = new short[bufSize / 2];

    for (; i != bufSize; ) {
        data[j] = (short)(dataStrResponse[i] | (dataStrResponse[i + 1] << 8));
        i += 2; ++j;
    }
    //    memcpy(data, dataStrResponse, strlen(dataStrResponse) * sizeof(char));
}

void AgU25xxAIChannelSet::fetchScale()
{
    QString cmdGetData = mWAVeformCommands.cmdQueryAcquisitionData();

    mDriver->SendCommandRequest(cmdGetData);

    QString    dataStr = readAgU25xxIEEEBlock();
    const char *dataStrResponse = dataStr.toStdString().c_str();

    resetAIDataBuffers();

    int i = 0, j = 0, k = 0;
    int bufSize = strlen(dataStrResponse);

    QVector<int> activeChannels     = getNumEnabledChannels();
    unsigned int activeChannelsSize = activeChannels.size();
    unsigned int iter               = 0;
    unsigned int srat               = getSamplingRate();

    for (; k != activeChannelsSize; ){
        (*this)[activeChannels[k]].ACQuisitionData = new double[srat];
        ++k;
    }

    k = 0;
    for (; i != bufSize - 2; ) {
        short untransformedVal = (short)(dataStrResponse[i] | (dataStrResponse[i + 1] << 8));
        (*this)[activeChannels[iter]].ACQuisitionData[k] = (*this)[activeChannels[iter]].getScaleValue(untransformedVal);

        if(++iter == activeChannelsSize)
            iter = 0;

        i += 2; ++j;
        if (i % activeChannelsSize == 0)
            ++k;
    }
}

QVector<int> AgU25xxAIChannelSet::getNumEnabledChannels()
{
    QVector<int> res;
    int i = 0;
    for (; i != 4; ) {
        if ((*this)[i].getEnabled())
            res.push_back(i);
        ++i;
    }

    return res;
}

int AgU25xxAIChannelSet::getSamplingRate()
{
    return mDriver->RequestQuery(mACQuireCommands.cmdGetSamplingrate()).toInt();
}

QString AgU25xxAIChannelSet::readAgU25xxIEEEBlock()
{
    QString headerLenStr = mDriver->ReceiveDeviceAnswer(2, true);
    QString headerLenRef = headerLenStr.mid(1);

    int headerLen = headerLenRef.toInt();
    int dataLen = mDriver->ReceiveDeviceAnswer(headerLen, true).toInt();

    int readBufSize;
    int nReadings;
    int lastBlockSize;

    if (dataLen > 4096) {
        readBufSize = 4096;
        nReadings = dataLen / readBufSize;

        lastBlockSize = dataLen - nReadings * readBufSize;
        if (lastBlockSize > 0)
            ++nReadings;
    }
    else {
        readBufSize = dataLen;
        nReadings = 1;
        lastBlockSize = 1;
    }

    QString dataStr;
    QTextStream dataStrStream(&dataStr);

    int i = 0;
    for (; i != nReadings - 1; ) {
        dataStrStream << mDriver->ReceiveDeviceAnswer(readBufSize, true);
        ++i;
    }

    if(lastBlockSize > 0)
        dataStrStream << mDriver->ReceiveDeviceAnswer(lastBlockSize, true);

    return dataStr;
}

void AgU25xxAIChannelSet::resetAIDataBuffers()
{
    int i = 0;
    for (; i != 4; ){
        if ((*this)[i].ACQuisitionData != NULL) {
            delete[] (*this)[i].ACQuisitionData;
            (*this)[i].ACQuisitionData = NULL;
        }
        ++i;
    }
}
