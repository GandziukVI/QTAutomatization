#ifndef AGU25XXROUTESUBSYS_H
#define AGU25XXROUTESUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxROUTeSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxROUTeSubSys();

    QString cmdSetAIChannelRange(AgU25xxAIChannelRanges range, AgU25xxAIChannels channel);
    QString cmdSetAIChannelRanges(AgU25xxAIChannelRanges range, QVector<AgU25xxAIChannels> channels);
    QString cmdGetAIChannelRange(AgU25xxAIChannels channel);
    QString cmdGetAIChannelRanges(QVector<AgU25xxAIChannels> channels);
    QString cmdSetAIChannelPolarity(AgU25xxAIChannelPolaities polarity, AgU25xxAIChannels channel);
    QString cmdSetAIChannelPolarities(AgU25xxAIChannelPolaities polarity, QVector<AgU25xxAIChannels> channels);
    QString cmdGetAIChannelPolarity(AgU25xxAIChannels channel);
    QString cmdGetAIChannelPolarities(QVector<AgU25xxAIChannels> channels);
    QString cmdSetAOChannelReferenceSource(AgU25xxAOChannelRSouRCes rSource, AgU25xxAOChannels channel);
    QString cmdSetAOChannelsReferenceSource(AgU25xxAOChannelRSouRCes rSource, QVector<AgU25xxAOChannels> channels);
    QString cmdGetAOChannelReferenceSource(AgU25xxAOChannels channel);
    QString cmdGetAOChannelsReferenceSource(QVector<AgU25xxAOChannels> channels);
    QString cmdSetAOChannelsReferenceVoltage(double voltage);
    QString cmdGetAOChannelsReferenceVoltage();
    QString cmdSetRouteEnabled(bool enabled, AgU25xxAIChannels channel);
    QString cmdSetRouteEnabled(bool enabled, QVector<AgU25xxAIChannels> channels);
    QString cmdSetRouteEnabled(bool enabled, AgU25xxAOChannels channel);
    QString cmdSetRouteEnabled(bool enabled, QVector<AgU25xxAOChannels> channels);
    QString cmdGetRouteEnabled(AgU25xxAIChannels channel);
    QString cmdGetRouteEnabled(QVector<AgU25xxAIChannels> channels);
    QString cmdGetRouteEnabled(AgU25xxAOChannels channel);
    QString cmdGetRouteEnabled(QVector<AgU25xxAOChannels> channels);

private:
    IAgU25xxSubsystem CHANnelSubSys;
};

#endif // AGU25XXROUTESUBSYS_H
