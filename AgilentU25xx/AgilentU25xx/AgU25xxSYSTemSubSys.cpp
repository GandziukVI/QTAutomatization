#include "AgU25xxSYSTemSubSys.h"
#include <QObject>

AgU25xxSYSTemSubSys::AgU25xxSYSTemSubSys()
    : IAgU25xxSubsystem("SYST"),
      IAgU25xxSubsystemExtensions()
{
}

QString AgU25xxSYSTemSubSys::cmdGetChassisDescription()
{
    return buildCommand(QString("CDES?"));
}

QString AgU25xxSYSTemSubSys::cmdGetDAQErrorMsg()
{
    return buildCommand(QString("ERR?"));
}
