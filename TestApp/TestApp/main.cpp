#include <QCoreApplication>
#include <QDebug>

#include <VisaDevice.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IDeviceIO* multimeter = new VisaDevice("GPIB0::12::INSTR");

    multimeter->SendCommandRequest("REN\n");
    //multimeter->SendCommandRequest("*RST\n");
    //multimeter->SendCommandRequest("F0X\n");
    //multimeter->SendCommandRequest("R0X\n");

    int i = 0;
    for(; i != 10; ) {
        QString responce = multimeter->RequestQuery("*IDN?\n", 22);
        qDebug() << responce;
        ++i;
    }

    delete multimeter;

    return a.exec();
}
