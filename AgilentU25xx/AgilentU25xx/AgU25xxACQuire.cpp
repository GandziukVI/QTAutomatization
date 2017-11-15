#include "AgU25xxACQuire.h"

AgU25xxACQuire::AgU25xxACQuire()
    : IAg25xxSubsystem("ACQ")
{
}

QString AgU25xxACQuire::cmdSetSamplingRate(const unsigned int samplingRate)
{
    QString cmdStr = QObject::tr("SRAT %1").arg(samplingRate);
    return buildCommand(cmdStr);
}

QString AgU25xxACQuire::cmdGetSamplingrate()
{
    QString cmdStr = QString("SRAT?");
    return buildCommand(cmdStr);
}

QString AgU25xxACQuire::cmdSetPointsSingleShot(unsigned int nPoints)
{
    QString cmdStr = QObject::tr("POIN %1").arg(nPoints);
    return buildCommand(cmdStr);
}

QString AgU25xxACQuire::cmdGetPointsSingleShot()
{
    QString cmdStr = QString("POIN?");
    return buildCommand(cmdStr);
}
