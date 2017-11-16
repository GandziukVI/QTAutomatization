#include "AgU25xxSENSeSubSys.h"

AgU25xxSENSeSubSys::AgU25xxSENSeSubSys()
    : IAgU25xxSubsystem("SENS"),
      IAgU25xxSubsystemExtensions()
{
    VOLTageSubsystem = getSubSubSystem("VOLT");
    COUNterSubsystem = getSubSubSystem("COUN");
    COUNterGateSubsubsystem = COUNterSubsystem.getSubSubSystem("GATE");
    COUNterClockSubsubsystem = COUNterSubsystem.getSubSubSystem("CLK");
    COUNterTotalizeSubsubsystem = COUNterSubsystem.getSubSubSystem("TOT");
    COUNterTotalizeUDOWnSubsubsystem = COUNterTotalizeSubsubsystem.getSubSubSystem("UDOW");
}

QString AgU25xxSENSeSubSys::cmdSetVoltageRange(AgU25xxAInChannelRanges range, AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("RANG %1, (@%2)")
            .arg(extGetAIChannelRange(range))
            .arg(extGetAIChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetVoltageRange(AgU25xxAInChannelRanges range, QVector<AgU25xxAInChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetAIChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("RANG %1, (@")
                    .arg(extGetAIChannelRange(range));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetVoltageRange(AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("RANG? (@%1)")
            .arg(extGetAIChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetVoltageRange(QVector<AgU25xxAInChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetAIChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("RANG? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetVoltagePolarity(AgU25xxAInChannelPolaities polarity, AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetAIChannelPolarity(polarity))
            .arg(extGetAIChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetVoltagePolarity(AgU25xxAInChannelPolaities polarity, QVector<AgU25xxAInChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetAIChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("POL %1, (@")
                    .arg(extGetAIChannelPolarity(polarity));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetVoltagePolarity(AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetAIChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetVoltagePolarity(QVector<AgU25xxAInChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetAIChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("POL? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetVoltageAveraging(unsigned int avgNum)
{
    QString cmdStr = QObject::tr("AVER %1")
            .arg(avgNum);

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetVoltageAveraging()
{
    QString cmdStr = QString("AVER?");
    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterFunction(AgU25xxCounterFunctions function, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("FUNC %1, (@%2)")
            .arg(extGetCOUNterFunc(function))
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterFunction(AgU25xxCounterFunctions function, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("FUNC %1, (@")
                    .arg(extGetCOUNterFunc(function));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterFunction(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("FUNC? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterFunction(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("FUNC? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterMeasAbort(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("ABOR (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterMeasAbort(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("ABOR (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGateSource(AgU25xxCounterGateSources counterSrc, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR %1, (@%2)")
            .arg(extGetCOUNterGateSource(counterSrc))
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGateSources(AgU25xxCounterGateSources counterSrc, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("SOUR %1 (@")
                    .arg(extGetCOUNterGateSource(counterSrc));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGateSource(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGateSources(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("SOUR? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGatePolarity(AgU25xxCounterGatePolarities gatePolarity, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetCOUNterGatePolarity(gatePolarity))
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGatePolarities(AgU25xxCounterGatePolarities gatePolarity, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("POL %1, (@")
                    .arg(extGetCOUNterGatePolarity(gatePolarity));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGatePolarity(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGatePolarities(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("POL? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGateEnabled(AgU25xxCounterGateStates gateState, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("CONT %1, (@%2)")
            .arg(extGetCOUNterGateState(gateState))
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGateEnabled(AgU25xxCounterGateStates gateState, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("CONT %1 (@")
                    .arg(extGetCOUNterGateState(gateState));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGateEnabled(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("CONT? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGateEnabled(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("CONT? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterClockSrc(AgU25xxCounterClockSources clkSrc, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR %1, (@%2)")
            .arg(extGetCOUNterClockSource(clkSrc))
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterClockSrc(AgU25xxCounterClockSources clkSrc, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("SOUR %1, (@")
                    .arg(extGetCOUNterClockSource(clkSrc));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterClockSrc(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterClockSrc(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("SOUR? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterInternalClockFreq()
{
    QString cmdStr = QString("INT?");
    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterExternalClockFreq(unsigned int clkFreq, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("EXT %1, (@%2)")
            .arg(clkFreq)
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterExternalClockFreq(unsigned int clkFreq, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("EXT %1, (@")
                    .arg(clkFreq);

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterExternalClockFreq(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("EXT (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterExternalClockFreq(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("EXT (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterClockPolarity(AgU25xxCounterClockPolarities clkPolarity, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetCOUNterClockPolarity(clkPolarity))
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterClockPolarity(AgU25xxCounterClockPolarities clkPolarity, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("POL %1, (@")
                    .arg(extGetCOUNterClockPolarity(clkPolarity));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterClockPolarity(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterClockPolarity(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("POL? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeInitVal(unsigned int initVal, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("IVAL %1, (@%2)")
            .arg(initVal)
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeInitVal(unsigned int initVal, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("IVAL %1, (@")
                    .arg(initVal);

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeInitVal(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("IVAL? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeInitVal(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("IVAL? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterTOTalizeInitiate(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("INIT (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterTOTalizeInitiate(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("INIT (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterTOTalizeClear(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("CLE (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterTOTalizeClear(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("CLE (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeCountingSrc(AgU25xxCounterTotalizeCountingSrc totSrc, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR %1, (@%2)")
            .arg(extGetCOUNterTotalizeCountingSrc(totSrc))
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeCountingSrc(AgU25xxCounterTotalizeCountingSrc totSrc, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("SOUR %1 (@")
                    .arg(extGetCOUNterTotalizeCountingSrc(totSrc));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeCountingSrc(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeCountingSrc(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("SOUR? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeCountingDir(AgU25xxCounterTotalizeCountingDir totDir, AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("DIR %1, (@%2)")
            .arg(extGetCOUNterTotalizeCountingDir(totDir))
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeCountingDir(AgU25xxCounterTotalizeCountingDir totDir, QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QObject::tr("DIR %1 (@")
                    .arg(extGetCOUNterTotalizeCountingDir(totDir));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeCountingDir(AgU25xxCounterChannels channel)
{
    QString cmdStr = QObject::tr("DIR? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeCountingDir(QVector<AgU25xxCounterChannels> channels)
{
    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    QVector<unsigned int> channelNums = extGetCounterChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    cmdStrStream << QString("DIR? (@");

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}
