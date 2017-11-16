#ifndef AGU25XXMEASURE_H
#define AGU25XXMEASURE_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxMEASureSubSys : public IAg25xxSubsystem
{
public:
    AgU25xxMEASureSubSys();

    QString cmdMeasureVoltage(AgU25xxVoltageChannels channel);
    QString cmdMeasureVoltage(QVector<AgU25xxVoltageChannels> channels);
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
    IAg25xxSubsystem COUNterSubsystem;
    IAg25xxSubsystem DIGitalSubsystem;
};

#endif // AGU25XXMEASURE_H
