#include "NoiseFETExperiment.h"

#include "../qmlBackEnd/NoiseFETModel.h"

#include "../ffft/def.h"
#include "../ffft/Array.h"
#include "../ffft/DynArray.h"
#include "../ffft/FFTReal.h"
#include "../ffft/OscSinCos.h"

NoiseFETExperiment::NoiseFETExperiment()
{

}

NoiseFETExperiment::NoiseFETExperiment(QObject *expSettings)
    : IExperiment(expSettings)
{
}

void NoiseFETExperiment::toDo(QObject *expSettings)
{
    ffft::FFTReal<double> fftEngine;

    QVector<QPointF> autoPSDLowFreq;
    QVector<QPointF> autoPSDHighFreq;


}
