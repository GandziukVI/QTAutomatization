#ifndef IEEE4882COMMONCOMMANDS_H
#define IEEE4882COMMONCOMMANDS_H

#include "deviceio_global.h"

class DEVICEIOSHARED_EXPORT IEEE4882CommonCommands
{
public:
    IEEE4882CommonCommands();

    const char* cmdClearStatus() const;
    const char* cmdResetInstr() const;
    const char* cmdWaitOperationComplete() const;

    const char* cmdSetEventStatusEnable(const unsigned short int value) const;
    const char* cmdGetEventStatusEnable() const;
    const char* cmdQueryEventStatusRegister() const;
    const char* cmdQueryInstrID() const;
    const char* cmdQueryOperationCompleteStatus() const;
};

#endif // IEEE4882COMMONCOMMANDS_H
