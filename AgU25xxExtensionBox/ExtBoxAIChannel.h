#ifndef EXTBOXAICHANNEL_H
#define EXTBOXAICHANNEL_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"
#include "ExtBoxAIChannelModeSwitch.h"
#include "ExtBoxAnalogInLatch.h"
#include "ExtBoxFilter.h"
#include "ExtBoxGainAmplifier.h"

#include <AgilentU25xx.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT ExtBoxAIChannels
{
public:
    ExtBoxAIChannels();
    ExtBoxAIChannels(AgilentU25xx &device);
    ~ExtBoxAIChannels();

    AgU25xxAIChannelSet *AIChannels;

private:
    ExtBoxAIChannelModeSwitch *mChannelModeSwitch;
    ExtBoxAnalogInLatch       *mAInLatch;

    ExtBoxFilter              *mFilter;
    ExtBoxGainAmplifier       *mGainAmplifier;
    AgU25xxDIGitalBit         *mLatchPulseBit;
    AgU25xxDIGitalBit         *mPulseBit;
    AgU25xxDIGitalBit         *mSetResetBit;
    AgU25xxDIGitalBit         *mSelectorA0;
    AgU25xxDIGitalBit         *mSelectorA1;
    AgU25xxDIGitalBit         *mHOLD_CS;
};

#endif // EXTBOXAICHANNEL_H
