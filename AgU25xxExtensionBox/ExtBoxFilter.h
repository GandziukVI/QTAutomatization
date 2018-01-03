#ifndef EXTBOXEFILTER_H
#define EXTBOXFILTER_H

#include "agu25xxextensionbox_global.h"
#include "AgU25xxExtBoxDefinitions.h"

#include <AgU25xxDIGChannel.h>

class AGU25XXEXTENSIONBOXSHARED_EXPORT ExtBoxFilter
{
public:
    ExtBoxFilter();
    ExtBoxFilter(AgU25xxDIGChannel &controlChannel);

    void                    setCutOffFreqAndGain(FilterCutOffFrequencies cutOffFreq, FilterGains gain);
    FilterCutOffFrequencies getFilterFrequency() const;
    FilterGains             getFilterGain() const;

private:
    AgU25xxDIGChannel       *mControlChannel;
    FilterCutOffFrequencies mFilterFrequency;
    FilterGains             mFilterGain;
};

#endif // EXTBOXFILTER_H
