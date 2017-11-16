#ifndef AGU25XXCALIBRATION_H
#define AGU25XXCALIBRATION_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxCALibrationSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxCALibrationSubSys();

    QString cmdStartSelfCalibration();
    QString cmdCheckCalibrationStatus();
};

#endif // AGU25XXCALIBRATION_H
