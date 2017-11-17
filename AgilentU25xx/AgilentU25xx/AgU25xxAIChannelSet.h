#ifndef AgU25xxEnumAIChannels_H
#define AgU25xxEnumAIChannels_H

#include "agilentu25xx_global.h"
#include "AgU25xxAIChannel.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxEnumAIChannelset
{
public:
    AgU25xxEnumAIChannelset();
    AgU25xxEnumAIChannelset(IDeviceIO& driver);

    QVector<AgU25xxAIChannel> AIChannels;

    AgU25xxAIChannel &operator[](const int index);
    AgU25xxAIChannel &operator[](const AgU25xxEnumAIChannels channelID);
};

#endif // AgU25xxEnumAIChannels_H
