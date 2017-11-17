#ifndef AGU25XXCONFIGURE_H
#define AGU25XXCONFIGURE_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxCONFigureSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxCONFigureSubSys();    

    QString cmdSetDigitalDirection(AgU25xxEnumDigitalDirection direction, AgU25xxEnumDigitalChannels channel);
    QString cmdSetDigitalDirection(AgU25xxEnumDigitalDirection direction, QVector<AgU25xxEnumDigitalChannels> channels);
    QString cmdGetDigitalDirection(AgU25xxEnumDigitalChannels channel);
    QString cmdGetDigitalDirection(QVector<AgU25xxEnumDigitalChannels> channels);
    QString cmdSetTimeBaseSrc(AgU25xxEnumTimeSrcModes timeSrcMode);
    QString cmdGetTimeBaseSrc();
    QString cmdSetExtClockFreq(unsigned int frequency);
    QString cmdGetExtClockFreq();
    QString cmdSetSSIMode(AgU25xxEnumSSIModes ssiMode);
    QString cmdGetSSIMode();

private:
    IAgU25xxSubsystem DIGitalSubsystem;
    IAgU25xxSubsystem TIMEbaseSubsystem;
};

#endif // AGU25XXCONFIGURE_H
