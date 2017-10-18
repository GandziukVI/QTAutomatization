#include "Keithley4200SMUChannel.h"

Keithley4200SMUChannel::Keithley4200SMUChannel()
{
    isInitialized = false;

    signalMapper = new QSignalMapper(this);

    signalMapper->setMapping(&chDef, QString("DE"));
    signalMapper->setMapping(&chSrcSetup, QString("SS"));
    signalMapper->setMapping(&chMeasSetup, QString("SM"));
    signalMapper->setMapping(&chMeasControl, QString("MD"));
    signalMapper->setMapping(&chUserMode, QString("US"));
}

Keithley4200SMUChannel::~Keithley4200SMUChannel()
{
    delete signalMapper;
}

void Keithley4200SMUChannel::Initialize(const IDeviceIO &Driver)
{
    driver = Driver;
    channelNumber = 1;
}

void Keithley4200SMUChannel::Initialize(const IDeviceIO &Driver, QString &channelID)
{
    driver = Driver;
    channelNumber = channelID.toUInt();
}

void Keithley4200SMUChannel::SwitchON()
{
    // There is no need in implementation?
}

void Keithley4200SMUChannel::SwitchOFF()
{
    if(isInitialized) {
        const char* cmd = chDef.cmdDisableChannel(channelNumber);
        driver.SendCommandRequest(cmd);
    }
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
    if(isInitialized) {
        const char* cmd = chUserMode.cmdSMUSetSourceVoltage(channelNumber, Keithley4200VoltageRanges::Autorange, voltage, srcCompliance).toLatin1().data();
        driver.SendCommandRequest(cmd);
    }
}

void Keithley4200SMUChannel::SetSourceCurrent(const double current)
{
    if(isInitialized) {
        const char* cmd = chUserMode.cmdSMUSetSourceCurrent(channelNumber, Keithley4200CurrentRanges::Autorange, current, srcCompliance).toLatin1().data();
        driver.SendCommandRequest(cmd);
    }
}

void Keithley4200SMUChannel::SetAveraging(const int avg)
{
    if(isInitialized) {
        const char* cmd = chMeasSetup.cmdSetNumberOfReadings(avg).toLatin1().data();
        driver.SendCommandRequest(cmd);
    }
}
