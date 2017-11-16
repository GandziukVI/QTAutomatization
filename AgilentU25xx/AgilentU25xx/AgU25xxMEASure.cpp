#include "AgU25xxMEASure.h"

AgU25xxMEASure::AgU25xxMEASure()
    : IAg25xxSubsystem("MEAS")
{
    COUNterSubsystem = getSubSubSystem("COUN");
    DIGitalSubsystem = getSubSubSystem("DIG");
}

QString AgU25xxMEASure::cmdMeasureVoltage(AgU25xxVOLTage::VoltageChannels channel)
{
    QString cmdStr = QObject::tr("VOLT:DC? (@%1)")
            .arg(extGetVoltageChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxMEASure::cmdMeasureVoltage(QVector<AgU25xxVOLTage::VoltageChannels> channels)
{
    QVector<unsigned int> channelNums = extGetVoltageChannels(channels);
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

QString AgU25xxMEASure::cmdMeasureCounterData(AgU25xxCOUNter::CounterChannels channel)
{
    QString cmdStr = QObject::tr("DATA? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASure::cmdMeasureCounterData(QVector<AgU25xxCOUNter::CounterChannels> channels)
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

QString AgU25xxMEASure::cmdMeasureCounterFrequency(AgU25xxCOUNter::CounterChannels channel)
{
    QString cmdStr = QObject::tr("FREQ? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASure::cmdMeasureCounterFrequency(QVector<AgU25xxCOUNter::CounterChannels> channels)
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

QString AgU25xxMEASure::cmdMeasureCounterPeriod(AgU25xxCOUNter::CounterChannels channel)
{
    QString cmdStr = QObject::tr("PER? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASure::cmdMeasureCounterPeriod(QVector<AgU25xxCOUNter::CounterChannels> channels)
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

QString AgU25xxMEASure::cmdMeasureCounterPulseWidth(AgU25xxCOUNter::CounterChannels channel)
{
    QString cmdStr = QObject::tr("PWID? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASure::cmdMeasureCounterPulseWidth(QVector<AgU25xxCOUNter::CounterChannels> channels)
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

QString AgU25xxMEASure::cmdMeasureCounterTotalize(AgU25xxCOUNter::CounterChannels channel)
{
    QString cmdStr = QObject::tr("TOT? (@%1)")
            .arg(extGetCounterChannel(channel));

    return COUNterSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASure::cmdMeasureCounterTotalize(QVector<AgU25xxCOUNter::CounterChannels> channels)
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

QString AgU25xxMEASure::cmdMeasureDigitalByte(AgU25xxDIGital::DigitalChannels channel)
{
    QString cmdStr = QObject::tr("DIG? (@%1)")
            .arg(extGetDigChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxMEASure::cmdMeasureDigitalByte(QVector<AgU25xxDIGital::DigitalChannels> channels)
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

QString AgU25xxMEASure::cmdMeasureDigitalBit(unsigned short bitNum, AgU25xxDIGital::DigitalChannels channel)
{
    QString cmdStr = QObject::tr("BIT? %1,(@%2)")
            .arg(bitNum)
            .arg(extGetDigChannel(channel));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxMEASure::cmdMeasureDigitalBit(unsigned short bitNum, QVector<AgU25xxDIGital::DigitalChannels> channels)
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

