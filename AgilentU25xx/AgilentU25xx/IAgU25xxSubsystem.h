#ifndef IAGU25XXSUBSYSTEM_H
#define IAGU25XXSUBSYSTEM_H

#include "agilentu25xx_global.h"

#include <QString>
#include <QVector>

class AGILENTU25XXSHARED_EXPORT IAgU25xxSubsystem {

public:
    IAgU25xxSubsystem();
    IAgU25xxSubsystem(const char* subSystemID);

    QString buildCommand(const char* command);
    QString buildCommand(const QString& command);

    char subsystemIdentifier[256];
    char subsystemSeparator;

    IAgU25xxSubsystem getSubSubSystem(const char* subSubSystemID) const;

protected:
    void    extCopyString(char* dest, const char* src) const;
    QString extCreateChannelsString(const QVector<unsigned int>& channels) const;

private:
    QString commandString;
};

#endif // IAGU25XXSUBSYSTEM_H
