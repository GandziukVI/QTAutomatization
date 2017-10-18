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

enum class KEITHLEY4200SHARED_EXPORT Keithley4200VoltageRanges {
    Autorange,
    Range20V,
    Range200V,
    Range200VExt
};

enum class KEITHLEY4200SHARED_EXPORT Keithley4200CurrentRanges {
    Autorange,
    Range1nA,
    Range10nA,
    Range100nA,
    Range1uA,
    Range10uA,
    Range100uA,
    Range1mA,
    Range10mA,
    Range100mA,
    Range1A,
    Range1pA,
    Range10pA,
    Range100pA
};

enum class KEITHLEY4200SHARED_EXPORT Keithley4200VoltageMeasureChannels {
    SMU1,
    SMU2,
    SMU3,
    SMU4,
    VM1,
    VM2,
    SMU5,
    SMU6,
    SMU7,
    SMU8,
    VM3,
    VM4,
    VM5,
    VM6,
    VM7,
    VM8
};

enum class KEITHLEY4200SHARED_EXPORT Keithley4200CurrentMeasureChannels {
    SMU1,
    SMU2,
    SMU3,
    SMU4,
    SMU5,
    SMU6,
    SMU7,
    SMU8
};

enum class KEITHLEY4200SHARED_EXPORT Keithley4200IntegrationTimes {
    Short,
    Medium,
    Long
};

#endif // KEITHLEY4200DEFINITIONS_H
