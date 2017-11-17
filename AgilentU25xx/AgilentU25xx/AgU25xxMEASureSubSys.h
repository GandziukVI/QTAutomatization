#ifndef AGU25XXMEASURE_H
#define AGU25XXMEASURE_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxMEASureSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxMEASureSubSys();

    QString cmdMeasureVoltage(AgU25xxEnumAIChannels channel);
    QString cmdMeasureVoltage(QVector<AgU25xxEnumAIChannels> channels);
    QString cmdMeasureCounterData(AgU25xxEnumCounterChannels channel);
    QString cmdMeasureCounterData(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdMeasureCounterFrequency(AgU25xxEnumCounterChannels channel);
    QString cmdMeasureCounterFrequency(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdMeasureCounterPeriod(AgU25xxEnumCounterChannels channel);
    QString cmdMeasureCounterPeriod(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdMeasureCounterPulseWidth(AgU25xxEnumCounterChannels channel);
    QString cmdMeasureCounterPulseWidth(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdMeasureCounterTotalize(AgU25xxEnumCounterChannels channel);
    QString cmdMeasureCounterTotalize(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdMeasureDigitalByte(AgU25xxEnumDigitalChannels channel);
    QString cmdMeasureDigitalByte(QVector<AgU25xxEnumDigitalChannels> channels);
    QString cmdMeasureDigitalBit(unsigned short int bitNum, AgU25xxEnumDigitalChannels channel);
    QString cmdMeasureDigitalBit(unsigned short int bitNum, QVector<AgU25xxEnumDigitalChannels> channels);

private:
    IAgU25xxSubsystem COUNterSubsystem;
    IAgU25xxSubsystem DIGitalSubsystem;
};

#endif // AGU25XXMEASURE_H
