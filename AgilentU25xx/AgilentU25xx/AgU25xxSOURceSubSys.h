#ifndef AGU25XXSOURCESUBSYS_H
#define AGU25XXSOURCESUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxSOURceSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxSOURceSubSys();

    QString cmdSetVoltage(double voltage, AgU25xxEnumAOChannels channel);
    QString cmdSetVoltage(double voltage, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdGetVoltage(AgU25xxEnumAOChannels channel);
    QString cmdGetVoltage(QVector<AgU25xxEnumAOChannels> channels);
    QString cmdSetVoltagePolarity(AgU25xxEnumAOChannelPolarities polarity, AgU25xxEnumAOChannels channel);
    QString cmdSetVoltagePolarity(AgU25xxEnumAOChannelPolarities polarity, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdGetVoltagePolarity(AgU25xxEnumAOChannels channel);
    QString cmdGetVoltagePolarity(QVector<AgU25xxEnumAOChannels> channels);
    QString cmdSetVoltageRefSource(AgU25xxEnumAOChannelRSouRCes refSource, AgU25xxEnumAOChannels channel);
    QString cmdSetVoltageRefSource(AgU25xxEnumAOChannelRSouRCes refSource, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdGetVoltageRefSource(AgU25xxEnumAOChannels channel);
    QString cmdGetVoltageRefSource(QVector<AgU25xxEnumAOChannels> channels);
    QString cmdSetVoltageRefValue(double voltage);
    QString cmdGetVoltageRefValue();
    QString cmdSetDigByte(unsigned short int data, AgU25xxEnumDigitalChannels channel);
    QString cmdSetDigByte(unsigned short int data, QVector<AgU25xxEnumDigitalChannels> channels);
    QString cmdGetDigByte(AgU25xxEnumDigitalChannels channel);
    QString cmdGetDigByte(QVector<AgU25xxEnumDigitalChannels> channels);
    QString cmdSetDigBit(bool value, unsigned short int bitNum, AgU25xxEnumDigitalChannels channel);
    QString cmdSetDigBit(bool value, unsigned short int bitNum, QVector<AgU25xxEnumDigitalChannels> channels);
    QString cmdGetDigBit(unsigned short int bitNum, AgU25xxEnumDigitalChannels channel);
    QString cmdGetDigBit(unsigned short int bitNum, QVector<AgU25xxEnumDigitalChannels> channels);

private:
    IAgU25xxSubsystem VOLTageSubsystem;
    IAgU25xxSubsystem DIGitalSubsystem;
    IAgU25xxSubsystem DIGitalDataSubSubsystem;
};

#endif // AGU25XXSOURCESUBSYS_H
