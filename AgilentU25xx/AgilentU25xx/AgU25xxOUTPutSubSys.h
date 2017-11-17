#ifndef AGU25XXOUTPUT_H
#define AGU25XXOUTPUT_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxOUTPutSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxOUTPutSubSys();

    QString cmdSetOutputState(AgU25xxEnumOutputState outpState) const;
    QString cmdSetWAVNumIterations(unsigned int numIter);
    QString cmdGetWAVNumIterations();
    QString cmdSetWAVSamplingRate(unsigned int samplingRate);
    QString cmdGetWAVSamplingRate();
    QString cmdSetWAVSamplingFreq(unsigned int samplingFreq);
    QString cmdGetWAVSamplingFreq();
    QString cmdSetTRIGSource(AgU25xxEnumTriggerSources triggerSource);
    QString cmdGetTRIGSource();
    QString cmdSetTRIGType(AgU25xxEnumTriggerTypes triggerType);
    QString cmdGetTRIGType();
    QString cmdSetTRIGDelayCount(unsigned int delayCount);
    QString cmdGetTRIGDelayCount();
    QString cmdSetATRiGgerSrc(AgU25xxEnumATRiGgerSources triggerSource);
    QString cmdGetATRiGgerSrc();
    QString cmdSetATRiGgerCondition(AgU25xxEnumATRiGgerConditions triggerCondition);
    QString cmdGetATRiGgerCondition();
    QString cmdSetATRiGgerHighVoltTreshold(double highVoltageTreshold);
    QString cmdGetATRiGgerHighVoltTreshold();
    QString cmdSetATRiGgerLowVoltTreshold(double lowVoltageTreshold);
    QString cmdGetATRiGgerLowVoltTreshold();
    QString cmdSetDTRiGgerPolarity(AgU25xxEnumDTRiGgerPolarities triggerPolarity);
    QString cmdGetDTRiGgerPolarity();

private:
    IAgU25xxSubsystem WAVeformSubsystem;
    IAgU25xxSubsystem TRIGgerSubsystem;
    IAgU25xxSubsystem TRIGgerATRiGgerSubsystem;
    IAgU25xxSubsystem TRIGgerDTRiGgerSubsystem;
};

#endif // AGU25XXOUTPUT_H
