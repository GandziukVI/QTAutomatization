#ifndef AGU25XXDEFINITIONS_H
#define AGU25XXDEFINITIONS_H

#include "agilentu25xx_global.h"

// Analog output

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumAOChannels : unsigned int {
    AOut01 = 0,
    AOut02 = 1
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumAOChannelRSouRCes {
    INT,
    EXT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumAOChannelPolarities {
    UNIP,
    BIP
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumOutputState {
    ON,
    OFF
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumTriggerSources {
    NONE, // Immediate triggering
    EXTD, // Selects the external digital trigger (EXTD_AO_TRIG) pin as the triggering source
    EXTA, // Selects the external analog trigger (EXTA_TRIG) pin as the triggering source
    STRG  // Star triggering
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumTriggerTypes {
    POST, // (Post-trigger): The instrument output is generated immediately after the trigger condition is met.
    DEL,   // (Delay-trigger): The instrument output is generated when the delay count reaches zero. The delay count starts immediately after the trigger condition is met.
    PRE,
    MID
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumATRiGgerSources {
    EXTAP,
    CH101,
    CH102,
    CH103,
    CH104
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumATRiGgerConditions {
    AHIG, // (Above-High- Level triggering): The trigger signal is generated when the analog signal is higher than the high- threshold voltage.
    BLOW, // (Below- Low-Level triggering): The trigger signal is generated when the analog signal is lower than the low- threshold voltage.
    WIND  // (Window (inside region) triggering): The trigger signal is generated when the analog signal falls within the range of the high- threshold and low- threshold voltages.
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumDTRiGgerPolarities {
    POS, // (Positive- edge triggering): The trigger signal is generated when a rising edge is detected in the digital signal.
    NEG  // (Negative- edge triggering): The trigger signal is generated when a falling edge is detected in the digital signal.
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumAIChannels : unsigned int {
    AIn01 = 0,
    AIn02 = 1,
    AIn03 = 2,
    AIn04 = 3
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumAIChannelRanges {
    AUTO,
    Range10V,
    Range5V,
    Range2_5V,
    Range1_25V
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumAIChannelPolaities {
    BIP,
    UNIP
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumAcquisitionStates {
    Complete,
    Running
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumDigitalDirection {
    INPut,
    OUTPut
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumDigitalChannels : unsigned int {
    DIG01 = 0,
    DIG02 = 1,
    DIG03 = 2,
    DIG04 = 3
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumTimeSrcModes {
    INTernal,
    EXTernal,
    CCG
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumCounterChannels {
    COUNT01,
    COUNT02
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumCounterFunctions {
    FREQ,
    PER,
    PWID,
    TOT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumCounterGateSources {
    INT,
    EXT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumCounterGatePolarities {
    AHI,
    ALO
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumCounterGateStates {
    DIS,
    ENAB
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumCounterClockSources {
    INT,
    EXT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxCounterEnumClockPolarities {
    AHI,
    ALO
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumCounterTotalizeCountingSrc {
    INT,
    EXT
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumCounterTotalizeCountingDir {
    UP,
    DOWN
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumSSIModes {
    None,
    Master,
    Slave
};

enum class AGILENTU25XXSHARED_EXPORT AgU25xxEnumBufferStatus {
    EPTY,
    FRAG,
    DATA,
    OVER
};

#endif // AGU25XXDEFINITIONS_H
