#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

#include <VisaDevice.h>

#include <iostream>
#include <fstream>

#include <Keithley4200SourceSetupPage.h>
#include <Keithley4200ChannelDefinitionPage.h>
#include <Keithley4200MeasurementSetupPage.h>
#include <Keithley4200MeasurementControlPage.h>
#include <Keithley4200UserModePage.h>
#include <Keithley4200CommonCommands.h>

#include <Keithley4200SMUChannel.h>

#include <AgU25xxMEASure.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AgU25xxMEASure commands;

    qDebug() << commands.cmdMeasureDigitalBit(1, AgU25xxDIGital::DigitalChannels::D01).toStdString().c_str();

//    Keithley4200SMUChannel smu;

//    smu.SwitchOFF();
//    smu.SwitchOFF();
//    smu.SetSourceVoltage(20.0);
//    smu.SwitchOFF();
//    smu.SetSourceVoltage(20.0);
//    smu.SetSourceVoltage(20.0);


//    Keithley4200ChannelDefinitionPage defPage;

//    qDebug() << defPage.cmdDisableChannel(2).toLatin1().data();
//    qDebug() << defPage.cmdDefineChannel(1).toLatin1().data();
//    qDebug() << defPage.cmdDefineVoltageMeterChannel(2).toLatin1().data();
//    qDebug() << defPage.cmdDefineVoltageSourceChannel(2).toLatin1().data();

//    Keithley4200SourceSetupPage ssPage;

//    qDebug() << ssPage.cmdConfVAR1Sweep(SMUSourceMode::Current, SMUSweepMode::LinearSweep, 0.1, 10.0, 0.05, 0.001).toLatin1().data();
//    qDebug() << ssPage.cmdConfVAR1Scale(0.5, 2, 3).toLatin1().data();
//    qDebug() << ssPage.cmdConfVAR2Sweep(SMUSourceMode::Current, 0.05, 0.01, 5, 0.001).toLatin1().data();

//    QVector<double> listValues;

//    listValues.push_back(0.1);
//    listValues.push_back(-0.2);
//    listValues.push_back(0.3);
//    listValues.push_back(0.25);
//    listValues.push_back(0.5);

//    qDebug() << ssPage.cmdConfListSweep(SMUSourceMode::Voltage, 1, SMUMasterOrSlaveMode::Master, 0.001, listValues).toLatin1().data();
//    qDebug() << ssPage.cmdConfAutoStandby(1, true).toLatin1().data();

//    Keithley4200MeasurementSetupPage msPage;

//    QVector<const char*> functionsToEnable;
//    functionsToEnable.push_back("V1");
//    functionsToEnable.push_back("I1");
//    functionsToEnable.push_back("V2");
//    functionsToEnable.push_back("I2");

//    qDebug() << msPage.cmdEnableVIFunctions(functionsToEnable).toLatin1().data();

//    Keithley4200MeasurementControlPage mdPage;

//    qDebug() << mdPage.cmdControlMeasurements(Keithley4200ControlMeasurementTypes::SingleTriggerTest).toLatin1().data();
//    qDebug() << mdPage.cmdObtainOutputData("Volt").toLatin1().data();
//    qDebug() << mdPage.cmdObtainOutputTimeStampData(1).toLatin1().data();
//    qDebug() << mdPage.cmdSaveFile(Keithley4200FileTypes::DataOrProgramFile, "Volt", "Comm").toLatin1().data();
//    qDebug() << mdPage.cmdGetFile(Keithley4200FileTypes::DataOrProgramFile, "Volt").toLatin1().data();
//    qDebug() << mdPage.cmdMapChannel(3, Keithley4200ChannelType::VM, 5).toLatin1().data();
//    qDebug() << mdPage.cmdSetFixedSourceRange(1, Keithley4200SourceRange::BestFixed).toLatin1().data();

//    Keithley4200UserModePage usPage;

//    qDebug() << usPage.cmdSMUSetSourceVoltage(1, Keithley4200VoltageRanges::Range20V, 2.15, 0.01).toLatin1().data();
//    qDebug() << usPage.cmdSMUSetSourceCurrent(1, Keithley4200CurrentRanges::Range100mA, 0.01, 10).toLatin1().data();
//    qDebug() << usPage.cmdVSSetSourceVoltage(1, 10).toLatin1().data();
//    qDebug() << usPage.cmdTriggerVoltage(Keithley4200VoltageMeasureChannels::SMU1).toLatin1().data();
//    qDebug() << usPage.cmdTriggerCurrent(Keithley4200CurrentMeasureChannels::SMU1).toLatin1().data();

//    Keithley4200CommonCommands commonCommands;

//    qDebug() << commonCommands.cmdPerformAutoCalibration(1).toLatin1().data();

//    std::ofstream fout("c:\\Users\\v.handziuk\\Documents\\GitHub\\SetupsAutomatization\\Hello.txt");

//    IDeviceIO* usbDAQ = new VisaDevice("USB0::2391::5912::TW54334510::INSTR");

//    QString responce;
//    responce = usbDAQ->RequestQuery("*IDN?\n", 2048);
//    qDebug() << responce;
//    fout << responce.toLatin1().data();

//    int i = 0;
//    for(; i != 10; ) {
//        responce = multimeter->RequestQuery("*IDN?\n", 22);
//        qDebug() << responce;
//        fout << responce.toLatin1().data();
//        ++i;
//    }

//    delete usbDAQ;

    return a.exec();
}
