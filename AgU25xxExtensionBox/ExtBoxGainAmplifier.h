#ifndef EXTBOXGAINAMPLIFIER_H
#define EXTBOXGAINAMPLIFIER_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"

#include <AgU25xxDIGChannel.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT ExtBoxGainAmplifier
{
public:
    ExtBoxGainAmplifier();
    ExtBoxGainAmplifier(AgU25xxDIGChannel &controlChannel);

    void setGain(PGAGains gain);

private:
    AgU25xxDIGChannel *mControlChannel;
    PGAGains          mGain;
};

#endif // EXTBOXGAINAMPLIFIER_H
