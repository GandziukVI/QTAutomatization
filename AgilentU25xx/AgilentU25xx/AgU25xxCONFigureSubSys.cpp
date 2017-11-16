#include "AgU25xxCONFigureSubSys.h"

AgU25xxCONFigureSubSys::AgU25xxCONFigureSubSys()
    : IAg25xxSubsystem("CONF")
{
    DIGitalSubsystem = getSubSubSystem("DIG");
    TIMEbaseSubsystem = getSubSubSystem("TIME");
}

QString AgU25xxCONFigureSubSys::cmdConfDigitalDirection(AgU25xxDIGital::DigitalDirection direction, AgU25xxDIGital::DigitalChannels channel)
{
    QString cmdStr = QObject::tr("DIR %1,(@%2)")
            .arg(extGetDigDirection(direction))
            .arg(extGetDigChannel(channel));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdConfDigitalDirection(AgU25xxDIGital::DigitalDirection direction, QVector<AgU25xxDIGital::DigitalChannels> channels)
{
    QVector<unsigned int> channelNums = extGetDigChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << QObject::tr("DIR %1,(@")
                    .arg(extGetDigDirection(direction));

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdGetConfDigitalDirection(AgU25xxDIGital::DigitalChannels channel)
{
    QString cmdStr = QObject::tr("DIR? (@%1")
            .arg(extGetDigChannel(channel));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdGetConfDigitalDirection(QVector<AgU25xxDIGital::DigitalChannels> channels)
{
    QVector<unsigned int> channelNums = extGetDigChannels(channels);
    QVector<unsigned int>::const_iterator iter = channelNums.cbegin();

    QString cmdStr;
    QTextStream cmdStrStream(&cmdStr);

    cmdStrStream << "DIR? (@";

    for (; iter != channelNums.cend(); ) {
        if (iter != channelNums.cend() - 1)
            cmdStrStream << *iter << ',';
        else
            cmdStrStream << *iter << ')';

        ++iter;
    }

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdSetTimeBaseSrc(AgU25xxTIMEbase::TimeSrcModes timeSrcMode)
{
    QString cmdStr = QObject::tr("SOUR %1")
            .arg(extGetTimeBaseSrcMode(timeSrcMode));

    return TIMEbaseSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdGetTimeBaseSrc()
{
    QString cmdStr = QString("SOUR?");
    return TIMEbaseSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdConfExtClockFreq(unsigned int frequency)
{
    QString cmdStr = QObject::tr("ECL %1")
            .arg(frequency);

    return TIMEbaseSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdGetExtClockFreq()
{
    QString cmdStr = QString("ECL?");

    return TIMEbaseSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdConfSSI(SSIModes ssiMode)
{
    QString cmdStr = QObject::tr("SSI %1")
            .arg(extGetSSIMode(ssiMode));

    return buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdGetSSIMode()
{
    QString cmdStr = QString("SSI?");
    return buildCommand(cmdStr);
}
