#include "Keithley4200UserModePage.h"

Keithley4200UserModePage::Keithley4200UserModePage()
{
    extCopyString(pageIdentifier, "US");
}

QString Keithley4200UserModePage::cmdSMUSetSourceVoltage(const unsigned int channelID, Keithley4200VoltageRanges voltageSourceRange, double outputValue, double complianceValue)
{
    extCopyString(commandIdentifier, "DV");

    QString cmdStr = QObject::tr("%1, %2, %3, %4")
            .arg(channelID)
            .arg(getSMUVoltageSourceRange(voltageSourceRange))
            .arg(outputValue)
            .arg(complianceValue);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200UserModePage::cmdSMUSetSourceCurrent(const unsigned int channelID, Keithley4200CurrentRanges currentSourceRange, double outputValue, double complianceValue)
{
    extCopyString(commandIdentifier, "DI");

    QString cmdStr = QObject::tr("%1, %2, %3, %4")
            .arg(channelID)
            .arg(getSMUCurrentSourceRange(currentSourceRange))
            .arg(outputValue)
            .arg(complianceValue);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200UserModePage::cmdVSSetSourceVoltage(const unsigned int channelID, double outputValue)
{
    extCopyString(commandIdentifier, "DS");

    QString cmdStr = QObject::tr("%1, %2")
            .arg(channelID)
            .arg(checkValueRange(outputValue, -210.0, 210.0));

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200UserModePage::cmdTriggerVoltage(Keithley4200VoltageMeasureChannels vmChannel)
{
    extCopyString(commandIdentifier, "TV");

    QString cmdStr = QObject::tr("%1").arg(getVoltageMeasureChannel(vmChannel));
    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200UserModePage::cmdTriggerCurrent(Keithley4200CurrentMeasureChannels imChannel)
{
    extCopyString(commandIdentifier, "TI");

    QString cmdStr = QObject::tr("%1").arg(getCurrentMeasureChannel(imChannel));
    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}
