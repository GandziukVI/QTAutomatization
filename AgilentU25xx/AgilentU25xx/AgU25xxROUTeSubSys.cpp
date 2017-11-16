#include "AgU25xxROUTeSubSys.h"
#include <QObject>

AgU25xxROUTeSubSys::AgU25xxROUTeSubSys()
    : IAgU25xxSubsystem("ROUT"),
      IAgU25xxSubsystemExtensions()
{
    CHANnelSubSys = getSubSubSystem("CHAN");
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelRange(AgU25xxAInChannelRanges range, AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("RANG %1, (@%2)")
            .arg(extGetAIChannelRange(range))
            .arg(extGetAIChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelRanges(AgU25xxAInChannelRanges range, QVector<AgU25xxAInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("RANG %1,%2")
            .arg(extGetAIChannelRange(range))
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelRange(AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("RANG? (@%1)")
            .arg(extGetAIChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelRanges(QVector<AgU25xxAInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("RANG? %1")
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelPolarity(AgU25xxAInChannelPolaities polarity, AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetAIChannelPolarity(polarity))
            .arg(extGetAIChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelPolarities(AgU25xxAInChannelPolaities polarity, QVector<AgU25xxAInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("POL %1, %2")
            .arg(extGetAIChannelPolarity(polarity))
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelPolarity(AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetAIChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelPolarities(QVector<AgU25xxAInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("POL? %1")
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAOChannelReferenceSource(AgU25xxAOutChannelRSouRCes rSource, AgU25xxAOChannels channel)
{
    QString cmdStr = QObject::tr("RSRC %1, (@%2)")
            .arg(extGetAOChannelRefereceSource(rSource))
            .arg(extGetAOChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAOChannelsReferenceSource(AgU25xxAOutChannelRSouRCes rSource, QVector<AgU25xxAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("RSRC %1, %2")
            .arg(extGetAOChannelRefereceSource(rSource))
            .arg(extCreateChannelsString(channelNums));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAOChannelReferenceSource(AgU25xxAOChannels channel)
{
    QString cmdStr = QObject::tr("RSRC? (@%1)")
            .arg(extGetAOChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAOChannelsReferenceSource(QVector<AgU25xxAOChannels> channels)
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

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, AgU25xxAInChannels channel)
{
    int state = enabled? 1 : 0;
    QString cmdStr = QObject::tr("ENAB %1, (@%2)")
            .arg(state)
            .arg(extGetAIChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, QVector<AgU25xxAInChannels> channels)
{
    int state = enabled? 1 : 0;

    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("ENAB %1, %2")
            .arg(state)
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, AgU25xxAOChannels channel)
{
    int state = enabled? 1 : 0;
    QString cmdStr = QObject::tr("ENAB %1, (@%2)")
            .arg(state)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, QVector<AgU25xxAOChannels> channels)
{
    int state = enabled? 1 : 0;

    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("ENAB %1, %2")
            .arg(state)
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("ENAB? (@%1)")
            .arg(extGetAIChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(QVector<AgU25xxAInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("ENAB? %1")
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(AgU25xxAOChannels channel)
{
    QString cmdStr = QObject::tr("ENAB? (@%1)")
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(QVector<AgU25xxAOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);

    QString cmdStr = QObject::tr("ENAB? %1")
            .arg(extCreateChannelsString(channelNums));

    return buildCommand(cmdStr);
}
