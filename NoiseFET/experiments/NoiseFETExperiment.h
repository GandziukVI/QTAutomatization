#ifndef NOISEFETEXPERIMENT_H
#define NOISEFETEXPERIMENT_H

#include "../IExperiment.h"
#include "../qmlBackEnd/NoiseFETModel.h"

#include "../ffft/def.h"
#include "../ffft/Array.h"
#include "../ffft/DynArray.h"
#include "../ffft/FFTReal.h"
#include "../ffft/OscSinCos.h"

#include <AgilentU25xx.h>
#include <AgU25xxExtensionBox.h>

#include <QPointF>

class NoiseFETExperiment : public IExperiment
{
public:
    NoiseFETExperiment();
    NoiseFETExperiment(QObject *expSettings);
    ~NoiseFETExperiment();

    void toDo();
    void toDo(QObject *expSettings);

private:
        std::deque<QPointF> autoPSDLowFreq;
        std::deque<QPointF> autoPSDHighFreq;

        void measureNoiseSpectra();

        IDeviceIO             *mDriver;
        AgilentU25xx          *mInstrument;
        AgU25xxExtensionBox   *mBoxController;
        NoiseFETModel         *mExpModel;

        unsigned int          mAvgCounter;
        mutable QMutex        mAvgCounterMutex;
        unsigned int          getCurrentAvgCounter();
        void                  setCurrentAvgCounter(const unsigned int avgCounter);

        ffft::FFTReal<double> *fftEngineLowFreq;
        ffft::FFTReal<double> *fftEngineHighFreq;

        QVector<QPointF>      calcTwoPartsNoisePSD(double* timeTrace, int timeTraceLength, int samplingFrequency = 262144, double kAmpl = 1.0, double lowFreqStartFreq = 1.0, double cutOffLowFreq = 1600, double cutOffHighFreq = 102400, int filterOrder = 8, double filterFrequency = -1);
};

#endif // NOISEFETEXPERIMENT_H
