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

    regExDouble = new QRegularExpression(QString("[+\\-]?(?:0|[1-9]\\d*)(?:\\.\\d*)?(?:[eE][+\\-]?\\d+)?"), QRegularExpression::MultilineOption);
}

Keithley4200SMUChannel::~Keithley4200SMUChannel()
{
    delete regExDouble;
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
    if(isInitialized) {
        avgNum = avg;
        driver->SendCommandRequest(chMeasSetup.cmdSetNumberOfReadings(avg));
    }
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

    double res = 0.0;

    int i = 0;
    for(; i != avgNum; ) {
        QString                 responseStr   = driver->RequestQuery(chUserMode.cmdTriggerVoltage(measureChannel));
        QRegularExpressionMatch responseMatch = regExDouble->match(responseStr);
        if (responseMatch.hasMatch())
            res += responseMatch.captured(0).toDouble();
        ++i;
    }

    return res / (double)avgNum;
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

    double res = 0.0;

    int i = 0;
    for(; i != avgNum; ) {
        QString responseStr = driver->RequestQuery(chUserMode.cmdTriggerCurrent(measureChannel));
        QRegularExpressionMatch responseMatch = regExDouble->match(responseStr);
        if (responseMatch.hasMatch())
            res += responseMatch.captured(0).toDouble();
        ++i;
    }

    return res / (double)avgNum;
}

double Keithley4200SMUChannel::MeasureResistance()
{
    return fabs(MeasureVoltage() / MeasureCurrent());
}

QVector<IV_Data> Keithley4200SMUChannel::LinearVoltageSweep(double start, double stop, int numPoints)
{
    QVector<IV_Data> res;

    // Page definition to perform linear voltage sweep
    const char* chVoltName = QObject::tr("Volt%1").arg(channelNumber).toStdString().c_str();
    const char* chCurrName = QObject::tr("Curr%1").arg(channelNumber).toStdString().c_str();

    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, SMUSourceMode::Voltage, SMUSourceFunction::VAR1));
    driver->SendCommandRequest(chSrcSetup.cmdConfVAR1Sweep(SMUSourceMode::Voltage, SMUSweepMode::LinearSweep, start, stop, (stop - start) / (double)numPoints, srcCompliance));

    // Definition of variables to read
    QVector<const char*> variableVec;

    variableVec.push_back(chVoltName);
    variableVec.push_back(chCurrName);

    driver->SendCommandRequest(chMeasSetup.cmdEnableVIFunctions(variableVec));

    // Performing the measurement
    driver->SendCommandRequest(chMeasControl.cmdControlMeasurements(Keithley4200ControlMeasurementTypes::SingleTriggerTest));

    // Reading the data obtained
    QString resTimeStr = driver->RequestQuery(chMeasControl.cmdObtainOutputTimeStampData(channelNumber));
    QString resVoltStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chVoltName));
    QString resCurrStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chCurrName));

    QRegularExpressionMatchIterator resVoltIter = regExDouble->globalMatch(resVoltStr);
    QRegularExpressionMatchIterator resCurrIter = regExDouble->globalMatch(resCurrStr);

    while (resVoltIter.hasNext() && resCurrIter.hasNext()) {

        double timeVal    = 0.0;
        double voltageVal = resVoltIter.next().captured().toDouble();
        double currentVal = resCurrIter.next().captured().toDouble();

        IV_Data ivDataPoint(0.0, voltageVal, currentVal);

        res.push_back(ivDataPoint);
    }

    // Setting back to constant voltage mode
    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, srcMode));

    // Switching the channel off
    driver->SendCommandRequest(chDef.cmdDisableChannel(channelNumber));

    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::LinearCurrentSweep(double start, double stop, int numPoints)
{
    QVector<IV_Data> res;

    // Page definition to perform linear voltage sweep
    const char* chVoltName = QObject::tr("Volt%1").arg(channelNumber).toStdString().c_str();
    const char* chCurrName = QObject::tr("Curr%1").arg(channelNumber).toStdString().c_str();

    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, SMUSourceMode::Current, SMUSourceFunction::VAR1));
    driver->SendCommandRequest(chSrcSetup.cmdConfVAR1Sweep(SMUSourceMode::Current, SMUSweepMode::LinearSweep, start, stop, (stop - start) / (double)numPoints, srcCompliance));

    // Definition of variables to read
    QVector<const char*> variableVec;

    variableVec.push_back(chVoltName);
    variableVec.push_back(chCurrName);

    driver->SendCommandRequest(chMeasSetup.cmdEnableVIFunctions(variableVec));

    // Performing the measurement
    driver->SendCommandRequest(chMeasControl.cmdControlMeasurements(Keithley4200ControlMeasurementTypes::SingleTriggerTest));

    // Reading the data obtained
    QString resTimeStr = driver->RequestQuery(chMeasControl.cmdObtainOutputTimeStampData(channelNumber));
    QString resVoltStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chVoltName));
    QString resCurrStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chCurrName));

    QRegularExpressionMatchIterator resVoltIter = regExDouble->globalMatch(resVoltStr);
    QRegularExpressionMatchIterator resCurrIter = regExDouble->globalMatch(resCurrStr);

    while (resVoltIter.hasNext() && resCurrIter.hasNext()) {

        double timeVal    = 0.0;
        double voltageVal = resVoltIter.next().captured().toDouble();
        double currentVal = resCurrIter.next().captured().toDouble();

        IV_Data ivDataPoint(0.0, voltageVal, currentVal);

        res.push_back(ivDataPoint);
    }

    // Setting back to constant voltage mode
    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, srcMode));

    // Switching the channel off
    driver->SendCommandRequest(chDef.cmdDisableChannel(channelNumber));

    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::LogarithmicVoltageSweep(double start, double stop, int numPoints)
{
    QVector<IV_Data> res;

    // Page definition to perform linear voltage sweep
    const char* chVoltName = QObject::tr("Volt%1").arg(channelNumber).toStdString().c_str();
    const char* chCurrName = QObject::tr("Curr%1").arg(channelNumber).toStdString().c_str();

    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, SMUSourceMode::Voltage, SMUSourceFunction::VAR1));
    driver->SendCommandRequest(chSrcSetup.cmdConfVAR1Sweep(SMUSourceMode::Voltage, SMUSweepMode::Log10Sweep, start, stop, (stop - start) / (double)numPoints, srcCompliance));

    // Definition of variables to read
    QVector<const char*> variableVec;

    variableVec.push_back(chVoltName);
    variableVec.push_back(chCurrName);

    driver->SendCommandRequest(chMeasSetup.cmdEnableVIFunctions(variableVec));

    // Performing the measurement
    driver->SendCommandRequest(chMeasControl.cmdControlMeasurements(Keithley4200ControlMeasurementTypes::SingleTriggerTest));

    // Reading the data obtained
    QString resTimeStr = driver->RequestQuery(chMeasControl.cmdObtainOutputTimeStampData(channelNumber));
    QString resVoltStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chVoltName));
    QString resCurrStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chCurrName));

    QRegularExpressionMatchIterator resVoltIter = regExDouble->globalMatch(resVoltStr);
    QRegularExpressionMatchIterator resCurrIter = regExDouble->globalMatch(resCurrStr);

    while (resVoltIter.hasNext() && resCurrIter.hasNext()) {

        double timeVal    = 0.0;
        double voltageVal = resVoltIter.next().captured().toDouble();
        double currentVal = resCurrIter.next().captured().toDouble();

        IV_Data ivDataPoint(timeVal, voltageVal, currentVal);

        res.push_back(ivDataPoint);
    }

    // Setting back to constant voltage mode
    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, srcMode));

    // Switching the channel off
    driver->SendCommandRequest(chDef.cmdDisableChannel(channelNumber));

    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::LogarithmicCurrentSweep(double start, double stop, int numPoints)
{
    QVector<IV_Data> res;

    // Page definition to perform linear voltage sweep
    const char* chVoltName = QObject::tr("Volt%1").arg(channelNumber).toStdString().c_str();
    const char* chCurrName = QObject::tr("Curr%1").arg(channelNumber).toStdString().c_str();

    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, SMUSourceMode::Current, SMUSourceFunction::VAR1));
    driver->SendCommandRequest(chSrcSetup.cmdConfVAR1Sweep(SMUSourceMode::Current, SMUSweepMode::Log10Sweep, start, stop, (stop - start) / (double)numPoints, srcCompliance));

    // Definition of variables to read
    QVector<const char*> variableVec;

    variableVec.push_back(chVoltName);
    variableVec.push_back(chCurrName);

    driver->SendCommandRequest(chMeasSetup.cmdEnableVIFunctions(variableVec));

    // Performing the measurement
    driver->SendCommandRequest(chMeasControl.cmdControlMeasurements(Keithley4200ControlMeasurementTypes::SingleTriggerTest));

    // Reading the data obtained
    QString resTimeStr = driver->RequestQuery(chMeasControl.cmdObtainOutputTimeStampData(channelNumber));
    QString resVoltStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chVoltName));
    QString resCurrStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chCurrName));

    QRegularExpressionMatchIterator resVoltIter = regExDouble->globalMatch(resVoltStr);
    QRegularExpressionMatchIterator resCurrIter = regExDouble->globalMatch(resCurrStr);

    while (resVoltIter.hasNext() && resCurrIter.hasNext()) {

        double timeVal    = 0.0;
        double voltageVal = resVoltIter.next().captured().toDouble();
        double currentVal = resCurrIter.next().captured().toDouble();

        IV_Data ivDataPoint(timeVal, voltageVal, currentVal);

        res.push_back(ivDataPoint);
    }

    // Setting back to constant voltage mode
    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, srcMode));

    // Switching the channel off
    driver->SendCommandRequest(chDef.cmdDisableChannel(channelNumber));

    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::ListVoltageSweep(const QVector<double>& sweepList)
{
    QVector<IV_Data> res;

    // Page definition to perform linear voltage sweep
    const char* chVoltName = QObject::tr("Volt%1").arg(channelNumber).toStdString().c_str();
    const char* chCurrName = QObject::tr("Curr%1").arg(channelNumber).toStdString().c_str();

    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, SMUSourceMode::Voltage, SMUSourceFunction::VAR1));
    driver->SendCommandRequest(chSrcSetup.cmdConfListSweep(SMUSourceMode::Voltage, channelNumber, srcCompliance, sweepList));

    // Definition of variables to read
    QVector<const char*> variableVec;

    variableVec.push_back(chVoltName);
    variableVec.push_back(chCurrName);

    driver->SendCommandRequest(chMeasSetup.cmdEnableVIFunctions(variableVec));

    // Performing the measurement
    driver->SendCommandRequest(chMeasControl.cmdControlMeasurements(Keithley4200ControlMeasurementTypes::SingleTriggerTest));

    // Reading the data obtained
    QString resTimeStr = driver->RequestQuery(chMeasControl.cmdObtainOutputTimeStampData(channelNumber));
    QString resVoltStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chVoltName));
    QString resCurrStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chCurrName));

    QRegularExpressionMatchIterator resVoltIter = regExDouble->globalMatch(resVoltStr);
    QRegularExpressionMatchIterator resCurrIter = regExDouble->globalMatch(resCurrStr);

    while (resVoltIter.hasNext() && resCurrIter.hasNext()) {

        double timeVal    = 0.0;
        double voltageVal = resVoltIter.next().captured().toDouble();
        double currentVal = resCurrIter.next().captured().toDouble();

        IV_Data ivDataPoint(timeVal, voltageVal, currentVal);

        res.push_back(ivDataPoint);
    }

    // Setting back to constant voltage mode
    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, srcMode));

    // Switching the channel off
    driver->SendCommandRequest(chDef.cmdDisableChannel(channelNumber));

    return res;
}

QVector<IV_Data> Keithley4200SMUChannel::ListCurrentSweep(const QVector<double>& sweepList)
{
    QVector<IV_Data> res;

    // Page definition to perform linear voltage sweep
    const char* chVoltName = QObject::tr("Volt%1").arg(channelNumber).toStdString().c_str();
    const char* chCurrName = QObject::tr("Curr%1").arg(channelNumber).toStdString().c_str();

    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, SMUSourceMode::Current, SMUSourceFunction::VAR1));
    driver->SendCommandRequest(chSrcSetup.cmdConfListSweep(SMUSourceMode::Current, channelNumber, srcCompliance, sweepList));

    // Definition of variables to read
    QVector<const char*> variableVec;

    variableVec.push_back(chVoltName);
    variableVec.push_back(chCurrName);

    driver->SendCommandRequest(chMeasSetup.cmdEnableVIFunctions(variableVec));

    // Performing the measurement
    driver->SendCommandRequest(chMeasControl.cmdControlMeasurements(Keithley4200ControlMeasurementTypes::SingleTriggerTest));

    // Reading the data obtained
    QString resTimeStr = driver->RequestQuery(chMeasControl.cmdObtainOutputTimeStampData(channelNumber));
    QString resVoltStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chVoltName));
    QString resCurrStr = driver->RequestQuery(chMeasControl.cmdObtainOutputData(chCurrName));

    QRegularExpressionMatchIterator resVoltIter = regExDouble->globalMatch(resVoltStr);
    QRegularExpressionMatchIterator resCurrIter = regExDouble->globalMatch(resCurrStr);

    while (resVoltIter.hasNext() && resCurrIter.hasNext()) {

        double timeVal    = 0.0;
        double voltageVal = resVoltIter.next().captured().toDouble();
        double currentVal = resCurrIter.next().captured().toDouble();

        IV_Data ivDataPoint(timeVal, voltageVal, currentVal);

        res.push_back(ivDataPoint);
    }

    // Setting back to constant voltage mode
    driver->SendCommandRequest(chDef.cmdDefineChannel(channelNumber, chVoltName, chCurrName, srcMode));

    // Switching the channel off
    driver->SendCommandRequest(chDef.cmdDisableChannel(channelNumber));

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
    if(isInitialized)
        driver->SendCommandRequest("*RST");
}
