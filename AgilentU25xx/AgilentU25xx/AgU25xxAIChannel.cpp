#include "AgU25xxAIChannel.h"
#include "AgU25xxException.h"

AgU25xxAIChannel::AgU25xxAIChannel()
    : IAgU25xxSubsystemExtensions()
{
    regExDouble = new QRegularExpression(QString("[+\\-]?(?:0|[1-9]\\d*)(?:\\.\\d*)?(?:[eE][+\\-]?\\d+)?"), QRegularExpression::MultilineOption);
}

AgU25xxAIChannel::AgU25xxAIChannel(AgU25xxEnumAIChannels channelName, IDeviceIO& driver)
    : IAgU25xxSubsystemExtensions()
{
    regExDouble = new QRegularExpression(QString("[+\\-]?(?:0|[1-9]\\d*)(?:\\.\\d*)?(?:[eE][+\\-]?\\d+)?"), QRegularExpression::MultilineOption);

    mChannelID = channelName;
    mDriver    = &driver;
}

AgU25xxAIChannel::~AgU25xxAIChannel()
{
    delete regExDouble;
}

void AgU25xxAIChannel::setSamplingRate(const unsigned int samplingRate)
{
    QString cmd = mACQuireSubsys.cmdSetSamplingRate(samplingRate);
    mDriver->SendCommandRequest(cmd);
}

void AgU25xxAIChannel::setEnabled(const bool enabled)
{
    QString cmd = mROUTeSubSys.cmdSetRouteEnabled(enabled, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

bool AgU25xxAIChannel::getEnabled()
{
    QString query       = mROUTeSubSys.cmdGetRouteEnabled(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    int intResponse = convertResponseToIntValue(strResponse);

    return intResponse == 1? true : false;
}

void AgU25xxAIChannel::setPolarity(AgU25xxEnumAIChannelPolaities polarity)
{
    QString cmd = mROUTeSubSys.cmdSetAIChannelPolarity(polarity, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

AgU25xxEnumAIChannelPolaities AgU25xxAIChannel::getPolarity()
{
    QString query       = mROUTeSubSys.cmdGetAIChannelPolarity(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    return extGetAIChannelPolarityEnum(strResponse);
}

void AgU25xxAIChannel::setRange(AgU25xxEnumAIChannelRanges range)
{
    QString cmd = mROUTeSubSys.cmdSetAIChannelRange(range, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

AgU25xxEnumAIChannelRanges AgU25xxAIChannel::getRange()
{
    QString query = mROUTeSubSys.cmdGetAIChannelRange(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    return extGetAIChannelRangeEnum(strResponse);
}

int AgU25xxAIChannel::convertResponseToIntValue(QString strResponse)
{
    int  intResponse;
    bool conversionIsOk;

    QRegularExpressionMatch responseMatch = regExDouble->match(strResponse);
    if(responseMatch.hasMatch())
        intResponse = responseMatch.captured(0).toInt(&conversionIsOk);
    else
        throw AgU25xxException(QString("Unable to read instrument response."));

    if(conversionIsOk)
        return intResponse;
    else
        throw AgU25xxException(QString("Unable to convert read value."));
}

double AgU25xxAIChannel::convertResponseToRealValue(QString strResponse)
{
    double doubleResponse;
    bool   conversionIsOk;

    QRegularExpressionMatch responseMatch = regExDouble->match(strResponse);
    if(responseMatch.hasMatch())
        doubleResponse = responseMatch.captured(0).toDouble(&conversionIsOk);
    else
        throw AgU25xxException(QString("Unable to read instrument response."));

    if(conversionIsOk)
        return doubleResponse;
    else
        throw AgU25xxException(QString("Unable to convert read value."));
}
