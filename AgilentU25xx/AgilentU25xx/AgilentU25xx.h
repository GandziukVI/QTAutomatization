#ifndef AGILENTU25XX_H
#define AGILENTU25XX_H

#include "agilentu25xx_global.h"

#include "AgU25xxACQuireSubSys.h"
#include "AgU25xxAPPLySubSys.h"
#include "AgU25xxCALibrationSubSys.h"
#include "AgU25xxCONFigureSubSys.h"
#include "AgU25xxMEASureSubSys.h"
#include "AgU25xxOUTPutSubSys.h"
#include "AgU25xxROUTeSubSys.h"
#include "AgU25xxSENSeSubSys.h"
#include "AgU25xxSOURceSubSys.h"
#include "AgU25xxSYSTemSubSys.h"
#include "AgU25xxTRIGgerSubSys.h"
#include "AgU25xxWAVeformSubSys.h"
#include "AgU25xxRootCommands.h"

#include <IEEE4882CommonCommands.h>

#include <IDeviceIO.h>

class AGILENTU25XXSHARED_EXPORT AgilentU25xx
{

public:
    AgilentU25xx();
};

#endif // AGILENTU25XX_H
