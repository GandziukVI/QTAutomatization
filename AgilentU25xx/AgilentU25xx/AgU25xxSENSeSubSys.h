#ifndef AGU25XXSENSESUBSYS_H
#define AGU25XXSENSESUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxSENSeSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxSENSeSubSys();

    QString cmdSetVoltageRange(AgU25xxAIChannelRanges range, AgU25xxAIChannels channel);
    QString cmdSetVoltageRange(AgU25xxAIChannelRanges range, QVector<AgU25xxAIChannels> channels);
    QString cmdGetVoltageRange(AgU25xxAIChannels channel);
    QString cmdGetVoltageRange(QVector<AgU25xxAIChannels> channels);
    QString cmdSetVoltagePolarity(AgU25xxAIChannelPolaities polarity, AgU25xxAIChannels channel);
    QString cmdSetVoltagePolarity(AgU25xxAIChannelPolaities polarity, QVector<AgU25xxAIChannels> channels);
    QString cmdGetVoltagePolarity(AgU25xxAIChannels channel);
    QString cmdGetVoltagePolarity(QVector<AgU25xxAIChannels> channels);
    QString cmdSetVoltageAveraging(unsigned int avgNum);
    QString cmdGetVoltageAveraging();
    QString cmdSetCounterFunction(AgU25xxCounterFunctions function, AgU25xxCounterChannels channel);
    QString cmdSetCounterFunction(AgU25xxCounterFunctions function, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterFunction(AgU25xxCounterChannels channel);
    QString cmdGetCounterFunction(QVector<AgU25xxCounterChannels> channels);
    QString cmdCounterMeasAbort(AgU25xxCounterChannels channel);
    QString cmdCounterMeasAbort(QVector<AgU25xxCounterChannels> channels);
    QString cmdSetCounterGateSource(AgU25xxCounterGateSources counterSrc, AgU25xxCounterChannels channel);
    QString cmdSetCounterGateSources(AgU25xxCounterGateSources counterSrc, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterGateSource(AgU25xxCounterChannels channel);
    QString cmdGetCounterGateSources(QVector<AgU25xxCounterChannels> channels);
    QString cmdSetCounterGatePolarity(AgU25xxCounterGatePolarities gatePolarity, AgU25xxCounterChannels channel);
    QString cmdSetCounterGatePolarities(AgU25xxCounterGatePolarities gatePolarity, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterGatePolarity(AgU25xxCounterChannels channel);
    QString cmdGetCounterGatePolarities(QVector<AgU25xxCounterChannels> channels);
    QString cmdSetCounterGateEnabled(AgU25xxCounterGateStates gateState, AgU25xxCounterChannels channel);
    QString cmdSetCounterGateEnabled(AgU25xxCounterGateStates gateState, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterGateEnabled(AgU25xxCounterChannels channel);
    QString cmdGetCounterGateEnabled(QVector<AgU25xxCounterChannels> channels);
    QString cmdSetCounterClockSrc(AgU25xxCounterClockSources clkSrc, AgU25xxCounterChannels channel);
    QString cmdSetCounterClockSrc(AgU25xxCounterClockSources clkSrc, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterClockSrc(AgU25xxCounterChannels channel);
    QString cmdGetCounterClockSrc(QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterInternalClockFreq();
    QString cmdSetCounterExternalClockFreq(unsigned int clkFreq, AgU25xxCounterChannels channel);
    QString cmdSetCounterExternalClockFreq(unsigned int clkFreq, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterExternalClockFreq(AgU25xxCounterChannels channel);
    QString cmdGetCounterExternalClockFreq(QVector<AgU25xxCounterChannels> channels);
    QString cmdSetCounterClockPolarity(AgU25xxCounterClockPolarities clkPolarity, AgU25xxCounterChannels channel);
    QString cmdSetCounterClockPolarity(AgU25xxCounterClockPolarities clkPolarity, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterClockPolarity(AgU25xxCounterChannels channel);
    QString cmdGetCounterClockPolarity(QVector<AgU25xxCounterChannels> channels);
    QString cmdSetCounterTOTalizeInitVal(unsigned int initVal, AgU25xxCounterChannels channel);
    QString cmdSetCounterTOTalizeInitVal(unsigned int initVal, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterTOTalizeInitVal(AgU25xxCounterChannels channel);
    QString cmdGetCounterTOTalizeInitVal(QVector<AgU25xxCounterChannels> channels);
    QString cmdCounterTOTalizeInitiate(AgU25xxCounterChannels channel);
    QString cmdCounterTOTalizeInitiate(QVector<AgU25xxCounterChannels> channels);
    QString cmdCounterTOTalizeClear(AgU25xxCounterChannels channel);
    QString cmdCounterTOTalizeClear(QVector<AgU25xxCounterChannels> channels);
    QString cmdSetCounterTOTalizeCountingSrc(AgU25xxCounterTotalizeCountingSrc totSrc, AgU25xxCounterChannels channel);
    QString cmdSetCounterTOTalizeCountingSrc(AgU25xxCounterTotalizeCountingSrc totSrc, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterTOTalizeCountingSrc(AgU25xxCounterChannels channel);
    QString cmdGetCounterTOTalizeCountingSrc(QVector<AgU25xxCounterChannels> channels);
    QString cmdSetCounterTOTalizeCountingDir(AgU25xxCounterTotalizeCountingDir totDir, AgU25xxCounterChannels channel);
    QString cmdSetCounterTOTalizeCountingDir(AgU25xxCounterTotalizeCountingDir totDir, QVector<AgU25xxCounterChannels> channels);
    QString cmdGetCounterTOTalizeCountingDir(AgU25xxCounterChannels channel);
    QString cmdGetCounterTOTalizeCountingDir(QVector<AgU25xxCounterChannels> channels);

private:
    IAgU25xxSubsystem VOLTageSubsystem;
    IAgU25xxSubsystem COUNterSubsystem;
    IAgU25xxSubsystem COUNterGateSubsubsystem;
    IAgU25xxSubsystem COUNterClockSubsubsystem;
    IAgU25xxSubsystem COUNterTotalizeSubsubsystem;
    IAgU25xxSubsystem COUNterTotalizeUDOWnSubsubsystem;
};

#endif // AGU25XXSENSESUBSYS_H
