#include "AgU25xxTRIGgerSubSys.h"
#include <QObject>

AgU25xxTRIGgerSubSys::AgU25xxTRIGgerSubSys()
    : IAgU25xxSubsystem("TRIG"),
      IAgU25xxSubsystemExtensions()
{
    ATRiGgerSubsystem = getSubSubSystem("ATRG");
    DTRiGgerSubsystem = getSubSubSystem("DTRG");
}

QString AgU25xxTRIGgerSubSys::cmdSetTriggerInpSrc(AgU25xxTriggerSources inpSrc)
{
    QString cmdStr = QObject::tr("SOUR %1")
            .arg(extGetInputTriggerSource(inpSrc));

    return buildCommand(cmdStr);
}

QString AgU25xxTRIGgerSubSys::cmdGetTriggerInpSrc()
{
    return buildCommand(QString("SOUR?"));
}

QString AgU25xxTRIGgerSubSys::cmdSetTriggerInpType(AgU25xxTriggerTypes inpType)
{
    QString cmdStr = QObject::tr("TYP %1")
            .arg(extGetInputTriggerType(inpType));

    return buildCommand(cmdStr);
}

QString AgU25xxTRIGgerSubSys::cmdGetTriggerInpType()
{
    return buildCommand(QString("TYP?"));
}

QString AgU25xxTRIGgerSubSys::cmdSetTriggerInputDelayCount(unsigned int delCount)
{
    QString cmdStr = QObject::tr("DCNT %1")
            .arg(delCount);

    return buildCommand(cmdStr);
}

QString AgU25xxTRIGgerSubSys::cmdGetTriggerInputDelayCount()
{
    return buildCommand(QString("DCNT?"));
}

QString AgU25xxTRIGgerSubSys::cmdSetATRiGgerExtSrc()
{
    QString cmdStr = QObject::tr("SOUR %1")
            .arg(extGetInputATRiGgerSource(AgU25xxATRiGgerSources::EXTAP));

    return ATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxTRIGgerSubSys::cmdGetATRiGgerExtSrc()
{
    return ATRiGgerSubsystem.buildCommand(QString("SOUR?"));
}

QString AgU25xxTRIGgerSubSys::cmdSetATRiGgerInpCondition(AgU25xxATRiGgerConditions atrigCondition)
{
    QString cmdStr = QObject::tr("COND %1")
            .arg(extGetInputATRiGgerCondition(atrigCondition));

    return ATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxTRIGgerSubSys::cmdGetATRiGgerInpCondition()
{
    return ATRiGgerSubsystem.buildCommand(QString("COND?"));
}

QString AgU25xxTRIGgerSubSys::cmdSetATRiGgerInpHighThr(double thresholdVoltage)
{
    QString cmdStr = QObject::tr("HTHR %1")
            .arg(thresholdVoltage);

    return ATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxTRIGgerSubSys::cmdGetATRiGgerInpHighThr()
{
    return ATRiGgerSubsystem.buildCommand(QString("HTHR?"));
}

QString AgU25xxTRIGgerSubSys::cmdSetATRiGgerInpLowThr(double thresholdVoltage)
{
    QString cmdStr = QObject::tr("LTHR %1")
            .arg(thresholdVoltage);

    return ATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxTRIGgerSubSys::cmdGetATRiGgerInpLowThr()
{
    return ATRiGgerSubsystem.buildCommand(QString("LTHR?"));
}

QString AgU25xxTRIGgerSubSys::cmdSetDTRiGgerPolarity(AgU25xxDTRiGgerPolarities polarity)
{
    QString cmdStr = QObject::tr("POL %1")
            .arg(extGetInputDTRiGgerPolarity(polarity));

    return DTRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxTRIGgerSubSys::cmdGetDTRiGgerPolarity()
{
    return DTRiGgerSubsystem.buildCommand(QString("POL?"));
}
