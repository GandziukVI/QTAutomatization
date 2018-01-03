#ifndef EXTBOXANALOGINLATCH_H
#define EXTBOXANALOGINLATCH_H

#include "agu25xxextensionbox_global.h"
#include "ILatch.h"

#include <AgU25xxDIGitalBit.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT ExtBoxAnalogInLatch : public ExtBoxILatch
{
public:
    ExtBoxAnalogInLatch();
    ExtBoxAnalogInLatch(AgU25xxDIGitalBit &selectorA0, AgU25xxDIGitalBit &selectorA1, AgU25xxDIGitalBit &latchPulseBit);
    void PulseLatchForChannel(AgU25xxEnumAIChannels channelName);

private:
    AgU25xxDIGitalBit *Selector_ADC_A0;
    AgU25xxDIGitalBit *Selector_ADC_A1;
    AgU25xxDIGitalBit *LatchPulseBit;
};

#endif // EXTBOXANALOGINLATCH_H
