#include "AgU25xxExtensionBox.h"
#include "AgU25xxExtBoxException.h"

AgU25xxExtensionBox::AgU25xxExtensionBox()
    : mDevice(NULL),
      AnalogInChannels(NULL),
      AnalogOutChannels(NULL),
      mAInChannelModeSwitch(NULL),
      mAInFilter(NULL),
      mAInGainAmplifier(NULL),
      mAInFilterCutOff(BoxEnumAInFilterCutOffFrequencies::Freq_150kHz),
      mAInFilterGain(BoxEnumAInFilterGains::gain1),
      mAInPGAGain(BoxEnumAInPGAGains::gain1),
      isChannelInit(false),
      mCurrentBoxAOutChannel(BoxEnumAOutChannels::NotSet)
{
}

AgU25xxExtensionBox::AgU25xxExtensionBox(AgilentU25xx &device)
    : mAInFilterCutOff(BoxEnumAInFilterCutOffFrequencies::Freq_150kHz),
      mAInFilterGain(BoxEnumAInFilterGains::gain1),
      mAInPGAGain(BoxEnumAInPGAGains::gain1),
      isChannelInit(false),
      mCurrentBoxAOutChannel(BoxEnumAOutChannels::NotSet)
{
    mDevice = &device;

    AnalogInChannels  = &device.AInChannelSet;
    AnalogOutChannels = &device.AOutChannelSet;

    mAInPulseBit    = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG04][0];
    mAInSetResetBit = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG04][1];

    mAInSelectorA0  = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG02][0];
    mAInSelectorA1  = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG02][1];

    mAInChannelModeSwitch = new ExtBoxAIChannelModeSwitch(*mAInPulseBit, *mAInSetResetBit, *mAInSelectorA0, *mAInSelectorA1);

    mAInFilter = new ExtBoxFilter(device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG01]);

    mAInHOLD_CS = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG03][2];
    mAInHOLD_CS->setBit(false);

    mAInGainAmplifier = new ExtBoxGainAmplifier(device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG03]);

    mAInLatchPulseBit = &device.DIGitalChannelSet[AgU25xxEnumDigitalChannels::DIG04][2];
    mAInLatch      = new ExtBoxAnalogInLatch(*mAInSelectorA0, *mAInSelectorA1, *mAInLatchPulseBit);

    int i = 0;
    for ( ; i != 2;) {
        device.AOutChannelSet.AOChannels[i]->setPolarity(AgU25xxEnumAOChannelPolarities::BIP);
    }
}

AgU25xxExtensionBox::~AgU25xxExtensionBox()
{
    if (mAInChannelModeSwitch != NULL) {
        delete mAInChannelModeSwitch;
        mAInChannelModeSwitch = NULL;
    }
    if (mAInLatch != NULL) {
        delete mAInLatch;
        mAInLatch = NULL;
    }
    if (mAInFilter != NULL) {
        delete mAInFilter;
        mAInFilter = NULL;
    }
    if (mAInGainAmplifier != NULL) {
        delete mAInGainAmplifier;
        mAInGainAmplifier = NULL;
    }
    if (mCurrentAgU25xxAOutChannel != NULL) {
        delete mCurrentAgU25xxAOutChannel;
        mCurrentAgU25xxAOutChannel = NULL;
    }
}

void AgU25xxExtensionBox::setAInChannelMode(AgU25xxEnumAIChannels channelID, BoxEnumAInChannelModes mode)
{
    if (mAInChannelModeSwitch != NULL) {
        mAInChannelModeSwitch->setChannelMode(channelID, mode);
    }
    else
        throw AgU25xxExtBoxException(QString("Unable to switch channel mode."));
}

void AgU25xxExtensionBox::setAInChannelParams(AgU25xxEnumAIChannels channelID, BoxEnumAInFilterCutOffFrequencies filterCutOff, BoxEnumAInFilterGains filterGain, BoxEnumAInPGAGains pgaGain)
{
    mAInFilterCutOff = filterCutOff;
    mAInFilterGain   = filterGain;
    mAInPGAGain      = pgaGain;

    mAInFilter->setCutOffFreqAndGain(filterCutOff, filterGain);
    mAInGainAmplifier->setGain(pgaGain);
    mAInLatch->PulseLatchForChannel(channelID);
}

void AgU25xxExtensionBox::setAInChannelFilterCutoff(AgU25xxEnumAIChannels channelID, BoxEnumAInFilterCutOffFrequencies filterCutOff)
{
    mAInFilterCutOff = filterCutOff;
    setAInChannelParams(channelID, mAInFilterCutOff, mAInFilterGain, mAInPGAGain);
}

void AgU25xxExtensionBox::setAInChannelFilterGain(AgU25xxEnumAIChannels channelID, BoxEnumAInFilterGains filterGain)
{
    mAInFilterGain = filterGain;
    setAInChannelParams(channelID, mAInFilterCutOff, mAInFilterGain, mAInPGAGain);
}

void AgU25xxExtensionBox::setAInChannelPGAGain(AgU25xxEnumAIChannels channelID, BoxEnumAInPGAGains pgaGain)
{
    mAInPGAGain = pgaGain;
    setAInChannelParams(channelID, mAInFilterCutOff, mAInFilterGain, mAInPGAGain);
}

void AgU25xxExtensionBox::setAOutVoltage(AgU25xxEnumAOChannels channelID, BoxEnumAOutChannels boxAOutChannelID, double voltage)
{
    setBoxAOutSelectors(channelID);
    setBoxAOutActiveChannel(boxAOutChannelID);

    if (voltage < -10.0)
        voltage = -10.0;
    else if (voltage > 10.0)
        voltage = 10.0;

    mDevice->AOutChannelSet[channelID].setDCVoltage(voltage);
}

void AgU25xxExtensionBox::setAOutEnabled(AgU25xxEnumAOChannels channelID, bool state)
{
    mDevice->AOutChannelSet[channelID].setEnabled(state);

    setBoxAOutSelectors(channelID);
    mAOutEnable->setBit(state);
}

void AgU25xxExtensionBox::switchAOutChannelON(AgU25xxEnumAOChannels channelID)
{
    mDevice->AOutChannelSet[channelID].setOutpON();
}

void AgU25xxExtensionBox::switchAOutChannelOFF(AgU25xxEnumAOChannels channelID)
{
    mDevice->AOutChannelSet[channelID].setOutpOFF();
}

void AgU25xxExtensionBox::setBoxAOutSelectors(AgU25xxEnumAOChannels channelID)
{      
    switch (channelID) {
    case AgU25xxEnumAOChannels::AOut01:
    {
        mAOutSelectorA0 = &mDevice->DIGitalChannelSet[0][4];
        mAOutSelectorA1 = &mDevice->DIGitalChannelSet[0][5];
        mAOutSelectorA2 = &mDevice->DIGitalChannelSet[0][6];
        mAOutEnable     = &mDevice->DIGitalChannelSet[0][7];
    } break;
    case AgU25xxEnumAOChannels::AOut02:
    {
        mAOutSelectorA0 = &mDevice->DIGitalChannelSet[0][0];
        mAOutSelectorA1 = &mDevice->DIGitalChannelSet[0][1];
        mAOutSelectorA2 = &mDevice->DIGitalChannelSet[0][2];
        mAOutEnable     = &mDevice->DIGitalChannelSet[0][3];
    } break;
    default:
        throw AgU25xxException(QString("Unable to select box AOut channel."));
    }

    if (!isChannelInit) {
        isChannelInit              = true;
        mCurrentAgU25xxAOutChannel = channelID;
        mCurrentBoxAOutChannel     = BoxEnumAOutChannels::NotSet;
    }
    else if (channelID != mCurrentAgU25xxAOutChannel) {
        mCurrentAgU25xxAOutChannel = channelID;
        mCurrentBoxAOutChannel     = BoxEnumAOutChannels::NotSet;
    }
}


void AgU25xxExtensionBox::setBoxAOutActiveChannel(BoxEnumAOutChannels boxAOutChannelID)
{
    if (boxAOutChannelID != mCurrentBoxAOutChannel) {
        switch (boxAOutChannelID) {
        case BoxEnumAOutChannels::BOX_AOut_01:
        {
            mAOutSelectorA0->setBit(false);
            mAOutSelectorA1->setBit(false);
            mAOutSelectorA2->setBit(false);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_02:
        {
            mAOutSelectorA0->setBit(true);
            mAOutSelectorA1->setBit(false);
            mAOutSelectorA2->setBit(false);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_03:
        {
            mAOutSelectorA0->setBit(false);
            mAOutSelectorA1->setBit(true);
            mAOutSelectorA2->setBit(false);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_04:
        {
            mAOutSelectorA0->setBit(true);
            mAOutSelectorA1->setBit(true);
            mAOutSelectorA2->setBit(false);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_05:
        {
            mAOutSelectorA0->setBit(false);
            mAOutSelectorA1->setBit(false);
            mAOutSelectorA2->setBit(true);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_06:
        {
            mAOutSelectorA0->setBit(true);
            mAOutSelectorA1->setBit(false);
            mAOutSelectorA2->setBit(true);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_07:
        {
            mAOutSelectorA0->setBit(false);
            mAOutSelectorA1->setBit(true);
            mAOutSelectorA2->setBit(true);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_08:
        {
            mAOutSelectorA0->setBit(true);
            mAOutSelectorA1->setBit(true);
            mAOutSelectorA2->setBit(true);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_09:
        {
            mAOutSelectorA0->setBit(false);
            mAOutSelectorA1->setBit(false);
            mAOutSelectorA2->setBit(false);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_10:
        {
            mAOutSelectorA0->setBit(true);
            mAOutSelectorA1->setBit(false);
            mAOutSelectorA2->setBit(false);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_11:
        {
            mAOutSelectorA0->setBit(false);
            mAOutSelectorA1->setBit(true);
            mAOutSelectorA2->setBit(false);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_12:
        {
            mAOutSelectorA0->setBit(true);
            mAOutSelectorA1->setBit(true);
            mAOutSelectorA2->setBit(false);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_13:
        {
            mAOutSelectorA0->setBit(false);
            mAOutSelectorA1->setBit(false);
            mAOutSelectorA2->setBit(true);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_14:
        {
            mAOutSelectorA0->setBit(true);
            mAOutSelectorA1->setBit(false);
            mAOutSelectorA2->setBit(true);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_15:
        {
            mAOutSelectorA0->setBit(false);
            mAOutSelectorA1->setBit(true);
            mAOutSelectorA2->setBit(true);
        } break;
        case BoxEnumAOutChannels::BOX_AOut_16:
        {
            mAOutSelectorA0->setBit(true);
            mAOutSelectorA1->setBit(true);
            mAOutSelectorA2->setBit(true);
        } break;
        case BoxEnumAOutChannels::NotSet:
        {
        } break;
        default:
            throw AgU25xxExtBoxException(QString("Unable to conf. BOX output hcannel."));
        }

        mCurrentBoxAOutChannel = boxAOutChannelID;
    }
}
