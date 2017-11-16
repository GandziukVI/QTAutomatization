#include "AgU25xxACQuireSubSys.h"

AgU25xxACQuireSubSys::AgU25xxACQuireSubSys()
    : IAgU25xxSubsystem("ACQ"),
      IAgU25xxSubsystemExtensions()
{
}

QString AgU25xxACQuireSubSys::cmdSetSamplingRate(const unsigned int samplingRate)
{
    QString cmdStr = QObject::tr("SRAT %1").arg(samplingRate);
    return buildCommand(cmdStr);
}

QString AgU25xxACQuireSubSys::cmdGetSamplingrate()
{
    QString cmdStr = QString("SRAT?");
    return buildCommand(cmdStr);
}

QString AgU25xxACQuireSubSys::cmdSetPointsSingleShot(unsigned int nPoints)
{
    QString cmdStr = QObject::tr("POIN %1").arg(nPoints);
    return buildCommand(cmdStr);
}

QString AgU25xxACQuireSubSys::cmdGetPointsSingleShot()
{
    QString cmdStr = QString("POIN?");
    return buildCommand(cmdStr);
}
