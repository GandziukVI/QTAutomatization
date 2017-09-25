#ifndef IKEITHLEY4200PAGE_H
#define IKEITHLEY4200PAGE_H

#include "keithley4200_global.h"

#include <SourceMeterUnitDefinitions.h>

class KEITHLEY4200SHARED_EXPORT IKeithley4200Page {

public:
    IKeithley4200Page () { }

    const char* buildCommand(const char* command) const;

protected:
    char pageIdentifier[256];
    char commandIdentifier[256];

    void extCopyString(char* dest, const char* src) const;
    int  getSMUSourceMode(SMUSourceMode sourceMode) const;
    int  getSMUSourceFunction(SMUSourceFunction sourceFunction) const;
};

#endif // IKEITHLEY4200PAGE_H
