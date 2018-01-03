#include "GainAmplifier.h"
#include "AgU25xxExtBoxException.h"

GainAmplifier::GainAmplifier()
    : mGain(PGAGains::gain1)
{
    mControlChannel = NULL;
}

GainAmplifier::GainAmplifier(AgU25xxDIGChannel &controlChannel)
    : mGain(PGAGains::gain1)
{
    mControlChannel = &controlChannel;
}

void GainAmplifier::setGain(PGAGains gain)
{
    if (gain < PGAGains::gain1 || gain > PGAGains::gain100)
        throw AgU25xxExtBoxException(QString("Invalid PGA gain value."));

    mGain = gain;

    mControlChannel->setByte((unsigned short)gain);
}
