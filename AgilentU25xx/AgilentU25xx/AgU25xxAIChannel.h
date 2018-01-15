#ifndef AGU25XXAICHANNEL_H
#define AGU25XXAICHANNEL_H

#include "agilentu25xx_global.h"

#include "AgU25xxACQuireSubSys.h"
#include "AgU25xxROUTeSubSys.h"

#include <IDeviceIO.h>

#include <QMutex>
#include <deque>

class AGILENTU25XXSHARED_EXPORT AgU25xxAIChannel : public IAgU25xxSubsystemExtensions
{    
    typedef double (AgU25xxAIChannel::*scaleValFunc)(const short&) const;
public:
    AgU25xxAIChannel();
    AgU25xxAIChannel(AgU25xxEnumAIChannels channelName, IDeviceIO& driver);
    ~AgU25xxAIChannel();

    void                          setSamplingRate (const unsigned int samplingRate);
    void                          setEnabled      (const bool enabled);
    bool                          queryEnabled    ();
    bool                          isEnabled       ();
    void                          setPolarity     (AgU25xxEnumAIChannelPolaities polarity);
    AgU25xxEnumAIChannelPolaities queryPolarity   ();
    AgU25xxEnumAIChannelPolaities getPolarity     ();
    void                          setRange        (AgU25xxEnumAIChannelRanges range);
    AgU25xxEnumAIChannelRanges    queryRange      ();
    AgU25xxEnumAIChannelRanges    getRange        ();
    double                        *ACQuisitionData;
    scaleValFunc                  scaleTransformFunc;

    void                          appendData(double* data, unsigned int maxCount = 5);
    double*                       getData();
    void                          resetChannelData();

private:
    IDeviceIO*           mDriver;

    AgU25xxACQuireSubSys mACQuireSubsys;
    AgU25xxROUTeSubSys   mROUTeSubSys;

    AgU25xxEnumAIChannels mChannelID;

    AgU25xxEnumAIChannelPolaities mChPolarity;
    AgU25xxEnumAIChannelRanges    mChRange;
    double                        mChRangeValue;
    bool                          mIsEnabled;

    double                        getScaleValueBipolar (const short &val) const;
    double                        getScaleValueUnipolar(const short &val) const;
    void                          setScaleTransformFunction(const AgU25xxEnumAIChannelPolaities &polarity);
    void                          resetScaleTransformFunction();

    bool                          mChannelHasData;
    mutable QMutex                mChannelHasDataMutex;
    std::deque<double*>           mChannelData;
    unsigned int                  mChannelDataCounter;
    mutable QMutex                mChannelDataAccessMutex;
};

#endif // AGU25XXAICHANNEL_H
