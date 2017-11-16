#ifndef AGU25XXMEASURE_H
#define AGU25XXMEASURE_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxMEASureSubSys : public IAg25xxSubsystem
{
public:
    AgU25xxMEASureSubSys();

    QString cmdMeasureVoltage(AgU25xxVOLTage::VoltageChannels channel);
    QString cmdMeasureVoltage(QVector<AgU25xxVOLTage::VoltageChannels> channels);
    QString cmdMeasureCounterData(AgU25xxCOUNter::CounterChannels channel);
    QString cmdMeasureCounterData(QVector<AgU25xxCOUNter::CounterChannels> channels);
    QString cmdMeasureCounterFrequency(AgU25xxCOUNter::CounterChannels channel);
    QString cmdMeasureCounterFrequency(QVector<AgU25xxCOUNter::CounterChannels> channels);
    QString cmdMeasureCounterPeriod(AgU25xxCOUNter::CounterChannels channel);
    QString cmdMeasureCounterPeriod(QVector<AgU25xxCOUNter::CounterChannels> channels);
    QString cmdMeasureCounterPulseWidth(AgU25xxCOUNter::CounterChannels channel);
    QString cmdMeasureCounterPulseWidth(QVector<AgU25xxCOUNter::CounterChannels> channels);
    QString cmdMeasureCounterTotalize(AgU25xxCOUNter::CounterChannels channel);
    QString cmdMeasureCounterTotalize(QVector<AgU25xxCOUNter::CounterChannels> channels);
    QString cmdMeasureDigitalByte(AgU25xxDIGital::DigitalChannels channel);
    QString cmdMeasureDigitalByte(QVector<AgU25xxDIGital::DigitalChannels> channels);
    QString cmdMeasureDigitalBit(unsigned short int bitNum, AgU25xxDIGital::DigitalChannels channel);
    QString cmdMeasureDigitalBit(unsigned short int bitNum, QVector<AgU25xxDIGital::DigitalChannels> channels);

private:
    IAg25xxSubsystem COUNterSubsystem;
    IAg25xxSubsystem DIGitalSubsystem;
};

#endif // AGU25XXMEASURE_H
