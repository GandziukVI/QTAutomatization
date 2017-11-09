#ifndef ISOURCEMETERUNIT_H
#define ISOURCEMETERUNIT_H

#include "sourcemeterunit_global.h"
#include "SourceMeterUnitDefinitions.h"

#include <IDeviceIO.h>

#include <QVector>

class SOURCEMETERUNITSHARED_EXPORT ISourceMeterUnit
{

public:
    ISourceMeterUnit() { }

    virtual void Initialize (IDeviceIO& Driver)                     = 0;
    virtual void Initialize (IDeviceIO& Driver, QString& channelID) = 0;

    virtual void SwitchON  ()  = 0;
    virtual void SwitchOFF () = 0;

    virtual void SetSourceMode    (const SMUSourceMode sourceMode) = 0;
    virtual void SetCompliance    (const double compliance) = 0;
    virtual void SetSourceDelay   (const double delay)   = 0;
    virtual void SetSourceVoltage (const double voltage) = 0;
    virtual void SetSourceCurrent (const double current) = 0;
    virtual void SetAveraging     (const int avg)        = 0;
    virtual void SetNPLC          (const double val)     = 0;

    virtual double MeasureVoltage () = 0;
    virtual double MeasureCurrent () = 0;
    virtual double MeasureResistance() = 0;

    virtual QVector<IV_Data> LinearVoltageSweep(double start, double stop, int numPoints) = 0;
    virtual QVector<IV_Data> LinearCurrentSweep(double start, double stop, int numPoints) = 0;
    virtual QVector<IV_Data> LogarithmicVoltageSweep(double start, double stop, int numPoints) = 0;
    virtual QVector<IV_Data> LogarithmicCurrentSweep(double start, double stop, int numPoints) = 0;
    virtual QVector<IV_Data> ListVoltageSweep(const double sweepList[]) = 0;
    virtual QVector<IV_Data> ListCurrentSweep(const double sweepList[]) = 0;

    virtual QVector<IV_Data> PulsedLinearVoltageSweep(double start, double stop, int numPoints, double pulseWidth, double pulsePeriod, bool remoteSense) = 0;
    virtual QVector<IV_Data> PulsedLinearCurrentSweep(double start, double stop, int numPoints, double pulseWidth, double pulsePeriod, bool remoteSense) = 0;

    virtual void StartVoltageTrace () = 0;
    virtual void StartCurrentTrace () = 0;

    virtual void Reset () = 0;
};

#endif // ISOURCEMETERUNIT_H
