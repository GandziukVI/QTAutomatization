#ifndef AGU25XXCALIBRATION_H
#define AGU25XXCALIBRATION_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxCALibrationSubSys : public IAg25xxSubsystem
{
public:
    AgU25xxCALibrationSubSys();

    QString cmdStartSelfCalibration();
    QString cmdCheckCalibrationStatus();
};

#endif // AGU25XXCALIBRATION_H
