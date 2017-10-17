#include "Keithley4200MeasurementSetupPage.h"

Keithley4200MeasurementSetupPage::Keithley4200MeasurementSetupPage()
{
    extCopyString(pageIdentifier, "SM");
}

QString Keithley4200MeasurementSetupPage::cmdSetWaitTime(const double waitTime)
{
    extCopyString(commandIdentifier, "WT");

    double realWaitTime = checkValueRange(waitTime, 0.0, 100.0);

    QString cmdStr = QObject::tr(" %1").arg(realWaitTime);
    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementSetupPage::cmdSetInterval(const double interval)
{
    extCopyString(commandIdentifier, "IN");

    double realInterval = checkValueRange(interval, 0.01, 10.0);

    QString cmdStr = QObject::tr(" %1").arg(realInterval);
    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementSetupPage::cmdSetNumberOfReadings(int numReadings)
{
    extCopyString(commandIdentifier, "NR");

    int realNumReadings = checkValueRange(numReadings, 1, 4096);

    QString cmdStr = QObject::tr(" %1").arg(realNumReadings);
    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementSetupPage::cmdSelectDisplayMode(Keithley4200DisplayMode displayMode)
{
    extCopyString(commandIdentifier, "DM");

    QString cmdStr = QObject::tr("%1").arg(getSMUDisplayMode(displayMode));
    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementSetupPage::cmdEnableVIFunctions(const QVector<const char*> variablesList)
{
    extCopyString(commandIdentifier, "LI");

    QString cmdStr;
    QTextStream commandStream(&cmdStr);

    int counter = 0, maxCount = checkValueRange(variablesList.count(), 1, 6);

    QVector<const char*>::const_iterator i;

    for(i = variablesList.cbegin(); i != variablesList.cend(), counter != maxCount; ++i) {
        if(counter == 0)
            commandStream << " \'" << *i << "\'";
        else
            commandStream << ", \'" << *i << "\'";

        ++counter;
    }

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementSetupPage::cmdConfGraphXAxis(const char* smuChannelName, Keithley4200XAxisScaleType xAxisScaleType, double xAxisMinVal, double xAxisMaxVal)
{
    extCopyString(commandIdentifier, "XN");

    QString cmdStr = QObject::tr(" \'%1\', %2, %3, %4")
            .arg(smuChannelName)
            .arg(getSMUXAxisScaleType(xAxisScaleType))
            .arg(xAxisMinVal)
            .arg(xAxisMaxVal);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementSetupPage::cmdConfGraphXAxisForTimeDomain(double minTimeVal, double maxTimeVal)
{
    extCopyString(commandIdentifier, "XT");

    QString cmdStr = QObject::tr(" %1, %2")
            .arg(checkValueRange(minTimeVal, 0.01, 9999.0))
            .arg(checkValueRange(maxTimeVal, 0.01, 9999.0));

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementSetupPage::cmdConfGraphY1Axis(const char* smuChannelName, Keithley4200YAxisScaleType yAxisScaleType, double y1AxisMinVal, double y1AxisMaxVal)
{
    extCopyString(commandIdentifier, "YA");

    QString cmdStr = QObject::tr(" \'%1\', %2, %3, %4")
            .arg(smuChannelName)
            .arg(getSMUYAxisScaleType(yAxisScaleType))
            .arg(y1AxisMinVal)
            .arg(y1AxisMaxVal);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementSetupPage::cmdConfGraphY2Axis(const char *smuChannelName, Keithley4200YAxisScaleType yAxisScaleType, double y2AxisMinVal, double y2AxisMaxVal)
{
    extCopyString(commandIdentifier, "YB");

    QString cmdStr = QObject::tr(" \'%1\', %2, %3, %4")
            .arg(smuChannelName)
            .arg(getSMUYAxisScaleType(yAxisScaleType))
            .arg(y2AxisMinVal)
            .arg(y2AxisMaxVal);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}


