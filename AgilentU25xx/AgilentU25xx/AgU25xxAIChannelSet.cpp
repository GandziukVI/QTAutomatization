#include "AgU25xxAIChannelSet.h"
#include "AgU25xxException.h"

#include <QTextStream>

#include <QDebug>
#include <QElapsedTimer>

AgU25xxAIChannelSet::AgU25xxAIChannelSet()
    : IAgU25xxSubsystemExtensions(),
      mAIChannelsSamplingFreq(1000),
      mAIChannelsEnabledCount(0)
{
    AIChannels = new AgU25xxAIChannel*[4];
}

AgU25xxAIChannelSet::AgU25xxAIChannelSet(IDeviceIO &driver)
    : IAgU25xxSubsystemExtensions(),
      mAIChannelsSamplingFreq(1000),
      mAIChannelsEnabledCount(0)
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
    mAIChannelsSamplingFreq = samplingFreq;

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

    qDebug() << "Starting data reading.";
    QElapsedTimer readTimer;

    readTimer.start();

    QString dataStr             = readAgU25xxIEEEBlock();

    qDebug() << QObject::tr("Reading from device took %1").arg(readTimer.elapsed());

    const char *dataStrResponse = dataStr.toStdString().c_str();

    qDebug() << QObject::tr("Data transform took %1").arg(readTimer.elapsed());

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
    QVector<int> activeChannels = getNumEnabledChannels();
    int estimatedDataBufSize = activeChannels.size() * mAIChannelsSamplingFreq * 2;

    QString cmdGetData = mWAVeformCommands.cmdQueryAcquisitionData();
    mDriver->SendCommandRequest(cmdGetData);

    qDebug() << "Starting data reading.";
    QElapsedTimer readTimer;    
    readTimer.start();

    QString dataStr = mDriver->ReceiveDeviceAnswer(estimatedDataBufSize + 256, false);

    qDebug() << QObject::tr("Reading from device took %1. Estimated data size is %2")
                .arg(readTimer.elapsed())
                .arg(estimatedDataBufSize)
                .toStdString().c_str();

    readTimer.restart();

    auto dataStrResponse = dataStr.mid(10).toLocal8Bit();
    int bufSize = estimatedDataBufSize;

    qDebug() << QObject::tr("Data transform took %1.\r\nData size is %2")
                .arg(readTimer.elapsed())
                .arg(dataStrResponse.size())
                .toStdString().c_str();

    resetAIDataBuffers();

    int i = 0, j = 0, k = 0, l = 0;

    unsigned int activeChannelsSize = activeChannels.size();
    unsigned int srat               = mAIChannelsSamplingFreq;

    for (; i != activeChannelsSize; ){
        (*this)[activeChannels[i]].ACQuisitionData = new double[srat];
        ++i;
    }

    for (; j != bufSize - 2; ) {
        short untransformedVal = (short)dataStrResponse[j] | ((short)dataStrResponse[j + 1] << 8);

        (*this)[activeChannels[k]].ACQuisitionData[l] = (*this)[activeChannels[k]].getScaleValue(untransformedVal);

        if(++k == activeChannelsSize)
            k = 0;

        j += 2;
        if (l % activeChannelsSize == 0)
            ++l;
    }
}

QVector<int> AgU25xxAIChannelSet::getNumEnabledChannels()
{
    QVector<int> res;
    int i = 0;
    for (; i != 4; ) {
        if ((*this)[i].isEnabled())
            res.push_back(i);
        ++i;
    }

    mAIChannelsEnabledCount = res.size();

    return res;
}

int AgU25xxAIChannelSet::getSamplingRate()
{
    return mDriver->RequestQuery(mACQuireCommands.cmdGetSamplingrate()).toInt();
}

QString AgU25xxAIChannelSet::readAgU25xxIEEEBlock()
{
    QString strResponse = mDriver->ReceiveDeviceAnswer(8000000, false);
    QString dataStr     = strResponse.mid(10);

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
