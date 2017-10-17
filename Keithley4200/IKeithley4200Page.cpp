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
