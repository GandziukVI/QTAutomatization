#include <QCoreApplication>
#include <QDebug>

#include <fstream>

#include "VisaDevice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::ofstream fout("c:\\Users\\v.handziuk\\Documents\\GitHub\\SetupsAutomatization\\Hello.txt");

    IDeviceIO* usbDAQ = new VisaDevice("USB0::2391::5912::TW54334510::INSTR");

    QString responce;
    responce = usbDAQ->RequestQuery("*IDN?\n", 52);
    qDebug() << responce;
    fout << responce.toLatin1().data();

//    int i = 0;
//    for(; i != 10; ) {
//        responce = multimeter->RequestQuery("*IDN?\n", 22);
//        qDebug() << responce;
//        fout << responce.toLatin1().data();
//        ++i;
//    }

    delete usbDAQ;

    return a.exec();
}
