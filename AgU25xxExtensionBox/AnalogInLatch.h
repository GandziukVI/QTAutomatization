#ifndef ANALOGINLATCH_H
#define ANALOGINLATCH_H

#include "agu25xxextensionbox_global.h"
#include "ILatch.h"

#include <AgU25xxDIGitalBit.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT AnalogInLatch : public ILatch
{
public:
    AnalogInLatch();
    AnalogInLatch(AgU25xxDIGitalBit &selectorA0, AgU25xxDIGitalBit &selectorA1, AgU25xxDIGitalBit &latchPulseBit);
    void PulseLatchForChannel(AgU25xxEnumAIChannels channelName);

private:
    AgU25xxDIGitalBit *Selector_ADC_A0;
    AgU25xxDIGitalBit *Selector_ADC_A1;
    AgU25xxDIGitalBit *LatchPulseBit;
};

#endif // ANALOGINLATCH_H
