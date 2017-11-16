#include "AgU25xxOUTPutSubSys.h"

AgU25xxOUTPutSubSys::AgU25xxOUTPutSubSys()
    : IAgU25xxSubsystem("OUTP"),
      IAgU25xxSubsystemExtensions()
{
    WAVeformSubsystem = getSubSubSystem("WAV");
    TRIGgerSubsystem  = getSubSubSystem("TRIG");
    TRIGgerATRiGgerSubsystem = TRIGgerSubsystem.getSubSubSystem("ATRG");
    TRIGgerDTRiGgerSubsystem = TRIGgerSubsystem.getSubSubSystem("DTRG");
}

QString AgU25xxOUTPutSubSys::cmdSetOutputState(AgU25xxOutputState outpState) const
{
    QString cmdStr = QObject::tr("%1 %2")
            .arg(subsystemIdentifier)
            .arg(extGetOutputState(outpState));

    return cmdStr;
}

QString AgU25xxOUTPutSubSys::cmdSetWAVNumIterations(unsigned int numIter)
{
    QString cmdStr = QObject::tr("ITER %1")
            .arg(numIter);

    return WAVeformSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetWAVNumIterations()
{
    QString cmdStr = QString("ITER?");
    return WAVeformSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetWAVSamplingRate(unsigned int samplingRate)
{
    QString cmdStr = QObject::tr("SRAT %1")
            .arg(samplingRate);

    return WAVeformSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetWAVSamplingRate()
{
    QString cmdStr = QString("SRAT?");
    return WAVeformSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetWAVSamplingFreq(unsigned int samplingFreq)
{
    QString cmdStr = QObject::tr("FREQ %1")
            .arg(samplingFreq);

    return WAVeformSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetWAVSamplingFreq()
{
    QString cmdStr = QString("FREQ?");
    return WAVeformSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetTRIGSource(AgU25xxTriggerSources triggerSource)
{
    QString cmdStr = QObject::tr("SOUR %1")
            .arg(extGetOutputTriggerSource(triggerSource));

    return TRIGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetTRIGSource()
{
    QString cmdStr = QString("SOUR?");
    return TRIGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetTRIGType(AgU25xxTriggerTypes triggerType)
{
    QString cmdStr = QObject::tr("TYP %1")
            .arg(extGetOutputTriggerType(triggerType));

    return TRIGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetTRIGType()
{
    QString cmdStr = QString("TYP?");
    return TRIGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetTRIGDelayCount(unsigned int delayCount)
{
    QString cmdStr = QObject::tr("DCNT %1")
            .arg(delayCount);

    return TRIGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetTRIGDelayCount()
{
    QString cmdStr = QString("DCNT?");
    return TRIGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetATRiGgerSrc(AgU25xxATRiGgerSources triggerSource)
{
    QString cmdStr = QObject::tr("SOUR %1")
            .arg(extGetOutputATRiGgerSource(triggerSource));

    return TRIGgerATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetATRiGgerSrc()
{
    QString cmdStr = QString("SOUR?");
    return TRIGgerATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetATRiGgerCondition(AgU25xxATRiGgerConditions triggerCondition)
{
    QString cmdStr = QObject::tr("COND %1")
            .arg(extGetOutputATRiGgerCondition(triggerCondition));

    return TRIGgerATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetATRiGgerCondition()
{
    QString cmdStr = QString("COND?");
    return TRIGgerATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetATRiGgerHighVoltTreshold(double highVoltageTreshold)
{
    QString cmdStr = QObject::tr("HTHR %1")
            .arg(highVoltageTreshold);

    return TRIGgerATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetATRiGgerHighVoltTreshold()
{
    QString cmdStr = QString("HTHR?");
    return TRIGgerATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetATRiGgerLowVoltTreshold(double lowVoltageTreshold)
{
    QString cmdStr = QObject::tr("LTHR %1")
            .arg(lowVoltageTreshold);

    return TRIGgerATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetATRiGgerLowVoltTreshold()
{
    QString cmdStr = QString("LTHR?");
    return TRIGgerATRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdSetDTRiGgerPolarity(AgU25xxDTRiGgerPolarities triggerPolarity)
{
    QString cmdStr = QObject::tr("POL %1")
            .arg(extGetOutputDTRiGgerPolarity(triggerPolarity));

    return TRIGgerDTRiGgerSubsystem.buildCommand(cmdStr);
}

QString AgU25xxOUTPutSubSys::cmdGetDTRiGgerPolarity()
{
    QString cmdStr = QObject::tr("POL?");
    return TRIGgerDTRiGgerSubsystem.buildCommand(cmdStr);
}
