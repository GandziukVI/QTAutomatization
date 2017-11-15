#ifndef KEITHLEY4200EXCEPTION_H
#define KEITHLEY4200EXCEPTION_H

#include "keithley4200_global.h"

#include <QException>

class KEITHLEY4200SHARED_EXPORT Keithley4200Exception : public QException
{
public:
    Keithley4200Exception();
    Keithley4200Exception(QString& msg);

    void                   raise() const;
    Keithley4200Exception* clone() const;
    QString                message() const;

private:
    QString errmsg;
};

#endif // KEITHLEY4200EXCEPTION_H
