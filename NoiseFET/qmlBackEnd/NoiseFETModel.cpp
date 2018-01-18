#include "NoiseFETModel.h"

#include <iterator>
#include <algorithm>

NoiseFETModel::NoiseFETModel(QObject *parent)
    : QObject(parent),
      mAgilentU2542ARes(QString("USB0::2391::5912::TW54334510::INSTR")),
      mIsTransferCurveMode(true),
      mIsOutputCurveMode(false),
      mVoltageDeviation(0.2),
      mVoltageDeviationDisplay(0.2),
      mVoltageDeviationMultIndex(0),
      mNAvgFast(2),
      mNAvgSlow(100),
      mStabilizationTime(45.0),
      mLoadResistance(5000.0),
      mSampleSize(262144),
      mLowFreqSelector(64),
      mHighFreqSelector(64),
      mSamplingFrequency(262144),
      mNSpectraAvg(100),
      mKPreampl(178),
      mKAmpl(100),
      mTemperature0(297.0),
      mTemperatureE(297.0),
      mMeasureTimeTraces(true),
      mTimeTraceFrequency(262144),
      mDataFilePath(QString("")),
      mDataFileName(QString(""))
{
    mGateVoltages.push_back(0.0);
    mDrainVoltages.push_back(0.0);
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

    mGateVoltages.clear();
    mGateVoltages.resize(voltages.size());
    std::copy(voltages.begin(), voltages.end(), mGateVoltages.begin());

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

    mDrainVoltages.clear();
    mDrainVoltages.resize(voltages.size());
    std::copy(voltages.begin(), voltages.end(), mDrainVoltages.begin());

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

double NoiseFETModel::voltageDeviationDisplay()
{
    return mVoltageDeviationDisplay;
}

void NoiseFETModel::setVoltageDeviationDisplay(const double &deviation)
{
    if (deviation == mVoltageDeviationDisplay)
        return;

    mVoltageDeviationDisplay = deviation;
    emit voltageDeviationDisplayChanged();
}

int NoiseFETModel::voltageDeviationMultIndex()
{
    return mVoltageDeviationMultIndex;
}

void NoiseFETModel::setVoltageDeviationMultIndex(const int &newIndex)
{
    if (newIndex == mVoltageDeviationMultIndex)
        return;

    mVoltageDeviationMultIndex = newIndex;
    emit voltageDeviationMultIndexChanged();
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

int NoiseFETModel::sampleSize()
{
    return mSampleSize;
}

void NoiseFETModel::setSampleSize(const int &sSize)
{
    if (sSize == mSampleSize)
        return;

    mSampleSize = sSize;
    emit sampleSizeChanged();
}

int NoiseFETModel::lowFreqSelector()
{
    return mLowFreqSelector;
}

void NoiseFETModel::setLowFreqSelector(const int &selector)
{
    if (selector == mLowFreqSelector)
        return;

    mLowFreqSelector = selector;
    emit lowFreqSelectorChanged();
}

int NoiseFETModel::highFreqSelector()
{
    return mHighFreqSelector;
}

void NoiseFETModel::setHighFreqSelector(const int &selector)
{
    if (selector == mHighFreqSelector)
        return;

    mHighFreqSelector = selector;
    emit highFreqSelectorChanged();
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
