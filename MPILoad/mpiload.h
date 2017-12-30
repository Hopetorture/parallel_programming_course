#ifndef MPILOAD_H
#define MPILOAD_H

#include "abstractworkload.h"

class MPILoad : public AbstractWorkload
{
public:
    MPILoad();
    QStringList startLoad(QMap<QString, QVariant> args) override;
};

#endif // MPILOAD_H
