#include "Keithley4200ChannelDefinitionPage.h"

#include <string>
#include <sstream>

Keithley4200ChannelDefinitionPage::Keithley4200ChannelDefinitionPage()
{
    extCopyString(pageIdentifier, "DE");
}

Keithley4200ChannelDefinitionPage::Keithley4200ChannelDefinitionPage(const unsigned int channelID)
{
    extCopyString(pageIdentifier, "DE");
    channelNumber = channelID;
}

const char* Keithley4200ChannelDefinitionPage::cmdDisableChannel(const unsigned int channelID)
{
    extCopyString(commandIdentifier, "CH");
    return buildCommand(std::to_string(channelID).c_str());
}

const char* Keithley4200ChannelDefinitionPage::cmdDefineChannel(const unsigned int channelID, const char* voltName, const char* currName, SMUSourceMode sourceMode, SMUSourceFunction sourceFunction)
{
    extCopyString(commandIdentifier, "CH");

    std::stringstream commandStringStream;

    commandStringStream << channelID << ", \'" << voltName << "\'', \'" << currName << "\'', " << getSMUSourceMode(sourceMode) << getSMUSourceFunction(sourceFunction);

    return buildCommand(commandStringStream.str().c_str());
}

const char* Keithley4200ChannelDefinitionPage::cmdDefineVoltageSourceChannel(const unsigned int channelID, const char *voltName, SMUSourceFunction sourceFunction)
{
    extCopyString(commandIdentifier, "CH");

    std::stringstream commandStringStream;

    commandStringStream << channelID << ", \'" << voltName << "\', " << getSMUSourceFunction(sourceFunction);

    return buildCommand(commandStringStream.str().c_str());
}
