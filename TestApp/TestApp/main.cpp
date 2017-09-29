#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

#include <VisaDevice.h>

#include <iostream>
#include <fstream>

#include <Keithley4200SourceSetupPage.h>
#include <Keithley4200ChannelDefinitionPage.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Keithley4200ChannelDefinitionPage defPage(2);

    qDebug() << defPage.cmdDefineChannel().toLatin1().data();

    Keithley4200SourceSetupPage ssPage(1);

    qDebug() << ssPage.cmdConfVAR1Sweep(SMUSourceMode::Voltage, SMUSweepMode::LinearSweep, 0.0, 1.0, 0.01, 0.01).toLatin1().data();

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
