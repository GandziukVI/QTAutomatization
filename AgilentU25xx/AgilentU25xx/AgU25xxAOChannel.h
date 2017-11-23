#ifndef AGU25XXAOCHANNEL_H
#define AGU25XXAOCHANNEL_H

#include "agilentu25xx_global.h"

#include "AgU25xxAPPLySubSys.h"
#include "AgU25xxOUTPutSubSys.h"
#include "AgU25xxROUTeSubSys.h"
#include "AgU25xxSOURceSubSys.h"

#include <IDeviceIO.h>

#include <QRegularExpression>

class AGILENTU25XXSHARED_EXPORT AgU25xxAOChannel : public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxAOChannel();
    AgU25xxAOChannel(AgU25xxEnumAOChannels channelName, IDeviceIO& driver);
    ~AgU25xxAOChannel();

    void   setDCVoltage(double voltage);
    double getDCVoltage();
    void   setOutpON();
    void   setOutpOFF();
    void   setEnabled(bool enabled);
    bool   getEnabled();
    void   setPolarity(AgU25xxEnumAOChannelPolarities polarity);

    AgU25xxEnumAOChannelPolarities getPolarity();

private:
    IDeviceIO*          mDriver;

    AgU25xxAPPLySubSys  mAPPLySubsys;
    AgU25xxOUTPutSubSys mOUTPutSubSys;
    AgU25xxSOURceSubSys mSOURceSubSys;
    AgU25xxROUTeSubSys  mROUTeSubSys;

    AgU25xxEnumAOChannels mChannelID;

//    QRegularExpression    *regExDouble;
};

#endif // AGU25XXAOCHANNEL_H
