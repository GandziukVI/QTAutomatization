#include "AgU25xxException.h"

AgU25xxException::AgU25xxException()
{

}

AgU25xxException::AgU25xxException(QString msg)
{
    errmsg = msg;
}

void AgU25xxException::raise() const
{
    throw *this;
}

AgU25xxException *AgU25xxException::clone() const
{
    return new AgU25xxException(*this);
}

QString AgU25xxException::message() const
{
    return errmsg;
}
