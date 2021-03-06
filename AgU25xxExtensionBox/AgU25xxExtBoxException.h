#ifndef AGU25XXEXTBOXEXCEPTION_H
#define AGU25XXEXTBOXEXCEPTION_H

#include "agu25xxextensionbox_global.h"
#include <QException>

class AGU25XXEXTENSIONBOXSHARED_EXPORT AgU25xxExtBoxException : public QException
{
public:
    AgU25xxExtBoxException();
    AgU25xxExtBoxException(QString msg);

    void raise() const;
    AgU25xxExtBoxException *clone() const;
    QString message() const;

private:
    QString errmsg;
};

#endif // AGU25XXEXTBOXEXCEPTION_H
