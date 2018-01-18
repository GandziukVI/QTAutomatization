#include "NoiseFETExperiment.h"
#include "NoiseFETException.h"

#include <VisaDevice.h>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

NoiseFETExperiment::NoiseFETExperiment()
    : IExperiment(),
      mDriver(NULL),
      mInstrument(NULL),
      mBoxController(NULL),
      fftEngineLowFreq(NULL),
      fftEngineHighFreq(NULL)
{
}

NoiseFETExperiment::NoiseFETExperiment(QObject *expSettings)
    : IExperiment(expSettings)
{
    mExpModel = qobject_cast<NoiseFETModel*>(mExpSettings);

    mDriver      = new VisaDevice(mExpModel->agilentU2542ARes().toStdString().c_str());
    mInstrument = new AgilentU25xx(*mDriver);
    mBoxController        = new AgU25xxExtensionBox(*mInstrument);

    // Initializing parameters for FFT transform
    int lowFreqFFTLen = mExpModel->sampleSize() /* / nDataSamples */ / mExpModel->lowFreqSelector() / 2;
    int highFreqFFTLen = mExpModel->sampleSize() /* / nDataSamples */ / mExpModel->highFreqSelector() / 2;

    fftEngineLowFreq  = new ffft::FFTReal<double>(lowFreqFFTLen);
    fftEngineHighFreq = new ffft::FFTReal<double>(highFreqFFTLen);
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
    if (fftEngineLowFreq != NULL) {
        delete fftEngineLowFreq;
        fftEngineLowFreq = NULL;
    }
    if (fftEngineHighFreq != NULL) {
        delete fftEngineHighFreq;
        fftEngineHighFreq = NULL;
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

QVector<QPointF> NoiseFETExperiment::calcTwoPartsNoisePSD(double *timeTrace, int timeTraceLength, int samplingFrequency, double kAmpl, double lowFreqStartFreq, double cutOffLowFreq, double cutOffHighFreq, int filterOrder, double filterFrequency)
{
    if (filterFrequency == -1)
        filterFrequency = cutOffLowFreq;

    double complexRealPart;
    double complexImagPart;

    double dtLowFreq = 0.0,  dfLowFreq = 0.0;
    double dtHighFreq = 0.0, dfHighFreq = 0.0;

    // Adding possibility to perform FFT in subsets of original data
    // Subsetting original data on subsets of smaller size

    double resizeFactor       = (double)timeTraceLength / (double)samplingFrequency;
    bool   resizeLowerOrExact = resizeFactor <= 1.0;
    int    nDataSamples       = resizeLowerOrExact? timeTraceLength / samplingFrequency: 1;

    int    timeTraceSelectionLength = resizeLowerOrExact? samplingFrequency / nDataSamples : timeTraceLength;
    double **timeTraceSelectionList = new double*[nDataSamples];
    for (int i = 0; i != nDataSamples; ) {
        timeTraceSelectionList[i] = new double[timeTraceSelectionLength];
        std::copy(&timeTrace[i * timeTraceSelectionLength], &timeTrace[(i + 1) * timeTraceSelectionLength - 1], timeTraceSelectionList[i]);
        ++i;
    }

    /*-----------------------------------*/
    /* Calculating FFT in each subsample */
    /*-----------------------------------*/

    for (int i = 0; i != nDataSamples;) {
        // Low-freq FFT part

        // To DO:
        // Implement data filtering
        int    lowFreqSelectionDivider = 64;
        int    lowFreqSelectionLength  = timeTraceSelectionLength / lowFreqSelectionDivider;
        double *lowFreqSelectionList   = new double[lowFreqSelectionLength];

        int counter = 0;
        for (int j = 0; j != timeTraceSelectionLength; ) {
            if (j % lowFreqSelectionDivider == 0) {
                lowFreqSelectionList[counter] = timeTraceSelectionList[i][j];
                ++counter;
            }
            ++j;
        }

        int singlePSDLowFreqLength = lowFreqSelectionLength / 2;

        dtLowFreq = (double)lowFreqSelectionDivider / (double)samplingFrequency;
        dfLowFreq = (double)samplingFrequency / 2.0 / (double)(singlePSDLowFreqLength * lowFreqSelectionDivider);

        double *singleFFTLowFreq = new double[lowFreqSelectionLength];
        fftEngineLowFreq->do_fft(singleFFTLowFreq, lowFreqSelectionList);

        double *singlePSDLowFreq = new double[singlePSDLowFreqLength];

        for (int j = 0; j != singlePSDLowFreqLength; ) {
            complexRealPart = singleFFTLowFreq[j];
            complexImagPart = singleFFTLowFreq[j + singlePSDLowFreqLength];

            singlePSDLowFreq[j] = (complexRealPart * complexRealPart + complexImagPart * complexImagPart) / (lowFreqSelectionLength * lowFreqSelectionLength);

            ++j;
        }

        // Cleaning memory after low-freq FFT calculation

        delete[] singleFFTLowFreq;     singleFFTLowFreq     = NULL;
        delete[] lowFreqSelectionList; lowFreqSelectionList = NULL;

        // Calculating high-frequency FFT part
        int highFreqPeriod = 64;
        int highFreqSelectionLength = timeTraceSelectionLength / highFreqPeriod;
        int singlePSDHighFreqLength = highFreqSelectionLength / 2;

        dtHighFreq = 1.0 /  (double)samplingFrequency;
        dfHighFreq = (double)samplingFrequency / 2.0 / (double)singlePSDHighFreqLength;

        double **highFreqSelectionList = new double*[highFreqPeriod];
        for (int j = 0; j != highFreqPeriod; ) {
            highFreqSelectionList[j] = new double[highFreqSelectionLength];
            std::copy(&timeTraceSelectionList[i][j * highFreqSelectionLength], &timeTraceSelectionList[i][(j + 1) * highFreqSelectionLength - 1], highFreqSelectionList[j]);
            ++j;
        }

        double *cumulativeNoisePSDHighFreq = NULL;
        for (int j = 0; j != highFreqPeriod; ) {
            double *singleFFTHighFreq = new double[highFreqSelectionLength];
            fftEngineHighFreq->do_fft(singleFFTHighFreq, highFreqSelectionList[j]);

            double *singlePSDHighFreq = new double[singlePSDHighFreqLength];

            for (int k = 0; k != singlePSDHighFreqLength; ) {
                complexRealPart = singleFFTHighFreq[k];
                complexImagPart = singleFFTHighFreq[k + singlePSDHighFreqLength];

                singlePSDHighFreq[k] = (complexRealPart * complexRealPart + complexImagPart * complexImagPart) / (highFreqSelectionLength * highFreqSelectionLength);

                ++k;
            }

            if (cumulativeNoisePSDHighFreq == NULL) {
                cumulativeNoisePSDHighFreq = new double[singlePSDHighFreqLength];
                for (int k = 0; k != singlePSDHighFreqLength; ) {
                    cumulativeNoisePSDHighFreq[k] = 0.0;
                    ++k;
                }
            }

            for (int k = 0; k != singlePSDHighFreqLength; ) {
                cumulativeNoisePSDHighFreq[k] += singlePSDHighFreq[k];
                ++k;
            }

            delete[] singleFFTHighFreq; singleFFTHighFreq = NULL;
            delete[] singlePSDHighFreq; singlePSDHighFreq = NULL;

            ++j;
        }

        // Cleaning memory after high-freq FFT calculation
        for (int j = 0; j != highFreqPeriod; ) {
            delete[] highFreqSelectionList[j];
            highFreqSelectionList[j] = NULL;
            ++j;
        }
        delete[] highFreqSelectionList;
        highFreqSelectionList = NULL;

        // Final LOW-FREQ part of spectrum
        double freqVal;
        for (int j = 0; j != singlePSDLowFreqLength; ) {
            freqVal = dfLowFreq * (double)j;
            if ((freqVal >= lowFreqStartFreq) && (freqVal <= cutOffLowFreq))
                autoPSDLowFreq[i] = QPointF(freqVal, singlePSDLowFreq[j] / (kAmpl * kAmpl));
            else if (freqVal > cutOffLowFreq)
                break;

            ++j;
        }
        // Cleaning memory with low-freq noise PSD part
        delete[] singlePSDLowFreq;

        // Final HIGH-FREQ part of spectrum
        for (int j = 0; j != singlePSDHighFreqLength; ) {
            freqVal = dfHighFreq * (double)j;
            if ((freqVal > cutOffLowFreq) && (freqVal <= cutOffHighFreq))
                autoPSDHighFreq[i] = QPointF(freqVal, cumulativeNoisePSDHighFreq[j] / ((double)(highFreqPeriod * highFreqPeriod)) / (kAmpl * kAmpl));
            else if (freqVal > cutOffHighFreq)
                break;

            ++j;
        }
        // Cleaning memory with high-freq noise PSD part
        delete[] cumulativeNoisePSDHighFreq;

        ++i;
    }

    QVector<QPointF> finalSpectrum(autoPSDLowFreq.size() + autoPSDHighFreq.size());

    std::copy(autoPSDLowFreq.cbegin(), autoPSDLowFreq.cend(), finalSpectrum.begin());
    std::copy(autoPSDHighFreq.cbegin(), autoPSDHighFreq.cend(), finalSpectrum.begin() + autoPSDLowFreq.size());

    return finalSpectrum;
}
