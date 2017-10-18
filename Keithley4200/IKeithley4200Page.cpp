#include "IKeithley4200Page.h"

#include <memory>
#include <QTextStream>

IKeithley4200Page::IKeithley4200Page()
    : isCurrent(false)
{
}

QString IKeithley4200Page::buildCommand(const char* command)
{
    if(!commandString.isEmpty())
        commandString.clear();

    QTextStream commandBuilder(&commandString);

    if(!isCurrent)
        commandBuilder << pageIdentifier << '\n' << commandIdentifier << command << '\n';
    else
        commandBuilder << commandIdentifier << command << '\n';

    return commandString;
}

QString IKeithley4200Page::buildCommand(const QString& command)
{
    if(!commandString.isEmpty())
        commandString.clear();

    QTextStream commandBuilder(&commandString);

    if(!isCurrent)
        commandBuilder << pageIdentifier << '\n' << commandIdentifier << command << '\n';
    else
        commandBuilder << commandIdentifier << command << '\n';

    return commandString;
}

void IKeithley4200Page::pageSetCurrent()
{
    if(!isCurrent) {
        isCurrent = true;
        emit pageChanged(pageIdentifier);
    }
}

double IKeithley4200Page::checkValueRange(const double value, const double lowerLimit, const double upperLimit) const
{
    double realValue;
    if(value < lowerLimit)
        realValue = lowerLimit;
    else if(value > upperLimit)
        realValue = upperLimit;
    else
        realValue = value;

    return realValue;
}

int IKeithley4200Page::checkValueRange(const int value, const int lowerLimit, const int upperLimit) const
{
    int realValue;
    if(value < lowerLimit)
        realValue = lowerLimit;
    else if(value > upperLimit)
        realValue = upperLimit;
    else
        realValue = value;

    return realValue;
}

void IKeithley4200Page::extCopyString(char* dest, const char* src) const
{
    std::string srcStr(src);
    std::size_t len = srcStr.copy(dest, srcStr.length());
    dest[len] = '\0';
}

int IKeithley4200Page::getSMUSourceMode(SMUSourceMode sourceMode) const
{
    switch(sourceMode) {

    case SMUSourceMode::Voltage:
        return 1;
    case SMUSourceMode::Current:
        return 2;
    case SMUSourceMode::Common:
        return 3;
    case SMUSourceMode::ModeNotSet:
        return -1;
    }

    return 1;
}

int IKeithley4200Page::getSMUSourceFunction(SMUSourceFunction sourceFunction) const
{
    switch (sourceFunction) {

    case SMUSourceFunction::VAR1:
        return 1;
    case SMUSourceFunction::VAR2:
        return 2;
    case SMUSourceFunction::Constant:
        return 3;
    case SMUSourceFunction::VAR1Scaled:
        return 4;
    }

    return 3;
}

int IKeithley4200Page::getSMUSweepMode(SMUSweepMode sweepMode) const
{
    switch (sweepMode) {

    case SMUSweepMode::LinearSweep:
        return 1;
    case SMUSweepMode::Log10Sweep:
        return 2;
    case SMUSweepMode::Log25Sweep:
        return 3;
    case SMUSweepMode::Log50Sweep:
        return 4;
    }

    return 1;
}

int IKeithley4200Page::getSMUMasterOrSlaveMode(SMUMasterOrSlaveMode masterOrSlaveMode) const
{
    switch (masterOrSlaveMode) {

    case SMUMasterOrSlaveMode::Slave:
        return 0;
    case SMUMasterOrSlaveMode::Master:
        return 1;
    }

    return 1;
}

int IKeithley4200Page::getSMUDisplayMode(Keithley4200DisplayMode displayMode) const
{
    switch (displayMode) {

    case Keithley4200DisplayMode::GraphicsDisplayMode:
        return 1;
    case Keithley4200DisplayMode::ListdisplayMode:
        return 2;
    }

    return 2;
}

int IKeithley4200Page::getSMUXAxisScaleType(Keithley4200XAxisScaleType xAxisScaleType) const
{
    switch (xAxisScaleType) {

    case Keithley4200XAxisScaleType::LinearScale:
        return 1;
    case Keithley4200XAxisScaleType::LogScale:
        return 2;
    }

    return 1;
}

int IKeithley4200Page::getSMUYAxisScaleType(Keithley4200YAxisScaleType yAxisScaleType) const
{
    switch (yAxisScaleType) {

    case Keithley4200YAxisScaleType::LinearScale:
        return 1;
    case Keithley4200YAxisScaleType::LogScale:
        return 2;
    case Keithley4200YAxisScaleType::LogScaleAbsoluteValue:
        return 3;
    }

    return 1;
}

int IKeithley4200Page::getSMUControlMeasurementType(Keithley4200ControlMeasurementTypes controlMeasurementType) const
{
    switch (controlMeasurementType) {

    case Keithley4200ControlMeasurementTypes::SingleTriggerTest:
        return 1;
    case Keithley4200ControlMeasurementTypes::RepeatedTriggerTest:
        return 2;
    case Keithley4200ControlMeasurementTypes::AppendTriggertest:
        return 3;
    case Keithley4200ControlMeasurementTypes::StopAbortTest:
        return 4;
    }

    return 1;
}

char IKeithley4200Page::getSMUSaveFileType(Keithley4200FileTypes fileType) const
{
    switch (fileType) {

    case Keithley4200FileTypes::DataOrProgramFile:
        return 'D';
    case Keithley4200FileTypes::ProgramFile:
        return 'P';
    }

    return 'D';
}

char *IKeithley4200Page::getChannelType(Keithley4200ChannelType channelType) const
{
    switch (channelType) {

    case Keithley4200ChannelType::SMU:
        return "SMU";
    case Keithley4200ChannelType::VS:
        return "VS";
    case Keithley4200ChannelType::VM:
        return "VM";
    }

    return "SMU";
}

int IKeithley4200Page::getChannelSourceRange(Keithley4200SourceRange sourceRange) const
{
    switch (sourceRange) {

    case Keithley4200SourceRange::Auto:
        return 0;
    case Keithley4200SourceRange::BestFixed:
        return 2;
    }

    return 0;
}

int IKeithley4200Page::getSMUVoltageSourceRange(Keithley4200VoltageRanges voltageSourceRange) const
{
    switch (voltageSourceRange) {

    case Keithley4200VoltageRanges::Autorange:
        return 0;
    case Keithley4200VoltageRanges::Range20V:
        return 1;
    case Keithley4200VoltageRanges::Range200V:
        return 2;
    case Keithley4200VoltageRanges::Range200VExt:
        return 3;
    }

    return 0;
}

int IKeithley4200Page::getSMUCurrentSourceRange(Keithley4200CurrentRanges currentSourceRange) const
{
    switch (currentSourceRange) {

    case Keithley4200CurrentRanges::Autorange:
        return 0;
    case Keithley4200CurrentRanges::Range1nA:
        return 1;
    case Keithley4200CurrentRanges::Range10nA:
        return 2;
    case Keithley4200CurrentRanges::Range100nA:
        return 3;
    case Keithley4200CurrentRanges::Range1uA:
        return 4;
    case Keithley4200CurrentRanges::Range10uA:
        return 5;
    case Keithley4200CurrentRanges::Range100uA:
        return 6;
    case Keithley4200CurrentRanges::Range1mA:
        return 7;
    case Keithley4200CurrentRanges::Range10mA:
        return 8;
    case Keithley4200CurrentRanges::Range100mA:
        return 9;
    case Keithley4200CurrentRanges::Range1A:
        return 10;
    case Keithley4200CurrentRanges::Range1pA:
        return 11;
    case Keithley4200CurrentRanges::Range10pA:
        return 11;
    case Keithley4200CurrentRanges::Range100pA:
        return 12;
    }

    return 0;
}

int IKeithley4200Page::getVoltageMeasureChannel(Keithley4200VoltageMeasureChannels vmChannel) const
{
    switch (vmChannel) {

    case Keithley4200VoltageMeasureChannels::SMU1:
        return 1;
    case Keithley4200VoltageMeasureChannels::SMU2:
        return 2;
    case Keithley4200VoltageMeasureChannels::SMU3:
        return 3;
    case Keithley4200VoltageMeasureChannels::SMU4:
        return 4;
    case Keithley4200VoltageMeasureChannels::VM1:
        return 5;
    case Keithley4200VoltageMeasureChannels::VM2:
        return 6;
    case Keithley4200VoltageMeasureChannels::SMU5:
        return 7;
    case Keithley4200VoltageMeasureChannels::SMU6:
        return 8;
    case Keithley4200VoltageMeasureChannels::SMU7:
        return 9;
    case Keithley4200VoltageMeasureChannels::SMU8:
        return 10;
    case Keithley4200VoltageMeasureChannels::VM3:
        return 11;
    case Keithley4200VoltageMeasureChannels::VM4:
        return 12;
    case Keithley4200VoltageMeasureChannels::VM5:
        return 13;
    case Keithley4200VoltageMeasureChannels::VM6:
        return 14;
    case Keithley4200VoltageMeasureChannels::VM7:
        return 15;
    case Keithley4200VoltageMeasureChannels::VM8:
        return 16;
    }

    return 1;
}

int IKeithley4200Page::getCurrentMeasureChannel(Keithley4200CurrentMeasureChannels imChannel) const
{
    switch (imChannel) {

    case Keithley4200CurrentMeasureChannels::SMU1:
        return 1;
    case Keithley4200CurrentMeasureChannels::SMU2:
        return 2;
    case Keithley4200CurrentMeasureChannels::SMU3:
        return 3;
    case Keithley4200CurrentMeasureChannels::SMU4:
        return 4;
    case Keithley4200CurrentMeasureChannels::SMU5:
        return 5;
    case Keithley4200CurrentMeasureChannels::SMU6:
        return 6;
    case Keithley4200CurrentMeasureChannels::SMU7:
        return 7;
    case Keithley4200CurrentMeasureChannels::SMU8:
        return 8;
    }

    return 1;
}

int IKeithley4200Page::getIntegrationTime(Keithley4200IntegrationTimes integrationTime) const
{
    switch (integrationTime) {

    case Keithley4200IntegrationTimes::Short:
        return 1;
    case Keithley4200IntegrationTimes::Medium:
        return 2;
    case Keithley4200IntegrationTimes::Long:
        return 3;
    }

    return 2;
}

double IKeithley4200Page::getCurrentRange(Keithley4200CurrentRanges currentRange) const
{
    switch (currentRange) {

    case Keithley4200CurrentRanges::Range1nA:
        return 1e-9;
    case Keithley4200CurrentRanges::Range10nA:
        return 1e-8;
    case Keithley4200CurrentRanges::Range100nA:
        return 1e-7;
    case Keithley4200CurrentRanges::Range1uA:
        return 1e-6;
    case Keithley4200CurrentRanges::Range10uA:
        return 1e-5;
    case Keithley4200CurrentRanges::Range100uA:
        return 1e-4;
    case Keithley4200CurrentRanges::Range1mA:
        return 1e-3;
    case Keithley4200CurrentRanges::Range10mA:
        return 1e-2;
    case Keithley4200CurrentRanges::Range100mA:
        return 1e-1;
    case Keithley4200CurrentRanges::Range1A:
        return 1.0;
    case Keithley4200CurrentRanges::Range1pA:
        return 1e-12;
    case Keithley4200CurrentRanges::Range10pA:
        return 1e-11;
    case Keithley4200CurrentRanges::Range100pA:
        return 1e-10;
    }

    return 1e-3;
}
