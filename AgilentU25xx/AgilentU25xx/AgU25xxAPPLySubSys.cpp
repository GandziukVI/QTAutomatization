#include "AgU25xxAPPLySubSys.h"
#include <QObject>

AgU25xxAPPLySubSys::AgU25xxAPPLySubSys()
    : IAgU25xxSubsystem("APPL"),
      IAgU25xxSubsystemExtensions()
{
}

QString AgU25xxAPPLySubSys::cmdGetAOParams(AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("APPL? (@%1)")
            .arg(extGetAOChannel(channel));

    return cmdStr;
}

QString AgU25xxAPPLySubSys::cmdGetAOParams(QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("APPL? %1")
            .arg(extCreateChannelsString(channelNums));

    return cmdStr;
}

QString AgU25xxAPPLySubSys::cmdApplySineWave(double amplitude, double offset, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("SIN %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplySineWave(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("SIN %1,%2,%3")
            .arg(amplitude)
            .arg(offset)
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplySquareWave(double amplitude, double offset, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("SQU %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplySquareWave(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("SQU %1,%2,%3")
            .arg(amplitude)
            .arg(offset)
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplySawToothWave(double amplitude, double offset, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("SAWT %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplySawToothWave(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("SAWT %1,%2,%3")
            .arg(amplitude)
            .arg(offset)
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplyTriangleWave(double amplitude, double offset, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("TRI %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplyTriangleWave(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("TRI %1,%2,%3")
            .arg(amplitude)
            .arg(offset)
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplyNoise(double amplitude, double offset, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("NOIS %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplyNoise(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("NOIS %1,%2,%3")
            .arg(amplitude)
            .arg(offset)
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplyUser(AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("USER (@%1)")
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLySubSys::cmdApplyUser(QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("USER %1")
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}
