#ifndef KEITHLEY4200DEFINITIONS_H
#define KEITHLEY4200DEFINITIONS_H

#include "keithley4200_global.h"

enum class KEITHLEY4200SHARED_EXPORT Keithley4200DisplayMode {
    GraphicsDisplayMode,
    ListdisplayMode
};

enum class KEITHLEY4200SHARED_EXPORT Keithley4200XAxisScaleType {
    LinearScale,
    LogScale
};

enum class KEITHLEY4200SHARED_EXPORT Keithley4200YAxisScaleType {
    LinearScale,
    LogScale,
    LogScaleAbsoluteValue
};

#endif // KEITHLEY4200DEFINITIONS_H
