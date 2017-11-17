#ifndef AGU25XXSOURCESUBSYS_H
#define AGU25XXSOURCESUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxSOURceSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxSOURceSubSys();

    QString cmdSetVoltage(double voltage, AgU25xxAOChannels channel);
    QString cmdSetVoltage(double voltage, QVector<AgU25xxAOChannels> channels);
    QString cmdGetVoltage(AgU25xxAOChannels channel);
    QString cmdGetVoltage(QVector<AgU25xxAOChannels> channels);
    QString cmdSetVoltagePolarity(AgU25xxAOChannelPolarities polarity, AgU25xxAOChannels channel);
    QString cmdSetVoltagePolarity(AgU25xxAOChannelPolarities polarity, QVector<AgU25xxAOChannels> channels);
    QString cmdGetVoltagePolarity(AgU25xxAOChannels channel);
    QString cmdGetVoltagePolarity(QVector<AgU25xxAOChannels> channels);
    QString cmdSetVoltageRefSource(AgU25xxAOChannelRSouRCes refSource, AgU25xxAOChannels channel);
    QString cmdSetVoltageRefSource(AgU25xxAOChannelRSouRCes refSource, QVector<AgU25xxAOChannels> channels);
    QString cmdGetVoltageRefSource(AgU25xxAOChannels channel);
    QString cmdGetVoltageRefSource(QVector<AgU25xxAOChannels> channels);
    QString cmdSetVoltageRefValue(double voltage);
    QString cmdGetVoltageRefValue();
    QString cmdSetDigByte(unsigned short int data, AgU25xxDigitalChannels channel);
    QString cmdSetDigByte(unsigned short int data, QVector<AgU25xxDigitalChannels> channels);
    QString cmdGetDigByte(AgU25xxDigitalChannels channel);
    QString cmdGetDigByte(QVector<AgU25xxDigitalChannels> channels);
    QString cmdSetDigBit(bool value, unsigned short int bitNum, AgU25xxDigitalChannels channel);
    QString cmdSetDigBit(bool value, unsigned short int bitNum, QVector<AgU25xxDigitalChannels> channels);
    QString cmdGetDigBit(unsigned short int bitNum, AgU25xxDigitalChannels channel);
    QString cmdGetDigBit(unsigned short int bitNum, QVector<AgU25xxDigitalChannels> channels);

private:
    IAgU25xxSubsystem VOLTageSubsystem;
    IAgU25xxSubsystem DIGitalSubsystem;
    IAgU25xxSubsystem DIGitalDataSubSubsystem;
};

#endif // AGU25XXSOURCESUBSYS_H
