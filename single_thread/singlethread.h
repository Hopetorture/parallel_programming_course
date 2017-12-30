#ifndef SINGLETHREAD_H
#define SINGLETHREAD_H

#include "abstractworkload.h"
#include <iostream>

class SingleThread : public AbstractWorkload
{
public:
     SingleThread();
    //~SingleThread();

    QStringList startLoad(QMap<QString, QVariant> args);
};

#endif // SINGLETHREAD_H

