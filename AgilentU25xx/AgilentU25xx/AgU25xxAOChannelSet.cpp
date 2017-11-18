#include "AgU25xxAOChannelSet.h"
#include "AgU25xxException.h"

AgU25xxAOChannelSet::AgU25xxAOChannelSet()
{
    AOChannels = new AgU25xxAOChannel*[2];
}

AgU25xxAOChannelSet::AgU25xxAOChannelSet(IDeviceIO &driver)
{
    initialize(driver);
}

AgU25xxAOChannelSet::~AgU25xxAOChannelSet()
{
    delete[] AOChannels;
}

AgU25xxAOChannel &AgU25xxAOChannelSet::operator [](const int index)
{
    if (index < 0 || index > 1)
        throw AgU25xxException(QString("Invalid index."));

    return *AOChannels[index];
}

AgU25xxAOChannel &AgU25xxAOChannelSet::operator [](const AgU25xxEnumAOChannels channelID)
{
    return *AOChannels[(int)channelID];
}

void AgU25xxAOChannelSet::initialize(IDeviceIO &driver)
{
    AOChannels = new AgU25xxAOChannel*[2];

    int i = 0;
    for (; i!= 2; ) {
        AOChannels[i] = new AgU25xxAOChannel(static_cast<AgU25xxEnumAOChannels>(i), driver);
        ++i;
    }
}
