#include "AgU25xxCONFigureSubSys.h"
#include <QObject>

AgU25xxCONFigureSubSys::AgU25xxCONFigureSubSys()
    : IAgU25xxSubsystem("CONF"),
      IAgU25xxSubsystemExtensions()
{
    DIGitalSubsystem = getSubSubSystem("DIG");
    TIMEbaseSubsystem = getSubSubSystem("TIME");
}

QString AgU25xxCONFigureSubSys::cmdSetDigitalDirection(AgU25xxEnumDigitalDirection direction, AgU25xxEnumDigitalChannels channel)
{
    QString cmdStr = QObject::tr("DIR %1,(@%2)")
            .arg(extGetDigDirection(direction))
            .arg(extGetDigChannel(channel));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdSetDigitalDirection(AgU25xxEnumDigitalDirection direction, QVector<AgU25xxEnumDigitalChannels> channels)
{
    QVector<unsigned int> channelNums = extGetDigChannels(channels);

    QString cmdStr = QObject::tr("DIR %1,%2")
            .arg(extGetDigDirection(direction))
            .arg(extCreateChannelsString(channelNums));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdGetDigitalDirection(AgU25xxEnumDigitalChannels channel)
{
    QString cmdStr = QObject::tr("DIR? (@%1)")
            .arg(extGetDigChannel(channel));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdGetDigitalDirection(QVector<AgU25xxEnumDigitalChannels> channels)
{
    QVector<unsigned int> channelNums = extGetDigChannels(channels);

    QString cmdStr = QObject::tr("DIR? %1")
            .arg(extCreateChannelsString(channelNums));

    return DIGitalSubsystem.buildCommand(cmdStr);
}

QString AgU25xxCONFigureSubSys::cmdSetTimeBaseSrc(AgU25xxEnumTimeSrcModes timeSrcMode)
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

QString AgU25xxCONFigureSubSys::cmdSetExtClockFreq(unsigned int frequency)
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

QString AgU25xxCONFigureSubSys::cmdSetSSIMode(AgU25xxEnumSSIModes ssiMode)
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
