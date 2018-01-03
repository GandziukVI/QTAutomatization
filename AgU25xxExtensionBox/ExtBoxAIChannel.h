#ifndef EXTBOXAICHANNEL_H
#define EXTBOXAICHANNEL_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"
#include "ExtBoxFilter.h"
#include "ExtBoxGainAmplifier.h"

#include <AgU25xxDefinitions.h>
#include <AgU25xxAIChannel.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT ExtBoxAIChannel
{
public:
    ExtBoxAIChannel();

private:
    AgU25xxAIChannel    *mAIChannel;
    ExtBoxFilter        *mFilter;
    ExtBoxGainAmplifier *mGainAmplifier;
};

#endif // EXTBOXAICHANNEL_H
