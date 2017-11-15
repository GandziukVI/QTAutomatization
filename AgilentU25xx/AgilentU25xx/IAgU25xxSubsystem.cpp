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

    for(; iter != channels.cend();) {
        res.push_back(extGetAOChannel(*iter));
        ++iter;
    }

    return res;
}
