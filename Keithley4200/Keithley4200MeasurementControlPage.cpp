#include "Keithley4200MeasurementControlPage.h"

Keithley4200MeasurementControlPage::Keithley4200MeasurementControlPage()
{
    extCopyString(pageIdentifier, "MD");
}

QString Keithley4200MeasurementControlPage::cmdControlMeasurements(Keithley4200ControlMeasurementTypes controlMeasurementType)
{
    extCopyString(commandIdentifier, "ME");

    QString cmdStr = QObject::tr("%1").arg(getSMUControlMeasurementType(controlMeasurementType));
    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementControlPage::cmdObtainOutputData(const char *channelName)
{
    extCopyString(commandIdentifier, "DO");

    QString cmdStr = QObject::tr(" \'%1\'").arg(channelName);
    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementControlPage::cmdObtainOutputTimeStampData(const unsigned int channelID)
{
    extCopyString(commandIdentifier, "DO");

    QString cmdStr = QObject::tr(" \'CH%1T\'").arg(channelID);
    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementControlPage::cmdSaveFile(Keithley4200FileTypes fileType, const char *fileName, const char *comment)
{
    extCopyString(commandIdentifier, "SV");

    QString cmdStr;

    if(strcmp(comment, "") != 0) {
        cmdStr = QObject::tr(" \'%1 %2 %3\'")
                .arg(getSMUSaveFileType(fileType))
                .arg(fileName)
                .arg(comment);
    }
    else {
        cmdStr = QObject::tr(" \'%1 %2\'")
                .arg(getSMUSaveFileType(fileType))
                .arg(fileName);
    }

    QString res    = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementControlPage::cmdGetFile(Keithley4200FileTypes fileType, const char *fileName)
{
    extCopyString(commandIdentifier, "GT");

    QString cmdStr = QObject::tr(" \'%1 %2\'")
            .arg(getSMUSaveFileType(fileType))
            .arg(fileName);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementControlPage::cmdMapChannel(const unsigned int channelID, Keithley4200ChannelType channelType, const unsigned int chNumber)
{
    extCopyString(commandIdentifier, "MP");

    QString cmdStr = QObject::tr(" %1, %2%3")
            .arg(channelID)
            .arg(getChannelType(channelType))
            .arg(chNumber);

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}

QString Keithley4200MeasurementControlPage::cmdSetFixedSourceRange(const unsigned int channelID, Keithley4200SourceRange sourceRange)
{
    extCopyString(commandIdentifier, "SR");

    QString cmdStr = QObject::tr(" %1, %2")
            .arg(channelID)
            .arg(getChannelSourceRange(sourceRange));

    QString res = buildCommand(cmdStr);

    pageSetCurrent();

    return res;
}
