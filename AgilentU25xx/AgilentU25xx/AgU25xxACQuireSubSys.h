#ifndef ACQUIRE_H
#define ACQUIRE_H

#include "agilentu25xx_global.h"

#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

#include <QString>

class AGILENTU25XXSHARED_EXPORT AgU25xxACQuireSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxACQuireSubSys();

    QString cmdSetSamplingRate(const unsigned int samplingRate);
    QString cmdGetSamplingrate();
    QString cmdSetPointsSingleShot(unsigned int nPoints);
    QString cmdGetPointsSingleShot();
};

#endif // ACQUIRE_H
