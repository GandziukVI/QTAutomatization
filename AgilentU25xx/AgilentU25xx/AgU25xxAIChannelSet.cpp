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
//    QString queryDataBufferReadyDataStatus  = mWAVeformCommands.cmdGetBufferStatus();

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

    int i = 0, j = 0, k = 0, l = 0;
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
    QByteArray dataStr = mDriver->ReceiveDeviceAnswer(estimatedDataBufSize + 256, true);

    QByteArray dataStrResponse      = dataStr.mid(10);//.toLocal8Bit();
    QByteArray::const_iterator iter = dataStrResponse.cbegin();

//    int bufSize          = estimatedDataBufSize;

//    short untransformedVal;
//    for (; iter != dataStrResponse.cend(); ) {
//        untransformedVal = (short)(*iter | (*(++iter) << 8));
//        (*this).AIChannels[k]->ACQuisitionData[l] = (this->*converterFunctions[k])(untransformedVal, activeChannelRanges[k]);

//        if(++k == activeChannelsSize) {
//            k = 0; ++l;
//        }

//        ++iter;
//    }

//    delete[] converterFunctions;

//    qDebug() << QObject::tr("All data transformation took %1.")
//                .arg(readTimer.elapsed())
//                .toStdString().c_str();
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
