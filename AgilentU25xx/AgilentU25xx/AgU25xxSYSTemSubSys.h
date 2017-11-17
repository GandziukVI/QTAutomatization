#ifndef SYSTEMSUBSYS_H
#define SYSTEMSUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxSYSTemSubSys :
        public IAgU25xxSubsystem,
        public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxSYSTemSubSys();

    QString cmdGetChassisDescription();
    QString cmdGetDAQErrorMsg();
};

#endif // SYSTEMSUBSYS_H
