#ifndef AVXLOAD_H
#define AVXLOAD_H

#include "abstractworkload.h"

class AVXLoad : public AbstractWorkload
{
public:
    AVXLoad();
    QStringList startLoad(QMap<QString, QVariant> args) override;
private:
    QString avxMd5(const QString &s);
};

#endif // AVXLOAD_H
