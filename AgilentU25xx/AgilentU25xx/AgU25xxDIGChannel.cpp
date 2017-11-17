#include "AgU25xxDIGChannel.h"
#include "AgU25xxException.h"

#include <QThread>

AgU25xxDIGChannel::AgU25xxDIGChannel()
{
}

AgU25xxDIGChannel::AgU25xxDIGChannel(AgU25xxEnumDigitalChannels channelName, IDeviceIO &driver)
{
    mChannelID = channelName;
    mDriver    = &driver;
}

void AgU25xxDIGChannel::setByte(const unsigned short byteVal)
{
    if (byteVal > 255)
        throw AgU25xxException(QString("Unable to write byte. Value is too high."));

    QString cmdSetDIGDirOUT = mCONFigureSubSys.cmdSetDigitalDirection(AgU25xxEnumDigitalDirection::OUTPut, mChannelID);
    mDriver->SendCommandRequest(cmdSetDIGDirOUT);

    QString cmd = mSOURceSubSys.cmdSetDigByte(byteVal, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

unsigned short AgU25xxDIGChannel::getByte()
{
    QString cmdSetDIGDirIN = mCONFigureSubSys.cmdSetDigitalDirection(AgU25xxEnumDigitalDirection::INPut, mChannelID);
    mDriver->SendCommandRequest(cmdSetDIGDirIN);

    QString query = mMEASureSubSys.cmdMeasureDigitalByte(mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    return (unsigned short)extConvertResponseToIntValue(strResponse);
}

void AgU25xxDIGChannel::setBit(bool state, const unsigned short bitNum)
{
    if (bitNum > 7)
        throw AgU25xxException(QString("Unable to write bit. Value is too high."));

    QString cmdSetDIGDirOUT = mCONFigureSubSys.cmdSetDigitalDirection(AgU25xxEnumDigitalDirection::OUTPut, mChannelID);
    mDriver->SendCommandRequest(cmdSetDIGDirOUT);

    QString cmd = mSOURceSubSys.cmdSetDigBit(state, bitNum, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

bool AgU25xxDIGChannel::getBit(const unsigned short bitNum)
{
    if (bitNum > 7)
        throw AgU25xxException(QString("Unable to write bit. Value is too high."));

    QString cmdSetDIGDirIN = mCONFigureSubSys.cmdSetDigitalDirection(AgU25xxEnumDigitalDirection::INPut, mChannelID);
    mDriver->SendCommandRequest(cmdSetDIGDirIN);

    QString query = mMEASureSubSys.cmdMeasureDigitalBit(bitNum, mChannelID);
    QString strResponse = mDriver->RequestQuery(query);

    int intResponse = extConvertResponseToIntValue(strResponse);

    if (intResponse == 0)
        return false;
    else if (intResponse == 1)
        return true;
    else
        throw AgU25xxException(QString("Unable to convert read bit."));
}

void AgU25xxDIGChannel::bitPulse(const unsigned short bitNum, unsigned int msec)
{
    if (bitNum > 7)
        throw AgU25xxException(QString("Unable to pulse bit. Value is too high."));

    int nCounts = (int)((double)msec / 1000.0 * 48000000.0);

    QString cmdSetDIGDirOUT = mCONFigureSubSys.cmdSetDigitalDirection(AgU25xxEnumDigitalDirection::OUTPut, mChannelID);

    QString cmdSetBitToOne  = mSOURceSubSys.cmdSetDigBit(true, bitNum, mChannelID);
    QString cmdSetBitToZero = mSOURceSubSys.cmdSetDigBit(false, bitNum, mChannelID);

    QString cmdConfTimebaseSrc = mCONFigureSubSys.cmdSetTimeBaseSrc(AgU25xxEnumTimeSrcModes::INTernal);
    QString cmdSetTriggerSrc   = mTRIGgerSubSys.cmdSetTriggerInpSrc(AgU25xxEnumTriggerSources::NONE);
    QString cmdSetTriggerType  = mTRIGgerSubSys.cmdSetTriggerInpType(AgU25xxEnumTriggerTypes::DEL);
    QString cmdSetTriggerDCNT  = mTRIGgerSubSys.cmdSetTriggerInputDelayCount(nCounts);

    mDriver->SendCommandRequest(cmdConfTimebaseSrc);
    mDriver->SendCommandRequest(cmdSetDIGDirOUT);
    mDriver->SendCommandRequest(cmdSetBitToOne);
    mDriver->SendCommandRequest(cmdSetTriggerSrc);
    mDriver->SendCommandRequest(cmdSetTriggerType);
    mDriver->SendCommandRequest(cmdSetTriggerDCNT);
    mDriver->SendCommandRequest(cmdSetBitToZero);
}
