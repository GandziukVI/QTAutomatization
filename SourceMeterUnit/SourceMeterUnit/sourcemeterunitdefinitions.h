#ifndef SOURCEMETERUNITDEFINITIONS_H
#define SOURCEMETERUNITDEFINITIONS_H

#include "sourcemeterunit_global.h"

enum class SOURCEMETERUNITSHARED_EXPORT SMUSourceMode {
    Voltage,
    Current,
    Common,
    ModeNotSet
};

enum class SOURCEMETERUNITSHARED_EXPORT SMUSourceFunction {
    VAR1,
    VAR2,
    Constant,
    VAR1Alternative
};

enum class SOURCEMETERUNITSHARED_EXPORT SMUSweepMode {
    LinearSweep,
    Log10Sweep,
    Log25Sweep,
    Log50Sweep
};

enum class SOURCEMETERUNITSHARED_EXPORT SMUSenseMode {
    Voltage,
    Current,
    Resistance,
    ModeNotSet
};

enum class SOURCEMETERUNITSHARED_EXPORT SMUOhmsMode {
    Auto,
    Manual,
    ModeNotSet
};

enum class SOURCEMETERUNITSHARED_EXPORT SMUAutoZeroMode {
    AutoZeroON,
    AutoZeroOFF
};

enum class SOURCEMETERUNITSHARED_EXPORT SMUShapeMode {
    DC,
    Pulse,
    ModeNotSet
};

class SOURCEMETERUNITSHARED_EXPORT IV_Data {

public:
    IV_Data();
    IV_Data(double time, double voltage, double current);

    double Time;
    double Voltage;
    double Current;

    QString ToString() const;
};

class SOURCEMETERUNITSHARED_EXPORT TraceData {

public:
    TraceData();
    TraceData(double time, double val);
    TraceData(QString inputString);

    double Time;
    double Value;
};

#endif // SOURCEMETERUNITDEFINITIONS_H
