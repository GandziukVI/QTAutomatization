#ifndef ACQUIRE_H
#define ACQUIRE_H

#include "agilentu25xx_global.h"

#include "IAgU25xxSubsystem.h"

#include <QString>

class AGILENTU25XXSHARED_EXPORT AgU25xxACQuire : public IAg25xxSubsystem
{
public:
    AgU25xxACQuire();

    QString cmdSetSamplingRate(const unsigned int samplingRate);
    QString cmdGetSamplingrate();
    QString cmdSetPointsSingleShot(unsigned int nPoints);
    QString cmdGetPointsSingleShot();
};

#endif // ACQUIRE_H
