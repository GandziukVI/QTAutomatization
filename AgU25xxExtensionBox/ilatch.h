#ifndef ILATCH_H
#define ILATCH_H

#include "agu25xxextensionbox_global.h"

class AGU25XXEXTENSIONBOXSHARED_EXPORT ILatch {
public:
    ILatch() { }
    virtual void PulseLatchForChannel(unsigned int) = 0;
};

#endif // ILATCH_H
