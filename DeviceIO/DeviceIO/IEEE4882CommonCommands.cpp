#include "IEEE4882CommonCommands.h"

#include <QObject>
#include <QString>

IEEE4882CommonCommands::IEEE4882CommonCommands()
{   
}

const char* IEEE4882CommonCommands::cmdClearStatus() const
{
    return "*CLS";
}

const char* IEEE4882CommonCommands::cmdResetInstr() const
{
    return "*RST";
}

const char* IEEE4882CommonCommands::cmdWaitOperationComplete() const
{
    return "*WAI";
}

const char* IEEE4882CommonCommands::cmdSetEventStatusEnable(const unsigned short value) const
{
    QString cmdStr = QObject::tr("*ESE %1")
            .arg(value);

    return cmdStr.toStdString().c_str();
}

const char* IEEE4882CommonCommands::cmdGetEventStatusEnable() const
{
    return "*ESE?";
}

const char* IEEE4882CommonCommands::cmdQueryEventStatusRegister() const
{
    return "*ESR?";
}

const char* IEEE4882CommonCommands::cmdQueryInstrID() const
{
    return "*IDN?";
}

const char* IEEE4882CommonCommands::cmdQueryOperationCompleteStatus() const
{
    return "*OPC?";
}
