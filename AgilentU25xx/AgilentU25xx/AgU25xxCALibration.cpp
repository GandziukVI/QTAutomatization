#include "AgU25xxCALibration.h"

AgU25xxCALibration::AgU25xxCALibration()
    : IAg25xxSubsystem("CAL")
{
}

QString AgU25xxCALibration::cmdStartSelfCalibration()
{
    QString cmdStr = QString("BEG");
    return buildCommand(cmdStr);
}

QString AgU25xxCALibration::cmdCheckCalibrationStatus()
{
    return QString("OPC?");
}
