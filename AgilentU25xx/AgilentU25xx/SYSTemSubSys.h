#ifndef SYSTEMSUBSYS_H
#define SYSTEMSUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT SYSTemSubSys :
        public IAgU25xxSubsystem,
        public IAgU25xxSubsystemExtensions
{
public:
    SYSTemSubSys();

    QString cmdGetChassisDescription();
    QString cmdGetDAQErrorMsg();
};

#endif // SYSTEMSUBSYS_H
