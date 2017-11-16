#ifndef AGU25XXCONFIGURE_H
#define AGU25XXCONFIGURE_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxCONFigureSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxCONFigureSubSys();
    ~AgU25xxCONFigureSubSys();

    QString cmdConfDigitalDirection(AgU25xxDigitalDirection direction, AgU25xxDigitalChannels channel);
    QString cmdConfDigitalDirection(AgU25xxDigitalDirection direction, QVector<AgU25xxDigitalChannels> channels);
    QString cmdGetConfDigitalDirection(AgU25xxDigitalChannels channel);
    QString cmdGetConfDigitalDirection(QVector<AgU25xxDigitalChannels> channels);
    QString cmdSetTimeBaseSrc(AgU25xxTimeSrcModes timeSrcMode);
    QString cmdGetTimeBaseSrc();
    QString cmdConfExtClockFreq(unsigned int frequency);
    QString cmdGetExtClockFreq();
    QString cmdConfSSI(SSIModes ssiMode);
    QString cmdGetSSIMode();

private:
    IAgU25xxSubsystem DIGitalSubsystem;
    IAgU25xxSubsystem TIMEbaseSubsystem;
};

#endif // AGU25XXCONFIGURE_H
