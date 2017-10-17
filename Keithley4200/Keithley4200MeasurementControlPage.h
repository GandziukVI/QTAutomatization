#ifndef KEITHLEY4200MEASUREMENTCONTROLPAGE_H
#define KEITHLEY4200MEASUREMENTCONTROLPAGE_H

#include "keithley4200_global.h"
#include "IKeithley4200Page.h"

class KEITHLEY4200SHARED_EXPORT Keithley4200MeasurementControlPage : public IKeithley4200Page
{
public:
    Keithley4200MeasurementControlPage();

    QString cmdControlMeasurements(Keithley4200ControlMeasurementTypes controlMeasurementType);
    QString cmdObtainOutputData(const char* channelName);
    QString cmdObtainOutputTimeStampData(const unsigned int channelID);
    QString cmdSaveFile(Keithley4200FileTypes fileType, const char* fileName, const char* comment);
    QString cmdGetFile(Keithley4200FileTypes fileType, const char* fileName);
    QString cmdMapChannel(const unsigned int channelID, Keithley4200ChannelType channelType, const unsigned int chNumber);
    QString cmdSetFixedSourceRange(const unsigned int channelID, Keithley4200SourceRange sourceRange);
};

#endif // KEITHLEY4200MEASUREMENTCONTROLPAGE_H
