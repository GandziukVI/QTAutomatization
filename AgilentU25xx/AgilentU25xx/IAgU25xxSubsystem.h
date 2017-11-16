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
    unsigned int          extGetAOChannel(AgU25xxOUTPut::AOChannels channel) const;
    QVector<unsigned int> extGetAOChannels(QVector<AgU25xxOUTPut::AOChannels> channels) const;
    unsigned int          extGetDigChannel(AgU25xxDIGital::DigitalChannels channel) const;
    QVector<unsigned int> extGetDigChannels(QVector<AgU25xxDIGital::DigitalChannels> channels) const;
    const char*           extGetDigDirection(AgU25xxDIGital::DigitalDirection direction) const;
    const char*           extGetTimeBaseSrcMode(AgU25xxTIMEbase::TimeSrcModes timeBaseMode) const;
    const char*           extGetSSIMode(SSIModes ssiMode) const;
    unsigned int          extGetVoltageChannel(AgU25xxVOLTage::VoltageChannels channel) const;
    QVector<unsigned int> extGetVoltageChannels(QVector<AgU25xxVOLTage::VoltageChannels> channels) const;
    unsigned int          extGetCounterChannel(AgU25xxCOUNter::CounterChannels channel) const;
    QVector<unsigned int> extGetCounterChannels(QVector<AgU25xxCOUNter::CounterChannels> channels) const;
    unsigned int          extGetOutputState(AgU25xxOUTPut::OutputState outpState) const;
    const char*           extGetOutputTriggerSource(AgU25xxOUTPut::TriggerSources triggerSource) const;
    const char*           extGetOutputTriggerType(AgU25xxOUTPut::TriggerTypes triggerType) const;
    const char*           extGetOutputATRiGgerSource(AgU25xxOUTPut::ATRiGgerSources triggerSource) const;
    const char*           extGetOutputATRiGgerCondition(AgU25xxOUTPut::ATRiGgerConditions triggerCondition) const;
    const char*           extGetOutputDTRiGgerPolarity(AgU25xxOUTPut::DTRiGgerPolarities triggerPolarity) const;
    unsigned int          extGetAnalogInChannel(AgU25xxROUTe::AnalogInChannels channel) const;
    QVector<unsigned int> extGetAnalogInChannels(QVector<AgU25xxROUTe::AnalogInChannels> channels) const;
    double                extGetAnalogInChannelRange(AgU25xxROUTe::AnalogInChannelRanges range) const;
    const char*           extGetAnalogInChannelPolarity(AgU25xxROUTe::AnalogInChannelPolaities polarity) const;
    const char*           extGetAnalogOutChannelRefereceSource(AgU25xxROUTe::AnalogOutChannelRSouRCes rSource) const;

private:
    QString commandString;
};

#endif // IAGU25XXSUBSYSTEM_H
