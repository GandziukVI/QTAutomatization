#ifndef AGILENTU25XX_H
#define AGILENTU25XX_H

#include "agilentu25xx_global.h"

#include "AgU25xxAIChannelSet.h"
#include "AgU25xxAOChannelSet.h"
#include "AgU25xxDIGitalChannelSet.h"

#include <IEEE4882CommonCommands.h>

class AGILENTU25XXSHARED_EXPORT AgilentU25xx
{

public:
    AgilentU25xx();
    AgilentU25xx(IDeviceIO &driver);
    ~AgilentU25xx();

    void resetDevice();
    void waitForOperationsCpmplete();

    AgU25xxAIChannelSet      *AInChannelSet;
    AgU25xxAOChannelSet      *AOutChannelSet;
    AgU25xxDIGitalChannelSet *DIGitalChannelSet;

private:
    IDeviceIO*             mDriver;
    IEEE4882CommonCommands mIEEE4882Commands;
};

#endif // AGILENTU25XX_H
