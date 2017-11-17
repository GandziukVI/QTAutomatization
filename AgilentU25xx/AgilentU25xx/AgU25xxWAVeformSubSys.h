#ifndef AGU25XXWAVEFORMSUBSYS_H
#define AGU25XXWAVEFORMSUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxWAVeformSubSys :
        public IAgU25xxSubsystem,
        public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxWAVeformSubSys();

    QString cmdQueryAcquisitionData();
    QString cmdSetContACQPointsNum(unsigned int pointsNum);
    QString cmdGetContACQPointsNum();
    QString cmdGetBufferStatus();
    QString cmdGetAcquisitionConpleteStatus();
};

#endif // AGU25XXWAVEFORMSUBSYS_H
