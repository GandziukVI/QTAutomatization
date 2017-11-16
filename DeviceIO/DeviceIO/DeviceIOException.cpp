#include "DeviceIOException.h"

DeviceIOException::DeviceIOException()
{
}

DeviceIOException::DeviceIOException(QString msg)
{
    errmsg = msg;
}

void DeviceIOException::raise() const
{
    throw *this;
}

DeviceIOException* DeviceIOException::clone() const
{
    return new DeviceIOException(*this);
}

QString DeviceIOException::message() const
{
    return errmsg;
}
