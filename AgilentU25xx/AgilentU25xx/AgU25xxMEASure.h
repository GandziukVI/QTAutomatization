#ifndef AGU25XXMEASURE_H
#define AGU25XXMEASURE_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"

class AgU25xxMEASure : public IAg25xxSubsystem
{
public:
    AgU25xxMEASure();

    QString cmdMeasureVoltage(AgU25xxVOLTage::VoltageChannels channel);
    QString cmdMeasureVoltage(QVector<AgU25xxVOLTage::VoltageChannels> channels);
};

#endif // AGU25XXMEASURE_H
