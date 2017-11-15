#ifndef AGU25XXCALIBRATION_H
#define AGU25XXCALIBRATION_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxCALibration : public IAg25xxSubsystem
{
public:
    AgU25xxCALibration();

    QString cmdStartSelfCalibration();
    QString cmdCheckCalibrationStatus();
};

#endif // AGU25XXCALIBRATION_H
