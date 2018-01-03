#ifndef EXTBOXANALOGOUTLATCH_H
#define EXTBOXANALOGOUTLATCH_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"

#include "agu25xxdefinitions.h"

class AGU25XXEXTENSIONBOXSHARED_EXPORT ExtBoxAnalogOutLatch
{
public:
    ExtBoxAnalogOutLatch();
    void PulseLatchForChannel(AgU25xxEnumAOChannels channelName);
};

#endif // EXTBOXANALOGOUTLATCH_H
