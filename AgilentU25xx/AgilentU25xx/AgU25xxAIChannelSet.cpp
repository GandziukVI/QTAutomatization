#include "AgU25xxAIChannelSet.h"
#include "AgU25xxException.h"

AgU25xxAIChannelSet::AgU25xxAIChannelSet()
{
}

AgU25xxAIChannelSet::AgU25xxAIChannelSet(IDeviceIO &driver)
{
    AgU25xxAIChannel AIn01(AgU25xxEnumAIChannels::AIn01, driver);
    AgU25xxAIChannel AIn02(AgU25xxEnumAIChannels::AIn02, driver);
    AgU25xxAIChannel AIn03(AgU25xxEnumAIChannels::AIn03, driver);
    AgU25xxAIChannel AIn04(AgU25xxEnumAIChannels::AIn04, driver);

    AIChannels.push_back(AIn01);
    AIChannels.push_back(AIn01);
    AIChannels.push_back(AIn01);
    AIChannels.push_back(AIn01);
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
