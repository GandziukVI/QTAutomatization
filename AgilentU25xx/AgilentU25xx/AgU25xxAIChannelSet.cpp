#include "AgU25xxAIChannelSet.h"
#include "AgU25xxException.h"

AgU25xxAIChannelSet::AgU25xxAIChannelSet()
    : IAgU25xxSubsystemExtensions(),
      mAIChannelsSamplingFreq(1000),
      mAIChannelsEnabledCount(0),
      mAcquisitionIsInProgress(false)
{
    AIChannels = new AgU25xxAIChannel*[4];
}

AgU25xxAIChannelSet::AgU25xxAIChannelSet(IDeviceIO &driver)
    : IAgU25xxSubsystemExtensions(),
      mAIChannelsSamplingFreq(1000),
      mAIChannelsEnabledCount(0),
      mAcquisitionIsInProgress(false)
{
    initialize(driver);
}

AgU25xxAIChannelSet::~AgU25xxAIChannelSet()
{
    int i = 0;
    for(; i != 4; ) {
        delete AIChannels[i];
        AIChannels[i] = NULL;
        ++i;
    }

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
    resetAIDataBuffers();

    // Configuring acquisition
    QString cmdSetSamplingFreq = mACQuireCommands.cmdSetSamplingRate(samplingFreq);
    QString cmdSetPOINOutput   = mACQuireCommands.cmdSetPointsSingleShot(samplingFreq);
    QString cmdStartSingleShot = mRootCommands.cmdStartSingleShotAcquisition();

    mDriver->SendCommandRequest(cmdSetSamplingFreq);
    mDriver->SendCommandRequest(cmdSetPOINOutput);
    mDriver->SendCommandRequest(cmdStartSingleShot);

    QString queryAcquisitionCompletedStatus = mWAVeformCommands.cmdGetAcquisitionConpleteStatus();

    unsigned int *activeChannels      = getEnabledChannelsIndexes();
    unsigned int activeChannelsSize   = mAIChannelsEnabledCount;
    unsigned int estimatedDataBufSize = activeChannelsSize * samplingFreq * 2;

    double                        *activeChannelRanges     = new double[activeChannelsSize];
    AgU25xxEnumAIChannelPolaities *activeChannelPolarities = new AgU25xxEnumAIChannelPolaities[activeChannelsSize];

    converterFunctions = new converterFunctionArray[activeChannelsSize];

    double **tempData = new double*[activeChannelsSize];

    int i = 0, j = 0, k = 0;
    for (; i != activeChannelsSize; ){
        tempData[i] = new double[samplingFreq];

        activeChannelRanges[i]     = QString(extGetAIChannelRangeStr((*this)[activeChannels[i]].getRange())).toDouble();
        activeChannelPolarities[i] = (*this)[activeChannels[i]].getPolarity();

        if (activeChannelPolarities[i] == AgU25xxEnumAIChannelPolaities::BIP)
            converterFunctions[i]      = &AgU25xxAIChannelSet::getAIChannelScaleFunctionBipolar;
        else if (activeChannelPolarities[i] == AgU25xxEnumAIChannelPolaities::UNIP)
            converterFunctions[i]      = &AgU25xxAIChannelSet::getAIChannelScaleFunctionUnipolar;

        ++i;
    }

    // Checking acquisition status
    while(true) {
        QString acquisitionStatus = mDriver->RequestQuery(queryAcquisitionCompletedStatus);
        if (extGetWAWeformSingleShotStatus(acquisitionStatus) == AgU25xxEnumAcquisitionStates::Complete)
            break;
    }

    /* --------------------- */
    /* Reading acquired data */
    /* --------------------- */

    QByteArray dataStr;
    QString    cmdGetData = mWAVeformCommands.cmdQueryAcquisitionData();

    QByteArray dataStrResponse;
    QByteArray::const_iterator iter;
    QByteArray::const_iterator condDataEndIter;

    short untransformedVal;

    mDriver->SendCommandRequest(cmdGetData);
    dataStr = mDriver->ReceiveDeviceAnswer(estimatedDataBufSize + 256, true);

    dataStrResponse = dataStr.mid(10);
    iter            = dataStrResponse.cbegin();
    condDataEndIter = dataStrResponse.cend() - 2;

    for (; ; ) {
        untransformedVal = (short)(*iter | (*(++iter) << 8));
        tempData[j][k]   = (this->*converterFunctions[j])(untransformedVal, *(activeChannelRanges + j));

        if(++j == activeChannelsSize) {
            j = 0; ++k;
        }
        if(iter != condDataEndIter)
            ++iter;
        if(iter == condDataEndIter)
            break;
    }

    i = 0;
    for (; i != activeChannelsSize; ){
        (*this)[*(activeChannels + i)].appendData(tempData[i]);
        ++i;
    }

    if (activeChannelsSize > 1) {
        delete[] activeChannels;
        delete[] activeChannelRanges;
        delete[] activeChannelPolarities;
    }
    else {
        delete activeChannels;
        delete activeChannelRanges;
        delete activeChannelPolarities;
    }

    delete[] converterFunctions;
}

void AgU25xxAIChannelSet::startContinuousAcquisition(const unsigned int &samplingFreq, const unsigned int &outputPoints, const unsigned int &dataBufferCapacity)
{
    mAcquisitionIsInProgress = true;
    resetAIDataBuffers();

    // Configuring acquisition
    QString setSamplingFrequency    = mACQuireCommands.cmdSetSamplingRate(samplingFreq);
    QString setNumOutPutPoints      = mWAVeformCommands.cmdSetContACQPointsNum(outputPoints);
    QString cmdStartContAcquisition = mRootCommands.cmdStartContinuousAcquisition();

    mDriver->SendCommandRequest(setSamplingFrequency);
    mDriver->SendCommandRequest(setNumOutPutPoints);
    mDriver->SendCommandRequest(cmdStartContAcquisition);

    mAIChannelsSamplingFreq = samplingFreq;

    QString queryDataBufferStatus = mWAVeformCommands.cmdGetBufferStatus();

    unsigned int *activeChannels      = getEnabledChannelsIndexes();
    unsigned int activeChannelsSize   = mAIChannelsEnabledCount;
    unsigned int estimatedDataBufSize = activeChannelsSize * outputPoints * 2;

    double                        *activeChannelRanges     = new double[activeChannelsSize];
    AgU25xxEnumAIChannelPolaities *activeChannelPolarities = new AgU25xxEnumAIChannelPolaities[activeChannelsSize];

    converterFunctions = new converterFunctionArray[activeChannelsSize];

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

    QByteArray dataStr;
    QString    cmdGetData = mWAVeformCommands.cmdQueryAcquisitionData();

    QByteArray dataStrResponse;
    QByteArray::const_iterator iter;
    QByteArray::const_iterator condDataEndIter;

    short untransformedVal;

    unsigned int numPointsAcquired;
    while (mAcquisitionIsInProgress) {
        numPointsAcquired = 0;

        double **tempData = new double*[activeChannelsSize];

        i = 0, j = 0, k = 0;
        for (; i != activeChannelsSize; ){
            tempData[i] = new double[samplingFreq];
            ++i;
        }

        /* --------------------- */
        /* Reading acquired data */
        /* --------------------- */

        do {            
            // Checking acquisition status
            while(!checkAcquisitionDataReady()) ;

            if (!mAcquisitionIsInProgress)
                break;

            mDriver->SendCommandRequest(cmdGetData);
            dataStr = mDriver->ReceiveDeviceAnswer(estimatedDataBufSize + 256, true);

            dataStrResponse = dataStr.mid(10);
            iter            = dataStrResponse.cbegin();
            condDataEndIter = dataStrResponse.cend() - 2;

            for (; ; ) {
                untransformedVal = (short)(*iter | (*(++iter) << 8));
                tempData[j][k]   = (this->*converterFunctions[j])(untransformedVal, *(activeChannelRanges + j));

                if(++j == activeChannelsSize) {
                    j = 0; ++k;
                }
                if(iter != condDataEndIter)
                    ++iter;
                if(iter == condDataEndIter)
                    break;
            }

            numPointsAcquired += outputPoints;
        } while (numPointsAcquired != samplingFreq);

        i = 0;
        for (; i != activeChannelsSize; ){
            (*this)[*(activeChannels + i)].appendData(tempData[i], dataBufferCapacity);
            ++i;
        }
    }

    if (activeChannelsSize > 1) {
        delete[] activeChannels;
        delete[] activeChannelRanges;
        delete[] activeChannelPolarities;
    }
    else {
        delete activeChannels;
        delete activeChannelRanges;
        delete activeChannelPolarities;
    }

    delete[] converterFunctions;
}

void AgU25xxAIChannelSet::stopAcquisition()
{
    setAcquisitionState(false);
    QString cmd = mRootCommands.cmdStopAcquisition();
    mDriver->SendCommandRequest(cmd);    
}

bool AgU25xxAIChannelSet::checkAcquisitionDataReady()
{
    QString query = mWAVeformCommands.cmdGetBufferStatus();
    QString response = mDriver->RequestQuery(query);

    if (extGetWAWeformBufferStatus(response) == AgU25xxEnumBufferStatus::DATA)
        return true;
    else if (extGetWAWeformBufferStatus(response) == AgU25xxEnumBufferStatus::OVER)
        throw AgU25xxException(QString("Device buffer overflow."));
    else
        return false;
}

unsigned int *AgU25xxAIChannelSet::getEnabledChannelsIndexes()
{
    unsigned int *temp = new unsigned int[4];

    int i = 0, counter = 0;
    for (; i != 4; ) {
        if ((*this)[i].isEnabled()) {
            temp[i] = i;
            ++counter;
        }
        ++i;
    }

    unsigned int *res = new unsigned int[counter];
    std::copy(temp, temp + counter, res);
    mAIChannelsEnabledCount = counter;

    return res;
}

unsigned int AgU25xxAIChannelSet::getSamplingRate()
{
    return mDriver->RequestQuery(mACQuireCommands.cmdGetSamplingrate()).toUInt();
}

void AgU25xxAIChannelSet::setAcquisitionState(const bool &state)
{
    QMutexLocker acqStateLocker(&mAcqInProgressMutex);
    mAcquisitionIsInProgress = state;
}

bool AgU25xxAIChannelSet::getAcquisitionState()
{
    QMutexLocker acqStateLocker(&mAcqInProgressMutex);
    return mAcquisitionIsInProgress;
}

void AgU25xxAIChannelSet::resetAIDataBuffers()
{
    int i = 0;
    for (; i != 4; ){
        (*this)[i].resetChannelData();
        ++i;
    }
}

double AgU25xxAIChannelSet::getAIChannelScaleFunctionBipolar(const short &val, const double &range) const
{
    return 2.0 * val / 65536.0 * range;
}

double AgU25xxAIChannelSet::getAIChannelScaleFunctionUnipolar(const short &val, const double &range) const
{
    return (2.0 * val / 65536.0 + 0.5) * range;
}
