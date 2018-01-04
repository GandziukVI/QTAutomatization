#include "ExtBoxFilter.h"
#include "AgU25xxExtBoxException.h"

ExtBoxFilter::ExtBoxFilter()
    : mFilterFrequency(BoxEnumAInFilterCutOffFrequencies::Freq_150kHz),
      mFilterGain(BoxEnumAInFilterGains::gain1)
{
    mControlChannel = NULL;
}

ExtBoxFilter::ExtBoxFilter(AgU25xxDIGChannel &controlChannel)
    : mFilterFrequency(BoxEnumAInFilterCutOffFrequencies::Freq_150kHz),
      mFilterGain(BoxEnumAInFilterGains::gain1)
{
    mControlChannel = &controlChannel;
}

void ExtBoxFilter::setCutOffFreqAndGain(BoxEnumAInFilterCutOffFrequencies cutOffFreq, BoxEnumAInFilterGains gain)
{
    if(mControlChannel == NULL)
        throw AgU25xxExtBoxException(QString("Control channel is not specified."));

    if (cutOffFreq < BoxEnumAInFilterCutOffFrequencies::Freq_0kHz || cutOffFreq > BoxEnumAInFilterCutOffFrequencies::Freq_150kHz)
        throw AgU25xxExtBoxException(QString("Frequency is out of range."));
    if (gain < BoxEnumAInFilterGains::gain1 || gain > BoxEnumAInFilterGains::gain16)
        throw AgU25xxExtBoxException(QString("Gain is out of range."));

    mFilterFrequency = cutOffFreq;
    mFilterGain      = gain;

    unsigned short valForLatch = (unsigned short)cutOffFreq | (unsigned short)gain;

    mControlChannel->setByte(valForLatch);
}

BoxEnumAInFilterCutOffFrequencies ExtBoxFilter::getFilterFrequency() const
{
    return mFilterFrequency;
}

BoxEnumAInFilterGains ExtBoxFilter::getFilterGain() const
{
    return mFilterGain;
}
