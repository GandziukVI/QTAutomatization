#include "AgU25xxAIChannel.h"
#include "AgU25xxException.h"

#include <QObject>
#include <QMutexLocker>

AgU25xxAIChannel::AgU25xxAIChannel()
    : IAgU25xxSubsystemExtensions(),
      mIsEnabled(false),
      ACQuisitionData(NULL),
      mChRangeValue(10.0)
{
    mChPolarity = AgU25xxEnumAIChannelPolaities::BIP;
    mChRange    = AgU25xxEnumAIChannelRanges::Range10V;

    this->scaleTransformFunc = &AgU25xxAIChannel::getScaleValueBipolar;
}

AgU25xxAIChannel::AgU25xxAIChannel(AgU25xxEnumAIChannels channelName, IDeviceIO& driver)
    : IAgU25xxSubsystemExtensions(),
      mIsEnabled(false),
      ACQuisitionData(NULL),
      mChRangeValue(10.0)
{
    mChannelID = channelName;
    mDriver    = &driver;

    mChPolarity = AgU25xxEnumAIChannelPolaities::BIP;
    mChRange    = AgU25xxEnumAIChannelRanges::Range10V;

    this->scaleTransformFunc = &AgU25xxAIChannel::getScaleValueBipolar;
}

AgU25xxAIChannel::~AgU25xxAIChannel()
{
    if (ACQuisitionData != NULL) {
        delete[] ACQuisitionData;
        ACQuisitionData = NULL;
    }

    resetScaleTransformFunction();
}

void AgU25xxAIChannel::setSamplingRate(const unsigned int samplingRate)
{
    QString cmd = mACQuireSubsys.cmdSetSamplingRate(samplingRate);
    mDriver->SendCommandRequest(cmd);
}

void AgU25xxAIChannel::setEnabled(const bool enabled)
{
    mIsEnabled = enabled;

    QString cmd = mROUTeSubSys.cmdSetRouteEnabled(enabled, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

bool AgU25xxAIChannel::queryEnabled()
{
    QString query       = mROUTeSubSys.cmdGetRouteEnabled(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    int intResponse = extConvertResponseToIntValue(strResponse);

    mIsEnabled = intResponse == 1? true : false;
    return mIsEnabled;
}

bool AgU25xxAIChannel::isEnabled()
{
    return mIsEnabled;
}

void AgU25xxAIChannel::setPolarity(AgU25xxEnumAIChannelPolaities polarity)
{
    mChPolarity = polarity;

    resetScaleTransformFunction();
    setScaleTransformFunction(polarity);

    QString cmd = mROUTeSubSys.cmdSetAIChannelPolarity(polarity, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

AgU25xxEnumAIChannelPolaities AgU25xxAIChannel::queryPolarity()
{
    QString query       = mROUTeSubSys.cmdGetAIChannelPolarity(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    mChPolarity = extGetAIChannelPolarityEnum(strResponse);

    resetScaleTransformFunction();
    setScaleTransformFunction(mChPolarity);

    return mChPolarity;
}

AgU25xxEnumAIChannelPolaities AgU25xxAIChannel::getPolarity()
{
    return mChPolarity;
}

void AgU25xxAIChannel::setRange(AgU25xxEnumAIChannelRanges range)
{
    mChRange      = range;
    mChRangeValue = QString(extGetAIChannelRangeStr(range)).toDouble();

    QString cmd = mROUTeSubSys.cmdSetAIChannelRange(range, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

AgU25xxEnumAIChannelRanges AgU25xxAIChannel::queryRange()
{
    QString query = mROUTeSubSys.cmdGetAIChannelRange(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    mChRange = extGetAIChannelRangeEnum(strResponse);
    mChRangeValue = strResponse.toDouble();
    return mChRange;
}

AgU25xxEnumAIChannelRanges AgU25xxAIChannel::getRange()
{
    return mChRange;
}

void AgU25xxAIChannel::appendData(double *data, unsigned int maxCount)
{
    QMutexLocker dataLocker (&mChannelDataAccessMutex);
    if (mChannelData.size() == maxCount) {
        delete[] mChannelData.first();
        mChannelData.first() = NULL;
        mChannelData.pop_front();
    }

    mChannelData.push_back(data);
}

double *AgU25xxAIChannel::getData()
{
    QMutexLocker dataLocker (&mChannelDataAccessMutex);
    double* data = std::move(mChannelData.first());
    delete[] mChannelData.first();
    mChannelData.first() = NULL;
    mChannelData.pop_front();

    return data;
}

double AgU25xxAIChannel::getScaleValueBipolar(const short &val) const
{
    return 2.0 * val / 65536.0 * mChRangeValue;
}

double AgU25xxAIChannel::getScaleValueUnipolar(const short &val) const
{
    return (2.0 * val / 65536.0 + 0.5) * mChRangeValue;
}

void AgU25xxAIChannel::setScaleTransformFunction(const AgU25xxEnumAIChannelPolaities &polarity)
{
    if (polarity == AgU25xxEnumAIChannelPolaities::BIP)
        this->scaleTransformFunc = &AgU25xxAIChannel::getScaleValueBipolar;
    else if (polarity == AgU25xxEnumAIChannelPolaities::UNIP)
        this->scaleTransformFunc = &AgU25xxAIChannel::getScaleValueUnipolar;
    else
        throw AgU25xxException(QString("Unable to get scale transform function."));
}

void AgU25xxAIChannel::resetScaleTransformFunction()
{
    if (this->scaleTransformFunc != NULL) {
        this->scaleTransformFunc = NULL;
    }
}
