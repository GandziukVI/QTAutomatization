#ifndef AGU25XXROUTESUBSYS_H
#define AGU25XXROUTESUBSYS_H

#include "agilentu25xx_global.h"
#include "AgU25xxDefinitions.h"
#include "IAgU25xxSubsystem.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxROUTeSubSys : public IAg25xxSubsystem
{
public:
    AgU25xxROUTeSubSys();

    QString cmdSetAIChannelRange(AgU25xxROUTe::AnalogInChannelRanges range, AgU25xxROUTe::AnalogInChannels channel);
    QString cmdSetAIChannelRanges(AgU25xxROUTe::AnalogInChannelRanges range, QVector<AgU25xxROUTe::AnalogInChannels> channels);
    QString cmdGetAIChannelRange(AgU25xxROUTe::AnalogInChannels channel);
    QString cmdGetAIChannelRanges(QVector<AgU25xxROUTe::AnalogInChannels> channels);
    QString cmdSetAIChannelPolarity(AgU25xxROUTe::AnalogInChannelPolaities polarity, AgU25xxROUTe::AnalogInChannels channel);
    QString cmdSetAIChannelPolarities(AgU25xxROUTe::AnalogInChannelPolaities polarity, QVector<AgU25xxROUTe::AnalogInChannels> channels);
    QString cmdGetAIChannelPolarity(AgU25xxROUTe::AnalogInChannels channel);
    QString cmdGetAIChannelPolarities(QVector<AgU25xxROUTe::AnalogInChannels> channels);
    QString cmdSetAOChannelReferenceSource(AgU25xxROUTe::AnalogOutChannelRSouRCes rSource, AgU25xxOUTPut::AOChannels channel);
    QString cmdSetAOChannelsReferenceSource(AgU25xxROUTe::AnalogOutChannelRSouRCes rSource, QVector<AgU25xxOUTPut::AOChannels> channels);
    QString cmdGetAOChannelReferenceSource(AgU25xxOUTPut::AOChannels channel);
    QString cmdGetAOChannelsReferenceSource(QVector<AgU25xxOUTPut::AOChannels> channels);
    QString cmdSetAOChannelsReferenceVoltage(double voltage);
    QString cmdGetAOChannelsReferenceVoltage();
    QString cmdSetRouteEnabled(bool enabled, AgU25xxROUTe::AnalogInChannels channel);
    QString cmdSetRouteEnabled(bool enabled, QVector<AgU25xxROUTe::AnalogInChannels> channels);
    QString cmdSetRouteEnabled(bool enabled, AgU25xxOUTPut::AOChannels channel);
    QString cmdSetRouteEnabled(bool enabled, QVector<AgU25xxOUTPut::AOChannels> channels);
    QString cmdGetRouteEnabled(AgU25xxROUTe::AnalogInChannels channel);
    QString cmdGetRouteEnabled(QVector<AgU25xxROUTe::AnalogInChannels> channels);
    QString cmdGetRouteEnabled(AgU25xxOUTPut::AOChannels channel);
    QString cmdGetRouteEnabled(QVector<AgU25xxOUTPut::AOChannels> channels);

private:
    IAg25xxSubsystem CHANnelSubSys;
};

#endif // AGU25XXROUTESUBSYS_H
