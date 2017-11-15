#include "AgU25xxMEASure.h"

AgU25xxMEASure::AgU25xxMEASure()
    : IAg25xxSubsystem("MEAS")
{
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


