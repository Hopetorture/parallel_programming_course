#ifndef PTHREADSLOAD_H
#define PTHREADSLOAD_H

#include "abstractworkload.h"

class PthreadsLoad : public AbstractWorkload
{
public:
    PthreadsLoad();
    QStringList startLoad(QMap<QString, QVariant> args) override;

private:
    QList<QStringList> dicts;
    QList<QStringList> results;
};

#endif // PTHREADSLOAD_H
