#include <QCoreApplication>
#include <QDebug>

#include <VisaDevice.h>

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::ofstream fout("c:\\Users\\v.handziuk\\Documents\\GitHub\\SetupsAutomatization\\Hello.txt");

    IDeviceIO* multimeter = new VisaDevice("GPIB0::12::INSTR");

    multimeter->SendCommandRequest("REN\n");
    //multimeter->SendCommandRequest("*RST\n");
    //multimeter->SendCommandRequest("F0X\n");
    //multimeter->SendCommandRequest("R0X\n");

    QString responce;
    int i = 0;
    for(; i != 10; ) {
        responce = multimeter->RequestQuery("*IDN?\n", 22);
        qDebug() << responce;
        fout << responce.toLatin1().data();
        ++i;
    }

    delete multimeter;

    return a.exec();
}
