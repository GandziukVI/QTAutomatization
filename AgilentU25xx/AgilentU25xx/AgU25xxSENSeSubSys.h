#ifndef AGU25XXSENSESUBSYS_H
#define AGU25XXSENSESUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxSENSeSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxSENSeSubSys();

    QString cmdSetVoltageRange(AgU25xxEnumAIChannelRanges range, AgU25xxEnumAIChannels channel);
    QString cmdSetVoltageRange(AgU25xxEnumAIChannelRanges range, QVector<AgU25xxEnumAIChannels> channels);
    QString cmdGetVoltageRange(AgU25xxEnumAIChannels channel);
    QString cmdGetVoltageRange(QVector<AgU25xxEnumAIChannels> channels);
    QString cmdSetVoltagePolarity(AgU25xxEnumAIChannelPolaities polarity, AgU25xxEnumAIChannels channel);
    QString cmdSetVoltagePolarity(AgU25xxEnumAIChannelPolaities polarity, QVector<AgU25xxEnumAIChannels> channels);
    QString cmdGetVoltagePolarity(AgU25xxEnumAIChannels channel);
    QString cmdGetVoltagePolarity(QVector<AgU25xxEnumAIChannels> channels);
    QString cmdSetVoltageAveraging(unsigned int avgNum);
    QString cmdGetVoltageAveraging();
    QString cmdSetCounterFunction(AgU25xxEnumCounterFunctions function, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterFunction(AgU25xxEnumCounterFunctions function, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterFunction(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterFunction(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdCounterMeasAbort(AgU25xxEnumCounterChannels channel);
    QString cmdCounterMeasAbort(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdSetCounterGateSource(AgU25xxEnumCounterGateSources counterSrc, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterGateSources(AgU25xxEnumCounterGateSources counterSrc, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterGateSource(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterGateSources(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdSetCounterGatePolarity(AgU25xxEnumCounterGatePolarities gatePolarity, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterGatePolarities(AgU25xxEnumCounterGatePolarities gatePolarity, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterGatePolarity(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterGatePolarities(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdSetCounterGateEnabled(AgU25xxEnumCounterGateStates gateState, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterGateEnabled(AgU25xxEnumCounterGateStates gateState, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterGateEnabled(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterGateEnabled(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdSetCounterClockSrc(AgU25xxEnumCounterClockSources clkSrc, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterClockSrc(AgU25xxEnumCounterClockSources clkSrc, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterClockSrc(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterClockSrc(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterInternalClockFreq();
    QString cmdSetCounterExternalClockFreq(unsigned int clkFreq, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterExternalClockFreq(unsigned int clkFreq, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterExternalClockFreq(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterExternalClockFreq(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdSetCounterClockPolarity(AgU25xxCounterEnumClockPolarities clkPolarity, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterClockPolarity(AgU25xxCounterEnumClockPolarities clkPolarity, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterClockPolarity(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterClockPolarity(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdSetCounterTOTalizeInitVal(unsigned int initVal, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterTOTalizeInitVal(unsigned int initVal, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterTOTalizeInitVal(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterTOTalizeInitVal(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdCounterTOTalizeInitiate(AgU25xxEnumCounterChannels channel);
    QString cmdCounterTOTalizeInitiate(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdCounterTOTalizeClear(AgU25xxEnumCounterChannels channel);
    QString cmdCounterTOTalizeClear(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdSetCounterTOTalizeCountingSrc(AgU25xxEnumCounterTotalizeCountingSrc totSrc, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterTOTalizeCountingSrc(AgU25xxEnumCounterTotalizeCountingSrc totSrc, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterTOTalizeCountingSrc(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterTOTalizeCountingSrc(QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdSetCounterTOTalizeCountingDir(AgU25xxEnumCounterTotalizeCountingDir totDir, AgU25xxEnumCounterChannels channel);
    QString cmdSetCounterTOTalizeCountingDir(AgU25xxEnumCounterTotalizeCountingDir totDir, QVector<AgU25xxEnumCounterChannels> channels);
    QString cmdGetCounterTOTalizeCountingDir(AgU25xxEnumCounterChannels channel);
    QString cmdGetCounterTOTalizeCountingDir(QVector<AgU25xxEnumCounterChannels> channels);

private:
    IAgU25xxSubsystem VOLTageSubsystem;
    IAgU25xxSubsystem COUNterSubsystem;
    IAgU25xxSubsystem COUNterGateSubsubsystem;
    IAgU25xxSubsystem COUNterClockSubsubsystem;
    IAgU25xxSubsystem COUNterTotalizeSubsubsystem;
    IAgU25xxSubsystem COUNterTotalizeUDOWnSubsubsystem;
};

#endif // AGU25XXSENSESUBSYS_H
