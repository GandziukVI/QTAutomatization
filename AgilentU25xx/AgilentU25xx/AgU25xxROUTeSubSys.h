#ifndef AGU25XXROUTESUBSYS_H
#define AGU25XXROUTESUBSYS_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxROUTeSubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxROUTeSubSys();

    QString cmdSetAIChannelRange(AgU25xxEnumAIChannelRanges range, AgU25xxEnumAIChannels channel);
    QString cmdSetAIChannelRanges(AgU25xxEnumAIChannelRanges range, QVector<AgU25xxEnumAIChannels> channels);
    QString cmdGetAIChannelRange(AgU25xxEnumAIChannels channel);
    QString cmdGetAIChannelRanges(QVector<AgU25xxEnumAIChannels> channels);
    QString cmdSetAIChannelPolarity(AgU25xxEnumAIChannelPolaities polarity, AgU25xxEnumAIChannels channel);
    QString cmdSetAIChannelPolarities(AgU25xxEnumAIChannelPolaities polarity, QVector<AgU25xxEnumAIChannels> channels);
    QString cmdGetAIChannelPolarity(AgU25xxEnumAIChannels channel);
    QString cmdGetAIChannelPolarities(QVector<AgU25xxEnumAIChannels> channels);
    QString cmdSetAOChannelReferenceSource(AgU25xxEnumAOChannelRSouRCes rSource, AgU25xxEnumAOChannels channel);
    QString cmdSetAOChannelsReferenceSource(AgU25xxEnumAOChannelRSouRCes rSource, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdGetAOChannelReferenceSource(AgU25xxEnumAOChannels channel);
    QString cmdGetAOChannelsReferenceSource(QVector<AgU25xxEnumAOChannels> channels);
    QString cmdSetAOChannelsReferenceVoltage(double voltage);
    QString cmdGetAOChannelsReferenceVoltage();
    QString cmdSetRouteEnabled(bool enabled, AgU25xxEnumAIChannels channel);
    QString cmdSetRouteEnabled(bool enabled, QVector<AgU25xxEnumAIChannels> channels);
    QString cmdSetRouteEnabled(bool enabled, AgU25xxEnumAOChannels channel);
    QString cmdSetRouteEnabled(bool enabled, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdGetRouteEnabled(AgU25xxEnumAIChannels channel);
    QString cmdGetRouteEnabled(QVector<AgU25xxEnumAIChannels> channels);
    QString cmdGetRouteEnabled(AgU25xxEnumAOChannels channel);
    QString cmdGetRouteEnabled(QVector<AgU25xxEnumAOChannels> channels);

private:
    IAgU25xxSubsystem CHANnelSubSys;
};

#endif // AGU25XXROUTESUBSYS_H
