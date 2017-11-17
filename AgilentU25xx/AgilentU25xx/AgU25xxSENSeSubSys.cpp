#include "AgU25xxSENSeSubSys.h"
#include <QObject>

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

QString AgU25xxSENSeSubSys::cmdSetVoltageRange(AgU25xxEnumAIChannelRanges range, AgU25xxEnumAIChannels channel)
{
    QString cmdStr = QObject::tr("RANG %1, (@%2)")
            .arg(extGetAIChannelRangeStr(range))
            .arg(extGetAIChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetVoltageRange(AgU25xxEnumAIChannelRanges range, QVector<AgU25xxEnumAIChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("RANG %1, %2")
            .arg(extGetAIChannelRangeStr(range))
            .arg(extCreateChannelsString(channelNums));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetVoltageRange(AgU25xxEnumAIChannels channel)
{
    QString cmdStr = QObject::tr("RANG? (@%1)")
            .arg(extGetAIChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetVoltageRange(QVector<AgU25xxEnumAIChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("RANG? %1")
            .arg(extCreateChannelsString(channelNums));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetVoltagePolarity(AgU25xxEnumAIChannelPolaities polarity, AgU25xxEnumAIChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetAIChannelPolarityStr(polarity))
            .arg(extGetAIChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetVoltagePolarity(AgU25xxEnumAIChannelPolaities polarity, QVector<AgU25xxEnumAIChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("POL %1, %2")
            .arg(extGetAIChannelPolarityStr(polarity))
            .arg(extCreateChannelsString(channelNums));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetVoltagePolarity(AgU25xxEnumAIChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetAIChannel(channel));

    return VOLTageSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetVoltagePolarity(QVector<AgU25xxEnumAIChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAIChannels(channels);

    QString cmdStr = QObject::tr("POL? %1")
            .arg(extCreateChannelsString(channelNums));

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

QString AgU25xxSENSeSubSys::cmdSetCounterFunction(AgU25xxEnumCounterFunctions function, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("FUNC %1, (@%2)")
            .arg(extGetCOUNterFunc(function))
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterFunction(AgU25xxEnumCounterFunctions function, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("FUNC %1, %2")
            .arg(extGetCOUNterFunc(function))
            .arg(extCreateChannelsString(channelNums));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterFunction(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("FUNC? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterFunction(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("FUNC? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterMeasAbort(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("ABOR (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterMeasAbort(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("ABOR %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGateSource(AgU25xxEnumCounterGateSources counterSrc, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR %1, (@%2)")
            .arg(extGetCOUNterGateSource(counterSrc))
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGateSources(AgU25xxEnumCounterGateSources counterSrc, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("SOUR %1 %2")
            .arg(extGetCOUNterGateSource(counterSrc))
            .arg(extCreateChannelsString(channelNums));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGateSource(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGateSources(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("SOUR? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGatePolarity(AgU25xxEnumCounterGatePolarities gatePolarity, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetCOUNterGatePolarity(gatePolarity))
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGatePolarities(AgU25xxEnumCounterGatePolarities gatePolarity, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("POL %1, %2")
            .arg(extGetCOUNterGatePolarity(gatePolarity))
            .arg(extCreateChannelsString(channelNums));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGatePolarity(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGatePolarities(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("POL? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGateEnabled(AgU25xxEnumCounterGateStates gateState, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("CONT %1, (@%2)")
            .arg(extGetCOUNterGateState(gateState))
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterGateEnabled(AgU25xxEnumCounterGateStates gateState, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("CONT %1 %2")
            .arg(extGetCOUNterGateState(gateState))
            .arg(extCreateChannelsString(channelNums));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGateEnabled(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("CONT? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterGateEnabled(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("CONT? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterGateSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterClockSrc(AgU25xxEnumCounterClockSources clkSrc, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR %1, (@%2)")
            .arg(extGetCOUNterClockSource(clkSrc))
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterClockSrc(AgU25xxEnumCounterClockSources clkSrc, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("SOUR %1, %2")
            .arg(extGetCOUNterClockSource(clkSrc))
            .arg(extCreateChannelsString(channelNums));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterClockSrc(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterClockSrc(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("SOUR? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterInternalClockFreq()
{
    QString cmdStr = QString("INT?");
    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterExternalClockFreq(unsigned int clkFreq, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("EXT %1, (@%2)")
            .arg(clkFreq)
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterExternalClockFreq(unsigned int clkFreq, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("EXT %1, %2")
            .arg(clkFreq)
            .arg(extCreateChannelsString(channelNums));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterExternalClockFreq(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("EXT (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterExternalClockFreq(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("EXT %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterClockPolarity(AgU25xxCounterEnumClockPolarities clkPolarity, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("POL %1, (@%2)")
            .arg(extGetCOUNterClockPolarity(clkPolarity))
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterClockPolarity(AgU25xxCounterEnumClockPolarities clkPolarity, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("POL %1, %2")
            .arg(extGetCOUNterClockPolarity(clkPolarity))
            .arg(extCreateChannelsString(channelNums));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterClockPolarity(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("POL? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterClockPolarity(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("POL? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterClockSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeInitVal(unsigned int initVal, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("IVAL %1, (@%2)")
            .arg(initVal)
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeInitVal(unsigned int initVal, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("IVAL %1, %2")
            .arg(initVal)
            .arg(extCreateChannelsString(channelNums));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeInitVal(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("IVAL? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeInitVal(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("IVAL? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterTOTalizeInitiate(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("INIT (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterTOTalizeInitiate(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("INIT %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterTOTalizeClear(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("CLE (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdCounterTOTalizeClear(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("CLE %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterTotalizeSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeCountingSrc(AgU25xxEnumCounterTotalizeCountingSrc totSrc, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR %1, (@%2)")
            .arg(extGetCOUNterTotalizeCountingSrc(totSrc))
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeCountingSrc(AgU25xxEnumCounterTotalizeCountingSrc totSrc, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("SOUR %1 %2")
            .arg(extGetCOUNterTotalizeCountingSrc(totSrc))
            .arg(extCreateChannelsString(channelNums));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeCountingSrc(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("SOUR? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeCountingSrc(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("SOUR? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeCountingDir(AgU25xxEnumCounterTotalizeCountingDir totDir, AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("DIR %1, (@%2)")
            .arg(extGetCOUNterTotalizeCountingDir(totDir))
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdSetCounterTOTalizeCountingDir(AgU25xxEnumCounterTotalizeCountingDir totDir, QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("DIR %1 %2")
            .arg(extGetCOUNterTotalizeCountingDir(totDir))
            .arg(extCreateChannelsString(channelNums));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeCountingDir(AgU25xxEnumCounterChannels channel)
{
    QString cmdStr = QObject::tr("DIR? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}

QString AgU25xxSENSeSubSys::cmdGetCounterTOTalizeCountingDir(QVector<AgU25xxEnumCounterChannels> channels)
{
    QVector<unsigned int> channelNums = extGetCounterChannels(channels);

    QString cmdStr = QObject::tr("DIR? %1")
            .arg(extCreateChannelsString(channelNums));

    return COUNterTotalizeUDOWnSubsubsystem.buildCommand(cmdStr);
}
