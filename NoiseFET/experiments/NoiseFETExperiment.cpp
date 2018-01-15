#include "NoiseFETExperiment.h"
#include "NoiseFETException.h"

#include "../ffft/def.h"
#include "../ffft/Array.h"
#include "../ffft/DynArray.h"
#include "../ffft/FFTReal.h"
#include "../ffft/OscSinCos.h"

#include <VisaDevice.h>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

NoiseFETExperiment::NoiseFETExperiment()
    : IExperiment(),
      mDriver(NULL),
      mInstrument(NULL),
      mBoxController(NULL)
{
}

NoiseFETExperiment::NoiseFETExperiment(QObject *expSettings)
    : IExperiment(expSettings)
{
    mExpModel = qobject_cast<NoiseFETModel*>(mExpSettings);

    mDriver      = new VisaDevice(mExpModel->agilentU2542ARes().toStdString().c_str());
    mInstrument = new AgilentU25xx(*mDriver);
    mBoxController        = new AgU25xxExtensionBox(*mInstrument);
}

NoiseFETExperiment::~NoiseFETExperiment()
{
    if (mBoxController != NULL) {
        delete mBoxController;
        mBoxController = NULL;
    }
    if (mInstrument != NULL) {
        delete mInstrument;
        mInstrument = NULL;
    }
    if (mDriver != NULL) {
        delete mDriver;
        mDriver = NULL;
    }
}

void NoiseFETExperiment::toDo()
{
    measureNoiseSpectra();
}

void NoiseFETExperiment::toDo(QObject *expSettings)
{
    mExpSettings = expSettings;
    measureNoiseSpectra();
}

void NoiseFETExperiment::measureNoiseSpectra()
{
    if (mExpModel->samplingFrequency() % 2 != 0)
        throw NoiseFETException(QString("Sampling frequency must be a power of two."));

    // Initializing FFT engine
    ffft::FFTReal<double> fftEngine (mExpModel->samplingFrequency());

    int          enabledChannelsLen      = mBoxController->AnalogInChannels->getEnabledCount();
    unsigned int *enabledChannelsIndexes = mBoxController->AnalogInChannels->getEnabledChannelsIndexes();

    for (int i = 0; i < enabledChannelsLen; ) {
        mBoxController->setAInChannelParams(static_cast<AgU25xxEnumAIChannels>(enabledChannelsIndexes[i]), BoxEnumAInFilterCutOffFrequencies::Freq_150kHz, BoxEnumAInFilterGains::gain1, BoxEnumAInPGAGains::gain1);
        ++i;
    }

    // Configuring box controller to start continuous data acquisition
    mBoxController->AnalogInChannels->setAcquisitionState(true);

    // Performing continuous data acquisition
    QFuture<void> acquisitionTask = QtConcurrent::run(mBoxController->AnalogInChannels, &AgU25xxAIChannelSet::startContinuousAcquisition, mExpModel->samplingFrequency(), mExpModel->samplingFrequency() / 8, 5);

    // Performing two parts fourier transform
    // of acquired data
    while (true) {
        if (getCurrentAvgCounter() >= mExpModel->nSpectraAvg()) {
            mBoxController->AnalogInChannels->setAcquisitionState(false);
            setCurrentAvgCounter(0);
            break;
        }
        if (acquisitionTask.isFinished() == true ||
                acquisitionTask.isCanceled() == true) {
            break;
        }

        // Reading time trace from active channel
        double *timeTrace = NULL;
        do {
            // To DO:
            // Work on ability to change index here
            timeTrace = mBoxController->AnalogInChannels->AIChannels[0]->getData();
        } while (timeTrace == NULL);

        /*---------------------------*/
        /* Calculating two parts FFT */
        /*---------------------------*/

    }

    acquisitionTask.waitForFinished();
}

unsigned int NoiseFETExperiment::getCurrentAvgCounter()
{
    QMutexLocker locker(&mAvgCounterMutex);
    return mAvgCounter;
}

void NoiseFETExperiment::setCurrentAvgCounter(const unsigned int avgCounter)
{
    QMutexLocker locker(&mAvgCounterMutex);
    mAvgCounter = avgCounter;
}

double *NoiseFETExperiment::calcTwoPartsNoisePSD(double *timeTrace, int timeTraceLength, int samplingFrequency, int nDataSamples, double kAmpl, double lowFreqStartFreq, double cutOffLowFreq, double cutOffHighFreq, int filterOrder, double filterFrequency)
{
    if (filterFrequency == -1)
        filterFrequency = cutOffLowFreq;

    double dtLowFreq = 0.0, dtHighFreq = 0.0;
    double dfLowFreq = 1.0, dfHighFreq = 0.0;
    double equivalentNoiseBandwidthLowFreq, equivalentNoiseBandwidthHighFreq;
    double coherentGainLowFreq, coherentGainHighFreq;

    // Adding possibility to perform FFT in subsets of original data
    // Subsetting original data on subsets of smaller size
//    int    timeTraceSelectionLength = samplingFrequency / nDataSamples;
//    double **timeTraceSelectionList = new double*[nDataSamples];
//    for (int i = 0; i != nDataSamples; ) {
//        timeTraceSelectionList[i] = new double[timeTraceSelectionLength];
//        std::copy(timeTrace[i * timeTraceSelectionLength], timeTrace[(i + 1) * timeTraceSelectionLength - 1], timeTraceSelectionList[i]);
//        ++i;
//    }

    // To DO:
    // Implement data filtering
    int    lowFreqSelectionDivider = 64;
    int    lowFreqSelectionLength  = samplingFrequency / lowFreqSelectionDivider;
    double *lowFreqSelectionList   = new double[lowFreqSelectionLength];
}
