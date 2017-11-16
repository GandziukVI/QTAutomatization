#include "AgU25xxMEASureSubSys.h"

AgU25xxMEASureSubSys::AgU25xxMEASureSubSys()
    : IAg25xxSubsystem("MEAS")
{
    COUNterSubsystem = getSubSubSystem("COUN");
    DIGitalSubsystem = getSubSubSystem("DIG");
}

QString AgU25xxMEASureSubSys::cmdMeasureVoltage(AgU25xxAInChannels channel)
{
    QString cmdStr = QObject::tr("VOLT:DC? (@%1)")
            .arg(extGetAnalogInChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxMEASureSubSys::cmdMeasureVoltage(QVector<AgU25xxAInChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAnalogInChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "VOLT:DC? (@";

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

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
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "DATA? (@";

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

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
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "FREQ? (@";

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

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
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "PER? (@";

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

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
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "PWID? (@";

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

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
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "TOT? (@";

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

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
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "DIG? (@";

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

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
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "BIT? " << bitNum << ",(@";

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return DIGitalSubsystem.buildCommand(cmdStr);
}

