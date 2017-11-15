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

unsigned int IAg25xxSubsystem::extGetAOChannel(AgU25xxAnalogOutput::AOChannels channel) const
{
    switch (channel) {

    case AgU25xxAnalogOutput::AOChannels::CH01:
        return 201;
    case AgU25xxAnalogOutput::AOChannels::CH02:
        return 202;
    }

    return 201;
}

QVector<unsigned int> IAg25xxSubsystem::extGetAOChannels(QVector<AgU25xxAnalogOutput::AOChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxAnalogOutput::AOChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend();) {
        res.push_back(extGetAOChannel(*iter));
        ++iter;
    }

    return res;
}

unsigned int IAg25xxSubsystem::extGetDigChannel(AgU25xxDIGital::DigitalChannels channel) const
{
    switch (channel) {

    case AgU25xxDIGital::DigitalChannels::D01:
        return 501;
    case AgU25xxDIGital::DigitalChannels::D02:
        return 502;
    case AgU25xxDIGital::DigitalChannels::D03:
        return 503;
    case AgU25xxDIGital::DigitalChannels::D04:
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
