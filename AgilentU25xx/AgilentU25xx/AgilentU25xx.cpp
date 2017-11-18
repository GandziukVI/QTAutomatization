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
