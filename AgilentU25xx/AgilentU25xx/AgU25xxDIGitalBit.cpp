#include "AgU25xxDIGitalBit.h"
#include "AgU25xxException.h"

AgU25xxDIGitalBit::AgU25xxDIGitalBit()
{
}

AgU25xxDIGitalBit::AgU25xxDIGitalBit(AgU25xxEnumDigitalChannels channelName, unsigned short bitNumber, IDeviceIO &driver)
{
    mChannelID = channelName;
    bitNum     = bitNumber;
    mDriver    = &driver;
}

void AgU25xxDIGitalBit::setBit(bool state)
{
    if (bitNum > 7)
        throw AgU25xxException(QString("Unable to write bit. Value is too high."));

    QString cmdSetDIGDirOUT = mCONFigureSubSys.cmdSetDigitalDirection(AgU25xxEnumDigitalDirection::OUTPut, mChannelID);
    mDriver->SendCommandRequest(cmdSetDIGDirOUT);

    QString cmd = mSOURceSubSys.cmdSetDigBit(state, bitNum, mChannelID);
    mDriver->SendCommandRequest(cmd);
}

bool AgU25xxDIGitalBit::getBit()
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

void AgU25xxDIGitalBit::bitPulse(unsigned int msec)
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
