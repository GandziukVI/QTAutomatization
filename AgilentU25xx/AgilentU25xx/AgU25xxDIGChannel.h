#ifndef AGU25XXDIGCHANNEL_H
#define AGU25XXDIGCHANNEL_H

#include "agilentu25xx_global.h"

#include "AgU25xxCONFigureSubSys.h"
#include "AgU25xxMEASureSubSys.h"
#include "AgU25xxSOURceSubSys.h"
#include "AgU25xxTRIGgerSubSys.h"

#include <IDeviceIO.h>

class AGILENTU25XXSHARED_EXPORT AgU25xxDIGChannel : public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxDIGChannel();
    AgU25xxDIGChannel(AgU25xxEnumDigitalChannels channelName, IDeviceIO& driver);

private:
    IDeviceIO                  *mDriver;

    AgU25xxCONFigureSubSys     mCONFigureSubSys;
    AgU25xxMEASureSubSys       mMEASureSubSys;
    AgU25xxSOURceSubSys        mSOURceSubSys;
    AgU25xxTRIGgerSubSys       mTRIGgerSubSys;

    void setByte(const unsigned short int byteVal);
    unsigned short int getByte();
    void setBit(bool state, const unsigned short int bitNum);
    bool getBit(const unsigned short int bitNum);
    void bitPulse(const unsigned short int bitNum, unsigned int msec = 1000);

    AgU25xxEnumDigitalChannels mChannelID;
};

#endif // AGU25XXDIGCHANNEL_H
