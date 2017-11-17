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
    ~IAgU25xxSubsystemExtensions();

    unsigned int                   extGetAOChannel(AgU25xxEnumAOChannels channel) const;
    QVector<unsigned int>          extGetAOChannels(QVector<AgU25xxEnumAOChannels> channels) const;
    const char*                    extGetAOChannelPolarityStr(AgU25xxEnumAOChannelPolarities polarity) const;
    AgU25xxEnumAOChannelPolarities extGetAOChannelPolarityEnum(QString& polarityStr);
    const char*                    extGetAOChannelRefereceSource(AgU25xxEnumAOChannelRSouRCes rSource) const;
    unsigned int                   extGetDigChannel(AgU25xxEnumDigitalChannels channel) const;
    QVector<unsigned int>         extGetDigChannels(QVector<AgU25xxEnumDigitalChannels> channels) const;
    const char*                   extGetDigDirection(AgU25xxEnumDigitalDirection direction) const;
    const char*                   extGetTimeBaseSrcMode(AgU25xxEnumTimeSrcModes timeBaseMode) const;
    const char*                   extGetSSIMode(AgU25xxEnumSSIModes ssiMode) const;
    unsigned int                  extGetCounterChannel(AgU25xxEnumCounterChannels channel) const;
    QVector<unsigned int>         extGetCounterChannels(QVector<AgU25xxEnumCounterChannels> channels) const;
    unsigned int                  extGetOutputState(AgU25xxEnumOutputState outpState) const;
    const char*                   extGetInputTriggerSource(AgU25xxEnumTriggerSources triggerSource) const;
    const char*                   extGetOutputTriggerSource(AgU25xxEnumTriggerSources triggerSource) const;
    const char*                   extGetInputTriggerType(AgU25xxEnumTriggerTypes triggerType) const;
    const char*                   extGetOutputTriggerType(AgU25xxEnumTriggerTypes triggerType) const;
    const char*                   extGetInputATRiGgerSource(AgU25xxEnumATRiGgerSources triggerSource) const;
    const char*                   extGetOutputATRiGgerSource(AgU25xxEnumATRiGgerSources triggerSource) const;
    const char*                   extGetInputATRiGgerCondition(AgU25xxEnumATRiGgerConditions triggerCondition) const;
    const char*                   extGetOutputATRiGgerCondition(AgU25xxEnumATRiGgerConditions triggerCondition) const;
    const char*                   extGetInputDTRiGgerPolarity(AgU25xxEnumDTRiGgerPolarities triggerPolarity) const;
    const char*                   extGetOutputDTRiGgerPolarity(AgU25xxEnumDTRiGgerPolarities triggerPolarity) const;
    unsigned int                  extGetAIChannel(AgU25xxEnumAIChannels channel) const;
    QVector<unsigned int>         extGetAIChannels(QVector<AgU25xxEnumAIChannels> channels) const;
    const char*                   extGetAIChannelRangeStr(AgU25xxEnumAIChannelRanges range) const;
    AgU25xxEnumAIChannelRanges    extGetAIChannelRangeEnum(QString& rangeStr);
    const char*                   extGetAIChannelPolarityStr(AgU25xxEnumAIChannelPolaities polarity) const;
    AgU25xxEnumAIChannelPolaities extGetAIChannelPolarityEnum(QString& polarityStr);
    const char*                   extGetCOUNterFunc(AgU25xxEnumCounterFunctions function) const;
    const char*                   extGetCOUNterGateSource(AgU25xxEnumCounterGateSources counterGateSrc) const;
    const char*                   extGetCOUNterGatePolarity(AgU25xxEnumCounterGatePolarities counterPolarity) const;
    const char*                   extGetCOUNterGateState(AgU25xxEnumCounterGateStates counterControl) const;
    const char*                   extGetCOUNterClockSource(AgU25xxEnumCounterClockSources counterClockSrc) const;
    const char*                   extGetCOUNterClockPolarity(AgU25xxCounterEnumClockPolarities counterClkPolarity) const;
    const char*                   extGetCOUNterTotalizeCountingSrc(AgU25xxEnumCounterTotalizeCountingSrc counterTotalizeSrc) const;
    const char*                   extGetCOUNterTotalizeCountingDir(AgU25xxEnumCounterTotalizeCountingDir counterTotalizeDir) const;

    int                           extConvertResponseToIntValue(QString strResponse);
    double                        extConvertResponseToRealValue(QString strResponse);

private:
    bool                          areStringsEqual(const char* str1, QString& str2);
    QRegularExpression            *regExDouble;
};

#endif // IAGU25XXSUBSYSTEMEXTENSIONS_H
