#ifndef NOISEFETEXPERIMENT_H
#define NOISEFETEXPERIMENT_H

#include "../IExperiment.h"

class NoiseFETExperiment : public IExperiment
{
public:
    NoiseFETExperiment();
    NoiseFETExperiment(QObject *expSettings);

    void toDo(QObject *expSettings);
};

#endif // NOISEFETEXPERIMENT_H
