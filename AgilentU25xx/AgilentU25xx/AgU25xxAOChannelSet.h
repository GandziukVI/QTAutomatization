#ifndef AGU25XXAOCHANNELSET_H
#define AGU25XXAOCHANNELSET_H

#include "agilentu25xx_global.h"
#include "AgU25xxAOChannel.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxAOChannelSet
{
public:
    AgU25xxAOChannelSet();
    AgU25xxAOChannelSet(IDeviceIO& driver);
    ~AgU25xxAOChannelSet();

    AgU25xxAOChannel **AOChannels;

    AgU25xxAOChannel &operator [] (const int index);
    AgU25xxAOChannel &operator [] (const AgU25xxEnumAOChannels channelID);
};

#endif // AGU25XXAOCHANNELSET_H
