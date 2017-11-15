#ifndef IAGU25XXSUBSYSTEM_H
#define IAGU25XXSUBSYSTEM_H

#include "agilentu25xx_global.h"
#include "AgU25xxDefinitions.h"

#include <QString>
#include <QTextStream>
#include <QVector>

#include <iterator>
#include <algorithm>

class AGILENTU25XXSHARED_EXPORT IAg25xxSubsystem {

public:
    IAg25xxSubsystem();
    IAg25xxSubsystem(const char* subSystemID);

    QString buildCommand(const char* command);
    QString buildCommand(const QString& command);

    char subsystemIdentifier[256];
    char subsystemSeparator;

    IAg25xxSubsystem getSubSubSystem(const char* subSubSystemID) const;

protected:
    void                  extCopyString(char* dest, const char* src) const;
    unsigned int          extGetAOChannel(AgU25xxAnalogOutput::AOChannels channel) const;
    QVector<unsigned int> extGetAOChannels(QVector<AgU25xxAnalogOutput::AOChannels> channels) const;

private:
    QString commandString;
};

#endif // IAGU25XXSUBSYSTEM_H
