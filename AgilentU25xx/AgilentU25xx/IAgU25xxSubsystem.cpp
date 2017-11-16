#include "IAgU25xxSubsystem.h"


IAg25xxSubsystem::IAg25xxSubsystem()
{
    subsystemSeparator = ':';
    extCopyString(subsystemIdentifier, "ACQ");
}

IAg25xxSubsystem::IAg25xxSubsystem(const char* subSystemID)
{
    subsystemSeparator = ':';
    extCopyString(subsystemIdentifier, subSystemID);
}

QString IAg25xxSubsystem::buildCommand(const char* command)
{
    if(!commandString.isEmpty())
        commandString.clear();

    QTextStream commandBuilder(&commandString);

    commandBuilder << subsystemIdentifier << subsystemSeparator << command << '\n';

    return commandString;
}

QString IAg25xxSubsystem::buildCommand(const QString &command)
{
    if(!commandString.isEmpty())
        commandString.clear();

    QTextStream commandBuilder(&commandString);

    commandBuilder << subsystemIdentifier << subsystemSeparator << command << '\n';

    return commandString;
}

IAg25xxSubsystem IAg25xxSubsystem::getSubSubSystem(const char* subSubSystemID) const
{
    QString buf;
    QTextStream bufStream(&buf);

    bufStream << subsystemIdentifier << subsystemSeparator << subSubSystemID;

    IAg25xxSubsystem res(buf.toStdString().c_str());

    return res;
}

void IAg25xxSubsystem::extCopyString(char *dest, const char *src) const
{
    std::string srcStr(src);
    std::size_t len = srcStr.copy(dest, srcStr.length());
    dest[len] = '\0';
}

unsigned int IAg25xxSubsystem::extGetAOChannel(AgU25xxAOChannels channel) const
{
    switch (channel) {

    case AgU25xxAOChannels::AOut01:
        return 201;
    case AgU25xxAOChannels::AOut02:
        return 202;
    }

    return 201;
}

QVector<unsigned int> IAg25xxSubsystem::extGetAOChannels(QVector<AgU25xxAOChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxAOChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend();) {
        res.push_back(extGetAOChannel(*iter));
        ++iter;
    }

    return res;
}

unsigned int IAg25xxSubsystem::extGetDigChannel(AgU25xxDigitalChannels channel) const
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

QVector<unsigned int> IAg25xxSubsystem::extGetDigChannels(QVector<AgU25xxDigitalChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxDigitalChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetDigChannel(*iter));
        ++iter;
    }

    return res;
}

const char* IAg25xxSubsystem::extGetDigDirection(AgU25xxDigitalDirection direction) const
{
    switch (direction) {

    case AgU25xxDigitalDirection::INPut:
        return "INP";
    case AgU25xxDigitalDirection::OUTPut:
        return "OUTP";
    }

    return "INP";
}

const char* IAg25xxSubsystem::extGetTimeBaseSrcMode(AgU25xxTimeSrcModes timeBaseMode) const
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

const char *IAg25xxSubsystem::extGetSSIMode(SSIModes ssiMode) const
{
    switch (ssiMode) {

    case SSIModes::None:
        return "NONE";
    case SSIModes::Master:
        return "MAST";
    case SSIModes::Slave:
        return "SLAV";
    }

    return "NONE";
}

unsigned int IAg25xxSubsystem::extGetCounterChannel(AgU25xxCounterChannels channel) const
{
    switch (channel) {

    case AgU25xxCounterChannels::CH01:
            return 301;
    case AgU25xxCounterChannels::CH02:
            return 302;
    }

    return 301;
}

QVector<unsigned int> IAg25xxSubsystem::extGetCounterChannels(QVector<AgU25xxCounterChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxCounterChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetCounterChannel(*iter));
        ++iter;
    }

    return res;
}

unsigned int IAg25xxSubsystem::extGetOutputState(AgU25xxOutputState outpState) const
{
    switch (outpState) {

    case AgU25xxOutputState::ON:
        return 1;
    case AgU25xxOutputState::OFF:
        return 0;
    }

    return 0;
}

const char* IAg25xxSubsystem::extGetOutputTriggerSource(AgU25xxTriggerSources triggerSource) const
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

const char* IAg25xxSubsystem::extGetOutputTriggerType(AgU25xxTriggerTypes triggerType) const
{
    switch (triggerType) {

    case AgU25xxTriggerTypes::POST:
        return "POST";
    case AgU25xxTriggerTypes::DEL:
        return "DEL";
    }
    return "POST";
}

const char* IAg25xxSubsystem::extGetOutputATRiGgerSource(AgU25xxATRiGgerSources triggerSource) const
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

const char* IAg25xxSubsystem::extGetOutputATRiGgerCondition(AgU25xxATRiGgerConditions triggerCondition) const
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

const char* IAg25xxSubsystem::extGetOutputDTRiGgerPolarity(AgU25xxDTRiGgerPolarities triggerPolarity) const
{
    switch (triggerPolarity) {

    case AgU25xxDTRiGgerPolarities::POS:
        return "POS";
    case AgU25xxDTRiGgerPolarities::NEG:
        return "NEG";
    }

    return "POS";
}

unsigned int IAg25xxSubsystem::extGetAnalogInChannel(AgU25xxAInChannels channel) const
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

QVector<unsigned int> IAg25xxSubsystem::extGetAnalogInChannels(QVector<AgU25xxAInChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxAInChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetAnalogInChannel(*iter));
        ++iter;
    }

    return res;
}

double IAg25xxSubsystem::extGetAnalogInChannelRange(AgU25xxAInChannelRanges range) const
{
    switch (range) {

    case AgU25xxAInChannelRanges::Range10V:
        return 10.0;
    case AgU25xxAInChannelRanges::Range5V:
        return 5.0;
    case AgU25xxAInChannelRanges::Range2_5V:
        return 2.5;
    case AgU25xxAInChannelRanges::Range1_25V:
        return 1.25;
    }

    return 10.0;
}

const char* IAg25xxSubsystem::extGetAnalogInChannelPolarity(AgU25xxAInChannelPolaities polarity) const
{
    switch (polarity) {

    case AgU25xxAInChannelPolaities::BIP:
        return "BIP";
    case AgU25xxAInChannelPolaities::UNIP:
        return "UNIP";
    }

    return"BIP";
}

const char *IAg25xxSubsystem::extGetAnalogOutChannelRefereceSource(AgU25xxAOutChannelRSouRCes rSource) const
{
    switch (rSource) {

    case AgU25xxAOutChannelRSouRCes::INT:
        return "INT";
    case AgU25xxAOutChannelRSouRCes::EXT:
        return "EXT";
    }

    return "INT";
}
