#ifndef PROGRAMMABLEGAINAMPLIFIER_H
#define PROGRAMMABLEGAINAMPLIFIER_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"

#include <AgU25xxDIGChannel.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT GainAmplifier
{
public:
    GainAmplifier();
    GainAmplifier(AgU25xxDIGChannel &controlChannel);

    void setGain(PGAGains gain);

private:
    AgU25xxDIGChannel *mControlChannel;
    PGAGains          mGain;
};

#endif // PROGRAMMABLEGAINAMPLIFIER_H
