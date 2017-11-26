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


//#include <AgU25xxACQuireSubSys.h>
//#include <AgU25xxAPPLySubSys.h>
//#include <AgU25xxMEASureSubSys.h>
//#include <AgU25xxCALibrationSubSys.h>
//#include <AgU25xxCONFigureSubSys.h>

#include "AgilentU25xx.h"
#include "AgU25xxException.h"

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


//    IDeviceIO *driver = new VisaDevice("USB0::0x0957::0x1718::TW54334510::INSTR");

//    AgilentU25xx *device = new AgilentU25xx(*driver);

//    device->resetDevice();

//    int samplingRate = 500000;
//    unsigned int nPoints = 50000;

//    for (int i = 0; i != 4; i++) {
//        bool enabled = i % 2 == 0? true : false;
//        device->AInChannelSet[i].setEnabled(true);
//        AgU25xxEnumAIChannelPolaities polarity = i % 2 == 0? AgU25xxEnumAIChannelPolaities::BIP : AgU25xxEnumAIChannelPolaities::UNIP;
//        device->AInChannelSet[i].setPolarity(polarity);
//    }

//    device.AInChannelSet[0].setEnabled(true);

//    for (int i = 0; i != 3; ) {
//        QFuture<void> acqThreadRun = QtConcurrent::run(&device->AInChannelSet, &AgU25xxAIChannelSet::startContinuousAcquisition, samplingRate, nPoints, 5);
//        QThread::sleep(20);

//        device->AInChannelSet.stopAcquisition();
//        acqThreadRun.waitForFinished();

//        ++i;
//    }

//    QString outputStr;
//    QTextStream outputStrStream(&outputStr);

//    for (int i = 0; i != 10; i++) {
//        device.AInChannelSet.acquireSingleShot(samplingRate);
//        qDebug() << "Acquisition successful";

//        outputStr.clear();

//        for (int j = 0; j != 5; j++)
//            outputStrStream << device.AInChannelSet[0].ACQuisitionData[j] << ' ';

//        qDebug() << outputStr.toStdString().c_str();
//    }

//    qDebug() << "End of acquisition";

//    try
//    {
//        qDebug() << "Reading value from the 1st DIGital channel";
//        qDebug() << (*device.DIGitalChannelSet)[0].getByte();
//        qDebug() << "Setting byte to 1 on the 1st DIGital channel";
//        (*device.DIGitalChannelSet)[0].setByte(1);
//        qDebug() << "Reading value from the 1st DIGital channel";
//        qDebug() << (*device.DIGitalChannelSet)[0].getByte();
//        qDebug() << "Setting byte to 2 on the 1st DIGital channel";
//        (*device.DIGitalChannelSet)[0].setByte(2);
//        qDebug() << "Reading value from the 1st DIGital channel";
//        qDebug() << (*device.DIGitalChannelSet)[0].getByte();
//        qDebug() << "Setting byte to 0 on the 1st DIGital channel";
//        (*device.DIGitalChannelSet)[0].setByte(0);
//        qDebug() << "Reading value from the 1st DIGital channel";
//        qDebug() << (*device.DIGitalChannelSet)[0].getByte();

//        device.DIGitalChannelSet[1][2].bitPulse(100);

//    }
//    catch(AgU25xxException ex)
//    {
//        qDebug() << ex.message();
//    }

//    delete device;
//    delete driver;

//    // Counter channels
//    AgU25xxEnumCounterChannels ch1 = AgU25xxEnumCounterChannels::COUNT01;
//    AgU25xxEnumCounterChannels ch2 = AgU25xxEnumCounterChannels::COUNT02;

//    QVector<AgU25xxEnumCounterChannels> counChVec;

//    counChVec.push_back(ch1);
//    counChVec.push_back(ch2);

//    // Digital channels

//    AgU25xxEnumDigitalChannels DigCh01 = AgU25xxEnumDigitalChannels::DIG01;
//    AgU25xxEnumDigitalChannels DigCh02 = AgU25xxEnumDigitalChannels::DIG02;
//    AgU25xxEnumDigitalChannels DigCh03 = AgU25xxEnumDigitalChannels::DIG03;
//    AgU25xxEnumDigitalChannels DigCh04 = AgU25xxEnumDigitalChannels::DIG04;

//    QVector<AgU25xxEnumDigitalChannels> digChVec;

//    digChVec.push_back(DigCh01);
//    digChVec.push_back(DigCh02);
//    digChVec.push_back(DigCh03);
//    digChVec.push_back(DigCh04);

//    // Analog in channels

//    AgU25xxEnumAIChannels AIn01 = AgU25xxEnumAIChannels::AIn01;
//    AgU25xxEnumAIChannels AIn02 = AgU25xxEnumAIChannels::AIn02;
//    AgU25xxEnumAIChannels AIn03 = AgU25xxEnumAIChannels::AIn03;
//    AgU25xxEnumAIChannels AIn04 = AgU25xxEnumAIChannels::AIn04;

//    QVector<AgU25xxEnumAIChannels> aInChVec;

//    aInChVec.push_back(AIn01);
//    aInChVec.push_back(AIn02);
//    aInChVec.push_back(AIn03);
//    aInChVec.push_back(AIn04);

//    // Analog out channels

//    AgU25xxEnumAOChannels AOut01 = AgU25xxEnumAOChannels::AOut01;
//    AgU25xxEnumAOChannels AOut02 = AgU25xxEnumAOChannels::AOut02;

//    QVector<AgU25xxEnumAOChannels> aOutChVec;

//    aOutChVec.push_back(AOut01);
//    aOutChVec.push_back(AOut02);

    /* Testing commands to the device */

    // ACQuire subsystem

//    AgU25xxACQuireSubSys ACQuireCommands;

//    qDebug() << ACQuireCommands.cmdSetPointsSingleShot(1000).toStdString().c_str();
//    qDebug() << ACQuireCommands.cmdGetPointsSingleShot().toStdString().c_str();
//    qDebug() << ACQuireCommands.cmdSetSamplingRate(10).toStdString().c_str();
//    qDebug() << ACQuireCommands.cmdGetSamplingrate().toStdString().c_str();

    // APPLy subsystem

//    AgU25xxAPPLySubSys APPLyCommands;

//    qDebug() << APPLyCommands.cmdApplyNoise(10.0, 0.0, AOut01).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplyNoise(5.0, 1.0, aOutChVec).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplySawToothWave(1.0, 2.0, AOut01).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplySawToothWave(1.0, 2.0, aOutChVec).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplySineWave(1.0, 2.0, AOut01).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplySineWave(1.0, 2.0, aOutChVec).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplySquareWave(1.0, 2.0, AOut01).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplySquareWave(1.0, 2.0, aOutChVec).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplyTriangleWave(1.0, 2.0, AOut01).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplyTriangleWave(1.0, 2.0, aOutChVec).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplyUser(AOut01).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdApplyUser(aOutChVec).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdGetAOParams(AOut01).toStdString().c_str();
//    qDebug() << APPLyCommands.cmdGetAOParams(aOutChVec).toStdString().c_str();

    // CALibration subsystem

//    AgU25xxCALibrationSubSys CALibrationCommands;

//    qDebug() << CALibrationCommands.cmdStartSelfCalibration().toStdString().c_str();
//    qDebug() << CALibrationCommands.cmdCheckCalibrationStatus().toStdString().c_str();

    // CONFigure subsystem

//    AgU25xxCONFigureSubSys CONFigureCommands;

//    qDebug() << CONFigureCommands.cmdSetDigitalDirection(AgU25xxEnumDigitalDirection::INPut, DigCh01).toStdString().c_str();
//    qDebug() << CONFigureCommands.cmdSetDigitalDirection(AgU25xxEnumDigitalDirection::OUTPut, digChVec).toStdString().c_str();
//    qDebug() << CONFigureCommands.cmdGetDigitalDirection(DigCh02).toStdString().c_str();
//    qDebug() << CONFigureCommands.cmdGetDigitalDirection(digChVec).toStdString().c_str();
//    qDebug() << CONFigureCommands.cmdSetExtClockFreq(10000).toStdString().c_str();
//    qDebug() << CONFigureCommands.cmdGetExtClockFreq().toStdString().c_str();
//    qDebug() << CONFigureCommands.cmdSetSSIMode(AgU25xxEnumSSIModes::Master).toStdString().c_str();
//    qDebug() << CONFigureCommands.cmdGetSSIMode().toStdString().c_str();
//    qDebug() << CONFigureCommands.cmdSetTimeBaseSrc(AgU25xxEnumTimeSrcModes::INTernal).toStdString().c_str();
//    qDebug() << CONFigureCommands.cmdGetTimeBaseSrc().toStdString().c_str();


    // MEASure subsystem

//    AgU25xxMEASureSubSys MEASureCommands;

//    qDebug() << MEASureCommands.cmdMeasureCounterData(ch1).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterData(counChVec).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterFrequency(ch1).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterFrequency(counChVec).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterPeriod(ch1).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterPeriod(counChVec).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureDigitalBit(1, AgU25xxEnumDigitalChannels::DIG01).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterPulseWidth(ch1).toStdString().c_str();;
//    qDebug() << MEASureCommands.cmdMeasureCounterPulseWidth(counChVec).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterTotalize(ch1).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterTotalize(counChVec).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterTotalize(ch1).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureCounterTotalize(counChVec).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureDigitalBit(2, DigCh01).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureDigitalBit(4, digChVec).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureDigitalByte(DigCh02).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureDigitalByte(digChVec).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureVoltage(AIn03).toStdString().c_str();
//    qDebug() << MEASureCommands.cmdMeasureVoltage(aInChVec).toStdString().c_str();


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
