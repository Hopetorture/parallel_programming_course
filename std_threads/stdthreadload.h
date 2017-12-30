#ifndef STDTHREADLOAD_H
#define STDTHREADLOAD_H
#include "abstractworkload.h"
#include <thread>
class StdThreadLoad : public AbstractWorkload
{
public:
    StdThreadLoad();
    QStringList startLoad(QMap<QString, QVariant> args) override;
private:
    std::vector<std::thread*> pool;
    //int trNum = std::thread::hardware_concurrency();
};

#endif // STDTHREADLOAD_H
