#include "AgU25xxDIGitalChannelSet.h"
#include "AgU25xxException.h"

AgU25xxDIGitalChannelSet::AgU25xxDIGitalChannelSet()
{
    DIGitalChannels = new AgU25xxDIGChannel*[4];
}

AgU25xxDIGitalChannelSet::AgU25xxDIGitalChannelSet(IDeviceIO &driver)
{
    initialize(driver);
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

void AgU25xxDIGitalChannelSet::initialize(IDeviceIO &driver)
{
    DIGitalChannels = new AgU25xxDIGChannel*[4];

    int i = 0;
    for(; i != 4; ) {
        DIGitalChannels[i] = new AgU25xxDIGChannel(static_cast<AgU25xxEnumDigitalChannels>(i), driver);
        ++i;
    }
}
