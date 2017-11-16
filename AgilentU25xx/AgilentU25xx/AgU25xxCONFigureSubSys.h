#ifndef AGU25XXCONFIGURE_H
#define AGU25XXCONFIGURE_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxCONFigureSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxCONFigureSubSys();    

    QString cmdSetDigitalDirection(AgU25xxDigitalDirection direction, AgU25xxDigitalChannels channel);
    QString cmdSetDigitalDirection(AgU25xxDigitalDirection direction, QVector<AgU25xxDigitalChannels> channels);
    QString cmdGetDigitalDirection(AgU25xxDigitalChannels channel);
    QString cmdGetDigitalDirection(QVector<AgU25xxDigitalChannels> channels);
    QString cmdSetTimeBaseSrc(AgU25xxTimeSrcModes timeSrcMode);
    QString cmdGetTimeBaseSrc();
    QString cmdSetExtClockFreq(unsigned int frequency);
    QString cmdGetExtClockFreq();
    QString cmdSetSSIMode(AgU25xxSSIModes ssiMode);
    QString cmdGetSSIMode();

private:
    IAgU25xxSubsystem DIGitalSubsystem;
    IAgU25xxSubsystem TIMEbaseSubsystem;
};

#endif // AGU25XXCONFIGURE_H
