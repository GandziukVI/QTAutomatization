#include "Keithley4200ChannelDefinitionPage.h"

#include <QObject>

Keithley4200ChannelDefinitionPage::Keithley4200ChannelDefinitionPage()
{
    extCopyString(pageIdentifier, "DE");
    channelNumber = 1;
}

Keithley4200ChannelDefinitionPage::Keithley4200ChannelDefinitionPage(const unsigned int channelID)
{
    extCopyString(pageIdentifier, "DE");
    channelNumber = channelID;
}

QString Keithley4200ChannelDefinitionPage::cmdDisableChannel(const unsigned int channelID)
{
    extCopyString(commandIdentifier, "CH");
    return buildCommand(std::to_string(channelID).c_str());
}

QString Keithley4200ChannelDefinitionPage::cmdDefineChannel(const char* voltName, const char* currName, SMUSourceMode sourceMode, SMUSourceFunction sourceFunction)
{
    extCopyString(commandIdentifier, "CH");

    QString res = QObject::tr("%1, \'%2\', \'%3\', %4, %5")
            .arg(channelNumber)
            .arg(voltName)
            .arg(currName)
            .arg(getSMUSourceMode(sourceMode))
            .arg(getSMUSourceFunction(sourceFunction));

    return buildCommand(res);
}

QString Keithley4200ChannelDefinitionPage::cmdDefineVoltageSourceChannel(const char *voltName, SMUSourceFunction sourceFunction)
{
    extCopyString(commandIdentifier, "VS");

    QString res = QObject::tr("%1, \'%2\', %3")
            .arg(channelNumber)
            .arg(voltName)
            .arg(getSMUSourceFunction(sourceFunction));

    return buildCommand(res);
}

QString Keithley4200ChannelDefinitionPage::cmdDefineVoltageMeterChannel(const char *voltName)
{
    extCopyString(commandIdentifier, "VM");

    QString res = QObject::tr("%1, \'%2\'")
            .arg(channelNumber)
            .arg(voltName);

    return buildCommand(res);
}
