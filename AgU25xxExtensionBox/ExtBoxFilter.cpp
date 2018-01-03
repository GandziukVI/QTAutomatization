#include "ExtBoxFilter.h"
#include "AgU25xxExtBoxException.h"

ExtBoxFilter::ExtBoxFilter()
    : mFilterFrequency(FilterCutOffFrequencies::Freq_150kHz),
      mFilterGain(FilterGains::gain1)
{
    mControlChannel = NULL;
}

ExtBoxFilter::ExtBoxFilter(AgU25xxDIGChannel &controlChannel)
    : mFilterFrequency(FilterCutOffFrequencies::Freq_150kHz),
      mFilterGain(FilterGains::gain1)
{
    mControlChannel = &controlChannel;
}

void ExtBoxFilter::setCutOffFreqAndGain(FilterCutOffFrequencies cutOffFreq, FilterGains gain)
{
    if(mControlChannel == NULL)
        throw AgU25xxExtBoxException(QString("Control channel is not specified."));

    if (cutOffFreq < FilterCutOffFrequencies::Freq_0kHz || cutOffFreq > FilterCutOffFrequencies::Freq_150kHz)
        throw AgU25xxExtBoxException(QString("Frequency is out of range."));
    if (gain < FilterGains::gain1 || gain > FilterGains::gain16)
        throw AgU25xxExtBoxException(QString("Gain is out of range."));

    mFilterFrequency = cutOffFreq;
    mFilterGain      = gain;

    unsigned short valForLatch = (unsigned short)cutOffFreq | (unsigned short)gain;

    mControlChannel->setByte(valForLatch);
}

FilterCutOffFrequencies ExtBoxFilter::getFilterFrequency() const
{
    return mFilterFrequency;
}

FilterGains ExtBoxFilter::getFilterGain() const
{
    return mFilterGain;
}
