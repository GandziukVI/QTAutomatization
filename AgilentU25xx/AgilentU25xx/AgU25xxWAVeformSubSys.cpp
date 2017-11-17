#include "AgU25xxWAVeformSubSys.h"
#include <QObject>

AgU25xxWAVeformSubSys::AgU25xxWAVeformSubSys()
    : IAgU25xxSubsystem("WAV"),
      IAgU25xxSubsystemExtensions()
{
}

QString AgU25xxWAVeformSubSys::cmdQueryAcquisitionData()
{
    return buildCommand(QString("DATA?"));
}

QString AgU25xxWAVeformSubSys::cmdSetContACQPointsNum(unsigned int pointsNum)
{
    QString cmdStr = QObject::tr("POIN %1")
            .arg(pointsNum);

    return buildCommand(cmdStr);
}

QString AgU25xxWAVeformSubSys::cmdGetContACQPointsNum()
{
    return buildCommand(QString("POIN?"));
}

QString AgU25xxWAVeformSubSys::cmdGetBufferStatus()
{
    return buildCommand(QString("STAT?"));
}

QString AgU25xxWAVeformSubSys::cmdGetAcquisitionConpleteStatus()
{
    return buildCommand(QString("COMP?"));
}
