#ifndef KEITHLEY4200COMMONCOMMANDS_H
#define KEITHLEY4200COMMONCOMMANDS_H

#include "keithley4200_global.h"
#include "Keithley4200Definitions.h"
#include "IKeithley4200Page.h"

class KEITHLEY4200SHARED_EXPORT Keithley4200CommonCommands : public IKeithley4200Page
{
public:
    Keithley4200CommonCommands();

    QString cmdSetPredefinedIntegrationTime(Keithley4200IntegrationTimes integrationTime) const;
    QString cmdSetCustomIntegrationTime(double delayFactor, double filterFactor, double ADIntegrationTime) const;
    QString cmdRetrieveInstrumentID() const;
    QString cmdDataReadyRequestEnable(bool enable) const;
    QString cmdSetGlobalMeasurementResolution(const unsigned int numDigits) const;
    QString cmdSetSpecifiedCurrentRange(const unsigned int smuNum, Keithley4200CurrentRanges currentRange, double complianceValue) const;
    QString cmdSetLowestCurrentRange(const unsigned int smuNum, Keithley4200CurrentRanges currentRange) const;
    QString cmdPerformAutoCalibration(const unsigned int smuNum) const;
    QString cmdExitOnCompliance(bool exit) const;
};

#endif // KEITHLEY4200COMMONCOMMANDS_H
