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

    if (channelName == AgU25xxEnumDigitalChannels::DIG01
            || channelName == AgU25xxEnumDigitalChannels::DIG02)
        nBits = 8;
    else if (channelName == AgU25xxEnumDigitalChannels::DIG03
             || channelName == AgU25xxEnumDigitalChannels::DIG04)
        nBits = 4;
    else
        throw AgU25xxException(QString("Unable to initialize BIT array."));

    DIGitalBits = new AgU25xxDIGitalBit*[nBits];

    unsigned short i = 0;
    for (; i != nBits; ) {
        DIGitalBits[i] = new AgU25xxDIGitalBit(channelName, i, driver);
        ++i;
    }
}

AgU25xxDIGChannel::~AgU25xxDIGChannel()
{
    int i = 0;
    for (; i != nBits; ) {
        delete DIGitalBits[i];
        DIGitalBits[i] = NULL;
    }

    delete[] DIGitalBits;
}

AgU25xxDIGitalBit &AgU25xxDIGChannel::operator [](const unsigned short index)
{
    if (index > nBits)
        throw AgU25xxException(QString("Out of range. Index is too large."));

    return *DIGitalBits[index];
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
