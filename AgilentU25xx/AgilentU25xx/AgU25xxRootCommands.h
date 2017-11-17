#ifndef AGU25XXROOTCOMMANDS_H
#define AGU25XXROOTCOMMANDS_H

#include "agilentu25xx_global.h"
#include <QString>

class AGILENTU25XXSHARED_EXPORT AgU25xxRootCommands
{
public:
    AgU25xxRootCommands();

    QString cmdStartSingleShotAcquisition() const;
    QString cmdStartContinuousAcquisition() const;
    QString cmdStopAcquisition() const;
    QString cmdGetInstrModel() const;
    QString cmdGetInstrSerialNum() const;
    QString cmdUploadUserData(const QString& userData) const;
};

#endif // AGU25XXROOTCOMMANDS_H
