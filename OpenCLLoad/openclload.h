#ifndef OPENCLLOAD_H
#define OPENCLLOAD_H

#include "abstractworkload.h"

class OpenCLLoad : AbstractWorkload
{
public:
    OpenCLLoad();
    QStringList startLoad(QMap<QString, QVariant> args) override;
};

#endif // OPENCLLOAD_H
