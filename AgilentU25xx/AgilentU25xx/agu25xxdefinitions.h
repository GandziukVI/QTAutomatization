#ifndef AGU25XXDEFINITIONS_H
#define AGU25XXDEFINITIONS_H

#include "agilentu25xx_global.h"

// Analog output

enum class AGILENTU25XXSHARED_EXPORT AgU25xxAOChannels {
    AOut01,
    AOut02
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxAOChannelRSouRCes {
    INT,
    EXT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxAOChannelPolarities {
    UNIP,
    BIP
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxOutputState {
    ON,
    OFF
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxTriggerSources {
    NONE, // Immediate triggering
    EXTD, // Selects the external digital trigger (EXTD_AO_TRIG) pin as the triggering source
    EXTA, // Selects the external analog trigger (EXTA_TRIG) pin as the triggering source
    STRG  // Star triggering
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxTriggerTypes {
    POST, // (Post-trigger): The instrument output is generated immediately after the trigger condition is met.
    DEL   // (Delay-trigger): The instrument output is generated when the delay count reaches zero. The delay count starts immediately after the trigger condition is met.
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxATRiGgerSources {
    EXTAP,
    CH101,
    CH102,
    CH103,
    CH104
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxATRiGgerConditions {
    AHIG, // (Above-High- Level triggering): The trigger signal is generated when the analog signal is higher than the high- threshold voltage.
    BLOW, // (Below- Low-Level triggering): The trigger signal is generated when the analog signal is lower than the low- threshold voltage.
    WIND  // (Window (inside region) triggering): The trigger signal is generated when the analog signal falls within the range of the high- threshold and low- threshold voltages.
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxDTRiGgerPolarities {
    POS, // (Positive- edge triggering): The trigger signal is generated when a rising edge is detected in the digital signal.
    NEG  // (Negative- edge triggering): The trigger signal is generated when a falling edge is detected in the digital signal.
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxAIChannels {
    AIn01,
    AIn02,
    AIn03,
    AIn04
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxAIChannelRanges {
    AUTO,
    Range10V,
    Range5V,
    Range2_5V,
    Range1_25V
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxAIChannelPolaities {
    BIP,
    UNIP
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxDigitalDirection {
    INPut,
    OUTPut
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxDigitalChannels {
    DIG01,
    DIG02,
    DIG03,
    DIG04
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxTimeSrcModes {
    INTernal,
    EXTernal,
    CCG
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterChannels {
    COUNT01,
    COUNT02
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterFunctions {
    FREQ,
    PER,
    PWID,
    TOT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterGateSources {
    INT,
    EXT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterGatePolarities {
    AHI,
    ALO
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterGateStates {
    DIS,
    ENAB
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterClockSources {
    INT,
    EXT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterClockPolarities {
    AHI,
    ALO
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterTotalizeCountingSrc {
    INT,
    EXT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterTotalizeCountingDir {
    UP,
    DOWN
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxSSIModes {
    None,
    Master,
    Slave
};

#endif // AGU25XXDEFINITIONS_H
