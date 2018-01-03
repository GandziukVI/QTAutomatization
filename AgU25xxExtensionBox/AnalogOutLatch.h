#ifndef ANALOGOUTLATCH_H
#define ANALOGOUTLATCH_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"
#include "ILatch.h"

#include "agu25xxdefinitions.h"

class AGU25XXEXTENSIONBOXSHARED_EXPORT AnalogOutLatch : public ILatch
{
public:
    AnalogOutLatch();
    void PulseLatchForChannel(AgU25xxEnumAOChannels channelName);
};

#endif // ANALOGOUTLATCH_H
