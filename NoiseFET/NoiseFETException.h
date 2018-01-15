#ifndef NOISEFETEXCEPTION_H
#define NOISEFETEXCEPTION_H

#include <QException>

class NoiseFETException : public QException
{
public:
    NoiseFETException();
    NoiseFETException(QString msg);

    void raise() const;
    NoiseFETException *clone() const;
    QString message() const;

private:
    QString errmsg;
};

#endif // NOISEFETEXCEPTION_H
