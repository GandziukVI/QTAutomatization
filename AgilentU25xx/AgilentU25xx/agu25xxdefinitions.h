#ifndef AGU25XXDEFINITIONS_H
#define AGU25XXDEFINITIONS_H

#include "agilentu25xx_global.h"

namespace AgU25xxOUTPut
{
    enum class AGILENTU25XXSHARED_EXPORT AOChannels {
        CH01,
        CH02
    };

    enum class AGILENTU25XXSHARED_EXPORT OutputState {
        ON,
        OFF
    };

    enum class AGILENTU25XXSHARED_EXPORT TriggerSources {
        NONE, // Immediate triggering
        EXTD, // Selects the external digital trigger (EXTD_AO_TRIG) pin as the triggering source
        EXTA, // Selects the external analog trigger (EXTA_TRIG) pin as the triggering source
        STRG  // Star triggering
    };

    enum class AGILENTU25XXSHARED_EXPORT TriggerTypes {
        POST, // (Post-trigger): The instrument output is generated immediately after the trigger condition is met.
        DEL   // (Delay-trigger): The instrument output is generated when the delay count reaches zero. The delay count starts immediately after the trigger condition is met.
    };

    enum class AGILENTU25XXSHARED_EXPORT ATRiGgerSources {
        EXTAP,
        CH101,
        CH102,
        CH103,
        CH104
    };

    enum class AGILENTU25XXSHARED_EXPORT ATRiGgerConditions {
        AHIG, // (Above-High- Level triggering): The trigger signal is generated when the analog signal is higher than the high- threshold voltage.
        BLOW, // (Below- Low-Level triggering): The trigger signal is generated when the analog signal is lower than the low- threshold voltage.
        WIND  // (Window (inside region) triggering): The trigger signal is generated when the analog signal falls within the range of the high- threshold and low- threshold voltages.
    };

    enum class AGILENTU25XXSHARED_EXPORT DTRiGgerPolarities {
        POS, // (Positive- edge triggering): The trigger signal is generated when a rising edge is detected in the digital signal.
        NEG  // (Negative- edge triggering): The trigger signal is generated when a falling edge is detected in the digital signal.
    };
}

namespace AgU25xxROUTe
{
    enum class AGILENTU25XXSHARED_EXPORT AnalogInChannels {
        AIn01,
        AIn02,
        AIn03,
        AIn04
    };

    enum class AGILENTU25XXSHARED_EXPORT AnalogInChannelRanges {
        Range10V,
        Range5V,
        Range2_5V,
        Range1_25V
    };

    enum class AGILENTU25XXSHARED_EXPORT AnalogInChannelPolaities {
        BIP,
        UNIP
    };

    enum class AGILENTU25XXSHARED_EXPORT AnalogOutChannels {
        AOut01,
        AOut02
    };

    enum class AGILENTU25XXSHARED_EXPORT AnalogOutChannelRSouRCes {
        INT,
        EXT
    };
}

namespace AgU25xxDIGital
{
    enum class AGILENTU25XXSHARED_EXPORT DigitalDirection {
        INPut,
        OUTPut
    };

    enum class AGILENTU25XXSHARED_EXPORT DigitalChannels {
        DIG01,
        DIG02,
        DIG03,
        DIG04
    };
}

namespace AgU25xxTIMEbase
{
    enum class AGILENTU25XXSHARED_EXPORT TimeSrcModes {
        INTernal,
        EXTernal,
        CCG
    };
}

namespace AgU25xxVOLTage
{
    enum class AGILENTU25XXSHARED_EXPORT VoltageChannels {
        CH01,
        CH02,
        CH03,
        CH04
    };
}

namespace AgU25xxCOUNter
{
    enum class AGILENTU25XXSHARED_EXPORT CounterChannels {
        CH01,
        CH02
    };
}

enum class AGILENTU25XXSHARED_EXPORT SSIModes {
    None,
    Master,
    Slave
};

#endif // AGU25XXDEFINITIONS_H
