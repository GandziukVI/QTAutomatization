#ifndef NOISEFETMODEL_H
#define NOISEFETMODEL_H

#include <QObject>
#include <QString>
#include <QVector>

class NoiseFETModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString agilentU2542ARes READ agilentU2542ARes WRITE setAgilentU2542ARes NOTIFY agilentU2542AResChanged)
    Q_PROPERTY(bool isTransferCurveMode READ isTransferCurveMode WRITE setIsTransferCurveMode NOTIFY isTransferCurveModeChanged)
    Q_PROPERTY(bool isOutputCurveMode READ isOutputCurveMode WRITE setIsOutputCurveMode NOTIFY isOutputCurveModeChanged)
    Q_PROPERTY(QVector<qreal> gateVoltages READ gateVoltages WRITE setGateVoltages NOTIFY gateVoltagesChanged)
    Q_PROPERTY(QVector<qreal> drainVoltages READ drainVoltages WRITE setDrainVoltages NOTIFY drainVoltagesChanged)
    Q_PROPERTY(double voltageDeviation READ voltageDeviation WRITE setVoltageDeviation NOTIFY voltageDeviationChanged)
    Q_PROPERTY(double voltageDeviationDisplay READ voltageDeviationDisplay WRITE setVoltageDeviationDisplay NOTIFY voltageDeviationDisplayChanged)
    Q_PROPERTY(int voltageDeviationMultIndex READ voltageDeviationMultIndex WRITE setVoltageDeviationMultIndex NOTIFY voltageDeviationMultIndexChanged)
    Q_PROPERTY(int nAvgFast READ nAvgFast WRITE setNAvgFast NOTIFY nAvgFastChanged)
    Q_PROPERTY(int nAvgSlow READ nAvgSlow WRITE setNAvgSlow NOTIFY nAvgSlowChanged)
    Q_PROPERTY(double stabilizationTime READ stabilizationTime WRITE setStabilizationTime NOTIFY stabilizationTimeChanged)
    Q_PROPERTY(double loadResistance READ loadResistance WRITE setLoadResistance NOTIFY loadResistanceChanged)
    Q_PROPERTY(int sampleSize READ sampleSize WRITE setSampleSize NOTIFY sampleSizeChanged)
    Q_PROPERTY(int lowFreqSelector READ lowFreqSelector WRITE setLowFreqSelector NOTIFY lowFreqSelectorChanged)
    Q_PROPERTY(int highFreqSelector READ highFreqSelector WRITE setHighFreqSelector NOTIFY highFreqSelectorChanged)
    Q_PROPERTY(int samplingFrequency READ samplingFrequency WRITE setSamplingFrequency NOTIFY samplingFrequencyChanged)
    Q_PROPERTY(int nSpectraAvg READ nSpectraAvg WRITE setNSpectraAvg NOTIFY nSpectraAvgChanged)
    Q_PROPERTY(double kPreampl READ kPreampl WRITE setKPreampl NOTIFY kPreamplChanged)
    Q_PROPERTY(double kAmpl READ kAmpl WRITE setKAmpl NOTIFY kAmplChanged)
    Q_PROPERTY(double temperature0 READ temperature0 WRITE setTemperature0 NOTIFY temperature0Changed)
    Q_PROPERTY(double temperatureE READ temperatureE WRITE setTemperatureE NOTIFY temperatureEChanged)
    Q_PROPERTY(bool measureTimeTraces READ measureTimeTraces WRITE setMeasureTimeTraces NOTIFY measureTimeTracesChanged)
    Q_PROPERTY(int timeTraceFrequency READ timeTraceFrequency WRITE setTimeTraceFrequency NOTIFY timeTraceFrequencyChanged)
    Q_PROPERTY(QString dataFilePath READ dataFilePath WRITE setDataFilePath NOTIFY dataFilePathChanged)
    Q_PROPERTY(QString dataFileName READ dataFileName WRITE setDataFileName NOTIFY dataFileNameChanged)
public:
    explicit NoiseFETModel(QObject *parent = nullptr);

    QString agilentU2542ARes();
    void setAgilentU2542ARes(const QString &resName);

    bool isTransferCurveMode();
    void setIsTransferCurveMode(const bool &mode);

    bool isOutputCurveMode();
    void setIsOutputCurveMode(const bool &mode);

    QVector<qreal> gateVoltages();
    void setGateVoltages(const QVector<qreal> &voltages);

    QVector<qreal> drainVoltages();
    void setDrainVoltages(const QVector<qreal> &voltages);

    double voltageDeviation();
    void setVoltageDeviation(const double &deviation);

    double voltageDeviationDisplay();
    void setVoltageDeviationDisplay(const double &deviation);

    int voltageDeviationMultIndex();
    void setVoltageDeviationMultIndex(const int &newIndex);

    int nAvgFast();
    void setNAvgFast(const int &nAvg);

    int nAvgSlow();
    void setNAvgSlow(const int &nAvg);

    double stabilizationTime();
    void setStabilizationTime(const double &stabTime);

    double loadResistance();
    void setLoadResistance(const double &resistance);

    int sampleSize();
    void setSampleSize(const int &sSize);

    int lowFreqSelector();
    void setLowFreqSelector(const int &selector);

    int highFreqSelector();
    void setHighFreqSelector(const int &selector);

    int samplingFrequency();
    void setSamplingFrequency(const int &frequency);

    int nSpectraAvg();
    void setNSpectraAvg(const int &nAvg);

    double kPreampl();
    void setKPreampl(const double &amplKoef);

    double kAmpl();
    void setKAmpl(const double &amplKoef);

    double temperature0();
    void setTemperature0(const double &temperature);

    double temperatureE();
    void setTemperatureE(const double &temperature);

    bool measureTimeTraces();
    void setMeasureTimeTraces(const bool &state);

    int timeTraceFrequency();
    void setTimeTraceFrequency(const int &frequency);

    QString dataFilePath();
    void setDataFilePath(const QString &path);

    QString dataFileName();
    void setDataFileName(const QString &fileName);

signals:
    void agilentU2542AResChanged();
    void isTransferCurveModeChanged();
    void isOutputCurveModeChanged();
    void gateVoltagesChanged();
    void drainVoltagesChanged();
    void voltageDeviationChanged();
    void voltageDeviationDisplayChanged();
    void voltageDeviationMultIndexChanged();
    void nAvgFastChanged();
    void nAvgSlowChanged();
    void stabilizationTimeChanged();
    void loadResistanceChanged();
    void sampleSizeChanged();
    void lowFreqSelectorChanged();
    void highFreqSelectorChanged();
    void samplingFrequencyChanged();
    void nSpectraAvgChanged();
    void kPreamplChanged();
    void kAmplChanged();
    void temperature0Changed();
    void temperatureEChanged();
    void measureTimeTracesChanged();
    void timeTraceFrequencyChanged();
    void dataFilePathChanged();
    void dataFileNameChanged();

//public slots:

private:
    QString mAgilentU2542ARes;

    bool mIsTransferCurveMode;
    bool mIsOutputCurveMode;

    QVector<qreal> mGateVoltages;
    QVector<qreal> mDrainVoltages;

    double mVoltageDeviation;
    double mVoltageDeviationDisplay;
    int mVoltageDeviationMultIndex;

    int mNAvgFast;
    int mNAvgSlow;

    double mStabilizationTime;
    double mLoadResistance;

    int mSampleSize;
    int mLowFreqSelector;
    int mHighFreqSelector;
    int mSamplingFrequency;
    int mNSpectraAvg;

    double mKPreampl;
    double mKAmpl;

    double mTemperature0;
    double mTemperatureE;

    bool mMeasureTimeTraces;

    int mTimeTraceFrequency;

    QString mDataFilePath;
    QString mDataFileName;
};

#endif // NOISEFETMODEL_H
