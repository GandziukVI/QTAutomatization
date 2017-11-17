#ifndef AGU25XXDIGCHANNEL_H
#define AGU25XXDIGCHANNEL_H

#include "agilentu25xx_global.h"

#include "AgU25xxDIGitalBit.h"

class AGILENTU25XXSHARED_EXPORT AgU25xxDIGChannel : public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxDIGChannel();
    AgU25xxDIGChannel(AgU25xxEnumDigitalChannels channelName, IDeviceIO& driver);

    QVector<AgU25xxDIGitalBit> DIGitalBits;

    AgU25xxDIGitalBit &operator [] (const unsigned short index);
private:
    IDeviceIO                  *mDriver;

    AgU25xxCONFigureSubSys     mCONFigureSubSys;
    AgU25xxMEASureSubSys       mMEASureSubSys;
    AgU25xxSOURceSubSys        mSOURceSubSys;
    AgU25xxTRIGgerSubSys       mTRIGgerSubSys;

    void setByte(const unsigned short int byteVal);
    unsigned short int getByte();

    AgU25xxEnumDigitalChannels mChannelID;
    unsigned short             nBits;
};

#endif // AGU25XXDIGCHANNEL_H
