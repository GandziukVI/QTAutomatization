#ifndef AGU25XXDIGITALBIT_H
#define AGU25XXDIGITALBIT_H

#include "agilentu25xx_global.h"

#include "AgU25xxCONFigureSubSys.h"
#include "AgU25xxMEASureSubSys.h"
#include "AgU25xxSOURceSubSys.h"
#include "AgU25xxTRIGgerSubSys.h"

#include <IDeviceIO.h>

class AGILENTU25XXSHARED_EXPORT AgU25xxDIGitalBit : public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxDIGitalBit();
    AgU25xxDIGitalBit(AgU25xxEnumDigitalChannels channelName, unsigned short bitNumber, IDeviceIO& driver);

    void setBit(bool state);
    bool getBit();
    void bitPulse(unsigned int msec = 1000);

private:
    IDeviceIO                  *mDriver;

    AgU25xxCONFigureSubSys     mCONFigureSubSys;
    AgU25xxMEASureSubSys       mMEASureSubSys;
    AgU25xxSOURceSubSys        mSOURceSubSys;
    AgU25xxTRIGgerSubSys       mTRIGgerSubSys;

    unsigned short bitNum;

    AgU25xxEnumDigitalChannels mChannelID;
};

#endif // AGU25XXDIGITALBIT_H
