#ifndef AGU25XXCONFIGURE_H
#define AGU25XXCONFIGURE_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxCONFigure : public IAg25xxSubsystem
{
public:
    AgU25xxCONFigure();
    ~AgU25xxCONFigure();

    QString cmdConfDigitalDirection(AgU25xxDIGital::DigitalDirection direction, AgU25xxDIGital::DigitalChannels channel);
    QString cmdConfDigitalDirection(AgU25xxDIGital::DigitalDirection direction, QVector<AgU25xxDIGital::DigitalChannels> channels);
    QString cmdGetConfDigitalDirection(AgU25xxDIGital::DigitalChannels channel);
    QString cmdGetConfDigitalDirection(QVector<AgU25xxDIGital::DigitalChannels> channels);
    QString cmdSetTimeBaseSrc(AgU25xxTIMEbase::TimeSrcModes timeSrcMode);
    QString cmdGetTimeBaseSrc();
    QString cmdConfExtClockFreq(unsigned int frequency);
    QString cmdGetExtClockFreq();
    QString cmdConfSSI(SSIModes ssiMode);
    QString cmdGetSSIMode();

private:
    IAg25xxSubsystem DIGitalSubsystem;
    IAg25xxSubsystem TIMEbaseSubsystem;
};

#endif // AGU25XXCONFIGURE_H
