#ifndef IAGU25XXSUBSYSTEM_H
#define IAGU25XXSUBSYSTEM_H

#include "agilentu25xx_global.h"
#include "AgU25xxDefinitions.h"

#include <QString>
#include <QTextStream>
#include <QVector>

#include <iterator>
#include <algorithm>

class AGILENTU25XXSHARED_EXPORT IAg25xxSubsystem {

public:
    IAg25xxSubsystem();
    IAg25xxSubsystem(const char* subSystemID);

    QString buildCommand(const char* command);
    QString buildCommand(const QString& command);

    char subsystemIdentifier[256];
    char subsystemSeparator;

    IAg25xxSubsystem getSubSubSystem(const char* subSubSystemID) const;

protected:
    void                  extCopyString(char* dest, const char* src) const;
    unsigned int          extGetAOChannel(AgU25xxAOChannels channel) const;
    QVector<unsigned int> extGetAOChannels(QVector<AgU25xxAOChannels> channels) const;
    unsigned int          extGetDigChannel(AgU25xxDigitalChannels channel) const;
    QVector<unsigned int> extGetDigChannels(QVector<AgU25xxDigitalChannels> channels) const;
    const char*           extGetDigDirection(AgU25xxDigitalDirection direction) const;
    const char*           extGetTimeBaseSrcMode(AgU25xxTimeSrcModes timeBaseMode) const;
    const char*           extGetSSIMode(SSIModes ssiMode) const;
    unsigned int          extGetVoltageChannel(AgU25xxVoltageChannels channel) const;
    QVector<unsigned int> extGetVoltageChannels(QVector<AgU25xxVoltageChannels> channels) const;
    unsigned int          extGetCounterChannel(AgU25xxCounterChannels channel) const;
    QVector<unsigned int> extGetCounterChannels(QVector<AgU25xxCounterChannels> channels) const;
    unsigned int          extGetOutputState(AgU25xxOutputState outpState) const;
    const char*           extGetOutputTriggerSource(AgU25xxTriggerSources triggerSource) const;
    const char*           extGetOutputTriggerType(AgU25xxTriggerTypes triggerType) const;
    const char*           extGetOutputATRiGgerSource(AgU25xxATRiGgerSources triggerSource) const;
    const char*           extGetOutputATRiGgerCondition(AgU25xxATRiGgerConditions triggerCondition) const;
    const char*           extGetOutputDTRiGgerPolarity(AgU25xxDTRiGgerPolarities triggerPolarity) const;
    unsigned int          extGetAnalogInChannel(AgU25xxAInChannels channel) const;
    QVector<unsigned int> extGetAnalogInChannels(QVector<AgU25xxAInChannels> channels) const;
    double                extGetAnalogInChannelRange(AgU25xxAInChannelRanges range) const;
    const char*           extGetAnalogInChannelPolarity(AgU25xxAInChannelPolaities polarity) const;
    const char*           extGetAnalogOutChannelRefereceSource(AgU25xxAOutChannelRSouRCes rSource) const;

private:
    QString commandString;
};

#endif // IAGU25XXSUBSYSTEM_H
