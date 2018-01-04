#include "ExtBoxGainAmplifier.h"
#include "AgU25xxExtBoxException.h"

ExtBoxGainAmplifier::ExtBoxGainAmplifier()
    : mGain(BoxEnumAInPGAGains::gain1)
{
    mControlChannel = NULL;
}

ExtBoxGainAmplifier::ExtBoxGainAmplifier(AgU25xxDIGChannel &controlChannel)
    : mGain(BoxEnumAInPGAGains::gain1)
{
    mControlChannel = &controlChannel;
}

void ExtBoxGainAmplifier::setGain(BoxEnumAInPGAGains gain)
{
    if (gain < BoxEnumAInPGAGains::gain1 || gain > BoxEnumAInPGAGains::gain100)
        throw AgU25xxExtBoxException(QString("Invalid PGA gain value."));

    mGain = gain;

    mControlChannel->setByte((unsigned short)gain);
}
