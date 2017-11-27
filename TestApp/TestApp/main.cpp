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

    return a.exec();
}
