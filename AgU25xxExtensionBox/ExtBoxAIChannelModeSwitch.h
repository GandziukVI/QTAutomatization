#ifndef EXTBOXAICHANNELMODESWITCH_H
#define EXTBOXAICHANNELMODESWITCH_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"

#include <AgU25xxDIGitalBit.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT ExtBoxAIChannelModeSwitch
{
public:
    ExtBoxAIChannelModeSwitch();
    ExtBoxAIChannelModeSwitch(AgU25xxDIGitalBit &pulseBit, AgU25xxDIGitalBit &setResetBit, AgU25xxDIGitalBit &selectorA0, AgU25xxDIGitalBit &selectorA1);

    void setChannelMode(AgU25xxEnumAIChannels channelID, BoxEnumAInChannelModes mode);

private:
    AgU25xxDIGitalBit *mPulseBit;
    AgU25xxDIGitalBit *mSetResetBit;
    AgU25xxDIGitalBit *mSelectorA0;
    AgU25xxDIGitalBit *mSelectorA1;
};

#endif // EXTBOXAICHANNELMODESWITCH_H
