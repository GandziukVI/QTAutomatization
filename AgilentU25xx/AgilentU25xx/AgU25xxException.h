#ifndef AGU25XXEXCEPTION_H
#define AGU25XXEXCEPTION_H

#include "agilentu25xx_global.h"

#include <QException>

class AGILENTU25XXSHARED_EXPORT AgU25xxException : public QException
{
public:
    AgU25xxException();
    AgU25xxException(QString& msg);

    void             raise() const;
    AgU25xxException *clone() const;
    QString          message() const;

private:
    QString errmsg;
};

#endif // AGU25XXEXCEPTION_H
