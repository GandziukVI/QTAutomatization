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

    void                    setCutOffFreqAndGain(BoxEnumAInFilterCutOffFrequencies cutOffFreq, BoxEnumAInFilterGains gain);
    BoxEnumAInFilterCutOffFrequencies getFilterFrequency() const;
    BoxEnumAInFilterGains             getFilterGain() const;

private:
    AgU25xxDIGChannel       *mControlChannel;
    BoxEnumAInFilterCutOffFrequencies mFilterFrequency;
    BoxEnumAInFilterGains             mFilterGain;
};

#endif // EXTBOXFILTER_H
