#include "AgU25xxAOChannel.h"
#include "AgU25xxException.h"

AgU25xxAOChannel::AgU25xxAOChannel()
    : IAgU25xxSubsystemExtensions()
{
//    regExDouble = new QRegularExpression(QString("[+\\-]?(?:0|[1-9]\\d*)(?:\\.\\d*)?(?:[eE][+\\-]?\\d+)?"), QRegularExpression::MultilineOption);
}

AgU25xxAOChannel::AgU25xxAOChannel(AgU25xxEnumAOChannels channelName, IDeviceIO &driver)
    : IAgU25xxSubsystemExtensions()
{
//    regExDouble = new QRegularExpression(QString("[+\\-]?(?:0|[1-9]\\d*)(?:\\.\\d*)?(?:[eE][+\\-]?\\d+)?"), QRegularExpression::MultilineOption);

    mChannelID = channelName;
    mDriver    = &driver;
}

AgU25xxAOChannel::~AgU25xxAOChannel()
{
//    delete regExDouble;
}

void AgU25xxAOChannel::setDCVoltage(double voltage)
{
    double realVoltage;

    if (voltage < -10.0)
        realVoltage = -10.0;
    else if(voltage > 10.0)
        realVoltage = 10.0;
    else
        realVoltage = voltage;

    QString cmdSetVoltageLevel    = mSOURceSubSys.cmdSetVoltage(realVoltage, mChannelID);

    mDriver->SendCommandRequest(cmdSetVoltageLevel);
}

double AgU25xxAOChannel::getDCVoltage()
{
    QString cmd         = mSOURceSubSys.cmdGetVoltage(mChannelID);
    QString responseStr = mDriver->RequestQuery(cmd);

    return extConvertResponseToRealValue(responseStr);
}

void AgU25xxAOChannel::setOutpON()
{
    QString cmd   = mOUTPutSubSys.cmdSetOutputState(AgU25xxEnumOutputState::ON);
    mDriver->SendCommandRequest(cmd);
}

void AgU25xxAOChannel::setOutpOFF()
{
    QString cmd   = mOUTPutSubSys.cmdSetOutputState(AgU25xxEnumOutputState::OFF);
    mDriver->SendCommandRequest(cmd);
}

void AgU25xxAOChannel::setEnabled(bool enabled)
{
    QString cmd = mROUTeSubSys.cmdSetRouteEnabled(enabled, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

bool AgU25xxAOChannel::getEnabled()
{
    QString query       = mROUTeSubSys.cmdGetRouteEnabled(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    int intResponse = extConvertResponseToIntValue(strResponse);

    if (intResponse == 0)
        return false;
    else if (intResponse == 1)
        return true;
    else
        throw AgU25xxException(QString("Unable to get Enable state."));
}

void AgU25xxAOChannel::setPolarity(AgU25xxEnumAOChannelPolarities polarity)
{
    QString cmd = mROUTeSubSys.cmdSetAOChannelPolarity(polarity, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

AgU25xxEnumAOChannelPolarities AgU25xxAOChannel::getPolarity()
{
    QString query       = mROUTeSubSys.cmdGetAOChannelPolarity(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    return extGetAOChannelPolarityEnum(strResponse);
}
