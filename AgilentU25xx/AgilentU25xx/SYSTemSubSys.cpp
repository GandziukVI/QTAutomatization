#include "SYSTemSubSys.h"
#include <QObject>

SYSTemSubSys::SYSTemSubSys()
    : IAgU25xxSubsystem("SYST"),
      IAgU25xxSubsystemExtensions()
{
}

QString SYSTemSubSys::cmdGetChassisDescription()
{
    return buildCommand(QString("CDES?"));
}

QString SYSTemSubSys::cmdGetDAQErrorMsg()
{
    return buildCommand(QString("ERR?"));
}
