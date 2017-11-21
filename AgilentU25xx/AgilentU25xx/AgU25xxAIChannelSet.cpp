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

    // Configuring acquisition
    QString cmdSetSamplingFreq = mACQuireCommands.cmdSetSamplingRate(samplingFreq);
    QString cmdSetPOINOutput   = mACQuireCommands.cmdSetPointsSingleShot(samplingFreq);
    QString cmdStartSingleShot = mRootCommands.cmdStartSingleShotAcquisition();

    mDriver->SendCommandRequest(cmdSetSamplingFreq);
    mDriver->SendCommandRequest(cmdSetPOINOutput);
    mDriver->SendCommandRequest(cmdStartSingleShot);

    QString queryAcquisitionCompletedStatus = mWAVeformCommands.cmdGetAcquisitionConpleteStatus();

    qDebug() << "Starting data reading.";
    QElapsedTimer readTimer;
    readTimer.start();

    // Checking acquisition status
    while(true) {
        QString acquisitionStatus = mDriver->RequestQuery(queryAcquisitionCompletedStatus);
        if (extGetWAWeformSingleShotStatus(acquisitionStatus) == AgU25xxEnumAcquisitionStates::Complete)
            break;
    }

    readTimer.restart();

    /* --------------------- */
    /* Reading acquired data */
    /* --------------------- */

    QVector<int> activeChannels       = getNumEnabledChannels();
    unsigned int activeChannelsSize   = activeChannels.size();
    unsigned int estimatedDataBufSize = activeChannelsSize * samplingFreq * 2;

    QVector<double>                        activeChannelRanges(activeChannelsSize);
    QVector<AgU25xxEnumAIChannelPolaities> activeChannelPolarities(activeChannelsSize);

    converterFunctions                = new convFunc[activeChannelsSize];

    resetAIDataBuffers();

    int i = 0, j = 0, k = 0;
    for (; i != activeChannelsSize; ){
        (*this)[activeChannels[i]].ACQuisitionData = new double[samplingFreq];

        activeChannelRanges[i]     = QString(extGetAIChannelRangeStr((*this)[activeChannels[i]].getRange())).toDouble();
        activeChannelPolarities[i] = (*this)[activeChannels[i]].getPolarity();

        if (activeChannelPolarities[i] == AgU25xxEnumAIChannelPolaities::BIP)
            converterFunctions[i]      = &AgU25xxAIChannelSet::getAIChannelScaleFunctionBipolar;
        else if (activeChannelPolarities[i] == AgU25xxEnumAIChannelPolaities::UNIP)
            converterFunctions[i]      = &AgU25xxAIChannelSet::getAIChannelScaleFunctionUnipolar;

        ++i;
    }

    QString cmdGetData = mWAVeformCommands.cmdQueryAcquisitionData();
    mDriver->SendCommandRequest(cmdGetData);
    QString dataStr = mDriver->ReceiveDeviceAnswer(estimatedDataBufSize + 256, true);

    QByteArray dataStrResponse      = dataStr.mid(10).toLocal8Bit();
    QByteArray::const_iterator iter = dataStrResponse.cbegin();

    short untransformedVal;
    for (; iter != dataStrResponse.cend() - 1; ) {
        untransformedVal = (short)(*iter | (*(++iter) << 8));
        (*this).AIChannels[j]->ACQuisitionData[k] = (this->*converterFunctions[j])(untransformedVal, activeChannelRanges[j]);

        if(++j == activeChannelsSize) {
            j = 0; ++k;
        }

        ++iter;
    }

    delete[] converterFunctions;

    qDebug() << QObject::tr("All data transformation took %1.")
                .arg(readTimer.elapsed())
                .toStdString().c_str();
}

void AgU25xxAIChannelSet::startContinuousAcquisition(unsigned int samplingFreq, unsigned int outputPoints)
{
    // Configuring acquisition
    QString setSamplingFrequency    = mACQuireCommands.cmdSetSamplingRate(samplingFreq);
    QString setNumOutPutPoints      = mWAVeformCommands.cmdSetContACQPointsNum(outputPoints);
    QString cmdStartContAcquisition = mRootCommands.cmdStartContinuousAcquisition();

    mDriver->SendCommandRequest(setSamplingFrequency);
    mDriver->SendCommandRequest(setNumOutPutPoints);
    mDriver->SendCommandRequest(cmdStartContAcquisition);

    mAIChannelsSamplingFreq = samplingFreq;

    QString queryDataBufferStatus = mWAVeformCommands.cmdGetBufferStatus();

    qDebug() << "Starting data reading.";
    QElapsedTimer readTimer;
    readTimer.start();

    QVector<int> activeChannels       = getNumEnabledChannels();
    unsigned int activeChannelsSize   = activeChannels.size();
    unsigned int estimatedDataBufSize = activeChannelsSize * outputPoints * 2;

    QVector<double>                        activeChannelRanges(activeChannelsSize);
    QVector<AgU25xxEnumAIChannelPolaities> activeChannelPolarities(activeChannelsSize);

    converterFunctions                = new convFunc[activeChannelsSize];

    int i = 0, j = 0, k = 0;
    for (; i != activeChannelsSize; ){
        activeChannelRanges[i]     = QString(extGetAIChannelRangeStr((*this)[activeChannels[i]].getRange())).toDouble();
        activeChannelPolarities[i] = (*this)[activeChannels[i]].getPolarity();

        if (activeChannelPolarities[i] == AgU25xxEnumAIChannelPolaities::BIP)
            converterFunctions[i]      = &AgU25xxAIChannelSet::getAIChannelScaleFunctionBipolar;
        else if (activeChannelPolarities[i] == AgU25xxEnumAIChannelPolaities::UNIP)
            converterFunctions[i]      = &AgU25xxAIChannelSet::getAIChannelScaleFunctionUnipolar;

        ++i;
    }

    QString dataStr;
    QString cmdGetData = mWAVeformCommands.cmdQueryAcquisitionData();
    QByteArray dataStrResponse;
    QByteArray::const_iterator iter;
    short untransformedVal;

    unsigned int numPointsAcquired;
    while (true) {
        numPointsAcquired = 0;

        resetAIDataBuffers();

        i = 0, j = 0, k = 0;
        for (; i != activeChannelsSize; ){
            (*this)[activeChannels[i]].ACQuisitionData = new double[samplingFreq];
            ++i;
        }

        /* --------------------- */
        /* Reading acquired data */
        /* --------------------- */

        readTimer.restart();

        do {
            // Checking acquisition status
            while(true) {
                QString bufferStatus = mDriver->RequestQuery(queryDataBufferStatus);
                if (extGetWAWeformBufferStatus(bufferStatus) == AgU25xxEnumBufferStatus::DATA)
                    break;
            }

            mDriver->SendCommandRequest(cmdGetData);
            dataStr = mDriver->ReceiveDeviceAnswer(estimatedDataBufSize + 256, true);

            dataStrResponse = dataStr.mid(10).toLocal8Bit();
            iter            = dataStrResponse.cbegin();

            for (; iter != dataStrResponse.cend() - 1; ) {
                untransformedVal = (short)(*iter | (*(++iter) << 8));
                (*this).AIChannels[j]->ACQuisitionData[k + numPointsAcquired] = (this->*converterFunctions[j])(untransformedVal, activeChannelRanges[j]);

                if(++j == activeChannelsSize) {
                    j = 0; ++k;
                }

                ++iter;
            }

            numPointsAcquired += outputPoints;
        } while (numPointsAcquired < (samplingFreq - numPointsAcquired));

        qDebug() << QObject::tr("All data transformation took %1.")
                    .arg(readTimer.elapsed())
                    .toStdString().c_str();
    }

    delete[] converterFunctions;
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

    QVector<double>                        activeChannelRanges(activeChannelsSize);
    QVector<AgU25xxEnumAIChannelPolaities> activeChannelPolarities(activeChannelsSize);

    converterFunctions              = new convFunc[activeChannelsSize];

    unsigned int srat               = mAIChannelsSamplingFreq;
//    double       **localData        = new double*[activeChannelsSize];


    for (; i != activeChannelsSize; ){
        (*this)[activeChannels[i]].ACQuisitionData = new double[srat];
//        localData[i]                               = new double[srat];

        activeChannelRanges[i]     = QString(extGetAIChannelRangeStr((*this)[activeChannels[i]].getRange())).toDouble();
        activeChannelPolarities[i] = (*this)[activeChannels[i]].getPolarity();

        if (activeChannelPolarities[i] == AgU25xxEnumAIChannelPolaities::BIP)
            converterFunctions[i]      = &AgU25xxAIChannelSet::getAIChannelScaleFunctionBipolar;
        else if (activeChannelPolarities[i] == AgU25xxEnumAIChannelPolaities::UNIP)
            converterFunctions[i]      = &AgU25xxAIChannelSet::getAIChannelScaleFunctionUnipolar;

        ++i;
    }

    short untransformedVal;

    readTimer.restart();

    for (; j != bufSize - 2; ) {
        untransformedVal = (short)(dataStrResponse[j] | (dataStrResponse[++j] << 8));
        //localData[k][l]  = (this->*converterFunctions[k])(untransformedVal, activeChannelRanges[k]);
        (*this).AIChannels[k]->ACQuisitionData[l] = (this->*converterFunctions[k])(untransformedVal, activeChannelRanges[k]);

        if(++k == activeChannelsSize) {
            k = 0; ++l;
        }

        ++j;
    }

    qDebug() << QObject::tr("Data transform to real values took %1")
                .arg(readTimer.elapsed())
                .toStdString().c_str();

//    delete[] localData;
    delete[] converterFunctions;
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

double AgU25xxAIChannelSet::getAIChannelScaleFunctionBipolar(short &val, double &range)
{
    return 2.0 * val / 65536.0 * range;
}

double AgU25xxAIChannelSet::getAIChannelScaleFunctionUnipolar(short &val, double &range)
{
    return (2.0 * val / 65536.0 + 0.5) * range;
}

//double AgU25xxAIChannelSet::getAIChannelScaleFunction(short &val, double &range, AgU25xxEnumAIChannelPolaities &polarity)
//{
//    if (polarity == AgU25xxEnumAIChannelPolaities::BIP)
//        return 2.0 * val / 65536.0 * range;
//    else if (polarity == AgU25xxEnumAIChannelPolaities::UNIP)
//        return (2.0 * val / 65536.0 + 0.5) * range;
//    else
//        throw AgU25xxException(QString("Unable to convert value."));
//}
