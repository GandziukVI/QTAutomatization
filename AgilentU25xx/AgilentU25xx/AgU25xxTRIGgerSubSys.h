#ifndef AGU25XXTRIGGERSUBSYS_H
#define AGU25XXTRIGGERSUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxTRIGgerSubSys :
        public IAgU25xxSubsystem,
        public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxTRIGgerSubSys();

    QString cmdSetTriggerInpSrc(AgU25xxEnumTriggerSources inpSrc);
    QString cmdGetTriggerInpSrc();
    QString cmdSetTriggerInpType(AgU25xxEnumTriggerTypes inpType);
    QString cmdGetTriggerInpType();
    QString cmdSetTriggerInputDelayCount(unsigned int delCount);
    QString cmdGetTriggerInputDelayCount();
    QString cmdSetATRiGgerExtSrc();
    QString cmdGetATRiGgerExtSrc();
    QString cmdSetATRiGgerInpCondition(AgU25xxEnumATRiGgerConditions atrigCondition);
    QString cmdGetATRiGgerInpCondition();
    QString cmdSetATRiGgerInpHighThr(double thresholdVoltage);
    QString cmdGetATRiGgerInpHighThr();
    QString cmdSetATRiGgerInpLowThr(double thresholdVoltage);
    QString cmdGetATRiGgerInpLowThr();
    QString cmdSetDTRiGgerPolarity(AgU25xxEnumDTRiGgerPolarities polarity);
    QString cmdGetDTRiGgerPolarity();

private:
    IAgU25xxSubsystem ATRiGgerSubsystem;
    IAgU25xxSubsystem DTRiGgerSubsystem;
};

#endif // AGU25XXTRIGGERSUBSYS_H
