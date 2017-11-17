#include "AgU25xxAOChannelSet.h"
#include "AgU25xxException.h"

AgU25xxAOChannelSet::AgU25xxAOChannelSet()
{
}

AgU25xxAOChannelSet::AgU25xxAOChannelSet(IDeviceIO &driver)
{
    AgU25xxAOChannel AOut01 (AgU25xxEnumAOChannels::AOut01, driver);
    AgU25xxAOChannel AOut02 (AgU25xxEnumAOChannels::AOut02, driver);

    AOChannels.push_back(AOut01);
    AOChannels.push_back(AOut02);
}

AgU25xxAOChannel &AgU25xxAOChannelSet::operator [](const int index)
{
    if (index < 0 || index > 1)
        throw AgU25xxException(QString("Invalid index."));

    return AOChannels[index];
}

AgU25xxAOChannel &AgU25xxAOChannelSet::operator [](const AgU25xxEnumAOChannels channelID)
{
    return AOChannels[(int)channelID];
}
