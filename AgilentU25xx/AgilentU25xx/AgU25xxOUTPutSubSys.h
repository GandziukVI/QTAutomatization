#ifndef AGU25XXOUTPUT_H
#define AGU25XXOUTPUT_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "AgU25xxDefinitions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxOUTPutSubSys : public IAg25xxSubsystem
{
public:
    AgU25xxOUTPutSubSys();

    QString cmdSetOutputState(AgU25xxOUTPut::OutputState outpState) const;
    QString cmdSetWAVNumIterations(unsigned int numIter);
    QString cmdGetWAVNumIterations();
    QString cmdSetWAVSamplingRate(unsigned int samplingRate);
    QString cmdGetWAVSamplingRate();
    QString cmdSetWAVSamplingFreq(unsigned int samplingFreq);
    QString cmdGetWAVSamplingFreq();
    QString cmdSetTRIGSource(AgU25xxOUTPut::TriggerSources triggerSource);
    QString cmdGetTRIGSource();
    QString cmdSetTRIGType(AgU25xxOUTPut::TriggerTypes triggerType);
    QString cmdGetTRIGType();
    QString cmdSetTRIGDelayCount(unsigned int delayCount);
    QString cmdGetTRIGDelayCount();
    QString cmdSetATRiGgerSrc(AgU25xxOUTPut::ATRiGgerSources triggerSource);
    QString cmdGetATRiGgerSrc();
    QString cmdSetATRiGgerCondition(AgU25xxOUTPut::ATRiGgerConditions triggerCondition);
    QString cmdGetATRiGgerCondition();
    QString cmdSetATRiGgerHighVoltTreshold(double highVoltageTreshold);
    QString cmdGetATRiGgerHighVoltTreshold();
    QString cmdSetATRiGgerLowVoltTreshold(double lowVoltageTreshold);
    QString cmdGetATRiGgerLowVoltTreshold();
    QString cmdSetDTRiGgerPolarity(AgU25xxOUTPut::DTRiGgerPolarities triggerPolarity);
    QString cmdGetDTRiGgerPolarity();

private:
    IAg25xxSubsystem WAVeformSubsystem;
    IAg25xxSubsystem TRIGgerSubsystem;
    IAg25xxSubsystem TRIGgerATRiGgerSubsystem;
    IAg25xxSubsystem TRIGgerDTRiGgerSubsystem;
};

#endif // AGU25XXOUTPUT_H
