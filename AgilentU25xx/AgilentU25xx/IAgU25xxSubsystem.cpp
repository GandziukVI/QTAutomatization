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

unsigned int IAg25xxSubsystem::extGetAOChannel(AgU25xxOUTPut::AOChannels channel) const
{
    switch (channel) {

    case AgU25xxOUTPut::AOChannels::CH01:
        return 201;
    case AgU25xxOUTPut::AOChannels::CH02:
        return 202;
    }

    return 201;
}

QVector<unsigned int> IAg25xxSubsystem::extGetAOChannels(QVector<AgU25xxOUTPut::AOChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxOUTPut::AOChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend();) {
        res.push_back(extGetAOChannel(*iter));
        ++iter;
    }

    return res;
}

unsigned int IAg25xxSubsystem::extGetDigChannel(AgU25xxDIGital::DigitalChannels channel) const
{
    switch (channel) {

    case AgU25xxDIGital::DigitalChannels::DIG01:
        return 501;
    case AgU25xxDIGital::DigitalChannels::DIG02:
        return 502;
    case AgU25xxDIGital::DigitalChannels::DIG03:
        return 503;
    case AgU25xxDIGital::DigitalChannels::DIG04:
        return 504;
    }

    return 501;
}

QVector<unsigned int> IAg25xxSubsystem::extGetDigChannels(QVector<AgU25xxDIGital::DigitalChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxDIGital::DigitalChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetDigChannel(*iter));
        ++iter;
    }

    return res;
}

const char* IAg25xxSubsystem::extGetDigDirection(AgU25xxDIGital::DigitalDirection direction) const
{
    switch (direction) {

    case AgU25xxDIGital::DigitalDirection::INPut:
        return "INP";
    case AgU25xxDIGital::DigitalDirection::OUTPut:
        return "OUTP";
    }

    return "INP";
}

const char* IAg25xxSubsystem::extGetTimeBaseSrcMode(AgU25xxTIMEbase::TimeSrcModes timeBaseMode) const
{
    switch (timeBaseMode) {

    case AgU25xxTIMEbase::TimeSrcModes::INTernal:
        return "INT";
    case AgU25xxTIMEbase::TimeSrcModes::EXTernal:
        return "EXT";
    case AgU25xxTIMEbase::TimeSrcModes::CCG:
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

unsigned int IAg25xxSubsystem::extGetVoltageChannel(AgU25xxVOLTage::VoltageChannels channel) const
{
    switch (channel) {

    case AgU25xxVOLTage::VoltageChannels::CH01:
        return 101;
    case AgU25xxVOLTage::VoltageChannels::CH02:
        return 102;
    case AgU25xxVOLTage::VoltageChannels::CH03:
        return 103;
    case AgU25xxVOLTage::VoltageChannels::CH04:
        return 104;
    }

    return 101;
}

QVector<unsigned int> IAg25xxSubsystem::extGetVoltageChannels(QVector<AgU25xxVOLTage::VoltageChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxVOLTage::VoltageChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetVoltageChannel(*iter));
        ++iter;
    }

    return res;
}

unsigned int IAg25xxSubsystem::extGetCounterChannel(AgU25xxCOUNter::CounterChannels channel) const
{
    switch (channel) {

    case AgU25xxCOUNter::CounterChannels::CH01:
            return 301;
    case AgU25xxCOUNter::CounterChannels::CH02:
            return 302;
    }

    return 301;
}

QVector<unsigned int> IAg25xxSubsystem::extGetCounterChannels(QVector<AgU25xxCOUNter::CounterChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxCOUNter::CounterChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetCounterChannel(*iter));
        ++iter;
    }

    return res;
}

unsigned int IAg25xxSubsystem::extGetOutputState(AgU25xxOUTPut::OutputState outpState) const
{
    switch (outpState) {

    case AgU25xxOUTPut::OutputState::ON:
        return 1;
    case AgU25xxOUTPut::OutputState::OFF:
        return 0;
    }

    return 0;
}

const char* IAg25xxSubsystem::extGetOutputTriggerSource(AgU25xxOUTPut::TriggerSources triggerSource) const
{
    switch (triggerSource) {

    case AgU25xxOUTPut::TriggerSources::NONE:
        return "NONE";
    case AgU25xxOUTPut::TriggerSources::EXTD:
        return "EXTD";
    case AgU25xxOUTPut::TriggerSources::EXTA:
        return "EXTA";
    case AgU25xxOUTPut::TriggerSources::STRG:
        return "STRG";
    }

    return "NONE";
}

const char* IAg25xxSubsystem::extGetOutputTriggerType(AgU25xxOUTPut::TriggerTypes triggerType) const
{
    switch (triggerType) {

    case AgU25xxOUTPut::TriggerTypes::POST:
        return "POST";
    case AgU25xxOUTPut::TriggerTypes::DEL:
        return "DEL";
    }
    return "POST";
}

const char* IAg25xxSubsystem::extGetOutputATRiGgerSource(AgU25xxOUTPut::ATRiGgerSources triggerSource) const
{
    switch (triggerSource) {

    case AgU25xxOUTPut::ATRiGgerSources::EXTAP:
        return "EXTAP";
    case AgU25xxOUTPut::ATRiGgerSources::CH101:
        return "CH101";
    case AgU25xxOUTPut::ATRiGgerSources::CH102:
        return "CH102";
    case AgU25xxOUTPut::ATRiGgerSources::CH103:
        return "CH103";
    case AgU25xxOUTPut::ATRiGgerSources::CH104:
        return "CH104";
    }

    return "EXTAP";
}

const char* IAg25xxSubsystem::extGetOutputATRiGgerCondition(AgU25xxOUTPut::ATRiGgerConditions triggerCondition) const
{
    switch (triggerCondition) {

    case AgU25xxOUTPut::ATRiGgerConditions::AHIG:
        return "AHIG";
    case AgU25xxOUTPut::ATRiGgerConditions::BLOW:
        return "BLOW";
    case AgU25xxOUTPut::ATRiGgerConditions::WIND:
        return "WIND";
    }

    return "BLOW";
}

const char* IAg25xxSubsystem::extGetOutputDTRiGgerPolarity(AgU25xxOUTPut::DTRiGgerPolarities triggerPolarity) const
{
    switch (triggerPolarity) {

    case AgU25xxOUTPut::DTRiGgerPolarities::POS:
        return "POS";
    case AgU25xxOUTPut::DTRiGgerPolarities::NEG:
        return "NEG";
    }

    return "POS";
}

unsigned int IAg25xxSubsystem::extGetAnalogInChannel(AgU25xxROUTe::AnalogInChannels channel) const
{
    switch (channel) {

    case AgU25xxROUTe::AnalogInChannels::AIn01:
        return 101;
    case AgU25xxROUTe::AnalogInChannels::AIn02:
        return 102;
    case AgU25xxROUTe::AnalogInChannels::AIn03:
        return 103;
    case AgU25xxROUTe::AnalogInChannels::AIn04:
        return 104;
    }

    return 101;
}

QVector<unsigned int> IAg25xxSubsystem::extGetAnalogInChannels(QVector<AgU25xxROUTe::AnalogInChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxROUTe::AnalogInChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetAnalogInChannel(*iter));
        ++iter;
    }

    return res;
}

double IAg25xxSubsystem::extGetAnalogInChannelRange(AgU25xxROUTe::AnalogInChannelRanges range) const
{
    switch (range) {

    case AgU25xxROUTe::AnalogInChannelRanges::Range10V:
        return 10.0;
    case AgU25xxROUTe::AnalogInChannelRanges::Range5V:
        return 5.0;
    case AgU25xxROUTe::AnalogInChannelRanges::Range2_5V:
        return 2.5;
    case AgU25xxROUTe::AnalogInChannelRanges::Range1_25V:
        return 1.25;
    }

    return 10.0;
}

const char* IAg25xxSubsystem::extGetAnalogInChannelPolarity(AgU25xxROUTe::AnalogInChannelPolaities polarity) const
{
    switch (polarity) {

    case AgU25xxROUTe::AnalogInChannelPolaities::BIP:
        return "BIP";
    case AgU25xxROUTe::AnalogInChannelPolaities::UNIP:
        return "UNIP";
    }

    return"BIP";
}

const char *IAg25xxSubsystem::extGetAnalogOutChannelRefereceSource(AgU25xxROUTe::AnalogOutChannelRSouRCes rSource) const
{
    switch (rSource) {

    case AgU25xxROUTe::AnalogOutChannelRSouRCes::INT:
        return "INT";
    case AgU25xxROUTe::AnalogOutChannelRSouRCes::EXT:
        return "EXT";
    }

    return "INT";
}
