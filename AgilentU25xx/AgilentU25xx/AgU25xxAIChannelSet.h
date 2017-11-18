#ifndef AgU25xxEnumAIChannels_H
#define AgU25xxEnumAIChannels_H

#include "agilentu25xx_global.h"
#include "AgU25xxAIChannel.h"

#include "AgU25xxACQuireSubSys.h"
#include "AgU25xxWAVeformSubSys.h"
#include "AgU25xxRootCommands.h"
#include "IAgU25xxSubsystemExtensions.h"
#include "AgU25xxException.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxAIChannelSet : public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxAIChannelSet();
    AgU25xxAIChannelSet(IDeviceIO& driver);
    ~AgU25xxAIChannelSet();

    AgU25xxAIChannel **AIChannels;

    AgU25xxAIChannel &operator [] (const int index);
    AgU25xxAIChannel &operator [] (const AgU25xxEnumAIChannels channelID);

    void initialize(IDeviceIO& driver);

    void acquireSingleShot(int samplingFreq);
    void startContinuousAcquisition();
    void stopAcquisition();
    bool checkDataReady();
    void fetch(short int *data);
    void fetchScale();
    QVector<int> getNumEnabledChannels();

    void setPolarity(AgU25xxEnumAIChannelPolaities polarity);
    AgU25xxEnumAIChannelPolaities getPolarity();

    void setRange(AgU25xxEnumAIChannelRanges range);
    AgU25xxEnumAIChannelRanges getRange();

private:
    IDeviceIO             *mDriver;
    AgU25xxACQuireSubSys  mACQuireCommands;
    AgU25xxRootCommands   mRootCommands;
    AgU25xxWAVeformSubSys mWAVeformCommands;

    QString               readAgU25xxIEEEBlock();
    void                  resetAIDataBuffers();
};

#endif // AgU25xxEnumAIChannels_H
