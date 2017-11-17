#ifndef AGU25XXAICHANNEL_H
#define AGU25XXAICHANNEL_H

#include "agilentu25xx_global.h"

#include "AgU25xxACQuireSubSys.h"
#include "AgU25xxROUTeSubSys.h"

#include <IDeviceIO.h>

#include <QRegularExpression>

class AGILENTU25XXSHARED_EXPORT AgU25xxAIChannel : public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxAIChannel();
    AgU25xxAIChannel(AgU25xxEnumAIChannels channelName, IDeviceIO& driver);
    ~AgU25xxAIChannel();

    void                          setSamplingRate (const unsigned int samplingRate);
    void                          setEnabled      (const bool enabled);
    bool                          getEnabled      ();
    void                          setPolarity     (AgU25xxEnumAIChannelPolaities polarity);
    AgU25xxEnumAIChannelPolaities getPolarity     ();
    void                          setRange        (AgU25xxEnumAIChannelRanges range);
    AgU25xxEnumAIChannelRanges    getRange        ();

private:
    IDeviceIO*           mDriver;

    AgU25xxACQuireSubSys mACQuireSubsys;
    AgU25xxROUTeSubSys   mROUTeSubSys;

    AgU25xxEnumAIChannels mChannelID;

    QRegularExpression    *regExDouble;
};

#endif // AGU25XXAICHANNEL_H
