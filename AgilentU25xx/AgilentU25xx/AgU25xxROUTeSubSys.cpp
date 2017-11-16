#include "AgU25xxROUTeSubSys.h"

AgU25xxROUTeSubSys::AgU25xxROUTeSubSys()
    : IAg25xxSubsystem("ROUT")
{
    CHANnelSubSys = getSubSubSystem("CHAN");
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelRange(AgU25xxROUTe::AnalogInChannelRanges range, AgU25xxROUTe::AnalogInChannels channel)
{
    QString cmdStr = QObject::tr("RANG %1, (@%2)")
            .arg(extGetAnalogInChannelRange(range))
            .arg(extGetAnalogInChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelRanges(AgU25xxROUTe::AnalogInChannelRanges range, QVector<AgU25xxROUTe::AnalogInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAnalogInChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("RANG %1,(@")
                    .arg(extGetAnalogInChannelRange(range));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelRange(AgU25xxROUTe::AnalogInChannels channel)
{
    QString cmdStr = QObject::tr("RANG? (@%1)")
            .arg(extGetAnalogInChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelRanges(QVector<AgU25xxROUTe::AnalogInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAnalogInChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QString("RANG? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelPolarity(AgU25xxROUTe::AnalogInChannelPolaities polarity, AgU25xxROUTe::AnalogInChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetAnalogInChannelPolarity(polarity))
            .arg(extGetAnalogInChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAIChannelPolarities(AgU25xxROUTe::AnalogInChannelPolaities polarity, QVector<AgU25xxROUTe::AnalogInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAnalogInChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("POL %1, (@")
                    .arg(extGetAnalogInChannelPolarity(polarity));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelPolarity(AgU25xxROUTe::AnalogInChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetAnalogInChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAIChannelPolarities(QVector<AgU25xxROUTe::AnalogInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAnalogInChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QString("POL? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAOChannelReferenceSource(AgU25xxROUTe::AnalogOutChannelRSouRCes rSource, AgU25xxOUTPut::AOChannels channel)
{
    QString cmdStr = QObject::tr("RSRC %1, (@%2)")
            .arg(extGetAnalogOutChannelRefereceSource(rSource))
            .arg(extGetAOChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetAOChannelsReferenceSource(AgU25xxROUTe::AnalogOutChannelRSouRCes rSource, QVector<AgU25xxOUTPut::AOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("RSRC %1, (@")
                    .arg(extGetAnalogOutChannelRefereceSource(rSource));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAOChannelReferenceSource(AgU25xxOUTPut::AOChannels channel)
{
    QString cmdStr = QObject::tr("RSRC? (@%1)")
            .arg(extGetAOChannel(channel));

    return CHANnelSubSys.buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetAOChannelsReferenceSource(QVector<AgU25xxOUTPut::AOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QString("RSRC? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

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

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, AgU25xxROUTe::AnalogInChannels channel)
{
    int state = enabled? 1 : 0;
    QString cmdStr = QObject::tr("ENAB %1, (@%2)")
            .arg(state)
            .arg(extGetAnalogInChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, QVector<AgU25xxROUTe::AnalogInChannels> channels)
{
    int state = enabled? 1 : 0;

    QVector<unsigned int> channelNums = extGetAnalogInChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("ENAB %1, (@")
                    .arg(state);

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, AgU25xxOUTPut::AOChannels channel)
{
    int state = enabled? 1 : 0;
    QString cmdStr = QObject::tr("ENAB %1, (@%2)")
            .arg(state)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdSetRouteEnabled(bool enabled, QVector<AgU25xxOUTPut::AOChannels> channels)
{
    int state = enabled? 1 : 0;

    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("ENAB %1, (@")
                    .arg(state);

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(AgU25xxROUTe::AnalogInChannels channel)
{
    QString cmdStr = QObject::tr("ENAB? (@%1)")
            .arg(extGetAnalogInChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(QVector<AgU25xxROUTe::AnalogInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAnalogInChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("ENAB? (@")
                    .arg(state);

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(AgU25xxOUTPut::AOChannels channel)
{
    QString cmdStr = QObject::tr("ENAB? (@%1)")
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxROUTeSubSys::cmdGetRouteEnabled(QVector<AgU25xxOUTPut::AOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("ENAB? (@")
                    .arg(state);

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}

