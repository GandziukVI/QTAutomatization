#include "NoiseFETException.h"

NoiseFETException::NoiseFETException()
{

}

NoiseFETException::NoiseFETException(QString msg)
{
    errmsg = msg;
}

void NoiseFETException::raise() const
{
    throw *this;
}

NoiseFETException *NoiseFETException::clone() const
{
    return new NoiseFETException(*this);
}

QString NoiseFETException::message() const
{
    return errmsg;
}
