#include "AgU25xxROUTeSubSys.h"
#include <QObject>

AgU25xxROUTeSubSys::AgU25xxROUTeSubSys()
    : IAgU25xxSubsystem("ROUT"),
      IAgU25xxSubsystemExtensions()
{
    CHANnelSubSys = getSubSubSystem("CHAN");
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelRange(AgU25xxEnumAIChannelRanges range, AgU25xxEnumAIChannels channel)
{
    QString cmdStr = QObject::tr("RANG %1, (@%2)")
            .arg(extGetAIChannelRangeStr(range))
            .arg(extGetAIChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelRanges(AgU25xxEnumAIChannelRanges range, QVector<AgU25xxEnumAIChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("RANG %1,%2")
            .arg(extGetAIChannelRangeStr(range))
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelRange(AgU25xxEnumAIChannels channel)
{
    QString cmdStr = QObject::tr("RANG? (@%1)")
            .arg(extGetAIChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelRanges(QVector<AgU25xxEnumAIChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("RANG? %1")
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelPolarity(AgU25xxEnumAIChannelPolaities polarity, AgU25xxEnumAIChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetAIChannelPolarityStr(polarity))
            .arg(extGetAIChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelPolarity(AgU25xxEnumAIChannelPolaities polarity, QVector<AgU25xxEnumAIChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("POL %1, %2")
            .arg(extGetAIChannelPolarityStr(polarity))
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelPolarity(AgU25xxEnumAIChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetAIChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelPolarity(QVector<AgU25xxEnumAIChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("POL? %1")
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAOChannelPolarity(AgU25xxEnumAOChannelPolarities polarity, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetAOChannelPolarityStr(polarity))
            .arg(extGetAOChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAOChannelPolarity(AgU25xxEnumAOChannelPolarities polarity, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("POL %1, %2")
            .arg(extGetAOChannelPolarityStr(polarity))
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAOChannelPolarity(AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetAOChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAOChannelPolarity(QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("POL? %1")
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAOChannelReferenceSource(AgU25xxEnumAOChannelRSouRCes rSource, AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("RSRC %1, (@%2)")
            .arg(extGetAOChannelRefereceSource(rSource))
            .arg(extGetAOChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAOChannelsReferenceSource(AgU25xxEnumAOChannelRSouRCes rSource, QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("RSRC %1, %2")
            .arg(extGetAOChannelRefereceSource(rSource))
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAOChannelReferenceSource(AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("RSRC? (@%1)")
            .arg(extGetAOChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAOChannelsReferenceSource(QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("RSRC? %1")
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAOChannelsReferenceVoltage(double voltage)
{
    QString cmdStr = QObject::tr("RVOL %1")
            .arg(voltage);

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAOChannelsReferenceVoltage()
{
    QString cmdStr = QString("RVOL?");
    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, AgU25xxEnumAIChannels channel)
{
    int state = enabled? 1 : 0;
    QString cmdStr = QObject::tr("ENAB %1, (@%2)")
            .arg(state)
            .arg(extGetAIChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, QVector<AgU25xxEnumAIChannels> channels)
{
    int state = enabled? 1 : 0;

    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("ENAB %1, %2")
            .arg(state)
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, AgU25xxEnumAOChannels channel)
{
    int state = enabled? 1 : 0;
    QString cmdStr = QObject::tr("ENAB %1, (@%2)")
            .arg(state)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, QVector<AgU25xxEnumAOChannels> channels)
{
    int state = enabled? 1 : 0;

    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("ENAB %1, %2")
            .arg(state)
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(AgU25xxEnumAIChannels channel)
{
    QString cmdStr = QObject::tr("ENAB? (@%1)")
            .arg(extGetAIChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(QVector<AgU25xxEnumAIChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("ENAB? %1")
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(AgU25xxEnumAOChannels channel)
{
    QString cmdStr = QObject::tr("ENAB? (@%1)")
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(QVector<AgU25xxEnumAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("ENAB? %1")
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}
