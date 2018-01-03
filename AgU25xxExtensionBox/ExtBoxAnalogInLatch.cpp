#include "ExtBoxAnalogInLatch.h"
#include "AgU25xxExtBoxException.h"

#include <AgU25xxDefinitions.h>

ExtBoxAnalogInLatch::ExtBoxAnalogInLatch()
    : ExtBoxILatch(),
      Selector_ADC_A0(NULL),
      Selector_ADC_A1(NULL),
      LatchPulseBit(NULL)
{

}

ExtBoxAnalogInLatch::ExtBoxAnalogInLatch(AgU25xxDIGitalBit &selectorA0, AgU25xxDIGitalBit &selectorA1, AgU25xxDIGitalBit &latchPulseBit)
    : ExtBoxILatch()
{
    Selector_ADC_A0 = &selectorA0;
    Selector_ADC_A1 = &selectorA1;
    LatchPulseBit   = &latchPulseBit;
}

void ExtBoxAnalogInLatch::PulseLatchForChannel(AgU25xxEnumAIChannels channelName)
{
    if (Selector_ADC_A0 == NULL || Selector_ADC_A1 == NULL || LatchPulseBit == NULL)
        throw AgU25xxExtBoxException(QString("AIn latch initialization error."));

    switch (channelName) {
    case AgU25xxEnumAIChannels::AIn01:
    {
        Selector_ADC_A0->setBit(false);
        Selector_ADC_A0->setBit(false);
    } break;
    case AgU25xxEnumAIChannels::AIn02:
    {
        Selector_ADC_A0->setBit(true);
        Selector_ADC_A0->setBit(false);
    } break;
    case AgU25xxEnumAIChannels::AIn03:
    {
        Selector_ADC_A0->setBit(false);
        Selector_ADC_A0->setBit(true);
    } break;
    case AgU25xxEnumAIChannels::AIn04:
    {
        Selector_ADC_A0->setBit(true);
        Selector_ADC_A0->setBit(true);
    } break;
    default:
        throw AgU25xxExtBoxException(QString("Invalid AI channel name."));
    }

    LatchPulseBit->bitPulse();
}
