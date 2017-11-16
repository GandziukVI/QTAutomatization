#ifndef AGU25XXMEASURE_H
#define AGU25XXMEASURE_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxMEASureSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxMEASureSubSys();

    QString cmdMeasureVoltage(AgU25xxAInChannels channel);
    QString cmdMeasureVoltage(QVector<AgU25xxAInChannels> channels);
    QString cmdMeasureCounterData(AgU25xxCounterChannels channel);
    QString cmdMeasureCounterData(QVector<AgU25xxCounterChannels> channels);
    QString cmdMeasureCounterFrequency(AgU25xxCounterChannels channel);
    QString cmdMeasureCounterFrequency(QVector<AgU25xxCounterChannels> channels);
    QString cmdMeasureCounterPeriod(AgU25xxCounterChannels channel);
    QString cmdMeasureCounterPeriod(QVector<AgU25xxCounterChannels> channels);
    QString cmdMeasureCounterPulseWidth(AgU25xxCounterChannels channel);
    QString cmdMeasureCounterPulseWidth(QVector<AgU25xxCounterChannels> channels);
    QString cmdMeasureCounterTotalize(AgU25xxCounterChannels channel);
    QString cmdMeasureCounterTotalize(QVector<AgU25xxCounterChannels> channels);
    QString cmdMeasureDigitalByte(AgU25xxDigitalChannels channel);
    QString cmdMeasureDigitalByte(QVector<AgU25xxDigitalChannels> channels);
    QString cmdMeasureDigitalBit(unsigned short int bitNum, AgU25xxDigitalChannels channel);
    QString cmdMeasureDigitalBit(unsigned short int bitNum, QVector<AgU25xxDigitalChannels> channels);

private:
    IAgU25xxSubsystem COUNterSubsystem;
    IAgU25xxSubsystem DIGitalSubsystem;
};

#endif // AGU25XXMEASURE_H
