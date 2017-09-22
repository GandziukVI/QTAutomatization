#ifndef ISOURCEMETERUNIT_H
#define ISOURCEMETERUNIT_H

#include "sourcemeterunit_global.h"
#include "SourceMeterUnitDefinitions.h"

#include <IDeviceIO.h>

class SOURCEMETERUNITSHARED_EXPORT ISourceMeterUnit
{

public:
    ISourceMeterUnit();

    virtual void Initialize (const IDeviceIO& Driver)                     = 0;
    virtual void Initialize (const IDeviceIO& Driver, QString& channelID) = 0;

    virtual void SwitchON  ()  = 0;
    virtual void SwitchOFF () = 0;

    virtual void SetSourceDelay   (const double delay)   = 0;
    virtual void SetSourceVoltage (const double voltage) = 0;
    virtual void SetSourceCurrent (const double current) = 0;
    virtual void SetAveraging     (const int avg)        = 0;
    virtual void SetNPLC          (const double val)     = 0;
};

#endif // ISOURCEMETERUNIT_H
