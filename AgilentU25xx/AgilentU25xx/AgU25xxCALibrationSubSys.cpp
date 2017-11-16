#include "AgU25xxCALibrationSubSys.h"

AgU25xxCALibrationSubSys::AgU25xxCALibrationSubSys()
    : IAgU25xxSubsystem("CAL"),
      IAgU25xxSubsystemExtensions()
{
}

QString AgU25xxCALibrationSubSys::cmdStartSelfCalibration()
{
    QString cmdStr = QString("BEG");
    return buildCommand(cmdStr);
}

QString AgU25xxCALibrationSubSys::cmdCheckCalibrationStatus()
{
    return QString("*OPC?");
}
