#include "Filter.h"
#include "AgU25xxExtBoxException.h"

Filter::Filter()
    : mFilterFrequency(FilterCutOffFrequencies::Freq_150kHz),
      mFilterGain(FilterGains::gain1)
{
    mControlChannel = NULL;
}

Filter::Filter(AgU25xxDIGChannel &controlChannel)
    : mFilterFrequency(FilterCutOffFrequencies::Freq_150kHz),
      mFilterGain(FilterGains::gain1)
{
    mControlChannel = &controlChannel;
}

void Filter::setCutOffFreqAndGain(FilterCutOffFrequencies cutOffFreq, FilterGains gain)
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

FilterCutOffFrequencies Filter::getFilterFrequency() const
{
    return mFilterFrequency;
}

FilterGains Filter::getFilterGain() const
{
    return mFilterGain;
}
