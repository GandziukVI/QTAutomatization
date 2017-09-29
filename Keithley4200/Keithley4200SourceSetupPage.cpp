#include "Keithley4200SourceSetupPage.h"

Keithley4200SourceSetupPage::Keithley4200SourceSetupPage()
{
    extCopyString(pageIdentifier, "SS");
    channelNumber = 1;
}

Keithley4200SourceSetupPage::Keithley4200SourceSetupPage(const unsigned int channelID)
{
    extCopyString(pageIdentifier, "SS");
    channelNumber = channelID;
}

QString Keithley4200SourceSetupPage::cmdConfVAR1Sweep(SMUSourceMode sourceMode, SMUSweepMode sweepMode, double startValue, double stopValue, double stepValue, double complianceValue)
{
    switch (sourceMode)
    {
        case SMUSourceMode::Voltage: {
            extCopyString(commandIdentifier, "VR");
            break;
        }
        case SMUSourceMode::Current: {
            extCopyString(commandIdentifier, "IR");
            break;
        }
    }

    QString res = QObject::tr("%1, %2, %3, %4, %5")
            .arg(getSMUSweepMode(sweepMode))
            .arg(startValue)
            .arg(stopValue)
            .arg(stepValue)
            .arg(complianceValue);

    return buildCommand(res);
}
