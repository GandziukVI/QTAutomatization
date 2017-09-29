#ifndef KEITHLEY4200SOURCESETUPPAGE_H
#define KEITHLEY4200SOURCESETUPPAGE_H

#include "keithley4200_global.h"
#include "IKeithley4200Page.h"

class KEITHLEY4200SHARED_EXPORT Keithley4200SourceSetupPage : public IKeithley4200Page
{
public:
    Keithley4200SourceSetupPage();
    Keithley4200SourceSetupPage(const unsigned int channelID);

    QString cmdConfVAR1Sweep(SMUSourceMode sourceMode, SMUSweepMode sweepMode, double startValue, double stopValue, double stepValue, double complianceValue);
};

#endif // KEITHLEY4200SOURCESETUPPAGE_H
