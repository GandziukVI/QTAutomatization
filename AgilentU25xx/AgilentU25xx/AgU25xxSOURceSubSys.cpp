#include "AgU25xxSOURceSubSys.h"
#include <QObject>

AgU25xxSOURceSubSys::AgU25xxSOURceSubSys()
    : IAgU25xxSubsystem("SOUR"),
      IAgU25xxSubsystemExtensions()
{
    VOLTageSubsystem = getSubSubSystem("VOLT");
    DIGitalSubsystem = getSubSubSystem("DIG");
    DIGitalDataSubSubsystem = DIGitalSubsystem.getSubSubSystem("DATA");
}

QString AgU25xxSOURceSubSys::cmdSetVoltage(double voltage, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("LEV %1, (@%2)")
            .arg(voltage)
            .arg(extGetAOChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetVoltage(double voltage, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("LEV %1, %2")
            .arg(voltage)
            .arg(extCreateChannelsString(channelNums));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetVoltage(AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("LEV? (@%1)")
            .arg(extGetAOChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetVoltage(QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("LEV? %1")
            .arg(extCreateChannelsString(channelNums));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetVoltagePolarity(AgU25xxEnumAOChannelPolarities polarity, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetAOChannelPolarityStr(polarity))
            .arg(extGetAOChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetVoltagePolarity(AgU25xxEnumAOChannelPolarities polarity, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("POL %1, %2")
            .arg(extGetAOChannelPolarityStr(polarity))
            .arg(extCreateChannelsString(channelNums));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetVoltagePolarity(AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetAOChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetVoltagePolarity(QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("POL? %1")
            .arg(extCreateChannelsString(channelNums));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetVoltageRefSource(AgU25xxEnumAOChannelRSouRCes refSource, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("RSRC %1, (@%2)")
            .arg(extGetAOChannelRefereceSource(refSource))
            .arg(extGetAOChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetVoltageRefSource(AgU25xxEnumAOChannelRSouRCes refSource, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("RSRC %1, %2")
            .arg(extGetAOChannelRefereceSource(refSource))
            .arg(extCreateChannelsString(channelNums));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetVoltageRefSource(AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("RSRC? (@%1)")
            .arg(extGetAOChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetVoltageRefSource(QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("RSRC? %1")
            .arg(extCreateChannelsString(channelNums));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetVoltageRefValue(double voltage)
{
    QString cmdStr = QObject::tr("RVOL %1")
            .arg(voltage);

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetVoltageRefValue()
{
    QString cmdStr = QString("RVOL?");
    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetDigByte(unsigned short data, AgU25xxEnumDigitalChannels channel)
{
    QString cmdStr = QObject::tr("DATA %1, (@%2)")
            .arg(data)
            .arg(extGetDigChannel(channel));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetDigByte(unsigned short data, QVector<AgU25xxEnumDigitalChannels> channels)
{
    QVector<unsigned int> channelNums = extGetDigChannels(channels);

    QString cmdStr = QObject::tr("DATA %1, %2")
            .arg(data)
            .arg(extCreateChannelsString(channelNums));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetDigByte(AgU25xxEnumDigitalChannels channel)
{
    QString cmdStr = QObject::tr("DATA? (@%1)")
            .arg(extGetDigChannel(channel));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetDigByte(QVector<AgU25xxEnumDigitalChannels> channels)
{
    QVector<unsigned int> channelNums = extGetDigChannels(channels);

    QString cmdStr = QObject::tr("DATA? %1")
            .arg(extCreateChannelsString(channelNums));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetDigBit(bool value, unsigned short bitNum, AgU25xxEnumDigitalChannels channel)
{
    unsigned short int bitVal = value? 1 : 0;

    QString cmdStr = QObject::tr("BIT %1, %2, (@%3)")
            .arg(bitVal)
            .arg(bitNum)
            .arg(extGetDigChannel(channel));

    return DIGitalDataSubSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdSetDigBit(bool value, unsigned short bitNum, QVector<AgU25xxEnumDigitalChannels> channels)
{
    unsigned short int bitVal = value? 1 : 0;

    QVector<unsigned int> channelNums = extGetDigChannels(channels);

    QString cmdStr = QObject::tr("BIT %1, %2, %3")
            .arg(bitVal)
            .arg(bitNum)
            .arg(extCreateChannelsString(channelNums));

    return DIGitalDataSubSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetDigBit(unsigned short bitNum, AgU25xxEnumDigitalChannels channel)
{
    QString cmdStr = QObject::tr("BIT? %1 (@%2)")
            .arg(bitNum)
            .arg(extGetDigChannel(channel));

    return DIGitalDataSubSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSOURceSubSys::cmdGetDigBit(unsigned short bitNum, QVector<AgU25xxEnumDigitalChannels> channels)
{
    QVector<unsigned int> channelNums = extGetDigChannels(channels);

    QString cmdStr = QObject::tr("BIT? %1, %2")
            .arg(bitNum)
            .arg(extCreateChannelsString(channelNums));

    return DIGitalDataSubSubsystem.buildCommand(cmdStr);
}
