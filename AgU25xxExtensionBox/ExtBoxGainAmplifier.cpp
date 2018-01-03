#include "ExtBoxGainAmplifier.h"
#include "AgU25xxExtBoxException.h"

ExtBoxGainAmplifier::ExtBoxGainAmplifier()
    : mGain(PGAGains::gain1)
{
    mControlChannel = NULL;
}

ExtBoxGainAmplifier::ExtBoxGainAmplifier(AgU25xxDIGChannel &controlChannel)
    : mGain(PGAGains::gain1)
{
    mControlChannel = &controlChannel;
}

void ExtBoxGainAmplifier::setGain(PGAGains gain)
{
    if (gain < PGAGains::gain1 || gain > PGAGains::gain100)
        throw AgU25xxExtBoxException(QString("Invalid PGA gain value."));

    mGain = gain;

    mControlChannel->setByte((unsigned short)gain);
}
