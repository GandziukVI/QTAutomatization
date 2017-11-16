#include "AgU25xxCALibrationSubSys.h"

AgU25xxCALibrationSubSys::AgU25xxCALibrationSubSys()
    : IAg25xxSubsystem("CAL")
{
}

QString AgU25xxCALibrationSubSys::cmdStartSelfCalibration()
{
    QString cmdStr = QString("BEG");
    return buildCommand(cmdStr);
}

QString AgU25xxCALibrationSubSys::cmdCheckCalibrationStatus()
{
    return QString("OPC?");
}
