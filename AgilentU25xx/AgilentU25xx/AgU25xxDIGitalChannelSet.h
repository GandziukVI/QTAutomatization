#ifndef AGU25XXDIGITALCHANNELSET_H
#define AGU25XXDIGITALCHANNELSET_H

#include "agilentu25xx_global.h"
#include "AgU25xxDIGChannel.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxDIGitalChannelSet
{
public:
    AgU25xxDIGitalChannelSet();
    AgU25xxDIGitalChannelSet(IDeviceIO& driver);
    ~AgU25xxDIGitalChannelSet();

    AgU25xxDIGChannel **DIGitalChannels;

    AgU25xxDIGChannel & operator [] (const int index);
    AgU25xxDIGChannel & operator [] (const AgU25xxEnumDigitalChannels channelID);

    void initialize(IDeviceIO& driver);
};

#endif // AGU25XXDIGITALCHANNELSET_H
