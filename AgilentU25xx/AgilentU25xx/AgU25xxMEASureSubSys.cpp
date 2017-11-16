#include "AgU25xxMEASureSubSys.h"
#include <QObject>

AgU25xxMEASureSubSys::AgU25xxMEASureSubSys()
    : IAgU25xxSubsystem("MEAS"),
      IAgU25xxSubsystemExtensions()
{
    COUNterSubsystem = getSubSubSystem("COUN");
    DIGitalSubsystem = getSubSubSystem("DIG");
}

QString AgU25xxMEASureSubSys::cmdMeasureVoltage(AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("VOLT:DC? (@%1)")
            .arg(extGetAIChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureVoltage(QVector<AgU25xxAInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("VOLT:DC? %1")
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterData(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("DATA? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterData(QVector<AgU25xxCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("DATA? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterFrequency(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("FREQ? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterFrequency(QVector<AgU25xxCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("FREQ? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterPeriod(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("PER? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterPeriod(QVector<AgU25xxCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("PER? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterPulseWidth(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("PWID? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterPulseWidth(QVector<AgU25xxCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("PWID? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterTotalize(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("TOT? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureCounterTotalize(QVector<AgU25xxCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("TOT? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureDigitalByte(AgU25xxDigitalChannels channel)
{
    QString cmdStr = QObject::tr("DIG? (@%1)")
            .arg(extGetDigChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureDigitalByte(QVector<AgU25xxDigitalChannels> channels)
{
    QVector<unsigned int> channelNums = extGetDigChannels(channels);

    QString cmdStr = QObject::tr("DIG? %1")
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureDigitalBit(unsigned short bitNum, AgU25xxDigitalChannels channel)
{
    QString cmdStr = QObject::tr("BIT? %1,(@%2)")
            .arg(bitNum)
            .arg(extGetDigChannel(channel));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureDigitalBit(unsigned short bitNum, QVector<AgU25xxDigitalChannels> channels)
{
    QVector<unsigned int> channelNums = extGetDigChannels(channels);

    QString cmdStr = QObject::tr("BIT? %1,%2")
            .arg(bitNum)
            .arg(extCreateChannelsString(channelNums));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

