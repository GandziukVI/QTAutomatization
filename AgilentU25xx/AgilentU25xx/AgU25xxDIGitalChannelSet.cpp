#include "AgU25xxDIGitalChannelSet.h"
#include "AgU25xxException.h"

AgU25xxDIGitalChannelSet::AgU25xxDIGitalChannelSet()
{
}

AgU25xxDIGitalChannelSet::AgU25xxDIGitalChannelSet(IDeviceIO &driver)
{
    AgU25xxDIGChannel DIG01(AgU25xxEnumDigitalChannels::DIG01, driver);
    AgU25xxDIGChannel DIG02(AgU25xxEnumDigitalChannels::DIG02, driver);
    AgU25xxDIGChannel DIG03(AgU25xxEnumDigitalChannels::DIG03, driver);
    AgU25xxDIGChannel DIG04(AgU25xxEnumDigitalChannels::DIG04, driver);

    DIGitalChannels.push_back(DIG01);
    DIGitalChannels.push_back(DIG02);
    DIGitalChannels.push_back(DIG03);
    DIGitalChannels.push_back(DIG04);
}

AgU25xxDIGChannel &AgU25xxDIGitalChannelSet::operator [](const int index)
{
    if(index < 0 || index > 3)
        throw AgU25xxException(QString("Invalid index."));

    return DIGitalChannels[index];
}

AgU25xxDIGChannel &AgU25xxDIGitalChannelSet::operator [](const AgU25xxEnumDigitalChannels channelID)
{
    return DIGitalChannels[(int)channelID];
}
