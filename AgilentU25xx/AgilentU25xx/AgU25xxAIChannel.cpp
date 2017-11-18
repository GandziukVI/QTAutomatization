#include "AgU25xxAIChannel.h"
#include "AgU25xxException.h"

#include <QObject>

AgU25xxAIChannel::AgU25xxAIChannel()
    : IAgU25xxSubsystemExtensions(),
      isEnabled(false),
      ACQuisitionData(NULL)
{
    mChPolarity = AgU25xxEnumAIChannelPolaities::BIP;
    mChRange    = AgU25xxEnumAIChannelRanges::Range10V;
}

AgU25xxAIChannel::AgU25xxAIChannel(AgU25xxEnumAIChannels channelName, IDeviceIO& driver)
    : IAgU25xxSubsystemExtensions(),
      isEnabled(false),
      ACQuisitionData(NULL)
{
    mChannelID = channelName;
    mDriver    = &driver;

    mChPolarity = AgU25xxEnumAIChannelPolaities::BIP;
    mChRange    = AgU25xxEnumAIChannelRanges::Range10V;
}

AgU25xxAIChannel::~AgU25xxAIChannel()
{
    if(ACQuisitionData != NULL) {
        delete[] ACQuisitionData;
        ACQuisitionData = NULL;
    }
}

void AgU25xxAIChannel::setSamplingRate(const unsigned int samplingRate)
{
    QString cmd = mACQuireSubsys.cmdSetSamplingRate(samplingRate);
    mDriver->SendCommandRequest(cmd);
}

void AgU25xxAIChannel::setEnabled(const bool enabled)
{
    isEnabled = enabled;

    QString cmd = mROUTeSubSys.cmdSetRouteEnabled(enabled, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

bool AgU25xxAIChannel::getEnabled()
{
    QString query       = mROUTeSubSys.cmdGetRouteEnabled(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    int intResponse = extConvertResponseToIntValue(strResponse);

    isEnabled = intResponse == 1? true : false;
    return isEnabled;
}

void AgU25xxAIChannel::setPolarity(AgU25xxEnumAIChannelPolaities polarity)
{
    mChPolarity = polarity;

    QString cmd = mROUTeSubSys.cmdSetAIChannelPolarity(polarity, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

AgU25xxEnumAIChannelPolaities AgU25xxAIChannel::getPolarity()
{
    QString query       = mROUTeSubSys.cmdGetAIChannelPolarity(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    mChPolarity = extGetAIChannelPolarityEnum(strResponse);
    return mChPolarity;
}

void AgU25xxAIChannel::setRange(AgU25xxEnumAIChannelRanges range)
{
    mChRange = range;

    QString cmd = mROUTeSubSys.cmdSetAIChannelRange(range, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

AgU25xxEnumAIChannelRanges AgU25xxAIChannel::getRange()
{
    QString query = mROUTeSubSys.cmdGetAIChannelRange(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    mChRange = extGetAIChannelRangeEnum(strResponse);
    return mChRange;
}

double AgU25xxAIChannel::getScaleValue(short &val)
{
    double rangeVal = QString(extGetAIChannelRangeStr(mChRange)).toDouble();

    if (mChPolarity == AgU25xxEnumAIChannelPolaities::BIP)
        return 2.0 * val / 65536.0 * rangeVal;
    else if (mChPolarity == AgU25xxEnumAIChannelPolaities::UNIP)
        return (2.0 * val / 65536.0 + 0.5) * rangeVal;
    else
        throw AgU25xxException(QObject::tr("Unable to convert AIn0% value.").arg((int)mChannelID));
}
