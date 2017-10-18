#ifndef KEITHLEY4200SMUCHANNEL_H
#define KEITHLEY4200SMUCHANNEL_H

#include "keithley4200_global.h"

#include "IKeithley4200Page.h"
#include "Keithley4200ChannelDefinitionPage.h"
#include "Keithley4200SourceSetupPage.h"
#include "Keithley4200MeasurementSetupPage.h"
#include "Keithley4200MeasurementControlPage.h"
#include "Keithley4200UserModePage.h"
#include "Keithley4200CommonCommands.h"

#include <IDeviceIO.h>
#include <ISourceMeterUnit.h>

#include <QObject>
#include <QSignalMapper>

class KEITHLEY4200SHARED_EXPORT Keithley4200SMUChannel : public ISourceMeterUnit
{
public:
    Keithley4200SMUChannel();
    ~Keithley4200SMUChannel();

    void Initialize(const IDeviceIO &Driver);
    void Initialize(const IDeviceIO &Driver, QString& channelID);

    void SwitchON();
    void SwitchOFF();

    void SetSourceMode    (const SMUSourceMode sourceMode);
    void SetCompliance    (const double compliance);
    void SetSourceDelay   (const double delay);
    void SetSourceVoltage (const double voltage);
    void SetSourceCurrent (const double current);
    void SetAveraging     (const int avg);

private:
    IDeviceIO    driver;
    unsigned int channelNumber;
    bool         isInitialized;

    double    srcCompliance;
    double    srcDelay;

    SMUSourceMode srcMode;

    Keithley4200ChannelDefinitionPage  chDef;
    Keithley4200SourceSetupPage        chSrcSetup;
    Keithley4200MeasurementSetupPage   chMeasSetup;
    Keithley4200MeasurementControlPage chMeasControl;
    Keithley4200UserModePage           chUserMode;
    Keithley4200CommonCommands         chCommon;

    QSignalMapper*                     signalMapper;
};

#endif // KEITHLEY4200SMUCHANNEL_H
