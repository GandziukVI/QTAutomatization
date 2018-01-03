#include "AgU25xxExtBoxException.h"

AgU25xxExtBoxException::AgU25xxExtBoxException()
{

}

AgU25xxExtBoxException::AgU25xxExtBoxException(QString msg)
{
    errmsg = msg;
}

void AgU25xxExtBoxException::raise() const
{
    throw *this;
}

AgU25xxExtBoxException *AgU25xxExtBoxException::clone() const
{
    return new AgU25xxExtBoxException(*this);
}

QString AgU25xxExtBoxException::message() const
{
    return errmsg;
}
