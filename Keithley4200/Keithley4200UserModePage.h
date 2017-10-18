#ifndef KEITHLEY4200USERMODEPAGE_H
#define KEITHLEY4200USERMODEPAGE_H

#include "keithley4200_global.h"
#include "IKeithley4200Page.h"
#include "Keithley4200Definitions.h"

class KEITHLEY4200SHARED_EXPORT Keithley4200UserModePage : public IKeithley4200Page
{
public:
    Keithley4200UserModePage();

    QString cmdSMUSetSourceVoltage(const unsigned int channelID, Keithley4200VoltageRanges voltageSourceRange, double outputValue, double complianceValue);
    QString cmdSMUSetSourceCurrent(const unsigned int channelID, Keithley4200CurrentRanges currentSourceRange, double outputValue, double complianceValue);
    QString cmdVSSetSourceVoltage(const unsigned int channelID, double outputValue);
    QString cmdTriggerVoltage(Keithley4200VoltageMeasureChannels vmChannel);
    QString cmdTriggerCurrent(Keithley4200CurrentMeasureChannels imChannel);
};

#endif // KEITHLEY4200USERMODEPAGE_H
