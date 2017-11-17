#include "AgU25xxAOChannelSet.h"
#include "AgU25xxException.h"

AgU25xxAOChannelSet::AgU25xxAOChannelSet()
{
    AOChannels = new AgU25xxAOChannel[2];
}

AgU25xxAOChannelSet::AgU25xxAOChannelSet(IDeviceIO &driver)
{
    AOChannels = new AgU25xxAOChannel[2];

    AOChannels[0] = AgU25xxAOChannel(AgU25xxEnumAOChannels::AOut01, driver);
    AOChannels[1] = AgU25xxAOChannel(AgU25xxEnumAOChannels::AOut02, driver);
}

AgU25xxAOChannelSet::~AgU25xxAOChannelSet()
{
    delete[] AOChannels;
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
