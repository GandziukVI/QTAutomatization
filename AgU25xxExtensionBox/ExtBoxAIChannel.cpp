#include "ExtBoxAIChannel.h"

ExtBoxAIChannels::ExtBoxAIChannels()
    : AIChannels(NULL),
      mChannelModeSwitch(NULL),
      mFilter(NULL),
      mGainAmplifier(NULL)
{
}

ExtBoxAIChannels::ExtBoxAIChannels(AgilentU25xx &device)
{
    AIChannels   = &device.AInChannelSet;

    mPulseBit    = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG04][0];
    mSetResetBit = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG04][1];

    mSelectorA0  = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG02][0];
    mSelectorA1  = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG02][1];

    mChannelModeSwitch = new ExtBoxAIChannelModeSwitch(*mPulseBit, *mSetResetBit, *mSelectorA0, *mSelectorA1);

    mFilter = new ExtBoxFilter(device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG01]);

    mHOLD_CS = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG03][2];
    mHOLD_CS->setBit(false);

    mGainAmplifier = new ExtBoxGainAmplifier(device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG03]);

    mLatchPulseBit = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG04][2];
    mAInLatch      = new ExtBoxAnalogInLatch(*mSelectorA0, *mSelectorA1, *mLatchPulseBit);
}

ExtBoxAIChannels::~ExtBoxAIChannels()
{
    delete mChannelModeSwitch;
    delete mAInLatch;
    delete mFilter;
    delete mGainAmplifier;
}
