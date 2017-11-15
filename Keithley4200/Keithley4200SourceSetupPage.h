#ifndef KEITHLEY4200SOURCESETUPPAGE_H
#define KEITHLEY4200SOURCESETUPPAGE_H

#include "keithley4200_global.h"
#include "IKeithley4200Page.h"

class KEITHLEY4200SHARED_EXPORT Keithley4200SourceSetupPage : public IKeithley4200Page
{
public:
    Keithley4200SourceSetupPage();

    QString cmdConfVAR1Sweep(SMUSourceMode sourceMode, SMUSweepMode sweepMode, double startValue, double stopValue, double stepValue, double complianceValue);
    QString cmdConfVAR1Scale(double ratio, double offset, const unsigned int channelID = 0);
    QString cmdConfVAR2Sweep(SMUSourceMode sourceMode, double startValue, double stepValue, int stepsNumber, double complianceValue);
    QString cmdConfListSweep(SMUSourceMode sourceMode, const unsigned int channelID, double complianceValue, const QVector<double>& listValues, SMUMasterOrSlaveMode masterOrSlaveMode = SMUMasterOrSlaveMode::Master);
    QString cmdConfAutoStandby(const unsigned int channelID, const bool standbyEnable);
    QString cmdConfConstSource(SMUSourceMode sourceMode, const unsigned int channelID, double outputValue, double complianceValue);
    QString cmdConfConstVoltageSource(const unsigned int channelID, double outputValue);
    QString cmdSetSweepHoldTime(double holdTime);
    QString cmdSetSweepDelayTime(double delayTime);
};

#endif // KEITHLEY4200SOURCESETUPPAGE_H
