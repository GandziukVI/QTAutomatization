#include "Keithley4200SourceSetupPage.h"

Keithley4200SourceSetupPage::Keithley4200SourceSetupPage()
{
    extCopyString(pageIdentifier, "SS");
    channelNumber = 1;
}

QString Keithley4200SourceSetupPage::cmdConfVAR1Sweep(SMUSourceMode sourceMode, SMUSweepMode sweepMode, double startValue, double stopValue, double stepValue, double complianceValue)
{
    switch (sourceMode)
    {
    case SMUSourceMode::Voltage: {
        extCopyString(commandIdentifier, "VR");
        break;
    }
    case SMUSourceMode::Current: {
        extCopyString(commandIdentifier, "IR");
        break;
    }
    }

    QString cmdStr = QObject::tr("%1, %2, %3, %4, %5")
            .arg(getSMUSweepMode(sweepMode))
            .arg(startValue)
            .arg(stopValue)
            .arg(stepValue)
            .arg(complianceValue);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200SourceSetupPage::cmdConfVAR1Scale(double ratio, double offset, const unsigned int channelID)
{
    QString cmdStr, res;
    QTextStream commandStream(&res);

    if(channelID == 0) {
        extCopyString(commandIdentifier, "RT");
        cmdStr = QObject::tr(" %1").arg(ratio);
        commandStream << buildCommand(cmdStr);
        pageSetCurrent();

        extCopyString(commandIdentifier, "FS");
        cmdStr = QObject::tr(" %1").arg(offset);
        commandStream << buildCommand(cmdStr);
    }
    else {
        extCopyString(commandIdentifier, "RT");
        cmdStr = QObject::tr(" %1, %2")
                .arg(ratio)
                .arg(channelID);

        commandStream << buildCommand(cmdStr);
        pageSetCurrent();

        extCopyString(commandIdentifier, "FS");
        cmdStr = QObject::tr(" %1, %2")
                .arg(offset)
                .arg(channelID);

        commandStream << buildCommand(cmdStr);
    }

    return res;
}

QString Keithley4200SourceSetupPage::cmdConfVAR2Sweep(SMUSourceMode sourceMode, double startValue, double stepValue, int stepsNumber, double complianceValue)
{
    switch (sourceMode)
    {
    case SMUSourceMode::Voltage: {
        extCopyString(commandIdentifier, "VP");
        break;
    }
    case SMUSourceMode::Current: {
        extCopyString(commandIdentifier, "IP");
        break;
    }
    }

    QString cmdStr = QObject::tr(" %1, %2, %3, %4")
            .arg(startValue)
            .arg(stepValue)
            .arg(stepsNumber)
            .arg(complianceValue);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200SourceSetupPage::cmdConfListSweep(SMUSourceMode sourceMode, const unsigned int channelID, SMUMasterOrSlaveMode masterOrSlaveMode, double complianceValue, const QVector<double>& listValues)
{
    switch (sourceMode) {

    case SMUSourceMode::Voltage: {
        extCopyString(commandIdentifier, "VL");
        break;
    }
    case SMUSourceMode::Current: {
        extCopyString(commandIdentifier, "IL");
        break;
    }
    }

    QString cmdStr = QObject::tr("%1, %2, %3")
            .arg(channelID)
            .arg(getSMUMasterOrSlaveMode(masterOrSlaveMode))
            .arg(complianceValue);

    QTextStream commandStream(&cmdStr);

    QVector<double>::const_iterator i;
    for(i = listValues.cbegin(); i != listValues.cend(); ++i)
        commandStream << ", " << *i;

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200SourceSetupPage::cmdConfAutoStandby(const unsigned int channelID, const bool standbyEnable)
{
    extCopyString(commandIdentifier, "ST");

    QString cmdStr = QObject::tr(" %1, %2")
            .arg(channelID)
            .arg(standbyEnable == true ? 1 : 0);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200SourceSetupPage::cmdConfConstSource(SMUSourceMode sourceMode, const unsigned int channelID, double outputValue, double complianceValue)
{
    switch (sourceMode) {

    case SMUSourceMode::Voltage: {
        extCopyString(commandIdentifier, "VC");
        break;
    }
    case SMUSourceMode::Current: {
        extCopyString(commandIdentifier, "IC");
        break;
    }
    }

    QString cmdStr = QObject::tr("%1, %2, %3")
            .arg(channelID)
            .arg(outputValue)
            .arg(complianceValue);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200SourceSetupPage::cmdConfConstVoltageSource(const unsigned int channelID, double outputValue)
{
    extCopyString(commandIdentifier, "SC");

    QString cmdStr = QObject::tr("%1, %2")
            .arg(channelID)
            .arg(outputValue);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200SourceSetupPage::cmdSetSweepHoldTime(double holdTime)
{
    extCopyString(commandIdentifier, "HT");

    QString cmdStr = QObject::tr(" %1").arg(holdTime);
    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200SourceSetupPage::cmdSetSweepDelayTime(double delayTime)
{
    extCopyString(commandIdentifier, "DT");

    QString cmdStr = QObject::tr(" %1").arg(delayTime);
    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}
