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

enum class KEITHLEY4200SHARED_EXPORT Keithley4200ControlMeasurementTypes {
    SingleTriggerTest,
    RepeatedTriggerTest,
    AppendTriggertest,
    StopAbortTest
};

enum class KEITHLEY4200SHARED_EXPORT Keithley4200FileTypes {
    ProgramFile,
    DataOrProgramFile
};

enum class KEITHLEY4200SHARED_EXPORT Keithley4200ChannelType {
    SMU,
    VS,
    VM
};

enum class KEITHLEY4200SHARED_EXPORT Keithley4200SourceRange {
    Auto,
    BestFixed
};

#endif // KEITHLEY4200DEFINITIONS_H
