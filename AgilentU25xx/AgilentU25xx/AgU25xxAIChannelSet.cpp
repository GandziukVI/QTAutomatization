#include "AgU25xxAIChannelSet.h"
#include "AgU25xxException.h"

AgU25xxAIChannelSet::AgU25xxAIChannelSet()
{
    AIChannels = new AgU25xxAIChannel[4];
}

AgU25xxAIChannelSet::AgU25xxAIChannelSet(IDeviceIO &driver)
{
    AIChannels = new AgU25xxAIChannel[4];

    AIChannels[0] = AgU25xxAIChannel(AgU25xxEnumAIChannels::AIn01, driver);
    AIChannels[1] = AgU25xxAIChannel(AgU25xxEnumAIChannels::AIn02, driver);
    AIChannels[2] = AgU25xxAIChannel(AgU25xxEnumAIChannels::AIn03, driver);
    AIChannels[3] = AgU25xxAIChannel(AgU25xxEnumAIChannels::AIn04, driver);
}

AgU25xxAIChannelSet::~AgU25xxAIChannelSet()
{
    delete[] AIChannels;
}

AgU25xxAIChannel &AgU25xxAIChannelSet::operator [](const int index)
{
    if(index < 0 || index > 3)
        throw AgU25xxException(QString("Invalid index."));

    return AIChannels[index];
}

AgU25xxAIChannel &AgU25xxAIChannelSet::operator [](const AgU25xxEnumAIChannels channelID)
{
    return AIChannels[(int)channelID];
}
