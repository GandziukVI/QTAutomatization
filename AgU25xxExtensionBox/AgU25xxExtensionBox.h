#ifndef AGU25XXEXTENSIONBOX_H
#define AGU25XXEXTENSIONBOX_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"
#include "ExtBoxAIChannelModeSwitch.h"
#include "ExtBoxAnalogInLatch.h"
#include "ExtBoxFilter.h"
#include "ExtBoxGainAmplifier.h"

//#include <AgU25xxDefinitions.h>
#include <AgilentU25xx.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT AgU25xxExtensionBox
{

public:
    AgU25xxExtensionBox ();
    AgU25xxExtensionBox (AgilentU25xx &device);
    ~AgU25xxExtensionBox();

    AgU25xxAIChannelSet *AnalogInChannels;

    void setAInChannelMode(AgU25xxEnumAIChannels channelID, BoxEnumAInChannelModes mode);
    void setAInChannelParams(AgU25xxEnumAIChannels channelID, BoxEnumAInFilterCutOffFrequencies filterCutOff, BoxEnumAInFilterGains filterGain, BoxEnumAInPGAGains pgaGain);
    void setAInChannelFilterCutoff(AgU25xxEnumAIChannels channelID, BoxEnumAInFilterCutOffFrequencies filterCutOff);
    void setAInChannelFilterGain(AgU25xxEnumAIChannels channelID, BoxEnumAInFilterGains filterGain);
    void setAInChannelPGAGain(AgU25xxEnumAIChannels channelID, BoxEnumAInPGAGains pgaGain);

    AgU25xxAOChannelSet *AnalogOutChannels;

    void setAOutVoltage(AgU25xxEnumAOChannels channelID, BoxEnumAOutChannels boxAOutChannelID, double voltage);
    void setAOutEnabled(AgU25xxEnumAOChannels channelID, bool state);
    void switchAOutChannelON(AgU25xxEnumAOChannels channelID);
    void switchAOutChannelOFF(AgU25xxEnumAOChannels channelID);

private:
    AgilentU25xx              *mDevice;

    // To analog in channels configuration
    ExtBoxAIChannelModeSwitch *mAInChannelModeSwitch;
    ExtBoxAnalogInLatch       *mAInLatch;

    ExtBoxFilter              *mAInFilter;
    ExtBoxGainAmplifier       *mAInGainAmplifier;
    AgU25xxDIGitalBit         *mAInLatchPulseBit;
    AgU25xxDIGitalBit         *mAInPulseBit;
    AgU25xxDIGitalBit         *mAInSetResetBit;
    AgU25xxDIGitalBit         *mAInSelectorA0;
    AgU25xxDIGitalBit         *mAInSelectorA1;
    AgU25xxDIGitalBit         *mAInHOLD_CS;

    BoxEnumAInFilterCutOffFrequencies   mAInFilterCutOff;
    BoxEnumAInFilterGains               mAInFilterGain;
    BoxEnumAInPGAGains                  mAInPGAGain;

    // To analog out channels configuration
    AgU25xxDIGitalBit         *mAOutSelectorA0;
    AgU25xxDIGitalBit         *mAOutSelectorA1;
    AgU25xxDIGitalBit         *mAOutSelectorA2;
    AgU25xxDIGitalBit         *mAOutEnable;

    void setBoxAOutSelectors(AgU25xxEnumAOChannels channelID);
    void setBoxAOutActiveChannel(BoxEnumAOutChannels boxAOutChannelID);

    AgU25xxEnumAOChannels    *mCurrentAgU25xxAOutChannel;
    BoxEnumAOutChannels      mCurrentBoxAOutChannel;
};

#endif // AGU25XXEXTENSIONBOX_H
