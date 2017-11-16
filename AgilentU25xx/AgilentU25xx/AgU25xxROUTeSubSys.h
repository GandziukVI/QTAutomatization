#ifndef AGU25XXROUTESUBSYS_H
#define AGU25XXROUTESUBSYS_H

#include "agilentu25xx_global.h"
#include "AgU25xxDefinitions.h"
#include "IAgU25xxSubsystem.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxROUTeSubSys : public IAg25xxSubsystem
{
public:
    AgU25xxROUTeSubSys();

    QString cmdSetAIChannelRange(AgU25xxAInChannelRanges range, AgU25xxAInChannels channel);
    QString cmdSetAIChannelRanges(AgU25xxAInChannelRanges range, QVector<AgU25xxAInChannels> channels);
    QString cmdGetAIChannelRange(AgU25xxAInChannels channel);
    QString cmdGetAIChannelRanges(QVector<AgU25xxAInChannels> channels);
    QString cmdSetAIChannelPolarity(AgU25xxAInChannelPolaities polarity, AgU25xxAInChannels channel);
    QString cmdSetAIChannelPolarities(AgU25xxAInChannelPolaities polarity, QVector<AgU25xxAInChannels> channels);
    QString cmdGetAIChannelPolarity(AgU25xxAInChannels channel);
    QString cmdGetAIChannelPolarities(QVector<AgU25xxAInChannels> channels);
    QString cmdSetAOChannelReferenceSource(AgU25xxAOutChannelRSouRCes rSource, AgU25xxAOChannels channel);
    QString cmdSetAOChannelsReferenceSource(AgU25xxAOutChannelRSouRCes rSource, QVector<AgU25xxAOChannels> channels);
    QString cmdGetAOChannelReferenceSource(AgU25xxAOChannels channel);
    QString cmdGetAOChannelsReferenceSource(QVector<AgU25xxAOChannels> channels);
    QString cmdSetAOChannelsReferenceVoltage(double voltage);
    QString cmdGetAOChannelsReferenceVoltage();
    QString cmdSetRouteEnabled(bool enabled, AgU25xxAInChannels channel);
    QString cmdSetRouteEnabled(bool enabled, QVector<AgU25xxAInChannels> channels);
    QString cmdSetRouteEnabled(bool enabled, AgU25xxAOChannels channel);
    QString cmdSetRouteEnabled(bool enabled, QVector<AgU25xxAOChannels> channels);
    QString cmdGetRouteEnabled(AgU25xxAInChannels channel);
    QString cmdGetRouteEnabled(QVector<AgU25xxAInChannels> channels);
    QString cmdGetRouteEnabled(AgU25xxAOChannels channel);
    QString cmdGetRouteEnabled(QVector<AgU25xxAOChannels> channels);

private:
    IAg25xxSubsystem CHANnelSubSys;
};

#endif // AGU25XXROUTESUBSYS_H
