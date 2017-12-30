#ifndef OPENMPLOAD_H
#define OPENMPLOAD_H

#include "abstractworkload.h"

class OpenMPLoad : public AbstractWorkload
{
public:
    OpenMPLoad();
    QStringList startLoad(QMap<QString, QVariant> args) override;
};

#endif // OPENMPLOAD_H
