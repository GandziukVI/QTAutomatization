#ifndef AGU25XXSENSESUBSYS_H
#define AGU25XXSENSESUBSYS_H

#include "agilentu25xx_global.h"
#include "AgU25xxDefinitions.h"
#include "IAgU25xxSubsystem.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxSENSeSubSys : public IAg25xxSubsystem
{
public:
    AgU25xxSENSeSubSys();

private:
    IAg25xxSubsystem VOLTageSubsystem;
    IAg25xxSubsystem COUNterSubsystem;
};

#endif // AGU25XXSENSESUBSYS_H
