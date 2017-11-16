#include "IAgU25xxSubsystemExtensions.h"

IAgU25xxSubsystemExtensions::IAgU25xxSubsystemExtensions()
{

}

unsigned int IAgU25xxSubsystemExtensions::extGetAOChannel(AgU25xxAOChannels channel) const
{
    switch (channel) {

    case AgU25xxAOChannels::AOut01:
        return 201;
    case AgU25xxAOChannels::AOut02:
        return 202;
    }

    return 201;
}

QVector<unsigned int> IAgU25xxSubsystemExtensions::extGetAOChannels(QVector<AgU25xxAOChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxAOChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend();) {
        res.push_back(extGetAOChannel(*iter));
        ++iter;
    }

    return res;
}

unsigned int IAgU25xxSubsystemExtensions::extGetDigChannel(AgU25xxDigitalChannels channel) const
{
    switch (channel) {

    case AgU25xxDigitalChannels::DIG01:
        return 501;
    case AgU25xxDigitalChannels::DIG02:
        return 502;
    case AgU25xxDigitalChannels::DIG03:
        return 503;
    case AgU25xxDigitalChannels::DIG04:
        return 504;
    }

    return 501;
}

QVector<unsigned int> IAgU25xxSubsystemExtensions::extGetDigChannels(QVector<AgU25xxDigitalChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxDigitalChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetDigChannel(*iter));
        ++iter;
    }

    return res;
}

const char* IAgU25xxSubsystemExtensions::extGetDigDirection(AgU25xxDigitalDirection direction) const
{
    switch (direction) {

    case AgU25xxDigitalDirection::INPut:
        return "INP";
    case AgU25xxDigitalDirection::OUTPut:
        return "OUTP";
    }

    return "INP";
}

const char* IAgU25xxSubsystemExtensions::extGetTimeBaseSrcMode(AgU25xxTimeSrcModes timeBaseMode) const
{
    switch (timeBaseMode) {

    case AgU25xxTimeSrcModes::INTernal:
        return "INT";
    case AgU25xxTimeSrcModes::EXTernal:
        return "EXT";
    case AgU25xxTimeSrcModes::CCG:
        return "CCG";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetSSIMode(AgU25xxSSIModes ssiMode) const
{
    switch (ssiMode) {

    case AgU25xxSSIModes::None:
        return "NONE";
    case AgU25xxSSIModes::Master:
        return "MAST";
    case AgU25xxSSIModes::Slave:
        return "SLAV";
    }

    return "NONE";
}

unsigned int IAgU25xxSubsystemExtensions::extGetCounterChannel(AgU25xxCounterChannels channel) const
{
    switch (channel) {

    case AgU25xxCounterChannels::COUNT01:
            return 301;
    case AgU25xxCounterChannels::COUNT02:
            return 302;
    }

    return 301;
}

QVector<unsigned int> IAgU25xxSubsystemExtensions::extGetCounterChannels(QVector<AgU25xxCounterChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxCounterChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetCounterChannel(*iter));
        ++iter;
    }

    return res;
}

unsigned int IAgU25xxSubsystemExtensions::extGetOutputState(AgU25xxOutputState outpState) const
{
    switch (outpState) {

    case AgU25xxOutputState::ON:
        return 1;
    case AgU25xxOutputState::OFF:
        return 0;
    }

    return 0;
}

const char* IAgU25xxSubsystemExtensions::extGetOutputTriggerSource(AgU25xxTriggerSources triggerSource) const
{
    switch (triggerSource) {

    case AgU25xxTriggerSources::NONE:
        return "NONE";
    case AgU25xxTriggerSources::EXTD:
        return "EXTD";
    case AgU25xxTriggerSources::EXTA:
        return "EXTA";
    case AgU25xxTriggerSources::STRG:
        return "STRG";
    }

    return "NONE";
}

const char* IAgU25xxSubsystemExtensions::extGetOutputTriggerType(AgU25xxTriggerTypes triggerType) const
{
    switch (triggerType) {

    case AgU25xxTriggerTypes::POST:
        return "POST";
    case AgU25xxTriggerTypes::DEL:
        return "DEL";
    }
    return "POST";
}

const char* IAgU25xxSubsystemExtensions::extGetOutputATRiGgerSource(AgU25xxATRiGgerSources triggerSource) const
{
    switch (triggerSource) {

    case AgU25xxATRiGgerSources::EXTAP:
        return "EXTAP";
    case AgU25xxATRiGgerSources::CH101:
        return "CH101";
    case AgU25xxATRiGgerSources::CH102:
        return "CH102";
    case AgU25xxATRiGgerSources::CH103:
        return "CH103";
    case AgU25xxATRiGgerSources::CH104:
        return "CH104";
    }

    return "EXTAP";
}

const char* IAgU25xxSubsystemExtensions::extGetOutputATRiGgerCondition(AgU25xxATRiGgerConditions triggerCondition) const
{
    switch (triggerCondition) {

    case AgU25xxATRiGgerConditions::AHIG:
        return "AHIG";
    case AgU25xxATRiGgerConditions::BLOW:
        return "BLOW";
    case AgU25xxATRiGgerConditions::WIND:
        return "WIND";
    }

    return "BLOW";
}

const char* IAgU25xxSubsystemExtensions::extGetOutputDTRiGgerPolarity(AgU25xxDTRiGgerPolarities triggerPolarity) const
{
    switch (triggerPolarity) {

    case AgU25xxDTRiGgerPolarities::POS:
        return "POS";
    case AgU25xxDTRiGgerPolarities::NEG:
        return "NEG";
    }

    return "POS";
}

unsigned int IAgU25xxSubsystemExtensions::extGetAIChannel(AgU25xxAInChannels channel) const
{
    switch (channel) {

    case AgU25xxAInChannels::AIn01:
        return 101;
    case AgU25xxAInChannels::AIn02:
        return 102;
    case AgU25xxAInChannels::AIn03:
        return 103;
    case AgU25xxAInChannels::AIn04:
        return 104;
    }

    return 101;
}

QVector<unsigned int> IAgU25xxSubsystemExtensions::extGetAIChannels(QVector<AgU25xxAInChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxAInChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetAIChannel(*iter));
        ++iter;
    }

    return res;
}

const char* IAgU25xxSubsystemExtensions::extGetAIChannelRange(AgU25xxAInChannelRanges range) const
{
    switch (range) {

    case AgU25xxAInChannelRanges::AUTO:
        return "AUTO";
    case AgU25xxAInChannelRanges::Range10V:
        return "10.0";
    case AgU25xxAInChannelRanges::Range5V:
        return "5.0";
    case AgU25xxAInChannelRanges::Range2_5V:
        return "2.5";
    case AgU25xxAInChannelRanges::Range1_25V:
        return "1.25";
    }

    return "AUTO";
}

const char* IAgU25xxSubsystemExtensions::extGetAIChannelPolarity(AgU25xxAInChannelPolaities polarity) const
{
    switch (polarity) {

    case AgU25xxAInChannelPolaities::BIP:
        return "BIP";
    case AgU25xxAInChannelPolaities::UNIP:
        return "UNIP";
    }

    return"BIP";
}

const char* IAgU25xxSubsystemExtensions::extGetAOChannelRefereceSource(AgU25xxAOutChannelRSouRCes rSource) const
{
    switch (rSource) {

    case AgU25xxAOutChannelRSouRCes::INT:
        return "INT";
    case AgU25xxAOutChannelRSouRCes::EXT:
        return "EXT";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterFunc(AgU25xxCounterFunctions function) const
{
    switch (function) {

    case AgU25xxCounterFunctions::FREQ:
        return "FREQ";
    case AgU25xxCounterFunctions::PER:
        return "PER";
    case AgU25xxCounterFunctions::PWID:
        return "PWID";
    case AgU25xxCounterFunctions::TOT:
        return "TOT";
    }

    return "FREQ";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterGateSource(AgU25xxCounterGateSources counterGateSrc) const
{
    switch (counterGateSrc) {

    case AgU25xxCounterGateSources::INT:
        return "INT";
    case AgU25xxCounterGateSources::EXT:
        return "EXT";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterGatePolarity(AgU25xxCounterGatePolarities counterPolarity) const
{
    switch (counterPolarity) {

    case AgU25xxCounterGatePolarities::AHI:
        return "AHI";
    case AgU25xxCounterGatePolarities::ALO:
        return "ALO";
    }

    return "AHI";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterGateState(AgU25xxCounterGateStates counterControl) const
{
    switch (counterControl) {

    case AgU25xxCounterGateStates::DIS:
        return "DIS";
    case AgU25xxCounterGateStates::ENAB:
        return "ENAB";
    }

    return "DIS";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterClockSource(AgU25xxCounterClockSources counterClockSrc) const
{
    switch (counterClockSrc) {

    case AgU25xxCounterClockSources::INT:
        return "INT";
    case AgU25xxCounterClockSources::EXT:
        return "EXT";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterClockPolarity(AgU25xxCounterClockPolarities counterClkPolarity) const
{
    switch (counterClkPolarity) {

    case AgU25xxCounterClockPolarities::AHI:
        return "AHI";
    case AgU25xxCounterClockPolarities::ALO:
        return "ALO";
    }

    return "AHI";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterTotalizeCountingSrc(AgU25xxCounterTotalizeCountingSrc counterTotalizeSrc) const
{
    switch (counterTotalizeSrc) {

    case AgU25xxCounterTotalizeCountingSrc::INT:
        return "INT";
    case AgU25xxCounterTotalizeCountingSrc::EXT:
        return "EXT";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterTotalizeCountingDir(AgU25xxCounterTotalizeCountingDir counterTotalizeDir) const
{
    switch (counterTotalizeDir) {

    case AgU25xxCounterTotalizeCountingDir::UP:
        return "UP";
    case AgU25xxCounterTotalizeCountingDir::DOWN:
        return "DOWN";
    }

    return "UP";
}
