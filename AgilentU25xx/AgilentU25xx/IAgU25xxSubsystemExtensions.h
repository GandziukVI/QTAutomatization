#ifndef IAGU25XXSUBSYSTEMEXTENSIONS_H
#define IAGU25XXSUBSYSTEMEXTENSIONS_H

#include "agilentu25xx_global.h"
#include "AgU25xxDefinitions.h"

#include <QVector>
#include <iterator>
#include <algorithm>

class AGILENTU25XXSHARED_EXPORT IAgU25xxSubsystemExtensions
{
public:
    IAgU25xxSubsystemExtensions();

    unsigned int          extGetAOChannel(AgU25xxAOChannels channel) const;
    QVector<unsigned int> extGetAOChannels(QVector<AgU25xxAOChannels> channels) const;
    const char*           extGetAOChannelPolarity(AgU25xxAOChannelPolarities polarity) const;
    unsigned int          extGetDigChannel(AgU25xxDigitalChannels channel) const;
    QVector<unsigned int> extGetDigChannels(QVector<AgU25xxDigitalChannels> channels) const;
    const char*           extGetDigDirection(AgU25xxDigitalDirection direction) const;
    const char*           extGetTimeBaseSrcMode(AgU25xxTimeSrcModes timeBaseMode) const;
    const char*           extGetSSIMode(AgU25xxSSIModes ssiMode) const;
    unsigned int          extGetCounterChannel(AgU25xxCounterChannels channel) const;
    QVector<unsigned int> extGetCounterChannels(QVector<AgU25xxCounterChannels> channels) const;
    unsigned int          extGetOutputState(AgU25xxOutputState outpState) const;
    const char*           extGetOutputTriggerSource(AgU25xxTriggerSources triggerSource) const;
    const char*           extGetOutputTriggerType(AgU25xxTriggerTypes triggerType) const;
    const char*           extGetOutputATRiGgerSource(AgU25xxATRiGgerSources triggerSource) const;
    const char*           extGetOutputATRiGgerCondition(AgU25xxATRiGgerConditions triggerCondition) const;
    const char*           extGetOutputDTRiGgerPolarity(AgU25xxDTRiGgerPolarities triggerPolarity) const;
    unsigned int          extGetAIChannel(AgU25xxAIChannels channel) const;
    QVector<unsigned int> extGetAIChannels(QVector<AgU25xxAIChannels> channels) const;
    const char*           extGetAIChannelRange(AgU25xxAIChannelRanges range) const;
    const char*           extGetAIChannelPolarity(AgU25xxAIChannelPolaities polarity) const;
    const char*           extGetAOChannelRefereceSource(AgU25xxAOChannelRSouRCes rSource) const;
    const char*           extGetCOUNterFunc(AgU25xxCounterFunctions function) const;
    const char*           extGetCOUNterGateSource(AgU25xxCounterGateSources counterGateSrc) const;
    const char*           extGetCOUNterGatePolarity(AgU25xxCounterGatePolarities counterPolarity) const;
    const char*           extGetCOUNterGateState(AgU25xxCounterGateStates counterControl) const;
    const char*           extGetCOUNterClockSource(AgU25xxCounterClockSources counterClockSrc) const;
    const char*           extGetCOUNterClockPolarity(AgU25xxCounterClockPolarities counterClkPolarity) const;
    const char*           extGetCOUNterTotalizeCountingSrc(AgU25xxCounterTotalizeCountingSrc counterTotalizeSrc) const;
    const char*           extGetCOUNterTotalizeCountingDir(AgU25xxCounterTotalizeCountingDir counterTotalizeDir) const;
};

#endif // IAGU25XXSUBSYSTEMEXTENSIONS_H
