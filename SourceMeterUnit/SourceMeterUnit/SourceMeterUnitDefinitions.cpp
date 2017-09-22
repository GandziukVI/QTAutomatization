#include "SourceMeterUnitDefinitions.h"

#include <QObject>

IV_Data::IV_Data()
    : Time(0),
      Voltage(0),
      Current(0)
{
}

IV_Data::IV_Data(double time, double voltage, double current)
    : Time(time),
      Voltage(voltage),
      Current(current)
{
}

QString IV_Data::ToString() const
{
    return QObject::tr("%1\t%2\t%3").arg(Time).arg(Voltage).arg(Current);
}


TraceData::TraceData()
    : Time(0),
      Value(0)
{
}

TraceData::TraceData(double time, double val)
    : Time(time),
      Value(val)
{
}

TraceData::TraceData(QString inputString)
{
    QRegExp delimitersRegExp("(\\r|\\n)");
    QRegExp separatorsRegExp("(\\ )");

    QStringList query = inputString.remove(delimitersRegExp).split(separatorsRegExp, QString::SkipEmptyParts);

    Time = QString(query.at(0)).toDouble();
    Value = QString(query.at(1)).toDouble();
}
