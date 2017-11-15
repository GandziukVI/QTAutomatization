#ifndef AGU25XXDEFINITIONS_H
#define AGU25XXDEFINITIONS_H

#include "agilentu25xx_global.h"

namespace AgU25xxAnalogOutput
{
    enum class AGILENTU25XXSHARED_EXPORT AOChannels {
        CH01,
        CH02
    };
}

namespace AgU25xxDIGital
{
    enum class AGILENTU25XXSHARED_EXPORT DigitalDirection {
        INPut,
        OUTPut
    };

    enum class AGILENTU25XXSHARED_EXPORT DigitalChannels {
        D01,
        D02,
        D03,
        D04
    };
}

namespace AgU25xxTIMEbase
{
    enum class AGILENTU25XXSHARED_EXPORT TimeSrcModes {
        INTernal,
        EXTernal,
        CCG
    };
}

enum class AGILENTU25XXSHARED_EXPORT SSIModes {
    None,
    Master,
    Slave
};

#endif // AGU25XXDEFINITIONS_H
