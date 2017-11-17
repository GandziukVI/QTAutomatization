#include "AgU25xxDIGitalChannelSet.h"
#include "AgU25xxException.h"

AgU25xxDIGitalChannelSet::AgU25xxDIGitalChannelSet()
{
    DIGitalChannels = new AgU25xxDIGChannel*[4];
}

AgU25xxDIGitalChannelSet::AgU25xxDIGitalChannelSet(IDeviceIO &driver)
{
    DIGitalChannels = new AgU25xxDIGChannel*[4];

    DIGitalChannels[0] = new AgU25xxDIGChannel(AgU25xxEnumDigitalChannels::DIG01, driver);
    DIGitalChannels[1] = new AgU25xxDIGChannel(AgU25xxEnumDigitalChannels::DIG02, driver);
    DIGitalChannels[2] = new AgU25xxDIGChannel(AgU25xxEnumDigitalChannels::DIG03, driver);
    DIGitalChannels[3] = new AgU25xxDIGChannel(AgU25xxEnumDigitalChannels::DIG04, driver);
}

AgU25xxDIGitalChannelSet::~AgU25xxDIGitalChannelSet()
{
    delete[] DIGitalChannels;
}

AgU25xxDIGChannel &AgU25xxDIGitalChannelSet::operator [] (const int index)
{
    if(index < 0 || index > 3)
        throw AgU25xxException(QString("Invalid index."));

    return *DIGitalChannels[index];
}

AgU25xxDIGChannel &AgU25xxDIGitalChannelSet::operator [] (const AgU25xxEnumDigitalChannels channelID)
{
    return *DIGitalChannels[(int)channelID];
}
