#ifndef IKEITHLEY4200PAGE_H
#define IKEITHLEY4200PAGE_H

#include "keithley4200_global.h"
#include "Keithley4200Definitions.h"

#include <SourceMeterUnitDefinitions.h>

#include <QObject>
#include <QString>
#include <QTextStream>

#include <QVector>
#include <qiterator.h>

class KEITHLEY4200SHARED_EXPORT IKeithley4200Page : public QObject {

    Q_OBJECT

public:
    IKeithley4200Page ();

    QString buildCommand(const char* command);
    QString buildCommand(const QString& command);

    bool isCurrent;
protected:
    char pageIdentifier[256];
    char commandIdentifier[256];
    unsigned int channelNumber;

    void pageSetCurrent();

    double checkValueRange(const double value, const double lowerLimit, const double upperLimit) const;
    int    checkValueRange(const int value, const int lowerLimit, const int upperLimit) const;

    void   extCopyString(char* dest, const char* src) const;
    int    getSMUSourceMode(SMUSourceMode sourceMode) const;
    int    getSMUSourceFunction(SMUSourceFunction sourceFunction) const;
    int    getSMUSweepMode(SMUSweepMode sweepMode) const;
    int    getSMUMasterOrSlaveMode(SMUMasterOrSlaveMode masterOrSlaveMode) const;
    int    getSMUDisplayMode(Keithley4200DisplayMode displayMode) const;
    int    getSMUXAxisScaleType(Keithley4200XAxisScaleType xAxisScaleType) const;
    int     getSMUYAxisScaleType(Keithley4200YAxisScaleType yAxisScaleType) const;
    int    getSMUControlMeasurementType(Keithley4200ControlMeasurementTypes controlMeasurementType) const;
    char   getSMUSaveFileType(Keithley4200FileTypes fileType) const;
    char*  getChannelType(Keithley4200ChannelType channelType) const;
    int    getChannelSourceRange(Keithley4200SourceRange sourceRange) const;
    int    getSMUVoltageSourceRange(Keithley4200VoltageRanges voltageSourceRange) const;
    int    getSMUCurrentSourceRange(Keithley4200CurrentRanges currentSourceRange) const;
    int    getVoltageMeasureChannel(Keithley4200VoltageMeasureChannels vmChannel) const;
    int    getCurrentMeasureChannel(Keithley4200CurrentMeasureChannels imChannel) const;
    int    getIntegrationTime(Keithley4200IntegrationTimes integrationTime) const;
    double getCurrentRange(Keithley4200CurrentRanges currentRange) const;

private:
    QString commandString;

signals:
    void pageChanged(const char* pageID);
};

#endif // IKEITHLEY4200PAGE_H
