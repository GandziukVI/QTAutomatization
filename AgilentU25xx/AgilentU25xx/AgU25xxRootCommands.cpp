#include "AgU25xxRootCommands.h"
#include <QObject>

AgU25xxRootCommands::AgU25xxRootCommands()
{

}

QString AgU25xxRootCommands::cmdStartSingleShotAcquisition() const
{
    return QString("DIG");
}

QString AgU25xxRootCommands::cmdStartContinuousAcquisition() const
{
    return QString("RUN");
}

QString AgU25xxRootCommands::cmdStopAcquisition() const
{
    return QString("STOP");
}

QString AgU25xxRootCommands::cmdGetInstrModel() const
{
    return QString("MOD");
}

QString AgU25xxRootCommands::cmdGetInstrSerialNum() const
{
    return QString("SER");
}

QString AgU25xxRootCommands::cmdUploadUserData(const QString& userData) const
{
    return QObject::tr("DATA:USER %1")
            .arg(userData);
}
