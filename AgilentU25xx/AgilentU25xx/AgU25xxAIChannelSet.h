#ifndef AgU25xxEnumAIChannels_H
#define AgU25xxEnumAIChannels_H

#include "agilentu25xx_global.h"
#include "AgU25xxAIChannel.h"

#include "AgU25xxACQuireSubSys.h"
#include "AgU25xxWAVeformSubSys.h"
#include "AgU25xxRootCommands.h"
#include "IAgU25xxSubsystemExtensions.h"
#include "AgU25xxException.h"

#include <QMutex>

class AGILENTU25XXSHARED_EXPORT AgU25xxAIChannelSet : public IAgU25xxSubsystemExtensions
{
    typedef double (AgU25xxAIChannelSet::*convFunc)(short&, double&);

public:
    AgU25xxAIChannelSet();
    AgU25xxAIChannelSet(IDeviceIO& driver);
    ~AgU25xxAIChannelSet();

    AgU25xxAIChannel **AIChannels;

    AgU25xxAIChannel &operator [] (const int index);
    AgU25xxAIChannel &operator [] (const AgU25xxEnumAIChannels channelID);

    void initialize(IDeviceIO& driver);

    void acquireSingleShot(int samplingFreq);
    void startContinuousAcquisition(unsigned int samplingFreq, unsigned int outputPoints);
    void stopAcquisition();
    bool checkDataReady();
    QVector<int> getNumEnabledChannels();
    int  getSamplingRate();

    void setPolarity(AgU25xxEnumAIChannelPolaities polarity);
    AgU25xxEnumAIChannelPolaities getPolarity();

    void setRange(AgU25xxEnumAIChannelRanges range);
    AgU25xxEnumAIChannelRanges getRange();

    void setAcquisitionState(const bool &state);
    bool getAcquisitionState();

private:
    IDeviceIO             *mDriver;
    AgU25xxACQuireSubSys  mACQuireCommands;
    AgU25xxRootCommands   mRootCommands;
    AgU25xxWAVeformSubSys mWAVeformCommands;

    int                   mAIChannelsSamplingFreq;
    int                   mAIChannelsEnabledCount;

    void                  resetAIDataBuffers();

    convFunc              *converterFunctions;

    double                getAIChannelScaleFunctionBipolar(short &val, double &range);
    double                getAIChannelScaleFunctionUnipolar(short &val, double &range);

    mutable QMutex mAcqInProgressMutex;
    bool           mAcquisitionIsInProgress;
};

#endif // AgU25xxEnumAIChannels_H
