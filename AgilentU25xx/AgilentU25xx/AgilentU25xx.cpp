#include "AgilentU25xx.h"


AgilentU25xx::AgilentU25xx()
{
}

AgilentU25xx::AgilentU25xx(IDeviceIO &driver)
{
    mDriver = &driver;

    AInChannelSet.initialize(driver);
    AOutChannelSet.initialize(driver);
    DIGitalChannelSet.initialize(driver);

//    AInChannelSet = new AgU25xxAIChannelSet(driver);
//    AOutChannelSet = new AgU25xxAOChannelSet(driver);
//    DIGitalChannelSet = new AgU25xxDIGitalChannelSet(driver);
}

AgilentU25xx::~AgilentU25xx()
{
//    delete AInChannelSet;
//    delete AOutChannelSet;
//    delete DIGitalChannelSet;
}

void AgilentU25xx::resetDevice()
{
    QString cmd = QObject::tr("%1; %2")
            .arg(mIEEE4882Commands.cmdClearStatus())
            .arg(mIEEE4882Commands.cmdResetInstr());

    mDriver->SendCommandRequest(cmd);
}

void AgilentU25xx::waitForOperationsCpmplete()
{
    mDriver->SendCommandRequest(mIEEE4882Commands.cmdWaitOperationComplete());
}
