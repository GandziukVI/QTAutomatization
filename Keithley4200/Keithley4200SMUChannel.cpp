#include "Keithley4200SMUChannel.h"

#include <QDebug>

Keithley4200SMUChannel::Keithley4200SMUChannel()
{
    isInitialized = false;

    QObject::connect(&chDef, SIGNAL(pageChanged(QString)),
                     this, SLOT(onPageChanged(QString)));
    QObject::connect(&chSrcSetup, SIGNAL(pageChanged(QString)),
                     this, SLOT(onPageChanged(QString)));
    QObject::connect(&chMeasSetup, SIGNAL(pageChanged(QString)),
                     this, SLOT(onPageChanged(QString)));
    QObject::connect(&chMeasControl, SIGNAL(pageChanged(QString)),
                     this, SLOT(onPageChanged(QString)));
    QObject::connect(&chUserMode, SIGNAL(pageChanged(QString)),
                     this, SLOT(onPageChanged(QString)));
}

Keithley4200SMUChannel::~Keithley4200SMUChannel()
{
}

void Keithley4200SMUChannel::onPageChanged(QString pageID)
{
    if (pageID == QString(chDef.pageIdentifier)) {
        chSrcSetup.isCurrent    = false;
        chMeasSetup.isCurrent   = false;
        chMeasControl.isCurrent = false;
        chUserMode.isCurrent    = false;
    }
    else if (pageID == QString(chSrcSetup.pageIdentifier)) {
        chDef.isCurrent         = false;
        chMeasSetup.isCurrent   = false;
        chMeasControl.isCurrent = false;
        chUserMode.isCurrent    = false;
    }
    else if (pageID == QString(chMeasSetup.pageIdentifier)) {
        chDef.isCurrent         = false;
        chSrcSetup.isCurrent    = false;
        chMeasControl.isCurrent = false;
        chUserMode.isCurrent    = false;
    }
    else if (pageID == QString(chMeasControl.pageIdentifier)) {
        chDef.isCurrent         = false;
        chSrcSetup.isCurrent    = false;
        chMeasSetup.isCurrent   = false;
        chUserMode.isCurrent    = false;
    }
    else if (pageID == QString(chUserMode.pageIdentifier)) {
        chDef.isCurrent         = false;
        chSrcSetup.isCurrent    = false;
        chMeasSetup.isCurrent   = false;
        chMeasControl.isCurrent = false;
    }
}

void Keithley4200SMUChannel::Initialize(IDeviceIO &Driver)
{
    driver = &Driver;
    channelNumber = 1;
}

void Keithley4200SMUChannel::Initialize(IDeviceIO &Driver, QString &channelID)
{
    driver = &Driver;
    channelNumber = channelID.toUInt();
}

void Keithley4200SMUChannel::SwitchON()
{
    // There is no need in implementation?
}

void Keithley4200SMUChannel::SwitchOFF()
{
    if(isInitialized)
        driver->SendCommandRequest(chDef.cmdDisableChannel(channelNumber));
}

void Keithley4200SMUChannel::SetSourceMode(const SMUSourceMode sourceMode)
{
    srcMode = sourceMode;
}

void Keithley4200SMUChannel::SetCompliance(const double compliance)
{
    srcCompliance = compliance;
}

void Keithley4200SMUChannel::SetSourceDelay(const double delay)
{
    srcDelay = delay;
}

void Keithley4200SMUChannel::SetSourceVoltage(const double voltage)
{
    if(isInitialized)
        driver->SendCommandRequest(chUserMode.cmdSMUSetSourceVoltage(channelNumber, Keithley4200VoltageRanges::Autorange, voltage, srcCompliance));
}

void Keithley4200SMUChannel::SetSourceCurrent(const double current)
{
    if(isInitialized)
        driver->SendCommandRequest(chUserMode.cmdSMUSetSourceCurrent(channelNumber, Keithley4200CurrentRanges::Autorange, current, srcCompliance));
}

void Keithley4200SMUChannel::SetAveraging(const int avg)
{
    if(isInitialized)
        driver->SendCommandRequest(chMeasSetup.cmdSetNumberOfReadings(avg));
}

void Keithley4200SMUChannel::SetNPLC(const double val)
{
    double value;

    if(val <= 0)
        value = 0.01;
    else if (val > 10.0)
        value = 10.0;
    else
        value = val;

    if(value > 0 && value < 3.5){
        if(isInitialized)
            driver->SendCommandRequest(chCommon.cmdSetPredefinedIntegrationTime(Keithley4200IntegrationTimes::Short));
    }
    else if(value >= 3.5 && value < 6.5) {
        if(isInitialized)
            driver->SendCommandRequest(chCommon.cmdSetPredefinedIntegrationTime(Keithley4200IntegrationTimes::Medium));
    }
    else if(value >= 6.5 && value <= 10.0) {
        if(isInitialized)
            driver->SendCommandRequest(chCommon.cmdSetPredefinedIntegrationTime(Keithley4200IntegrationTimes::Long));
    }
}

double Keithley4200SMUChannel::MeasureVoltage()
{
    Keithley4200VoltageMeasureChannels measureChannel;

    if(channelNumber == 1)
        measureChannel = Keithley4200VoltageMeasureChannels::SMU1;
    else if(channelNumber == 2)
        measureChannel = Keithley4200VoltageMeasureChannels::SMU2;
    else if(channelNumber == 3)
        measureChannel = Keithley4200VoltageMeasureChannels::SMU3;
    else if(channelNumber == 4)
        measureChannel = Keithley4200VoltageMeasureChannels::SMU4;
    else if(channelNumber == 5)
        measureChannel = Keithley4200VoltageMeasureChannels::SMU5;
    else if(channelNumber == 6)
        measureChannel = Keithley4200VoltageMeasureChannels::SMU6;
    else if(channelNumber == 7)
        measureChannel = Keithley4200VoltageMeasureChannels::SMU7;
    else if(channelNumber == 8)
        measureChannel = Keithley4200VoltageMeasureChannels::SMU8;

    return driver->RequestQuery(chUserMode.cmdTriggerVoltage(measureChannel)).toDouble();
}

double Keithley4200SMUChannel::MeasureCurrent()
{
    Keithley4200CurrentMeasureChannels measureChannel;

    if(channelNumber == 1)
        measureChannel = Keithley4200CurrentMeasureChannels::SMU1;
    else if(channelNumber == 2)
        measureChannel = Keithley4200CurrentMeasureChannels::SMU2;
    else if(channelNumber == 3)
        measureChannel = Keithley4200CurrentMeasureChannels::SMU3;
    else if(channelNumber == 4)
        measureChannel = Keithley4200CurrentMeasureChannels::SMU4;
    else if(channelNumber == 5)
        measureChannel = Keithley4200CurrentMeasureChannels::SMU5;
    else if(channelNumber == 6)
        measureChannel = Keithley4200CurrentMeasureChannels::SMU6;
    else if(channelNumber == 7)
        measureChannel = Keithley4200CurrentMeasureChannels::SMU7;
    else if(channelNumber == 8)
        measureChannel = Keithley4200CurrentMeasureChannels::SMU8;

    return driver->RequestQuery(chUserMode.cmdTriggerCurrent(measureChannel)).toDouble();
}

double Keithley4200SMUChannel::MeasureResistance()
{
    return fabs(MeasureVoltage() / MeasureCurrent());
}

QVector<IV_Data> Keithley4200SMUChannel::LinearVoltageSweep(double start, double stop, int numPoints)
{
    QVector<IV_Data> res;
    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::LinearCurrentSweep(double start, double stop, int numPoints)
{
    QVector<IV_Data> res;
    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::LogarithmicVoltageSweep(double start, double stop, int numPoints)
{
    QVector<IV_Data> res;
    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::LogarithmicCurrentSweep(double start, double stop, int numPoints)
{
    QVector<IV_Data> res;
    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::ListVoltageSweep(const double sweepList[])
{
    QVector<IV_Data> res;
    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::ListCurrentSweep(const double sweepList[])
{
    QVector<IV_Data> res;
    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::PulsedLinearVoltageSweep(double start, double stop, int numPoints, double pulseWidth, double pulsePeriod, bool remoteSense)
{
    QVector<IV_Data> res;
    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::PulsedLinearCurrentSweep(double start, double stop, int numPoints, double pulseWidth, double pulsePeriod, bool remoteSense)
{
    QVector<IV_Data> res;
    return res;
}

void Keithley4200SMUChannel::StartVoltageTrace()
{

}

void Keithley4200SMUChannel::StartCurrentTrace()
{

}

void Keithley4200SMUChannel::Reset()
{

}
