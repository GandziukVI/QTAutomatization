#include "ExtBoxAIChannelModeSwitch.h"
#include "agu25xxdefinitions.h"
#include "AgU25xxExtBoxException.h"

ExtBoxAIChannelModeSwitch::ExtBoxAIChannelModeSwitch()
    : mPulseBit(NULL),
      mSetResetBit(NULL),
      mSelectorA0(NULL),
      mSelectorA1(NULL)
{
}

ExtBoxAIChannelModeSwitch::ExtBoxAIChannelModeSwitch(AgU25xxDIGitalBit &pulseBit, AgU25xxDIGitalBit &setResetBit, AgU25xxDIGitalBit &selectorA0, AgU25xxDIGitalBit &selectorA1)
{
    mPulseBit    = &pulseBit;
    mSetResetBit = &setResetBit;
    mSelectorA0  = &selectorA0;
    mSelectorA1  = &selectorA1;
}

void ExtBoxAIChannelModeSwitch::setChannelMode(AgU25xxEnumAIChannels channelID, AInChannelModes mode)
{
    if (mPulseBit == NULL || mSetResetBit == NULL || mSelectorA0 == NULL || mSelectorA1 == NULL)
        throw AgU25xxExtBoxException(QString("Error initializing AI channel mode switch."));

    switch (channelID) {
    case AgU25xxEnumAIChannels::AIn01:
    {
        mSelectorA0->setBit(false);
        mSelectorA1->setBit(false);
    } break;
    case AgU25xxEnumAIChannels::AIn02:
    {
        mSelectorA0->setBit(true);
        mSelectorA1->setBit(false);
    } break;
    case AgU25xxEnumAIChannels::AIn03:
    {
        mSelectorA0->setBit(false);
        mSelectorA1->setBit(true);
    } break;
    case AgU25xxEnumAIChannels::AIn04:
    {
        mSelectorA0->setBit(true);
        mSelectorA1->setBit(true);
    } break;
    default:
        throw AgU25xxExtBoxException(QString("Error selecting AI channel."));
    }

    switch (mode) {
    case AInChannelModes::AC:
        mSetResetBit->setBit(false);
        break;
    case AInChannelModes::DC:
        mSetResetBit->setBit(true);
        break;
    default:
        throw AgU25xxExtBoxException(QString("Error selecting AI channel mode."));
    }

    mPulseBit->bitPulse();
}

