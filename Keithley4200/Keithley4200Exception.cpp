#include "Keithley4200Exception.h"

Keithley4200Exception::Keithley4200Exception()
{
}

Keithley4200Exception::Keithley4200Exception(QString& msg)
{
    errmsg = msg;
}

void Keithley4200Exception::raise() const
{
    throw *this;
}

Keithley4200Exception* Keithley4200Exception::clone() const
{
    return new Keithley4200Exception(*this);
}

QString Keithley4200Exception::message() const
{
    return errmsg;
}
