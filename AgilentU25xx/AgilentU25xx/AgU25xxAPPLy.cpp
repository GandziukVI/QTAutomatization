#include "AgU25xxAPPLy.h"

AgU25xxAPPLy::AgU25xxAPPLy()
    : IAg25xxSubsystem("APPL")
{
}

QString AgU25xxAPPLy::cmdGetAOParams(AgU25xxAnalogOutput::AOChannels channel)
{
    QString cmdStr = QObject::tr("APPL? (@%1)")
            .arg(extGetAOChannel(channel));

    return cmdStr;
}

QString AgU25xxAPPLy::cmdGetAOParams(QVector<AgU25xxAnalogOutput::AOChannels> channels)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "APPL? (@";

    for(; iter !=  channelNums.cend(); ) {
        if(iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return cmdStr;
}

QString AgU25xxAPPLy::cmdApplySineWave(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel)
{
    QString cmdStr = QObject::tr("SIN %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplySineWave(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channel)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("SIN %1,%2,(@")
                    .arg(amplitude)
                    .arg(offset);

    for(; iter !=  channelNums.cend(); ) {
        if(iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ', ';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplySquareWave(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel)
{
    QString cmdStr = QObject::tr("SQU %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplySquareWave(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channel)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("SQU %1,%2,(@")
                    .arg(amplitude)
                    .arg(offset);

    for(; iter !=  channelNums.cend(); ) {
        if(iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ', ';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplySawToothWave(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel)
{
    QString cmdStr = QObject::tr("SAWT %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplySawToothWave(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channel)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("SAWT %1,%2,(@")
                    .arg(amplitude)
                    .arg(offset);

    for(; iter !=  channelNums.cend(); ) {
        if(iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ', ';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplyTriangleWave(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel)
{
    QString cmdStr = QObject::tr("TRI %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplyTriangleWave(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channel)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("TRI %1,%2,(@")
                    .arg(amplitude)
                    .arg(offset);

    for(; iter !=  channelNums.cend(); ) {
        if(iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ', ';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplyNoise(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel)
{
    QString cmdStr = QObject::tr("NOIS %1,%2,(@%3)")
            .arg(amplitude)
            .arg(offset)
            .arg(extGetAOChannel(channel));

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplyNoise(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channel)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("NOIS %1,%2,(@")
                    .arg(amplitude)
                    .arg(offset);

    for(; iter !=  channelNums.cend(); ) {
        if(iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ', ';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplyUser(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel)
{
    QString cmdStr = QObject::tr("USER (@%1)")
            .arg(amplitude);

    return buildCommand(cmdStr);
}

QString AgU25xxAPPLy::cmdApplyUser(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channel)
{
    QVector<unsigned int> channelNums = extGetAOChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "USER (@";

    for(; iter !=  channelNums.cend(); ) {
        if(iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ', ';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return buildCommand(cmdStr);
}
