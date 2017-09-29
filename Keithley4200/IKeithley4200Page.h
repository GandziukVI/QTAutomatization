#ifndef IKEITHLEY4200PAGE_H
#define IKEITHLEY4200PAGE_H

#include "keithley4200_global.h"

#include <SourceMeterUnitDefinitions.h>

#include <QObject>
#include <QString>

class KEITHLEY4200SHARED_EXPORT IKeithley4200Page {

public:
    IKeithley4200Page () { }

    QString buildCommand(const char* command);
    QString buildCommand(const QString& command);

protected:
    char pageIdentifier[256];
    char commandIdentifier[256];
    unsigned int channelNumber;

    void extCopyString(char* dest, const char* src) const;
    int  getSMUSourceMode(SMUSourceMode sourceMode) const;
    int  getSMUSourceFunction(SMUSourceFunction sourceFunction) const;
    int  getSMUSweepMode(SMUSweepMode sweepMode) const;

private:
    QString commandString;
};

#endif // IKEITHLEY4200PAGE_H
