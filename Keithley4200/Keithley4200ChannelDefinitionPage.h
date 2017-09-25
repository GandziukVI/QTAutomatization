#ifndef CHANNELDEFINITIONPAGE_H
#define CHANNELDEFINITIONPAGE_H

#include "keithley4200_global.h"
#include "IKeithley4200Page.h"

class KEITHLEY4200SHARED_EXPORT Keithley4200ChannelDefinitionPage : public IKeithley4200Page {

public:
    Keithley4200ChannelDefinitionPage();
    Keithley4200ChannelDefinitionPage(const unsigned int channelID);

    const char* cmdDisableChannel(const unsigned int channelID);
    const char* cmdDefineChannel (const unsigned int channelID, const char* voltName = "Volt", const char* currName = "Curr", SMUSourceMode sourceMode = SMUSourceMode::Voltage, SMUSourceFunction sourceFunction = SMUSourceFunction::Constant);
    const char* cmdDefineVoltageSourceChannel(const unsigned int channelID, const char* voltName = "Volt", SMUSourceFunction sourceFunction = SMUSourceFunction::Constant);

private:
    unsigned int channelNumber;
};

#endif // CHANNELDEFINITIONPAGE_H
