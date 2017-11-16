#include "IAgU25xxSubsystem.h"

#include <QTextStream>
#include <iterator>
#include <algorithm>

IAgU25xxSubsystem::IAgU25xxSubsystem()
{
    subsystemSeparator = ':';
    extCopyString(subsystemIdentifier, "ACQ");
}

IAgU25xxSubsystem::IAgU25xxSubsystem(const char* subSystemID)
{
    subsystemSeparator = ':';
    extCopyString(subsystemIdentifier, subSystemID);
}

QString IAgU25xxSubsystem::buildCommand(const char* command)
{
    if(!commandString.isEmpty())
        commandString.clear();

    QTextStream commandBuilder(&commandString);

    commandBuilder << subsystemIdentifier << subsystemSeparator << command << '\n';

    return commandString;
}

QString IAgU25xxSubsystem::buildCommand(const QString &command)
{
    if(!commandString.isEmpty())
        commandString.clear();

    QTextStream commandBuilder(&commandString);

    commandBuilder << subsystemIdentifier << subsystemSeparator << command << '\n';

    return commandString;
}

IAgU25xxSubsystem IAgU25xxSubsystem::getSubSubSystem(const char* subSubSystemID) const
{
    QString buf;
    QTextStream bufStream(&buf);

    bufStream << subsystemIdentifier << subsystemSeparator << subSubSystemID;

    IAgU25xxSubsystem res(buf.toStdString().c_str());

    return res;
}

void IAgU25xxSubsystem::extCopyString(char *dest, const char *src) const
{
    std::string srcStr(src);
    std::size_t len = srcStr.copy(dest, srcStr.length());
    dest[len] = '\0';
}

QString IAgU25xxSubsystem::extCreateChannelsString(const QVector<unsigned int>& channels) const
{
    QString res;
    QTextStream resStream(&res);

    resStream << "(@";

    QVector<unsigned int>::const_iterator iter = channels.cbegin();

    for(; iter != channels.cend(); ) {
        if (iter != channels.cend() - 1)
            resStream << *iter << ',';
        else
            resStream << *iter << ')';
        ++iter;
    }

    return res;
}
