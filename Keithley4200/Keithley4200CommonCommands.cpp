#include "Keithley4200CommonCommands.h"

Keithley4200CommonCommands::Keithley4200CommonCommands()
{

}

QString Keithley4200CommonCommands::cmdSetPredefinedIntegrationTime(Keithley4200IntegrationTimes integrationTime) const
{
    QString res = QObject::tr("IT%1\n").arg(getIntegrationTime(integrationTime));

    return res;
}

QString Keithley4200CommonCommands::cmdSetCustomIntegrationTime(double delayFactor, double filterFactor, double ADIntegrationTime) const
{
    QString res = QObject::tr("IT4,%1,%2,%3\n")
            .arg(checkValueRange(delayFactor, 0.0, 10.0))
            .arg(checkValueRange(filterFactor, 0.0, 10.0))
            .arg(checkValueRange(ADIntegrationTime, 0.01, 10.0));

    return res;
}

QString Keithley4200CommonCommands::cmdRetrieveInstrumentID() const
{
    return QString("ID\n");
}

QString Keithley4200CommonCommands::cmdDataReadyRequestEnable(bool enable) const
{
    return enable? QString("DR1\n") : QString("DR0\n");
}

QString Keithley4200CommonCommands::cmdSetGlobalMeasurementResolution(const unsigned int numDigits) const
{
    return QObject::tr("RS %1\n").arg(checkValueRange(numDigits, 3, 7));
}

QString Keithley4200CommonCommands::cmdSetSpecifiedCurrentRange(const unsigned int smuNum, Keithley4200CurrentRanges currentRange, double complianceValue) const
{
    return QObject::tr("RI %1,%2,%3\n")
            .arg(smuNum)
            .arg(getCurrentRange(currentRange))
            .arg(complianceValue);
}

QString Keithley4200CommonCommands::cmdSetLowestCurrentRange(const unsigned int smuNum, Keithley4200CurrentRanges currentRange) const
{
    return QObject::tr("RG %1,%2\n")
            .arg(smuNum)
            .arg(getCurrentRange(currentRange));
}

QString Keithley4200CommonCommands::cmdPerformAutoCalibration(const unsigned int smuNum) const
{
    return QObject::tr("AC %1\n").arg(checkValueRange(smuNum, 1, 8));
}

QString Keithley4200CommonCommands::cmdExitOnCompliance(bool exit) const
{
    unsigned int state = exit? 1 : 0;
    return QObject::tr("EC %1\n").arg(state);
}
