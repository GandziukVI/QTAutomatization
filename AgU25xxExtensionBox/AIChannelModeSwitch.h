#ifndef AICHANNELMODESWITCH_H
#define AICHANNELMODESWITCH_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"

#include <AgU25xxDIGitalBit.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT AIChannelModeSwitch
{
public:
    AIChannelModeSwitch();
    AIChannelModeSwitch(AgU25xxDIGitalBit &pulseBit, AgU25xxDIGitalBit &setResetBit, AgU25xxDIGitalBit &selectorA0, AgU25xxDIGitalBit &selectorA1);

    void setChannelMode(AgU25xxEnumAIChannels channelID, AInChannelModes mode);

private:
    AgU25xxDIGitalBit *mPulseBit;
    AgU25xxDIGitalBit *mSetResetBit;
    AgU25xxDIGitalBit *mSelectorA0;
    AgU25xxDIGitalBit *mSelectorA1;
};

#endif // AICHANNELMODESWITCH_H
