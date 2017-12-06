#include "NoiseFETModel.h"

NoiseFETModel::NoiseFETModel(QObject *parent) : QObject(parent)
{

}

QString NoiseFETModel::agilentU2542ARes()
{
    return mAgilentU2542ARes;
}

void NoiseFETModel::setAgilentU2542ARes(const QString &resName)
{
    if (resName == mAgilentU2542ARes)
        return;

    mAgilentU2542ARes = resName;
    emit agilentU2542AResChanged();
}

bool NoiseFETModel::isTransferCurveMode()
{
    return mIsTransferCurveMode;
}

void NoiseFETModel::setIsTransferCurveMode(const bool &mode)
{
    if (mode == mIsTransferCurveMode)
        return;

    mIsTransferCurveMode = mode;
    emit isTransferCurveModeChanged();
}

bool NoiseFETModel::isOutputCurveMode()
{
    return mIsOutputCurveMode;
}

void NoiseFETModel::setIsOutputCurveMode(const bool &mode)
{
    if (mode == mIsOutputCurveMode)
        return;

    mIsOutputCurveMode = mode;
    emit isOutputCurveModeChanged();
}

QVector<qreal> NoiseFETModel::gateVoltages()
{
    return mGateVoltages;
}

void NoiseFETModel::setGateVoltages(const QVector<qreal> &voltages)
{
    if (voltages == mGateVoltages)
        return;

    mGateVoltages = voltages;
    emit gateVoltagesChanged();
}

QVector<qreal> NoiseFETModel::drainVoltages()
{
    return mDrainVoltages;
}

void NoiseFETModel::setDrainVoltages(const QVector<qreal> &voltages)
{
    if (voltages == mDrainVoltages)
        return;

    mDrainVoltages = voltages;
    emit drainVoltagesChanged();
}

double NoiseFETModel::voltageDeviation()
{
    return mVoltageDeviation;
}

void NoiseFETModel::setVoltageDeviation(const double &deviation)
{
    if (deviation == mVoltageDeviation)
        return;

    mVoltageDeviation = deviation;
    emit voltageDeviationChanged();
}

int NoiseFETModel::nAvgFast()
{
    return mNAvgFast;
}

void NoiseFETModel::setNAvgFast(const int &nAvg)
{
    if(nAvg == mNAvgFast)
        return;

    mNAvgFast = nAvg;
    emit nAvgFastChanged();
}

int NoiseFETModel::nAvgSlow()
{
    return mNAvgSlow;
}

void NoiseFETModel::setNAvgSlow(const int &nAvg)
{
    if (nAvg == mNAvgSlow)
        return;

    mNAvgSlow = nAvg;
    emit nAvgSlowChanged();
}

double NoiseFETModel::stabilizationTime()
{
    return mStabilizationTime;
}

void NoiseFETModel::setStabilizationTime(const double &stabTime)
{
    if (stabTime == mStabilizationTime)
        return;

    mStabilizationTime = stabTime;
    emit stabilizationTimeChanged();
}

double NoiseFETModel::loadResistance()
{
    return mLoadResistance;
}

void NoiseFETModel::setLoadResistance(const double &resistance)
{
    if (resistance == mLoadResistance)
        return;

    mLoadResistance = resistance;
    emit loadResistanceChanged();
}

int NoiseFETModel::samplingFrequency()
{
    return mSamplingFrequency;
}

void NoiseFETModel::setSamplingFrequency(const int &frequency)
{
    if (frequency == mSamplingFrequency)
        return;

    mSamplingFrequency = frequency;
    emit samplingFrequencyChanged();
}

int NoiseFETModel::nSpectraAvg()
{
    return mNSpectraAvg;
}

void NoiseFETModel::setNSpectraAvg(const int &nAvg)
{
    if (nAvg == mNSpectraAvg)
        return;

    mNSpectraAvg = nAvg;
    emit nSpectraAvgChanged();
}

double NoiseFETModel::kPreampl()
{
    return mKPreampl;
}

void NoiseFETModel::setKPreampl(const double &amplKoef)
{
    if (amplKoef == mKPreampl)
        return;

    mKPreampl = amplKoef;
    emit kPreamplChanged();
}

double NoiseFETModel::kAmpl()
{
    return mKAmpl;
}

void NoiseFETModel::setKAmpl(const double &amplKoef)
{
    if (amplKoef == mKAmpl)
        return;

    mKAmpl = amplKoef;
    emit kAmplChanged();
}

double NoiseFETModel::temperature0()
{
    return mTemperature0;
}

void NoiseFETModel::setTemperature0(const double &temperature)
{
    if (temperature == mTemperature0)
        return;

    mTemperature0 = temperature;
    emit temperature0Changed();
}

double NoiseFETModel::temperatureE()
{
    return mTemperatureE;
}

void NoiseFETModel::setTemperatureE(const double &temperature)
{
    if (temperature == mTemperatureE)
        return;

    mTemperatureE = temperature;
    emit temperatureEChanged();
}

bool NoiseFETModel::measureTimeTraces()
{
    return mMeasureTimeTraces;
}

void NoiseFETModel::setMeasureTimeTraces(const bool &state)
{
    if (state == mMeasureTimeTraces)
        return;

    mMeasureTimeTraces = state;
    emit measureTimeTracesChanged();
}

int NoiseFETModel::timeTraceFrequency()
{
    return mTimeTraceFrequency;
}

void NoiseFETModel::setTimeTraceFrequency(const int &frequency)
{
    if (frequency == mTimeTraceFrequency)
        return;

    mTimeTraceFrequency = frequency;
    emit timeTraceFrequencyChanged();
}

QString NoiseFETModel::dataFilePath()
{
    return mDataFilePath;
}

void NoiseFETModel::setDataFilePath(const QString &path)
{
    if (path == mDataFilePath)
        return;

    mDataFilePath = path;
    emit dataFilePathChanged();
}

QString NoiseFETModel::dataFileName()
{
    return mDataFileName;
}

void NoiseFETModel::setDataFileName(const QString &fileName)
{
    if (fileName == mDataFileName)
        return;

    mDataFileName = fileName;
    emit dataFileNameChanged();
}
