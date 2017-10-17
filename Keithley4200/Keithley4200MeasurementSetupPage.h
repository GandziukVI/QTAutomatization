#ifndef MEASUREMENTSETUPPAGE_H
#define MEASUREMENTSETUPPAGE_H

#include "keithley4200_global.h"
#include "IKeithley4200Page.h"

class KEITHLEY4200SHARED_EXPORT Keithley4200MeasurementSetupPage : public IKeithley4200Page
{
public:
    Keithley4200MeasurementSetupPage();

    QString cmdSetWaitTime(const double waitTime);
    QString cmdSetInterval(const double interval);
    QString cmdSetNumberOfReadings(int numReadings);
    QString cmdSelectDisplayMode(Keithley4200DisplayMode displayMode);
    QString cmdEnableVIFunctions(const QVector<const char*> variablesList);
    QString cmdConfGraphXAxis(const char* smuChannelName, Keithley4200XAxisScaleType xAxisScaleType, double xAxisMinVal, double xAxisMaxVal);
    QString cmdConfGraphXAxisForTimeDomain(double minTimeVal, double maxTimeVal);
    QString cmdConfGraphY1Axis(const char* smuChannelName, Keithley4200YAxisScaleType yAxisScaleType, double y1AxisMinVal, double y1AxisMaxVal);
    QString cmdConfGraphY2Axis(const char* smuChannelName, Keithley4200YAxisScaleType yAxisScaleType, double y2AxisMinVal, double y2AxisMaxVal);

};

#endif // MEASUREMENTSETUPPAGE_H
