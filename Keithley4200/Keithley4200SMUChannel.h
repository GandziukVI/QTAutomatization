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

#include <QRegularExpression>

class KEITHLEY4200SHARED_EXPORT Keithley4200SMUChannel : public QObject, ISourceMeterUnit
{
    Q_OBJECT

public:
    Keithley4200SMUChannel();
    ~Keithley4200SMUChannel();

    void Initialize(IDeviceIO &Driver);
    void Initialize(IDeviceIO &Driver, QString& channelID);

    void SwitchON();
    void SwitchOFF();

    void SetSourceMode    (const SMUSourceMode sourceMode);
    void SetCompliance    (const double compliance);
    void SetSourceDelay   (const double delay);
    void SetSourceVoltage (const double voltage);
    void SetSourceCurrent (const double current);
    void SetAveraging     (const int avg);
    void SetNPLC          (const double val);

    double MeasureVoltage ();
    double MeasureCurrent ();
    double MeasureResistance();

    QVector<IV_Data> LinearVoltageSweep(double start, double stop, int numPoints);
    QVector<IV_Data> LinearCurrentSweep(double start, double stop, int numPoints);
    QVector<IV_Data> LogarithmicVoltageSweep(double start, double stop, int numPoints);
    QVector<IV_Data> LogarithmicCurrentSweep(double start, double stop, int numPoints);
    QVector<IV_Data> ListVoltageSweep(const QVector<double>& sweepList);
    QVector<IV_Data> ListCurrentSweep(const QVector<double>& sweepList);

    QVector<IV_Data> PulsedLinearVoltageSweep(double start, double stop, int numPoints, double pulseWidth, double pulsePeriod, bool remoteSense);
    QVector<IV_Data> PulsedLinearCurrentSweep(double start, double stop, int numPoints, double pulseWidth, double pulsePeriod, bool remoteSense);

    void StartVoltageTrace ();
    void StartCurrentTrace ();

    void Reset ();

private:
    IDeviceIO    *driver;
    unsigned int channelNumber;
    bool         isInitialized;

    double       srcCompliance;
    double       srcDelay;
    int          avgNum;

    SMUSourceMode srcMode;

    Keithley4200ChannelDefinitionPage  chDef;
    Keithley4200SourceSetupPage        chSrcSetup;
    Keithley4200MeasurementSetupPage   chMeasSetup;
    Keithley4200MeasurementControlPage chMeasControl;
    Keithley4200UserModePage           chUserMode;
    Keithley4200CommonCommands         chCommon;

    QRegularExpression*                regExDouble;

public slots:
    void onPageChanged(QString pageID);
};

#endif // KEITHLEY4200SMUCHANNEL_H
