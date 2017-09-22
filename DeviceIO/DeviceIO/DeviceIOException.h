#ifndef DEVICEIOEXCEPTION_H
#define DEVICEIOEXCEPTION_H

#include "deviceio_global.h"

#include <QException>

class DEVICEIOSHARED_EXPORT DeviceIOException : public QException
{
public:
    DeviceIOException();
    DeviceIOException(QString& msg);

    void               raise() const;
    DeviceIOException* clone() const;
    QString            message() const;

private:
    QString errmsg;
};

#endif // DEVICEIOEXCEPTION_H
